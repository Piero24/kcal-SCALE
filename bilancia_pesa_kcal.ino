/*  Attenzione: facendo il copia/incolla dal PDF all’IDE si perde la formattazione del testo.
Per rendere piu’ facilmente leggibile il programma e’ opportuno formattarlo subito dopo il
trasferimento nell’IDE, premendo CTRL+T   Nel trasferimento  si perdono anche gli spazi compresi
tra apici (“ “),  per cui una volta trasferito il programma nell’IDE bisogna intervenire
manualmente per reintrodurre gli spazi perduti (vedi anche le note in rosso nella versione pdf
del programma).
*
 * Questo programma contiene, oltre al set di caratteri utilizzati dalla libreria liquidcrystal,
 * una tabella di oltre 2200 caratteri e per tale ragione non puo' essere eseguito su Arduino uno
 * (che dispone, per le variabili, poco piu' di 2000 caratteri). E' stato quindi sviluppato e
 * provato su Arduino mega che, per caratteristiche e potenza, puo' tranquillamente gestire
 * tabelle di grandi dimensioni.
 *
 * Questo programma unisce le esperienze degli esercizi 41 e 42 (sensore di peso e
 * tastiera  + display2004), alle cui schede si rimanda per la costruzione
 * dell'impianto e per le problematiche di installazione delle librerie (attenzione:
 * il display 2004 deve essere collegato alle porte 20 e 21 di arduino mega al posto
 * delle tradizionali porte A4 ed a5 di arduino uno).
 *
connessioni del modulo H711:
   Hx711.DO   - porta analogica 1
   Hx711.SCK  - porta analogica 0
*
connessioni del sensore di peso:
   rosso  = E+
   nero   = E-
   bianco = A-
   verde  = A+
*
connessioni del tastierino numerico:
pin delle righe (primi 4 connettori di sinistra):
                                                    porte 2,3,4 e 5
pin delle colonne (ultimi 4 connettori di destra):  porte 6,7,8,e 9
*
connessione del display 2004 (4 righe da 20 caratteri)
   pin SDA: porta 20
   pin SCL: porta 21
*
Manuale d'uso:
  tasti numerici: selezione della categoria alimentare e dell'alimento
  tasti non numerici:
   "A"  = clear, cancella l'ultima selezione e chiede nuovamente la categoria alimentare
          per il prodotto presente sul piatto
   "B"  = aggiunge alla ricetta l'ingrediente sul piatto
   "C"  = eliminazione dalla ricetta l'ultimo ingrediente aggiunto
   "D"  = pulisce il sistema  e lo predispone ad una nuova ricetta
   "*"  = conferma l'eliminazione
   "#"  = annulla la richiesta di eliminazione
*/
#include <Keypad.h> // libreria di gestione della tastiera
#include <Wire.h> // libreria wire presente, di fault, nell'IDE
#include <LiquidCrystal_I2C.h> // libreria di gestione del display lcd
#include "HX711.h" // libreria di gestione del modulo HX711, per la gestione // del sensore di peso
//
// nelle prossime due righe vengono attribuiti i parametri per la gestione del display //--------------------addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
#define DOUT A1
#define CLK A0
//HX711 bilancia(DOUT, CLK);
HX711 bilancia;
int peso = 0;
int pesoprec = 0;
float zonacalcolo = 0;
char tastobattuto;
const byte righe = 4;
const byte colonne = 4;
char chiave[righe][colonne] ={
// tabella di trascodifica dei tasti battuti. 
// la tabella riproduce, su quattro righe di quattro colonne, la posizione dei tasti 
// e assegna ad ogni tasto il valore che gli compete. E'possibile assegnare valori 
// diversi semplicemente modificando i singoli valori in tabella
{'1', '2', '3', 'a'},
{'4', '5', '6', 'b'},
{'7', '8', '9', 'c'},
{'*', '0', '#', 'd'}
};

byte pinrighe[righe] = {2, 3, 4, 5}; //porte cui devono essere connessi i pin delle righe (i primi quattro pin di sinistra) della
//
//
byte pincolonne[colonne] = {6, 7, 8, 9}; //porte cui devono essere connessi i pin delle
//                                         colonne (gli ultimi quattro pin di destra) della
// tastiera
//prossima riga: assegnazione dei parametri alla libreria keypad.h
Keypad keypad = Keypad( makeKeymap(chiave), pinrighe, pincolonne, righe, colonne );
int tastocorrente = 0;// zona di memorizzazione dell'ultimo tasto numerico battuto
unsigned long iniziopesostabile = 0; // zona di memorizzazione del momento di inizio del controllo
// della stabilizzazione del peso
unsigned long calalim  = 0; // zona di calcolo intermedio
unsigned long comodocalcolo = 0; // zona di calcolo intermedio

