
/*
      Program Screams Data

      Over Serial Pin One

      Listens on Second



     This box helps test data
     links by sending different
     data streams over serial.

*/

#include "globals.h"

//#include <EEPROM.h>


//#define EEPROM_SIZE 1

//int memorySize = 512;   only ATmega168
int memorySize = 1024;

//

const int dataPin = 2;  // data output pin

// const int dataInPin = 1 ;



//_____________________________________ Working Variables _______________________


uint8_t lastInput = 0;   // stores last inputValue to the fibbonacci machine.
// Needed to work out fibbonachi numbers/ratios etc





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~##### RS-232 Data Sender & Receiver #####~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*

This program screams serial data.

  This software is licenced by Pan Galactic LTD.

  Only the licence holder may copy or distribute this software.

  Created by Pan Galactic Tech.

  29/03/2020 Declan James


*/




//------------------------------------------------VVVV-----OLED Variables & Settings--------------------------
#include <SPI.h>
//#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels



//------------------------------Added from Hackster------------------------
//https://www.hackster.io/yilmazyurdakul/arduino-oled-encoder-simple-menu-system-f9baa1

#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
//#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif





// Screen Connects SCL to A4 & SDL to A5








//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#### SETUP ####~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup() {

  Serial.begin(9600);                                     // Open the serial connection.

 ///  buttonRead();


  OLEDsetupSimple();                                          // OLED setup & Splash Screen

  //  display.setFont(&FreeSansBold9pt7b);


  display.setTextSize(1);
  display.setTextColor(WHITE);

 // recallSettings();


}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#### end of SETUP ####~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~






byte cursorX = 0;

byte cursorY = 0;




//[font=monospace]int size = sizeof(myarray) / sizeof(int);[/font]


char buff[] = { };  // buffer to hold incoming serial data


bool invertDisplay = false;





char inputString[32];     // specify max length of 32 chars
bool stringComplete;

byte byteCount = 0;





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#### MAIN LOOP ####~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop() {


  buttonRead();                   // Read input Buttons
  buttonControl();                 // Decide action to take based on button array
  menuMode();                       // decide if menu is active or not

  screenClear();                      // clear the screen if flag has been set

  // Serial.println(menuActive);

  if (menuActive) {                                              // If Menu is Active
    itemNav();
    itemSelect();
    staticMenu();    // this sets up screen buffers

    oledUpdate(lineColours[0], lineColours[1], lineColours[2], lineColours[3]);  // This prints the screen buffers if required.

  } else {                                                       // If Menu is Not Active then print incoming serial data to the screen.


    // Serial Listening
    serialEvent();             // if received message on serial RX pin 2

    checkLength();         // makes sure there is sufficient room on the screen to print


    serialPrintout();          // Display Print
    display.display();         

  }




  if (serialScream) {

   serialScreaming();    // this function screams data on tx pin 1
  }


debugging();

} //____________________________________________________ End of Void Loop __________________________________________
