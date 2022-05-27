#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "HX711.h"

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
#define DOUT A1
#define CLK A0
HX711 scale;
int weight = 0;
int weightprec = 0;
float calczone = 0;
char clickbutton;
const byte rows = 4;
const byte columns = 4;

// table of transcoding of keystrokes.
char key[rows][columns] ={
  
  {'1', '2', '3', 'a'},
  {'4', '5', '6', 'b'},
  {'7', '8', '9', 'c'},
  {'*', '0', '#', 'd'}
};

// ports to which the rows pins must be connected
byte pinrows[rows] = {2, 3, 4, 5};
// ports to which columns pins must be connected
byte pincolumns[columns] = {6, 7, 8, 9};
Keypad keypad = Keypad( makeKeymap(key), pinrows, pincolumns, rows, columns );

int actualbutton = 0;
unsigned long startstableweight = 0;
unsigned long calalim  = 0;
unsigned long comcalc = 0;

// semaphore indicating the system situation:
// 0 = waiting for the first key to be typed
// 1 = the second key is awaited
// 2 = you are waiting for a confirmation or cancel code to be typed
// 3 = key "b" (add to recipe) or key "a" (cleansection) is awaited
// 6 = the recipe is being reset
int semaphore = 0; 
// stable weight signaling semaphore:
// 0 = weight being defined
// 1 = weight stable, system in phase of calculating calories
int stableweight =0;
// storage area of the food category code
int catalim =0;
// food code storage area
int alim =0;
// area for storing the calories of the food that is on the plate
int cal =0;
// calorie storage area of the recipe being developed
int totcal =0;
// storage area of the main category of the last food added to the recipe
int ultcat =0;
// area for storing the code of the last food added to the recipe
int ultalim =0;
// weight storage area of the last foodcat added to the recipe
int ultweight =0;
// calorie storage area of the last foodcat added to the recipe
int ultcal =0;

// food categories table
char maincategory [10][21]  =
{
  {"vegetables, frsh veg"},
  {"fresh / dried fruit "},
  {"fresh meat and eggs "},
  {"fresh / preserv fish"},
  {"milk and dairy pruct"},
  {"cured meats and cons"},
  {"bread/cereals deriv "},
  {"condiments/unfinis. "},
  {"processed products  "},
  {"drinks              "},
};

// the following tables: food and calories are twin tables,
// they are tables that, with the same index, provide a description of the food
// and the other the number of calories per 100 grams

char food [100][21] =
{
  {"carrots and leeks   "},
  {"onions and cabbage  "},
  {"beans and cabbage   "},
  {"musnrooms           "},
  {"eggpla/artich/pumpk "},
  {"potatoes and legumes"},
  {"peppers             "},
  {"tomatoes            "},
  {"salad/fennel/celery "},
  {"zucchini/cucumbers  "},
  
  {"apric/peaches/melons"},
  {"oranges             "},
  {"chestnut/dried plums"},
  {"fresh figs and plums"},
  {"dried figs          "},
  {"almonds/pine nuts   "},
  {"apples and pears    "},
  {"walnuts/hazelnuts   "},
  {"grapes and banana   "},
  {"invalid code        "},
  
  {"lamb                "},
  {"duck                "},
  {"capon               "},
  {"rabbit and wild boar"},
  {"pig                 "},
  {"beef                "},
  {"chicken and turkey  "},
  {"whole eggs          "},
  {"egg yolk            "},
  {"invalid code        "},
  
  {"Anchovies           "},
  {"anchovie/fresh anch."},
  {"Sea bass and cod    "},
  {"shellfish           "},
  {"cuttlefish, oct ecc."},
  {"smoked salmon       "},
  {"sardines/sea bream  "},
  {"sardine/tuna wth oil"},
  {"mackerel/tuna/salmon"},
  {"fresh trout         "},
  
  {"fresh cheeses       "},
  {"hard aged cheeses   "},
  {"soft aged cheeses   "},
  {"whole milk/yogurt   "},
  {"milk/skimmed yogurt "},
  {"mascarpone cheese   "},
  {"cream               "},
  {"ricotta cheese      "},
  {"invalid code        "},
  {"invalid code        "},
  
  {"raw ham             "},
  {"baked ham           "},
  {"speck               "},
  {"mortadella          "},
  {"fresh sausage       "},
  {"sausage             "},
  {"bacon               "},
  {"bresaola            "},
  {"invalid code        "},
  {"invalid code        "},
  
  {"shortbread/rice bisc"},
  {"flour and starch    "},
  {"dry slices and bis  "},
  {"potato gnocchi      "},
  {"seasoned bread      "},
  {"fresh bread/pasta   "},
  {"whole grain bread   "},
  {"dry wholemeal pasta "},
  {"rice and dry pasta  "},
  {"fresh filled pasta  "},
  
  {"oil and lard        "},
  {"butter              "},
  {"stock cube          "},
  {"lard                "},
  {"margarine           "},
  {"tomato concentrate  "},
  {"peeled tom/tom sauce"},
  {"dried vegetables    "},
  {"Pearl barlev        "},
  {"invalid code        "},
  
  {"cereal flakes       "},
  {"candied fruit       "},
  {"canned beans/corn   "},
  {"jam                 "},
  {"honey               "},
  {"pickled olives      "},
  {"canned peas         "},
  {"semolina            "},
  {"sugar               "},
  {"nutella/chocolate   "},
  
  {"sweet/fizzy drinks  "},
  {"light drinks        "},
  {"beer                "},
  {"liqueur 40 degrees  "},
  {"wine 12 degrees     "},
  {"invalid code        "},
  {"invalid code        "},
  {"invalid code        "},
  {"invalid code        "},
  {"invalid code        "},
};


