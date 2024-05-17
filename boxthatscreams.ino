
/*
      Program Screams Data

      Over Serial Pin One

      Listens on Second



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

  17/12/2019 Imogen Wren


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

bool serialScream = true;   // if true data is screamed

byte numberOfBytes = 7;   // number of bytes that will be screamed




char inputString[32];     // specify max length of 32 chars? bytes?
bool stringComplete;

byte byteCount = 0;


bool lineChanged = false;   // sets true if a new line has started < bug fix.




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#### MAIN LOOP ####~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop() {


  // Serial Listening
  serialEvent();

  checkLength();         // makes sure there is sufficient room on the screen to print
  // received message
  // Display Print
  serialPrintout();
  display.display();


  // Serial Printing

  if (serialScream) {

    for (int i = 0; i < 7; i++) {
      //  Serial.print(charArray[i]);
      Serial.print(arrayEight[i]);
    }
    Serial.println(" ");
  }



} //____________________________________________________ End of Void Loop __________________________________________









byte strLength;

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

    //  Serial.print(inChar);
    //  display.print(inChar);

    //  Serial.print("  byteCount: ");
    //   Serial.println(byteCount);

    // add it to the inputString:
    inputString[byteCount] = inChar;



    byteCount++;                                           // if the incoming character is a newline, set a flag so the main loop can

    //  cursorX = cursorX + 6;

    strLength = byteCount;

    // do something about it:
    if (inChar == '\n' or byteCount >= 32) {         // if null character reached or buffer is filled, then string is completed
      stringComplete = true;
      byteCount = 0;

    }
  }
}



//---------------------------------Print Serial Data to Screen


void serialPrintout() {

  if (stringComplete) {

    display.setCursor(cursorX, cursorY);

  //  Serial.print(cursorX);

 //   Serial.print("   ");

  //  Serial.println(cursorY);

    removeDot();

    // display.print(" ");

    for (int i = 0; i < strLength; i++) {

      //   Serial.print(i);
      //  Serial.print(inputString[i]);
      display.print(inputString[i]);
      cursorX = cursorX + 6;
      cursorManage();
    }

    // cursorManage();
    //  Serial.println(cursorX);
    // display.print(" ");

    if (lineChanged) {
      cursorX = cursorX + 6;
      lineChanged = false;
    }
    
    drawDot();   // actually draws square like a boss
    cursorManage();       // this makes sure a new line is started if drawn box is off the page


    stringComplete = false;
  }
}











bool boxDrawn = false;
byte lastX;
byte lastY;
// Function to draw a dot in the space waiting for new data
void drawDot() {

  // cursorX = cursorX + 1;
  display.drawRect(cursorX, cursorY, 5, 8, WHITE); // – plot a pixel in the x,y coordinates
  lastX = cursorX;
  lastY = cursorY;
  boxDrawn = true;

  // cursorX = cursorX - 1;
}




void removeDot() {                           /// actually removes square like a boss

  if (boxDrawn) {
    display.drawRect(lastX, lastY, 5, 8, BLACK);
    boxDrawn = false;
  }

}





// Check to see if strLength is longer than the remaining character spaces on the screen

void checkLength() {
  //int lengthSpare = 128 - (cursorX + strLength);
  if (cursorY >= 32) {
    if ((strLength + cursorX) > 129);
    resetDisplay(true);
  }
}



void resetDisplay(bool invertActive) {

  display.clearDisplay();
  cursorY = 0;
  cursorX = 0;  // reset cursors

  if (invertActive)
    if (invertDisplay) {                       // invert display for fun and for profit.ffff


      invertDisplay = false;
      display.invertDisplay(false);
    } else if (!invertDisplay)  {
      invertDisplay = true;
      display.invertDisplay(true);
    }

}





void cursorManage() {


  // cursorX = cursorX + (sizeofArray) * 8; // moves the cursor the length of the char array

  // Cursor Management


  // Serial.println(cursorX);

  if (cursorX >= 128) {

    cursorY = cursorY + 8;

    cursorX = 0;

    lineChanged = true;

    if (cursorY >= 32) {     // reached end of screen so wipe completely

      resetDisplay(true);


    }
  }


}
