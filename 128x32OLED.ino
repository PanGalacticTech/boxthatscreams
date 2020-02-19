//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~##### Kerbal Space Program Controller #####~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*

  This software is licenced by Pan Galactic LTD.

  Only the licence holder may copy or distribute this software

  Created by Pan Galactic Tech

  17/12/2019 Declan James


*/




//------------------------------------------------VVVV-----OLED Variables & Settings--------------------------
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Fonts/FreeMonoBold12pt7b.h >
#include <Fonts/FreeSansBold12pt7b.h >
#include <Fonts/FreeSansBold9pt7b.h >

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels



//------------------------------Added from Hackster------------------------
//https://www.hackster.io/yilmazyurdakul/arduino-oled-encoder-simple-menu-system-f9baa1

#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
//#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

//#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16


#if (SSD1306_LCDHEIGHT != 64)
//#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


// Screen Connects SCL to A4 & SDL to A5


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#### SETUP ####~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup() {

  Serial.begin(9600);                                     // Open the serial connection.


  OLEDsetupSimple();                                          // OLED setup & Splash Screen

  //  display.setFont(&FreeSansBold9pt7b);


  display.setTextSize(1);
  display.setTextColor(WHITE);


}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#### end of SETUP ####~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~






byte cursorX = 0;

byte cursorY = 0;

char charOne = 'U';

char charTwo = 'W';

char charThree = 'V';

char singleSpace = ' ';

char charArray[] = {charOne, charTwo, charThree, singleSpace};

char *printWord[8] = {"Jeffery"};


//[font=monospace]int size = sizeof(myarray) / sizeof(int);[/font]



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#### MAIN LOOP ####~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop() {



  int sizeofArray = sizeof(charArray);    // / sizeof(char);   // returns number of characters in array
  // int sizeofArray = sizeof(printWord) / 2;   // returns number of characters in array


  // Serial.println(sizeofArray);                           // Test print



  display.setCursor(cursorX, cursorY);




  for (int i = 0; i < sizeofArray; i++) {
    display.print(charArray[i]);
    Serial.print(charArray[i]);
  }



  // display.print(*printWord);

  display.display();


  // Serial.println(" ");









  /*


    Serial.print("cursorX: ");

    Serial.print(cursorX);

    Serial.print("   cursorY: ");

    Serial.print(cursorY);


    Serial.println(" ");
  */



  cursorX = cursorX + (sizeofArray) * 8; // moves the cursor the length of the char array

  if (cursorX >= 128) {

    cursorY = cursorY + 8;

    cursorX = 0;

    if (cursorY >= 32) {     // reached end of screen so wipe completely

      cursorY = 0;

      display.clearDisplay();

    }
  }


  delay(500);


}
