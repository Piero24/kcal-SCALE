<div id="top"></div>

<!-- BADGE -->
[![](https://img.shields.io/github/release-date/piero24/kcal-SCALE)]()
[![](https://img.shields.io/github/last-commit/piero24/kcal-SCALE)]()
[![Maintenance](https://img.shields.io/badge/Maintained-yes-green.svg)](https://github.com/Piero24/kcal-SCALE)
<!--[![Maintenance](https://img.shields.io/badge/Maintained%3F-no-red.svg)](https://github.com/Piero24/kcal-SCALE) -->
[![](https://img.shields.io/github/issues/piero24/kcal-SCALE)]()
[![](https://img.shields.io/github/issues-pr/piero24/kcal-SCALE)]()
[![](https://img.shields.io/github/downloads/piero24/kcal-SCALE/total)]()

[![](https://img.shields.io/github/license/piero24/kcal-SCALE)]()
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](code_of_conduct.md)



<br/>

<!-- Working ✅ Work in progress ⚠️ ~~Deprecate~~ ⛔️ -->
**Project Status:** Working ✅ <a href="#maintenance">⇩</a>
<br/>
**Percentage Completely:** 100% 🔋 <a href="#roadmap">⇩</a>
<br/>
<br/>

<p align="center">
  <img src="https://github.com/Piero24/kcal-SCALE/blob/main/icon/png_scales.png" width="100" height="100">
</p>

<h1 align="center">
    <a href="https://github.com/Piero24/kcal-SCALE">kcal-SCALE</a>
</h1>

> *<p align="center">A scale that, in addition to displaying the weight, also calculates the number of kilocalories of the product it has on dish across an internal table, for then display them on a 4-line by 20-character display.*
  
<p align="center">
    The Index for this project is available here
    <br/>
    <a href="#index"><strong>Explore the Index »</strong></a>
    <br/>
    <br/>
    <a href="https://www.youtube.com/watch?v=Rk3uGoyE4gs&t=2s">View Demo</a>
    •
    <a href="https://github.com/Piero24/kcal-SCALE/issues">Report Bug</a>
    •
    <a href="https://github.com/Piero24/kcal-SCALE/issues">Request Feature</a>
  </p>


---


<div>
  <br/>
  <br/>
  <h2 id="itroduction" align="center">📔  Itroduction  📔</h2>        
  The balance allows you to weigh the calories of an entire recipe by adding the weights of the calories of each individual ingredient.
  <br/>
  The project was carried out with the following components:
  <br/>
  <br/>
  <ul>
    <li><a href="https://amzn.to/3G95Vg4">Arduino Mega 2560</a></li>
    <li><a href="https://amzn.to/3wIDXmX">Weight sensor</a></li>
    <li><a href="https://amzn.to/3wzVfDG">Numeric keypad</a> (16-key)</li>
    <li><a href="https://amzn.to/3yMvIJ1">Display 2004</a></li>
  </ul>
  <br/>
  <br/>
  <strong>You can find other recommended components, cheaper versions and for your region <a href="#recommended-components">here  »</strong></a>
  <br/>
  <br/>
  <strong>ATTENTION:</strong> The size of the product table is such as to make it prohibitive to use with Arduino Uno. This project can only be replicated if you have a higher power board, such as the arduino mega 2560, which has 256k of memory instead of the 32k of the Arduino uno.
  <br/>
  <br/>
  Currently the supported ingredients are as follows:
  <br/>
  <br/>
  <img src="https://github.com/Piero24/kcal-SCALE/blob/main/icon/Ingredients.png">
  <br/>
  <br/>
  <p align="right"><a href="#top">⇧</a></p>
</div>


  
<div>
  <br/>
  <br/>
  <h2 id="made-in" align="center">🛠  Built in  🛠</h2>
  If you replicate this project with different components the required libraries may be different. For example, using a different numeric keypad with fewer keys may require not only different libraries but also a change to some parts of the code.
  <br/>
  <br/>
  Below and in the appropriate section there are links to the libraries used. In the code, however, you will find the version used at the time of the upload, which may be different from the current one.
  <br/>
  <br/>
  To carry out this project I used 3 libraries:
  <br/>
  <br/>
  <ul>
    <li><a href="https://github.com/bogde/HX711">Scale</a></li>
    <li><a href="TO ADD">Keypad</a></li>
    <li><a href="https://github.com/fmalpartida/New-LiquidCrystal">Display</a></li>
  </ul>
  <br/>
  Obviously the language used is that of <a href="https://www.arduino.cc">Arduino</a> (C/C++)
  <br/>
  <br/>
  <p align="right"><a href="#top">⇧</a></p>
</div>



<div>
  <h2 id="index" align="center"><br/>📋  Index  📋</h2>
  <h4>➡️ <a href="#prerequisites">Prerequisites</a></h4>
  <h4>➡️ <a href="#how-to-start">How to Start</a></h4>
  <h4>➡️ <a href="#structure-of-the-project">Structure of the Project</a></h4>
  <h4>➡️ <a href="#roadmap">Roadmap</a></h4>
  <h4>➡️ <a href="#responsible-disclosure">Responsible Disclosure</a></h4>
  <h4>➡️ <a href="#report-a-bug">Report a Bug</a></h4>
  <h4>➡️ <a href="#maintenance">Maintenance</a></h4>
  <h4>➡️ <a href="#license">License</a></h4>
  <h4>➡️ <a href="#third-party-licenses">Third Party Licenses</a></h4>
  <h4>➡️ <a href="#recommended-components">Recommended Components</a></h4>
  <p align="right"><a href="#top">⇧</a></p>
</div>


<div>
  <h2 id="prerequisites" align="center"><br/>🧰  Prerequisites  🧰</h2>
  <ol>
    <li>All the harware components you can find it <a href="#recommended-components">here</a></li>
    <li>Download the latest version of <a href="https://www.arduino.cc/en/software">Arduino IDE</a></li>
    <li>Download the latest version of these package:</li>
    <br/>
    <ul>
      <li><a href="http://playground.arduino.cc/Code/Keypad">keypad</a></li>
      <li><a href="https://github.com/fmalpartida/New-LiquidCrystal">lcd</a></li>
      <li><a href="https://github.com/bogde/HX711">scale</a></li>
    </ul>
  </ol>
  <br/>
  <br/>
  <p align="right"><a href="#top">⇧</a></p>
</div>


<div>
  <h2 id="how-to-start" align="center"><br/>⚙️  How to Start  ⚙️</h2>
  <p>
    There are no major difficulties in the realization of this project since the code for its operation is already written.
    <br/>
    First of all we have to connect all the components to the arduino as indicated in the diagram below.
    <br/>
    <br/>
    You can change the connections to some ports if you like. The important thing in this case is to make the necessary changes also within the code.
    <br/>
  </p>
  <br/>
  <br/>
  <br/>
  <img src="https://github.com/Piero24/kcal-SCALE/blob/main/icon/arduino.png">
  <br/>
  <br/>
  <p align="right"><a href="#top">⇧</a></p>
</div>


<div>
  <h2 id="structure-of-the-project" align="center"><br/><br/>💻  Structure of the Project  💻</h2>
  <p>
    Now that everything is connected we simply have to import the code into Arduino.
    <ul>
      <li>Import the 3 previously downloaded folders into the libraries folder (keypad, lcd, scale)</li>
      <li>Let's open the kcal-SCALE.ino file in the Arduino IDE</li>
      <li>Connect the board to the pc/mac</li>
      <li>In the tool section select the type of board you have, the processor and the pc port to which it is connected
      <br/>
      <br/>
      <img src="https://github.com/Piero24/kcal-SCALE/blob/main/icon/tool-bar.png"></li>
      <li>Let's upload the file to the board</li>
    </ul>
    <br/>
    <br/>
    <p align="center"><strong>DONE !!!</strong></p>
    <br/>
    <br/>
    Now we can disconnect the board from the pc and use the battery to power it.
    <br/>
    This is a quick explanation of the main commands instead.
    <br/>
  </p>
  <p>
    <strong>User manual:</strong>
    <br/>
    <br/>
    <ul>
      <li><strong>numeric keys:</strong> selection of food category and food</li>
      <li><strong>non-numeric keys:</strong></li>
      <ul>
        <li><strong>"*"</strong> = confirm deletion</li>
        <li><strong>"#"</strong> = cancel the delete request</li>
        <li><strong>"A"</strong> = clear, clears the last selection and asks for the food category again for the product on the plate</li>
        <li><strong>"B"</strong> = adds the ingredient on the plate to the recipe</li>
        <li><strong>"C"</strong> = elimination of the last added ingredient from the recipe</li>
        <li><strong>"D"</strong> = cleans the system and prepares it for a new recipe</li>
      </ul>
    </ul>
  </p>
  <br/>
  <br/>
  <p align="right"><a href="#top">⇧</a></p>
</div>
  
---

<h2 id="roadmap" align="center"><br/><br/>🛫  Roadmap  🛬</h2>

- [x] Upload code
- [x] Add Ingredients
- [x] Add Ingredients 2
- [x] Add Ingredients 3

See the [open issues](https://github.com/Piero24/kcal-SCALE/issues) for a full list of proposed features (and known issues).

<p align="right"><a href="#top">⇧</a></p>


<div>
<h2 id="responsible-disclosure" align="center"><br/><br/>📮  Responsible Disclosure  📮</h2>
  We assume no responsibility for an improper use of this code and everything related to it.
  <br/>
  We do not assume any responsibility for damage caused to people and/or objects in the use of the code.
  <br/>
  <strong>By using this code even in a small part, the developers are declined from any responsibility.</strong>
  <br/>
  <br/>
  It is possible to have more information by viewing the following links:
  <a href="#code-of-conduct"><strong>Code of conduct</strong></a> • 
  <a href="#license"><strong>License</strong></a>
  <br/>
  <br/>
  <h3 id="code-of-conduct" align="center"><br/><br/>📜  Code of conduct  📜</h3>
  As members, collaborators and leaders we are committed to performance participation in our community a harassment-free experience for all, regardless of age, size, visible or invisible disability, ethnicity, sexual characteristics, gender identity and expression, level of experience, education, socioeconomic status, nationality, appearance, race, caste, color, religion or identity and sexual orientation.
  <br/>
  We are committed to acting and interacting in ways that help create an open community, welcoming, diverse, inclusive and healthy.
  <br/>
  <br/>
  The complete version of the code of conduct can be viewed at the following link:
  <a href="https://github.com/Piero24/kcal-SCALE/blob/main/CODE-OF-CONDUCT.md"><strong>Code of Conduct »</strong></a>
  <p align="right"><a href="#top">⇧</a></p>
</div>


<div>
  <h2 id="report-a-bug"  align="center"><br/><br/>🐛  Bug and Feature 🐛</h2>
  To <strong>report a bug</strong> or to request the implementation of <strong>new features</strong>, it is strongly recommended to use the 
  <a href="https://github.com/Piero24/kcal-SCALE/issues"><strong>ISSUES tool from Github »</strong></a>
  <br/>
  <br/>
  Here you may already find the answer to the problem you have encountered, in case it has already happened to other people. Otherwise you can report the bugs found.
  <br/>
  <br/>
  <strong>ATTENTION : To speed up the resolution of problems, it is recommended to answer all the questions present in the request phase in an exhaustive manner.</strong>
  <br/>
  <br/>
  (Even in the phase of requests for the implementation of new functions, we ask you to better specify the reasons for the request and what final result you want to obtain).
  <br/>
  <br/>
  <p align="right"><a href="#top">⇧</a></p>
</div>



 <div> 
  <h2 id="maintenance" align="center"><br/><br/>🔧  Maintenance  🔧</h2>
  There are currently no parts of the code under maintenance. You can quickly check the <a href="#top">status of the project</a> at the top of the page.
  <br/>
  <br/>
  This section details which parts of the code are under maintenance and for what reason.
  <br/>
  <br/>
  <h3 id="changelog" align="center">📟  Changelog  📟</h3>
  Here you can find all the information regarding the fixes and implementations that took place in the various program reviews.
  <br/>
  <a href="https://github.com/Piero24/kcal-SCALE/blob/main/CHANGELOG.md"><strong>Explore the changelog docs</strong></a>
  <br/>
  <p align="right"><a href="#top">⇧</a></p>
</div>


 --- 
 

<div>
 <h2 id="license" align="center"><br/><br/><br/>🔍  License  🔍</h2>
  The licensing section is divided into:
  <br/>
  <br/>
  <ul>
    <li><a href="#general-license">General License</a></li>
    <br/>
    <li><a href="#authors-and-copyright">Authors and Copyright</a></li>
  </ul>
  The <a href="#general-license">General License</a> indicates the base license chosen for the code.
  <br/>
  While <a href="#authors-and-copyright">Authors and Copyright</a> indicates who are the authors and who owns the copyright of the code.
  <br/>
  <br/>
  <h3 id="general-license" align="center"><br/>🖋  General License  🖋</h3>
  <strong>GNU GENERAL PUBLIC LICENSE</strong>
  <br/>
  <i>Version 3, 29 June 2007</i>
  <br/>
  <br/>
  <i>Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>. Everyone is permitted to copy and distribute verbatim copies of this license document, but changing it is not allowed.</i>
  <br/>
  <i>Preamble</i>
  <br/>
  <i>The GNU General Public License is a free, copyleft license for software and other kinds of works.</i>
  <br/>
  <a href="https://github.com/Piero24/kcal-SCALE/blob/main/LICENSE"><strong>License Documentation »</strong></a>
  <br/>
  <br/>
  <h3 id="authors-and-copyright" align="center"><br/>✏️  Authors and Copyright  ✏️</h3>
  👨🏽‍💻: <strong>Pietrobon Andrea</strong>
  <br/>
  🌐: <a href="https://www.pietrobonandrea.com">pietrobonandrea.com</a>
  <br/>
  <img src="https://assets.stickpng.com/thumbs/580b57fcd9996e24bc43c53e.png" width="30" height="30" align="center">:
  <a href="https://twitter.com/pietrobonandrea">@PietrobonAndrea</a>
  <br/>
  🗄: <a href="https://github.com/Piero24/kcal-SCALE">kcal-SCALE</a>
  <br/>
  <br/>
  My name is <strong>Pietrobon Andrea</strong>, a computer engineering student at the 
  <img src="https://upload.wikimedia.org/wikipedia/it/thumb/5/53/Logo_Università_Padova.svg/800px-Logo_Università_Padova.svg.png"  width="30" height="30" align="center"> University of Padua (🇮🇹).
  <br/>
  <br/>
  My passion turns towards <strong>AI</strong> and <strong>ML</strong>. I have learned and worked in different sectors that have allowed me to gain skills in different fields, such as IT and industrial design. To find out more, visit my <a href="https://www.pietrobonandrea.com"><strong>website »</strong></a>
  <br/>
  <br/>
  The license of this repo as indicated in the <a href="#general-license">general license</a> section is the GNU General Public License v3.0
  <br/>
  For more details visit the <a href="https://github.com/Piero24/kcal-SCALE/blob/main/LICENSE"><strong>licensing page »</strong></a>
  <br/>
  <br/>
  <strong>The Copyright (C) of this project is held exclusively by my person.</strong>
  <p align="right"><a href="#top">⇧</a></p>
</div>


<div>
  <h2 id="third-party-licenses" align="center"><br/>📌  Third Party Licenses  📌</h2>
  In the event that the software uses third-party components for its operation, the individual licenses are indicated in the following section.
  <br/>
  <br/>
  <strong>Software list:</strong>
  <br/>
  <table align="center">
    <tr  align="center">
      <th>Software</th>
      <th>License owner</th> 
      <th>License type</th> 
      <th>Link</th>
      <th>Note</th>
    </tr>
    <tr  align="center">
      <td>Keypad</td>
      <td> - </td>
      <td> - </td>
      <td> - </td>
      <td></td>
    </tr>
    <tr  align="center">
      <td>LCD I2C</td>
      <td><a href="https://github.com/fmalpartida">fmalpartida</a></td>
      <td><a href="https://github.com/fmalpartida/New-LiquidCrystal/blob/master/LICENSE.webarchive">link</a></td>
      <td><a href="https://github.com/fmalpartida/New-LiquidCrystal">github</a></td>
      <td></td>
    </tr>
    <tr  align="center">
      <td>Scale</td>
      <td><a href="https://github.com/bogde">bodge</a></td>
      <td><a href="https://github.com/bogde/HX711/blob/master/LICENSE">MIT</a></td>
      <td><a href="https://github.com/bogde/HX711">scale</a></td>
      <td></td>
    </tr>
  </table>
  <p>
    <br/>
    <br/>
    A special thanks also goes to <a href="https://www.youtube.com/watch?v=Rk3uGoyE4gs">Giocarduino</a> from whom I took the table of ingredients and from whom I took inspiration for the project.
    <br/>
    Go and see his <a href="https://www.youtube.com/watch?v=Rk3uGoyE4gs">Youtube channel</a> for further information and guides on the world of Arduino.
    <br/>
    <br/>
  </p>
  <p align="right"><a href="#top">⇧</a></p>
</div>


<div>
  <h2 id="recommended-components" align="center"><br/>📌  Recommended Components  📌</h2>
  This is a list of the components suggested for the realization of the project.
  <br/>
  <br/>
  <strong>List of components:</strong>
  <br/>
  <table align="center">
    <tr  align="center">
      <th>🇺🇸 US 🇺🇸</th>
      <th>🇬🇧 UK 🇬🇧</th>
      <th>🇫🇷 FR 🇫🇷</th>
      <th>🇮🇹 IT 🇮🇹</th>
      <th>🇩🇪 DE 🇩🇪</th>
      <th>🇪🇸 ES 🇪🇸</th>
      <th>Note</th> 
    </tr>
    <tr  align="center">
      <th><a href="https://amzn.to/3wQVhr2">Arduino Mega 2560</a></th>
      <th> - </th>
      <th> - </th>
      <th><a href="https://amzn.to/3luUYf6">Arduino Mega 2560</a></th>
      <th><a href="https://amzn.to/3wVLFKz">Arduino Mega 2560</a></th>
      <th> - </th>
      <th>(Raccomanded)</th> 
    </tr>
    <tr  align="center">
      <th><a href="https://amzn.to/3LY0JMZ">Arduino Mega REV3</a></th>
      <th><a href="https://amzn.to/3wPUCoM">Arduino Mega REV3</a></th>
      <th><a href="https://amzn.to/3GxzqIr">Arduino Mega REV3</a></th>
      <th><a href="https://amzn.to/3wGjnnc">Arduino Mega REV3</a></th>
      <th> - </th>
      <th><a href="https://amzn.to/3t2iBQe">Arduino Mega REV3</a></th>
      <th></th> 
    </tr>
    <tr  align="center">
      <th><a href="https://amzn.to/3wOaOI9">ELEGOO Mega R3</a></th>
      <th><a href="https://amzn.to/3MX7e4f">SUNFOUNDER Mega</a></th>
      <th><a href="https://amzn.to/3lPefYR">ELEGOO Mega R3</a></th>
      <th><a href="https://amzn.to/3LCEz2X">ELEGOO Mega R3</a></th>
      <th><a href="https://amzn.to/3z0u8DF">ELEGOO Mega R3 (Black)</a></th>
      <th><a href="https://amzn.to/3Gsz8lW">ELEGOO Mega R3</a></th>
      <th></th> 
    </tr>
    <tr  align="center">
      <th><a href="https://amzn.to/3wUqx8N">Weight sensor</a></th>
      <th><a href="https://amzn.to/3z3oJvI">Weight sensor</a></th>
      <th><a href="https://amzn.to/3MWKlh8">Weight sensor</a></th>
      <th><a href="https://amzn.to/3a3fmRZ">Weight sensor</a></th>
      <th><a href="https://amzn.to/3GnVqFA">Weight sensor</a></th>
      <th><a href="https://amzn.to/3wUB1U9">Weight sensor</a></th>
      <th>(Raccomanded)</th> 
    </tr>
    <tr  align="center">
      <th><a href="https://amzn.to/3lPzr12">Weight sensor</a></th>
      <th><a href="https://amzn.to/3lNoHQA">Weight sensor</a></th>
      <th><a href="https://amzn.to/3GpGXsF">Weight sensor</a></th>
      <th><a href="https://amzn.to/3MCLLxg">Weight sensor</a></th>
      <th><a href="https://amzn.to/3lLTSfc">Weight sensor</a></th>
      <th><a href="https://amzn.to/3LUGIqA">Weight sensor</a></th>
      <th></th> 
    </tr>
    <tr  align="center">
      <th><a href="https://amzn.to/3GwZQdl">Keypad</a></th>
      <th><a href="https://amzn.to/3lQMQFY">Keypad</a></th>
      <th><a href="https://amzn.to/3akAxz3">Keypad</a></th>
      <th><a href="https://amzn.to/3luViL1">Keypad</a></th>
      <th><a href="https://amzn.to/3lQVGUa">Keypad</a></th>
      <th><a href="https://amzn.to/3MZY72D">Keypad</a></th>
      <th></th> 
    </tr>
    <tr  align="center">
      <th><a href="https://amzn.to/39XnQKs"> 2004 20x4 LCD</a></th>
      <th><a href="https://amzn.to/3wPUDck"> 2004 20x4 LCD</a></th>
      <th><a href="https://amzn.to/3wP6RmC"> 2004 20x4 LCD</a></th>
      <th><a href="https://amzn.to/3sLBk2j"> 2004 20x4 LCD</a></th>
      <th><a href="https://amzn.to/3NG2901"> 2004 20x4 LCD</a></th>
      <th><a href="https://amzn.to/3t2iHY6"> 2004 20x4 LCD</a></th>
      <th></th> 
    </tr>
    <tr  align="center">
      <th><a href="https://amzn.to/3Gs12ys">Cable</a></th>
      <th><a href="https://amzn.to/39XWa8g">Cable</a></th>
      <th><a href="https://amzn.to/3LV30st">Cable</a></th>
      <th><a href="https://amzn.to/3LNokjy">Cable</a></th>
      <th><a href="https://amzn.to/38sAnFs">Cable</a></th>
      <th><a href="https://amzn.to/3NItezU">Cable</a></th>
      <th></th> 
    </tr>
  </table>
  <br/>
  <br/>
  *As an amazon affiliate, I may receive a commission from the links indicated
  <p align="right"><a href="#top">⇧</a></p>
</div>

---
<br/>

> *<p align="center"> Copyrright (C) by Pietrobon Andrea <br/> Released date: May-16-2022*
