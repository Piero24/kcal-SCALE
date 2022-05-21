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
**Project Status:** Work in progress ⚠️ <a href="#maintenance">⇩</a>
<br/>
**Percentage Completely:** 40% 🔋 <a href="#roadmap">⇩</a>
<br/>
<br/>

<p align="center">
  <img src="https://github.com/Piero24/kcal-SCALE/blob/main/icon/png_scales.png" width="100" height="100">
</p>

<h1 align="center">
    <a href="https://github.com/Piero24/kcal-SCALE">kcal-SCALE</a>
</h1>

> *<p align="center">A scale that, in addition to displaying the weight, also calculates also the number of kilocalories of the product it has on dish across an internal table, for then display them on a 4-line by 20-character display.*
  
<p align="center">
    The Index for this project is available here
    <br/>
    <a href="#index"><strong>Explore the Index »</strong></a>
    <br/>
    <br/>
    <a href="https://github.com/Piero24/kcal-SCALE">View Demo</a>
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
  <strong>You can find other recommended components, cheaper versions and for your region <a href="https://amzn.to/3yMvIJ1">here  »</strong></a>
  <br/>
  <br/>
  <strong>ATTENTION:</strong> The size of the product table is such as to make it prohibitive to use with Arduino Uno. This project can only be replicated if you have a higher power board, such as the arduino mega 2560, which has 256k of memory instead of the 32k of the Arduino uno.
  <br/>
  <br/>
  Currently the supported ingredients are as follows:
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
  <ul>
    <li><a href="TO ADD">Scale</a></li>
    <li><a href="TO ADD">Keypad</a></li>
    <li><a href="TO ADD">Display</a></li>
  </ul>
  <br/>
  Obviously the language used is that of <a href="https://www.arduino.cc">Arduino</a>
  <br/>
  <br/>
  <p align="right"><a href="#top">⇧</a></p>
</div>



<div>
  <h2 id="index" align="center"><br/>📋  Index  📋</h2>
  <h4>➡️%20%20<a href="#prerequisites">Prerequisites</a></h4>
  <h4>➡️<a href="#how-to-start">How to Start</a></h4>
  <h4>➡️<a href="#structure-of-the-project">Structure of the Project</a></h4>
  <h4>➡️<a href="#roadmap">Roadmap</a></h4>
  <h4>➡️<a href="#responsible-disclosure">Responsible Disclosure</a></h4>
  <h4>➡️<a href="#report-a-bug">Report a Bug</a></h4>
  <h4>➡️<a href="#maintenance">Maintenance</a></h4>
  <h4>➡️<a href="#license">License</a></h4>
  <h4>➡️<a href="#third-party-licenses">Third Party Licenses</a></h4>
  <p align="right"><a href="#top">⇧</a></p>
</div>


<div>
  <h2 id="prerequisites" align="center"><br/>🧰  Prerequisites  🧰</h2>
  <ol>
    <li>All the harware components (you can find it <a href="https://www.arduino.cc/en/software">here</a>)</li>
    <li>Download the latest version of <a href="https://www.arduino.cc/en/software">Arduino IDE</a></li>
    <li>Download the latest version of these package</li>
    <li>Milk</li>
  </ol>
  This is an example of how to list the things needed to use the software and how to install them.
  
  ```
  Pre-requisites section
  ```
  <p align="right"><a href="#top">⇧</a></p>
</div>





<h2 id="how-to-start" align="center"><br/>⚙️  How to Start  ⚙️</h2>

<p align="center"> 
  <i>Below is an example of how you can instruct your audience on installing and setting up your app. This template doesn't rely on any external 
  dependencies or services.</i>
</p>
<br/>
<h3 id="windows" align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/87/Windows_logo_-_2021.svg/768px-Windows_logo_-_2021.svg.png" width="15" height="15">
  Windows
</h3>
<br/>

<p align="center">1. 
  Get a free API Key  
  <a href="https://example.com">here</a>