int calories [100] =
{
  32,  // indice 00  {"carrots and leeks   ", 32},
  25,  // indice 01  {"onions and cabbage  ", 25},
  20,  // indice 02  {"beans and cabbage   ", 20},
  23,  // indice 03  {"musnrooms           ", 23},
  18,  // indice 04  {"eggpla/artich/pumpk ", 18},
  80,  // indice 05  {"potatoes and legumes", 80},
  22,  // indice 06  {"peppers             ", 22},
  19,  // indice 07  {"tomatoes            ", 19},
  15,  // indice 08  {"salad/fennel/celery ", 15},
  14,  // indice 09  {"zucchini/cucumbers  ", 14},
  
  28,  // indice 10  {"apric/peaches/melons", 28},
  34,  // indice 11  {"oranges             ", 34},
  180, // indice 12  {"chestnut/dried plums", 180},
  50,  // indice 13  {"fresh figs and plums", 50},
  246, // indice 14  {"dried figs          ", 246},
  575, // indice 15  {"almonds/pine nuts   ", 575},
  43,  // indice 16  {"apples and pears    ", 43},
  630, // indice 17  {"walnuts/hazelnuts   ", 630},
  63,  // indice 18  {"grapes and banana   ", 63},
  0,   // indice 19  {"                    ", 0},
  
  162, // indice 20  {"lamb                ", 162},
  159, // indice 21  {"duck                ", 159},
  226, // indice 22  {"capon               ", 226},
  120, // indice 23  {"rabbit and wild boar", 120},
  180, // indice 24  {"pig                 ", 180},
  160, // indice 25  {"beef                ", 160},
  130, // indice 26  {"chicken and turkey  ", 130},
  130, // indice 27  {"whole eggs          ", 130},
  325, // indice 28  {"egg yolk            ", 325},
  0,   // indice 29  {"                    ", 0},
  
  128, // indice 30  {"Anchovies           ", 128},
  110, // indice 31  {"anchovie/fresh anch.", 110},
  82,  // indice 32  {"Sea bass and cod    ", 82},
  85,  // indice 33  {"shellfish           ", 85},
  70,  // indice 34  {"cuttlefish, oct ecc.", 70},
  180, // indice 35  {"smoked salmon       ", 180},
  120, // indice 36  {"sardines/sea bream  ", 120},
  250, // indice 37  {"sardine/tuna wth oil", 250},
  160, // indice 38  {"mackerel/tuna/salmon", 160},
  100, // indice 39  {"fresh trout         ", 100},
  
  240, // indice 40  {"fresh cheeses       ", 240},
  400, // indice 41  {"hard aged cheeses   ", 400},
  310, // indice 42  {"soft aged cheeses   ", 310},
  64,  // indice 43  {"whole milk/yogurt   ", 64},
  46,  // indice 44  {"milk/skimmed yogurt ", 46},
  460, // indice 45  {"mascarpone cheese   ", 460},
  300, // indice 46  {"cream               ", 300},
  146, // indice 47  {"ricotta cheese      ", 146},
  0,   // indice 48  {"                    ", 0},
  0,   // indice 49  {"                    ", 0},
  
  159, // indice 50  {"raw ham             ", 159},
  138, // indice 51  {"baked ham           ", 138},
  303, // indice 52  {"speck               ", 303},
  317, // indice 53  {"mortadella          ", 317},
  400, // indice 54  {"fresh sausage       ", 400},
  170, // indice 55  {"sausage             ", 170},
  661, // indice 56  {"bacon               ", 661},
  153, // indice 57  {"bresaola            ", 153},
  0,   // indice 58  {"                    ", 0},
  0,   // indice 59  {"                    ", 0},
  
  465, // indice 60  {"shortbread/rice bisc", 465},
  350, // indice 61  {"flour and starch    ", 350},
  390, // indice 62  {"dry slices and bis  ", 390},
  156, // indice 63  {"potato gnocchi      ", 156},
  285, // indice 64  {"seasoned bread      ", 285},
  270, // indice 65  {"fresh bread/pasta   ", 270},
  230, // indice 66  {"whole grain bread   ", 230},
  335, // indice 67  {"dry wholemeal pasta ", 335},
  362, // indice 68  {"rice and dry pasta  ", 362},
  280, // indice 60  {"fresh filled pasta  ", 280},
  
  900, // indice 70  {"oil and lard        ", 900},
  750, // indice 71  {"butter              ", 750},
  180, // indice 72  {"stock cube          ", 180},
  891, // indice 73  {"lard                ", 891},
  760, // indice 74  {"margarine           ", 760},
  50,  // indice 75  {"tomato concentrate  ", 50},
  20,  // indice 76  {"peeled tom/tom sauce", 20},
  310, // indice 77  {"dried vegetables    ", 310},
  319, // indice 78  {"Pearl barlev        ", 319},
  0,   // indice 79  {"                    ", 0},
  
  360, // indice 80  {"cereal flakes       ", 360},
  250, // indice 81  {"candied fruit       ", 250},
  90,  // indice 82  {"canned beans/corn   ", 90},
  284, // indice 83  {"jam                 ", 284},
  204, // indice 84  {"honey               ", 204},
  110, // indice 85  {"pickled olives      ", 110},
  55,  // indice 86  {"canned peas         ", 55},
  350, // indice 87  {"semolina            ", 350},
  392, // indice 88  {"sugar               ", 392},
  533, // indice 89  {"nutella/chocolate   ", 533},
  
  45,  // indice 90  {"sweet/fizzy drinks  ", 45},
  22,  // indice 91  {"light drinks        ", 22},
  42,  // indice 92  {"beer                ", 42},
  240, // indice 93  {"liqueur 40 degrees  ", 240},
  66,  // indice 94  {"wine 12 degrees     ", 66},
  0,   // indice 95  {"                    ", 0},
  0,   // indice 96  {"                    ", 0},
  0,   // indice 97  {"                    ", 0},
  0,   // indice 98  {"                    ", 0},
  0,   // indice 98  {"                    ", 0},
};


