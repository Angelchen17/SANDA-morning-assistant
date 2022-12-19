INTRODUCTION
---------------------------------------------------
This file is the documentation for SANDA project. SANDA will have core functionalities including alarm, calendars and playing musics. This document will explain how to test these functionalities for grading purposes.


PREREQUESITES
---------------------------------------------------
Before running the app, please ensure you have the following requirements satisfied:
* A stable internet connection
* Download the following library
   - curl
   - json
* Download and install Qt


COMPILATION
---------------------------------------------------
* In Qt:
    - In SANDA project, press build
    - After sucessful compilation, enter run, and a window of the UI will pop up

* In Terminal:
    - Go to the SANDA project directory, enter: qmake SANDA.pro
    - enter make to makefile
    - enter ./SANDA to invoke the executable file, and a window of the UI will pop up



TESTING
---------------------------------------------------
* Tests for alarms:
    - After complication, run the SANDA app and click on alarm
    - Follow the insturction on the screen to add an alarm, and wait for the alarm to sound

* Tests for calendars:
    - After compilation, run the SANDA app and click on calendar
    - You can add, delete and modify events in the app

* Tests for weather:
    - After compilation, run the SANDA app and click on weather
    - Enter your current location (Toronto) and the weather will display
    - Only allows one word to be inputted

* Tests for music:
   - After compilation, run the SANDA app and click on music
   - Select a music name and play

* Tests for news:
   - After compilation, run the SANDA app and click on news
   - Enter the number of news you want to see, and news will display on screen