</p>
<p align="center">
  2. Clone the repo
  
  ```sh
  git clone https://github.com/your_username_/Project-Name.git
  ```
</p>
<p align="center">
  3. Install NPM packages
  
  ```sh
  npm install
  ```
</p>
<p align="center">
  4. Enter your API in `config.js`
  
  ```js
  const API_KEY = 'ENTER YOUR API';
  ```
</p>

<p align="right"><a href="#top">⇧</a></p>

<h3 id="macos" align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/f/fa/Apple_logo_black.svg" width="15" height="15">
  macOS
</h3>
<br/>

<p align="center">1. 
  Get a free API Key  
  <a href="https://example.com">here</a>
</p>
<p align="center">
  2. Clone the repo
  
  ```sh
  git clone https://github.com/your_username_/Project-Name.git
  ```
</p>
<p align="center">
  3. Install NPM packages
  
  ```sh
  npm install
  ```
</p>
<p align="center">
  4. Enter your API in `config.js`
  
  ```js
  const API_KEY = 'ENTER YOUR API';
  ```
</p>

<h3 id="linux" align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/35/Tux.svg/1012px-Tux.svg.png" width="15" height="15">
  Linux
</h3>
<br/>

<p align="center">1. 
  Get a free API Key  
  <a href="https://example.com">here</a>
</p>
<p align="center">
  2. Clone the repo
  
  ```sh
  git clone https://github.com/your_username_/Project-Name.git
  ```
</p>
<p align="center">
  3. Install NPM packages
  
  ```sh
  npm install
  ```
</p>
<p align="center">
  4. Enter your API in `config.js`
  
  ```js
  const API_KEY = 'ENTER YOUR API';
  ```
</p>

<p align="right"><a href="#top">⇧</a></p>



<h2 id="structure-of-the-project" align="center"><br/><br/>💻  Structure of the Project  💻</h2>

<p align="center">
  This section explains the structure of directories and branches in order to easily guide the user through the code.
  <br/>
  <br/>
  We have reached the last part of the central body concerning our project.
  <br/>
  From the next point we will indicate all the additional information such as: Contribute, Licenses etc...
</p>

<p align="right"><a href="#top">⇧</a></p>



---
  


<h2 id="roadmap" align="center"><br/><br/>🛫  Roadmap  🛬</h2>

- [x] Upload code
- [x] README file
- [x] Multi-language README
    - [x] Inglese
    - [x] Italaino
- [x] Point 1
- [ ] Point 2
- [ ] Point 3

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
  <br/>
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
  <br/>
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
  There are currently no parts of the code under maintenance.
  <br/>
  You can quickly check the 
  <a href="#top">status of the project</a>
   at the top of the page.
  <br/>
  <br/>
  This section details which parts of the code are under 
  <br/>
  maintenance and for what reason.
  <br/>
  <br/>
  <h3 id="changelog" align="center">📟  Changelog  📟</h3>
  Here you can find all the information regarding the fixes and implementations that took place in the various program reviews.
  <br/>
  <a href="https://github.com/Piero24/kcal-SCALE/blob/main/CHANGELOG.md"><strong>Explore the changelog docs</strong></a>
  <br/>
  <p align="right"><a href="#top">⇧</a></p>
</di>



 --- 
 


 <h2 id="license" align="center"><br/><br/><br/>🔍  License  🔍</h2>

<p align="center">
  The licensing section is divided into:
  <br/>
  <br/>
  - <a href="#general-license">General License</a>
  <br/>
  - <a href="#authors-and-copyright">Authors and Copyright</a>
  <br/>
  <br/>
  The 
  <a href="#general-license">General License</a> 
   indicates the base license chosen for the code.
  <br/>
  While 
  <a href="#authors-and-copyright">Authors and Copyright</a> 
   indicates who are the authors and who owns the copyright of the code.
  <br/>
</p>

<br/>