void weighing (void){

  // if the weight has been stable for less than 2 seconds, check that it hasn't changed
  while ((millis() - startstableweight) < 2000) {

    weight = scale.get_units(20), 3;
    calczone = weightprec - weight;

    if (weight < 3){

      startstableweight = millis ();
      

      lcd.clear ();
      lcd.setCursor(0, 0);
      lcd.print(weight);
      lcd.print("g ");
      lcd.setCursor(0, 1);
      lcd.print(" put on the plate ");
      lcd.setCursor(0, 2);
      lcd.print("a new foodcateg ");
      lcd.setCursor(0, 3);
      lcd.print("tot.kcal: ");
      lcd.print (totcal);
    }

    if ((((calczone * 100) / weightprec) > 2) || (((calczone * 100) / weightprec) < -2)){

      startstableweight = millis (); 
      weightprec = weight;
      lcd.clear ();
      lcd.setCursor(0, 0);
      lcd.print(weight);
      lcd.print("g - wait         ");
      lcd.setCursor(0, 1);
      lcd.print("stabilization     ");
      lcd.setCursor(0, 2);
      lcd.print("of the weighing...");
      lcd.setCursor(0, 3); 
      lcd.print("tot.kcal: ");
      lcd.print (totcal);
 
    }
  }


  lcd.clear ();
  lcd.setCursor(0, 0);
  lcd.print(weight);
  lcd.print("g -food category?");
  lcd.setCursor(0, 3);
  lcd.print("tot.kcal: ");
  lcd.print (totcal);
  stableweight = 1;
  
}


void cleansection (void){

  lcd.clear ();
  weightprec= 0;
  stableweight = 0;
  semaphore = 0;
}