int semaforo = 0; // semaforo che indica la situazione del sistema:
//0= si e' in attesa della battitura del primo tasto
//1= si e' in attesa della battitura del secondo tasto
//2= si e' in attesa della battitura di un codice di conferma o annulla
//3= si e' in attesa di battutura del tasto "b" (aggiungi alla ricetta)
//o del tasto "a" (pulisci)
//6= e' in corso l'azzeramento della ricetta
int pesostabile =0; // semaforo di segnalazione di peso stabile:
//0 = peso in via di definzione
//1 = peso stabile, sistema in fase di calcolo calorie
int catalim =0; // zona di memorizzazione del codice della categoria alimentare
int alim =0; // zona di memorizzazione del codice dell'alimento
int cal =0;// zona di memorizzazione delle calorie dell'alimento che si trova sul piatto
int totcal =0; // zona di memorizzazione delle calorie della ricetta in via di elaborazione
int ultcat =0; // zona di memorizzazione della categoria dell'ultimo alimento aggiunto alla ricetta
int ultalim =0; // zona di memorizzazione del codice dell'ultimo alimento aggiunto alla ricetta
int ultpeso =0; // zona di memorizzazione del peso dell'ultimo ingrediente aggiunto alla ricetta
int ultcal =0; // zona di memorizzazione delle calorie dell'ultimo ingrediente aggiunto alla ricetta
//

char categoria [10][21]  =        // tabella categorie alimentari
{
  {"verdura,ortaggi frsc"},
  {"frutta fresca/secca "},
  {"carni fresche e uova"},
  {"pesce fresco/conserv"},
  {"latte e latticini   "},     // riempire con spazi a destra sino a completare i 20 caratteri
  {"salumi/carni conserv"},
  {"pane/cereali e deriv"},
  {"condimenti e semilav"},
  {"prodotti lavorati   "},     // riempire con spazi a destra sino a completare i 20 caratteri
  {"bevande             "},     // riempire con spazi a destra sino a completare i 20 caratteri
};

// le seguenti tabelle: alimento e calorie sono tabelle gemelle,
// sono cioe' tabelle che, a parita' di indice, forniscono una la descrizione dell'alimento 
// e l'altra il numero di calorie per 100 grammi

char alimento [100][21] =
{
  {"maiale              "}, // indice 24
  {"manzo               "}, // indice 25
  {"pollo o tacchino    "}, // indice 26
  {"pasta secca/riso    "}, // indice 68
  {"pasta ripiena fresca"}, // indice 69
  {"codice non valido   "}, // indice 95
  {"codice non valido   "}, // indice 96
  {"codice non valido   "}, // indice 97
  {"codice non valido   "}, // indice 98
  {"codice non valido   "}, // indice 99
};