<!--
*** To choose the licenses you can look at the following links.
*** https://choosealicense.com/
*** https://github.com/teamdigitale/licenses
-->

<h3 id="general-license" align="center"><br/>🖋  General License  🖋</h3>

<p align="center">
  <strong>GNU GENERAL PUBLIC LICENSE</strong>
  <br/>
  <i>Version 3, 29 June 2007</i>
  <br/>
  <br/>
  <i>Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/></i>
  <br/>
  <i>Everyone is permitted to copy and distribute verbatim copies</i>
  <br/>
  <i>of this license document, but changing it is not allowed.</i>
  <br/>
  <br/>
  <i>Preamble</i>
  <br/>
  <i>The GNU General Public License is a free, copyleft license for</i>
  <br/>
  <i>software and other kinds of works.</i>
  <br/>
  <br/>
  <a href="https://github.com/Piero24/kcal-SCALE/blob/main/LICENSE"><strong>License Documentation »</strong></a>
  <br/>
</p>

<br/>

<!--
<p align="center">
  <img src="https://cdn.dribbble.com/users/1292677/screenshots/6139167/media/fcf7fd0c619bb87706533079240915f3.gif" width="390" height="292">
</p>
 
-->

<h3 id="authors-and-copyright" align="center"><br/>✏️  Authors and Copyright  ✏️</h3>

<p align="center">
  👨🏽‍💻: <strong>Pietrobon Andrea</strong>
  <br/>
  🌐: 
  <a href="https://www.pietrobonandrea.com">www.pietrobonandrea.com</a>
  <br/>
  <img src="https://assets.stickpng.com/thumbs/580b57fcd9996e24bc43c53e.png" width="30" height="30" align="center">:
  <a href="https://twitter.com/pietrobonandrea">@PietrobonAndrea</a>
  <br/>
  🗄:
  <a href="https://github.com/Piero24/kcal-SCALE">kcal-SCALE</a>
  <br/>
  <br/>
  <br/>
  My name is <strong>Pietrobon Andrea</strong>,
  <br/>
  a computer engineering student at the 
  <br/>
  <img src="https://upload.wikimedia.org/wikipedia/it/thumb/5/53/Logo_Università_Padova.svg/800px-Logo_Università_Padova.svg.png"  width="30" height="30" align="center"> University of Padua (🇮🇹).
  <br/>
  <br/>
  My passion turns towards <strong>AI</strong> and <strong>ML</strong>.
  <br/>
  I have learned and worked in different sectors that have allowed me to gain skills 
  <br/>
  in different fields, such as IT and industrial design.
  <br/>
  <br/>
  To find out more, visit my 
  <br/>
  <a href="https://www.pietrobonandrea.com"><strong>website »</strong></a>
  <br/>
  <br/>
  The license of this repo as indicated in the 
  <a href="#general-license">general license</a> section is the 
  <br/>
  GNU General Public License v3.0
  <br/>
  For more details visit the 
  <a href="https://github.com/Piero24/kcal-SCALE/blob/main/LICENSE"><strong>licensing page »</strong></a>
  <br/>
  <br/>
  <strong>The Copyright (C) of this project is held exclusively by my person.</strong>
</p>

<p align="right"><a href="#top">⇧</a></p>


<!--
 ***This operation could be particularly long or laborious to report and therefore it is possible to avail
 *** of some automatic support tools.
 ***https://fossa.com/pricing/
-->

<h2 id="third-party-licenses" align="center"><br/>📌  Third Party Licenses  📌</h2>

<p align="center">
  In the event that the software uses third-party components for its operation, 
  <br/>
  the individual licenses are indicated in the following section.
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
    <td>None</td>
    <td></td> 
    <td></td>
    <td></td>
    <td></td>
  </tr>
</table>
</p>

<p align="right"><a href="#top">⇧</a></p>



---
<br/>

> *<p align="center"> Copyrright (C) by Pietrobon Andrea <br/> Released date: May-16-2022*