void addtorecipe (void){

  ultalim = alim;
  ultcat  = catalim;
  ultweight = weight;
  ultcal  = cal;
  totcal  = totcal + cal;
  lcd.setCursor(0, 1);
  lcd.print("added ingredient    ");
  lcd.setCursor(0, 2);
  lcd.print("empty the plate     ");
  lcd.setCursor(0, 3);
  lcd.print ("                    ");
  lcd.setCursor(0, 3);
  lcd.print("tot.kcal: ");
  lcd.print (totcal);
  delay (3000);
  cleansection ();
}


void askforconfirmation(void){

  if (semaphore == 6){

    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("vuoi cancellare ");
    lcd.print("do you want to  ");
    lcd.setCursor(0, 1);
    lcd.print("del. all an restat?");
    lcd.setCursor(0, 3);
    lcd.print("Confirm?  Y/N");
    
  } else {
    semaphore = 2;
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print ("canc. ");
    lcd.print(ultweight);
    lcd.print ("g ");
    lcd.print (ultcal);
    lcd.print ("kcal");
    lcd.setCursor(0, 1);
    lcd.print(maincategory [ultcat]);
    lcd.setCursor(0, 2);
    lcd.print(food [ultalim]);
    lcd.setCursor(0, 3);
    lcd.print("Confirm?  Y/N");
                           
  }
}

void foodcategory (void){

  semaphore = 1;
  catalim = actualbutton;
  lcd.setCursor(0, 1);
  lcd.print(maincategory [catalim]);
  lcd.setCursor(0, 2);
  lcd.print ("food code?     ");
}


void foodcat (void){
  
  semaphore = 3;
  lcd.setCursor(0, 2);
  alim = (catalim * 10) + actualbutton;
  lcd.print(food [alim]);
  lcd.setCursor (0, 0);
  lcd.print("                    ");
  lcd.setCursor (0, 0);
  lcd.print(weight);
  lcd.print("g - kcal: ");
  calalim =calories[alim];
  comcalc = weight * calalim;
  Serial.print(weight);
  Serial.print(" - ");
  Serial.print(calalim);
  Serial.print(" - ");
  Serial.print(comcalc);
  Serial.print(" - ");
  cal = comcalc / 100;
  lcd.print(cal);
  lcd.setCursor(0, 3); 
  lcd.print("a: delete / b: add  ");
}

void confirmdeletion (void){

  if (semaphore == 2){

    totcal = totcal - ultcal;
    ultweight = 0;
    ultcal = 0;
    lcd.clear ();
    lcd.setCursor(0, 0);
    lcd.print("ingredient  ");
    lcd.setCursor(0, 1);
    lcd.print("deleted   ");
    lcd.setCursor(0, 3);
    lcd.print ("new tot.kcal:  ");
    lcd.print (totcal);
    delay (3000);
    
  } else {

    totcal = 0; 
    lcd.clear ();
    lcd.print("scale ready  ");
    lcd.setCursor(0, 1);
    lcd.print("for a new one");
    lcd.setCursor(0, 2);
    lcd.print("recipe ");
    lcd.setCursor(0, 3);
    lcd.print("tot.kcal: ");
    lcd.print(totcal);
    delay (3000);
    
  }

  cleansection ();
}

void setup(){

  scale.begin(DOUT, CLK);

  Serial.begin (9600);
  lcd.begin(20, 4);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("tare calculation  ");
  lcd.setCursor(0, 1);
  lcd.print("put nothing on ");
  lcd.setCursor(0, 2);
  lcd.print ("the stairs.....   ");
  lcd.setCursor(0, 3);
  scale.set_scale(2045);
  scale.tare(20);
  lcd.clear();
  lcd.print ("scale ready   ");
  
}


void loop() {

  if (stableweight == 0) {

    startstableweight = millis ();
    weighing ();
    
    
  } else {

    clickbutton = keypad.getKey();
    if (clickbutton) {

      if (clickbutton == 'a')
        cleansection ();

      if ((semaphore == 3) && (clickbutton == 'b'))
        addtorecipe ();

      if ((totcal > 0) && (clickbutton == 'c'))
        askforconfirmation ();

      if (clickbutton == 'd'){
        semaphore = 6;
        askforconfirmation();
      }

      if (((semaphore == 2) || (semaphore == 6)) && (clickbutton == '*')) 
        confirmdeletion ();

      if (((semaphore == 2) || (semaphore == 6)) && (clickbutton == '#')) 
        cleansection ();

      if ((clickbutton >= '0') && (clickbutton <= '9')){

        actualbutton = clickbutton;
        actualbutton = actualbutton - 48;

        if (semaphore == 0)
          foodcategory ();

        else if (semaphore == 1)
          foodcat ();
      
      }
      }
    }
  }