int calorie [100] =
{
  180, // indice 24  {"maiale              ", 180},
  160, // indice 25  {"manzo               ", 160},
  130, // indice 26  {"pollo o tacchino    ", 130},
  362, // indice 68  {"pasta secca/riso    ", 362},
  280, // indice 60  {"pasta ripiena fresca", 280},
  0,   // indice 95  {"                    ", 0},
  0,   // indice 96  {"                    ", 0},
  0,   // indice 97  {"                    ", 0},
  0,   // indice 98  {"                    ", 0},
  0,   // indice 98  {"                    ", 0},
};
//
// *************** routine di pesatura ***************** //
//
void pesatura (void){

  // se il peso e' stabile da meno di 2 secondi verifica che non sia cambiato
  while ((millis() - iniziopesostabile) < 2000) {

    peso = bilancia.get_units(20), 3;
    zonacalcolo = pesoprec - peso;
    // se sulla bilancia ci sono meno di 3 grammi
    if (peso < 3){

      // non considera il valore e mette il sistema in attesa di un nuovo peso
      iniziopesostabile = millis ();
      
      // Pulisce lo schermo
      lcd.clear ();
      // posiziona il cursore all'inizio della prima riga (car.0 e riga0)
      lcd.setCursor(0, 0);
      lcd.print(peso);
      lcd.print("g ");
      // posiziona cursore a inizio della seconda riga (cararattere 0 e riga 1)
      lcd.setCursor(0, 1);
      lcd.print(" metti sul piatto ");
      // posiziona cursore a inizio della terza riga (car.0 e riga 1)
      lcd.setCursor(0, 2);
      lcd.print("un nuovo ingrediente");
      // posiziona cursore a inizio quarta riga (car. 0 e riga 3) lcd.print("tot.kcal: ");
      lcd.setCursor(0, 3);
      lcd.print("tot.kcal: ");
      lcd.print (totcal);
    }

    // se c'e' stata un'escursione di peso maggiore del 2%
    if ((((zonacalcolo * 100) / pesoprec) > 2) || (((zonacalcolo * 100) / pesoprec) < -2)){

      // e' variato il peso, ricomincia da capo
      iniziopesostabile = millis (); 
      // memorizza il peso corrente
      pesoprec = peso;
      // pulisce lo schermo
      lcd.clear ();
      // posiziona il cursore all'inizio della prima riga (car.0 e riga0)
      lcd.setCursor(0, 0);
      lcd.print(peso);
      // inserire 6 spazi a destra, prima dell’apice di chiusura
      lcd.print("g - attendi      ");
      // posiziona cursore a inizio della seconda riga (cararattere 0 e riga 1)
      lcd.setCursor(0, 1);
      lcd.print("la stabilizzazione");
      // posiziona cursore a inizio terza riga (carattere 0 e riga 2)
      lcd.setCursor(0, 2);
      lcd.print("della pesatura... ");
      // posiziona cursore a inizio quarta riga (carattere 0 e riga 3)
      lcd.setCursor(0, 3); 
      lcd.print("tot.kcal: ");
      lcd.print (totcal);
 
    }
  }

  // se il peso e' stabile da piu' di due secondi
  // pulisce lo schermo
  lcd.clear ();
  // posiziona il cursore all'inizio della prima riga (carattere 0 e riga 0)
  lcd.setCursor(0, 0);
  lcd.print(peso);
  lcd.print("g - categ. alim.?");
  // posiziona cursore a inizio quarta riga (carattere 0 e riga 3)
  lcd.setCursor(0, 3);
  lcd.print("tot.kcal: ");
  lcd.print (totcal);
  // setta il semaforo di peso stabile, per consentire la scelta dell'alimento
  pesostabile = 1;
  
}
//
//********************** routine di pulizia della selezione corrente ************
//

void pulisci (void){

  lcd.clear ();
  // azzera il peso memorizzato
  pesoprec= 0;
  // predispone il sistema ad una nuova pesatura
  pesostabile = 0;
  // predispone il semaforo all'acquisizione del primo codice
  semaforo = 0;
}

//********************** routine di somma dell'ultimo ingrediente ************

