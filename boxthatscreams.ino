
/*
      Program Screams Data

      Over Serial Pin 2

      But Can You Hear It?



     This box helps test data
     links by sending different
     data streams over serial.

*/


//

const int dataPin = 2;  // data output pin

//---------------- possible data to send-------------------------

uint8_t byteOne = 0;  // a single byte

uint16_t intTwo = 0;   // a single unsigned int

int16_t intThree = 0;    // a single signed int

uint32_t intFour = 0;   // a single unsigned long

int32_t intFive = 0;    // a single signed long

float floatSix = 0.0;     // a float value
// used to hold the golden ratio of the universe
// most of the time

char charSeven = 'C';     // a single char

char arrayEight[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};   // a char array with one octave of the A minor scale

struct color {       // a data structure containing 3 bytes of RGB color data
  byte red;
  byte green;
  byte blue;

};


color colourNine = { 255, 100, 150};    // a random colour using the structure above

//------------------------------------- ^^ Data to send ^^ -------------------------


//_____________________________________ Working Variables _______________________


uint8_t lastInput = 0;   // stores last inputValue to the fibbonacci machine.
// Needed to work out fibbonachi numbers/ratios etc





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


char buff[] = { };  // buffer to hold incoming serial data


bool invertDisplay = false;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#### MAIN LOOP ####~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop() {



  int sizeofArray = sizeof(charArray);    // / sizeof(char);   // returns number of characters in array
  // int sizeofArray = sizeof(printWord) / 2;   // returns number of characters in array


  // Serial.println(sizeofArray);                           // Test print



  display.setCursor(cursorX, cursorY);


  serialEvent();

  serialPrintout();




  for (int i = 0; i < sizeofArray; i++) {
    //  display.print(charArray[i]);
    //  Serial.print(charArray[i]);
  }



  //Serial.println(" ");


  // display.print(*printWord);

  display.display();


  // Serial.println(" ");





  // cursorX = cursorX + (sizeofArray) * 8; // moves the cursor the length of the char array

  if (cursorX >= 128) {

    cursorY = cursorY + 8;

    cursorX = 0;

    if (cursorY >= 32) {     // reached end of screen so wipe completely

      cursorY = 0;

      display.clearDisplay();

      if (invertDisplay) {
        invertDisplay = false;
        display.invertDisplay(false);
      } else if (!invertDisplay)  {
        invertDisplay = true;
        display.invertDisplay(true);
      }



    }
  }

} //____________________________________________________ End of Void Loop __________________________________________

char inputString[] = {};
bool stringComplete;

byte byteCount;

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {

  byteCount = 0;                                               // Counts the number of incoming bytes

  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();

    //   Serial.print(inChar);
    display.print(inChar);
    // add it to the inputString:
    inputString[byteCount] = inChar;


    Serial.println(byteCount);
    byteCount++;                                           // if the incoming character is a newline, set a flag so the main loop can

    cursorX = cursorX + 8;

    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
      drawDot();
    }
  }
}


void serialPrintout() {

  if (stringComplete) {
    //Serial.print("String Length: ");
    //Serial.println(sizeof(inputString));

    Serial.print("byteCount: ");

    Serial.println(byteCount);


    for (int i = 0; i > sizeof(inputString); i++) {

      Serial.print(inputString[i]);

    }

    stringComplete = false;
  }
}

byte lastX;
byte lastY;
// Function to draw a dot in the space waiting for new data
void drawDot() {

 display.drawRect(lastX, lastY, 8, 8, BLACK);
    display.drawRect(cursorX, cursorY, 8, 8, WHITE); // – plot a pixel in the x,y coordinates

lastX = cursorX;
lastY = cursorY;

}