void aggiungiallaricetta (void){

  // memorizza il codice dell'alimento
  ultalim = alim;
  // memorizza il codice della categoria
  ultcat  = catalim;
  // memorizza il peso dell'ingrediente che si sta aggiungendo
  ultpeso = peso;
  // memorizza le calorie dell'ingrediente che si sta aggiungendo
  ultcal  = cal;
  // aggiunge le calorie correnti al totale della ricetta
  totcal  = totcal + cal;
  // posiziona cursore a inizio della seconda riga (cararattere 0 e riga 1)
  lcd.setCursor(0, 1);
  lcd.print("ingrediente aggiunto");
  // posiziona cursore a inizio della terza riga (cararattere 0 e riga 2)
  lcd.setCursor(0, 2);
  lcd.print("svuota il piatto    ");
  // posiziona cursore a inizio della seconda riga (cararattere 0 e riga 1)
  lcd.setCursor(0, 3);
  lcd.print ("                    ");
  // posiziona cursore a inizio della seconda riga (cararattere 0 e riga 1)
  lcd.setCursor(0, 3);
  lcd.print("tot.kcal: ");
  lcd.print (totcal);
  // attende 3 secondi prima di continuare nella elaborazione
  delay (3000);
  // predispone il sistema ad accettare un nuovo ingrediente
  pulisci ();
}
//
//************** routine di richiesta conferma eliminazione *************************
//
void chiediconferma(void){

  // se e' stato chiesto il reset
  if (semaforo == 6){

    // pulisce lo schermo
    lcd.clear ();
    // posiziona cursore a inizio prima riga (carattere 0 e riga 0)
    lcd.setCursor(0, 0);
    lcd.print("vuoi cancellare "); // inserire spazi a destra sino a 20 caratteri
    // posiziona cursore a inizio seconda riga (carattere 0 e riga 1)
    lcd.setCursor(0, 1);
    lcd.print("tutto e ripartire? ");
    // posiziona cursore a inizio della terza riga (carattere 0 e riga 3)
    lcd.setCursor(0, 3);
    // chiede conferma
    lcd.print("confermi? S/N");
    
  } else {
    // predispone la ricezione del codice di conferma o di eliminazione
    semaforo = 2;
    // pulisce lo schermo
    lcd.clear ();
    // posiziona cursore a inizio prima riga (carattere 0 e riga 0)
    lcd.setCursor(0, 0);
    lcd.print ("canc. ");
    // evidenzia il peso dell'ultimo ingrediente aggiunto
    lcd.print(ultpeso);
    lcd.print ("g ");
    // evidenzia le calorie dell'ultimo ingrediente aggiunto
    lcd.print (ultcal);
    lcd.print ("kcal");
    // posiziona cursore a inizio seconda riga (carattere 0 e riga 1)
    lcd.setCursor(0, 1);
    // evidenzia la categoria dell'ultimo ingrediente
    lcd.print(categoria [ultcat]);
    // posiziona cursore a inizio terza riga (carattere 0 e riga 2)
    lcd.setCursor(0, 2);
    // evidenzia il nome dell'ultimo ingrediente 
    lcd.print(alimento [ultalim]);
    // posiziona cursore a inizio terza riga (carattere 0 e riga 3)
    lcd.setCursor(0, 3);
    // chiede conferma
    lcd.print("confermi? S/N");
                           
  }
}
//
//******************** routine di selezione della categoria alimentare********
//

void categorialimentare (void){

  // predispone alla ricezione del secondo codice (alimento)
  semaforo = 1;
  // memorizza la categoria alimentare
  catalim = tastocorrente;
  // posiziona cursore a inizio seconda riga (carattere 0 e riga 1)
  lcd.setCursor(0, 1);
  // visualizza sul display (riga 1) la categoria alimentare
  lcd.print(categoria [catalim]);
  // posiziona cursore a inizio terza riga (carattere 0 e riga 2)
  lcd.setCursor(0, 2);
  // chiede l'inserimento del codice di alimento
  lcd.print("codice alimento?");
}
//
//********************** routine di selezione dell'ingrediente ****************
//

void ingrediente (void){
  
  semaforo = 3;
  // posiziona cursore a inizio terza riga (carattere 0 e riga 2)
  lcd.setCursor(0, 2);
  // Calcola la posizione dell'alimento in tabella
  alim = (catalim * 10) + tastocorrente;
  // espone la descrizione dell'alimento
  lcd.print(alimento [alim]);
  // posiziona il cursore sulla prima riga
  lcd.setCursor (0, 0);
  // inserire spazi sino a 20 caratteri
  lcd.print ("                    ");
  lcd.setCursor (0, 0);
  // posiziona il cursore sulla prima riga
  lcd.print (peso);
  lcd.print ("g - kcal: ");
  calalim = calorie[alim];
  // calcolo intermedio
  comodocalcolo = peso * calalim;
  Serial.print (peso);
  Serial.print (" - ");
  Serial.print (calalim);
  Serial.print (" - ");
  Serial.print (comodocalcolo);
  Serial.print (" - ");
  // calcola le calorie dell'ingrediente sul piatto
  cal = comodocalcolo / 100;
  lcd.print (cal);
  // posiziona il cursore sulla quarta riga
  lcd.setCursor (0, 3); 
  lcd.print ("a:canc. / b:aggiungi");
}
//
//****** routine di conferma dell'eliminazione dell'ultimo ingrediente********
//
void confermaeliminazione (void){

  if (semaforo == 2){

    //sottrae l'ultimo ingrediente al totale calorie
    totcal = totcal - ultcal;
    // azzera ultimo peso
    ultpeso = 0;
    // azzera ultime calorie
    ultcal = 0;
    // pulisce lo schermo
    lcd.clear ();
    // posiziona cursore a inizio prima riga (carattere 0 e riga 0)
    lcd.setCursor(0, 0);
    lcd.print ("ingrediente ");
    // posiziona cursore a inizio seconda riga (carattere 0 e riga 1)
    lcd.setCursor(0, 1);
    lcd.print("cancellato");
    // posiziona cursore a inizio quarta riga (carattere 0 e riga 3)
    lcd.setCursor(0, 3);
    lcd.print("nuovo tot.kcal: ");
    lcd.print (totcal);
    delay (3000);
    
  } else {

    // pone il sistema in attesa di una nuova ricetta
    // azzera il totale della ricetta
    totcal = 0; 
    lcd.clear ();
    lcd.print ("bilancia pronta ");
    // posiziona cursore a inizio seconda riga (carattere 0 e riga 1)
    lcd.setCursor(0, 1);
    lcd.print("per una nuova");
    // posiziona cursore a inizio terza riga (carattere 0 e riga 2)
    lcd.setCursor(0, 2);
    lcd.print("ricetta");
    // posiziona cursore a inizio quarta riga (carattere 0 e riga 3)
    lcd.setCursor(0, 3);
    lcd.print("tot.kcal: ");
    lcd.print (totcal);
    // attende 3 secondi
    delay (3000);
    
  }

  pulisci ();
}

void setup(){

  bilancia.begin(DOUT, CLK);

  // attiva monitor seriale per comunicazioni di debug
  Serial.begin (9600);
  // inizializza il display (20 caratteri per 4 righe)
  lcd.begin(20, 4);
  // illumina lo sfondo del display
  lcd.backlight();
  // pulisce il display
  lcd.clear();
  // posiziona il cursore all'inizio della prima riga (carattere 0 e riga 0)
  lcd.setCursor(0, 0);

  lcd.print("calcolo della tara");
  // posiziona il cursore all'inizio della seconda riga (carattere 0 e riga 1)
  lcd.setCursor(0, 1);
  lcd.print("non porre nulla");
  // posiziona il cursore all'inizio della terza riga (carattere 0 e riga 2) 
  lcd.setCursor(0, 2);
  lcd.print("sulla bilancia.....");
  // posiziona il cursore all'inizio della quarta riga (carattere 0 e riga 3)
  lcd.setCursor(0, 3);
  // valore di scala, definito tramite il programma inserito nella scheda descrittiva del progetto
  bilancia.set_scale(2045);
  // il peso attuale e' considerato tara
  bilancia.tare(20);
  // pulisce il display
  lcd.clear();
  lcd.print("bilancia pronta");
  
}


void loop() {
  // se si deve procedere ad una pesatura
  if (pesostabile == 0) {

    // memorizza il momento di inizio della pesatura
    iniziopesostabile = millis ();
    // lancia la routine di pesatura
    pesatura ();
    
    
  } else {

    // acquisisce il valore ascii del tasto battuto (gia' trascodificato tramite la tabella chiave)
    tastobattuto = keypad.getKey();

    // se è stato premuto un tasto
    if (tastobattuto) {

      // richiesta di eliminazione della selezione corrente
      if (tastobattuto == 'a')
        pulisci ();

      // richiesta di aggiunta alla ricetta
      if ((semaforo == 3) && (tastobattuto == 'b'))
        aggiungiallaricetta ();

      // richiesta di cancellazione dell'ultimo ingrediente inserito nella ricetta
      if ((totcal > 0) && (tastobattuto == 'c'))
        chiediconferma ();

      // richiesta di reset della ricetta
      if (tastobattuto == 'd'){
        // imposta il semaforo di reset della ricetta
        semaforo = 6;
        chiediconferma();
      }

      // se viene confermata l'eliminazione
      if (((semaforo == 2) || (semaforo == 6)) && (tastobattuto == '*')) 
        confermaeliminazione ();

      // se viene annullata la eliminazione
      if (((semaforo == 2) || (semaforo == 6)) && (tastobattuto == '#')) 
        pulisci ();

      if ((tastobattuto >= '0') && (tastobattuto <= '9')){

        // memorizza in una zona di lavoro numerica il valore ascii del tasto battuto
        tastocorrente = tastobattuto;
        // trasforma il valore ascii in un valore numerico da 0 a 9
        tastocorrente = tastocorrente - 48;

        // se si attendeva una categoria alimentare
        if (semaforo == 0)
          categorialimentare ();
        // se si attendeva un codice di alimento
        else if (semaforo == 1)
          // lancia la routine di acqusizione del codice di alimento
          ingrediente ();
      
      }
      }
    }
  }
