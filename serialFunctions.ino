// All of the Serial Data Functions:




/*

  //---------------- possible data to send-------------------------


  const char        Numbers[10] = {"  Numbers"};
  const char           Text[10] = {"     Text"};
  const char     NumberText[10] = {"Numb&Text"};

  const char          uint8[10] = {"  uint8_t"};
  const char         uint16[10] = {" uint16_t"};
  const char          int16[10] = {"  int16_t"};
  const char         uint32[10] = {" uint32_t"};     //
  const char          int32[10] = {"  int32_t"};
  const char         floatT[10] = {"    float"};
  const char          charT[10] = {"     char"};
  const char        structT[10] = {"   Struct"};

  uint8_t byteOne = 150;  // a single byte                        1 byte                 0 - 255

  uint16_t intTwo = 0;   // a single unsigned int                 2 bytes                0 - 65,535

  int16_t intThree = 0;    // a single signed int                 2 bytes          -32,768 - 32,767

  uint32_t intFour = 0;   // a single unsigned long               4 bytes                0 - 4,294,967,295

  int32_t intFive = 0;    // a single signed long                 4 bytes     -2147483648  - 2147483647

  float floatSix = 0.0;     // a float value                      4 bytes            6 decimal places
  // used to hold the golden ratio of the universe
  // most of the time

  char charSeven = 'C';     // a single char                      1 byte                 0 - 255


  char arrayEightZero[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};   // a char array with one octave of the A minor scale and h

  char arrayEightOne[8] = {'1', '1', '2', '3', '5', '8', '1', '3'};   // a different char array for veriaty



  struct color {       // a data structure containing 3 bytes of RGB color data
  byte red;
  byte green;
  byte blue;

  };


  color colourNine = { 255, 100, 150};    // a random colour using the structure above

  //------------------------------------- ^^ Data to send ^^ -------------------------

*/







//int charArraySelection = 2;   // used to choose between different char arrays. at the moment set to 0, 1 or 2. (2 prints both, one after the other)

unsigned long lastScreamTime;    // saves the last time screaming happened



void serialScreaming() {




  if (millis() - lastScreamTime >= screamDelay) {                              // Delay Function, Common to all data types


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Data Selection 0 - 2: Char Strings - Numbers & Text ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



    if (dataSelection == 0 || dataSelection == 2) {

      for (int i = 0; i < numberOfBytes; i++) {
        Serial.print(arrayEightZero[i]);
      }
      //   Serial.println(" ");
    }


    if (dataSelection == 2) {    // adds in extra space if both are printed.
      Serial.print(" ");

    }

    if (dataSelection == 1 || dataSelection == 2) {

      for (int j = 0; j < numberOfBytes; j++) {
        Serial.print(arrayEightOne[j]);
      }
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Data Selection 0 - 2: Char Strings - Numbers & Text ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Data Selection 3-10:  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    if (dataSelection == 3) {
      Serial.print(byteOne);
    }

    if (dataSelection == 4) {
      Serial.print(intTwo);
    }

    if (dataSelection == 5) {
      Serial.print(intThree);
    }

    if (dataSelection == 6) {
      Serial.print(intFour);
    }

    if (dataSelection == 7) {
      Serial.print(intFive);
    }

    if (dataSelection == 8) {
      Serial.print(floatSix, 4);
    }

    if (dataSelection == 9) {
      Serial.print(charSeven);
    }

    if (dataSelection == 10) {
      Serial.print(colourNine.red);
      Serial.print(" ");
      Serial.print(colourNine.green);
      Serial.print(" ");
      Serial.print(colourNine.blue);
    }


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Data Selection 3-10:  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




    Serial.println(" ");    // return symbol (new line) tells listening device message is complete. could use a null packet? Does this always need to be sent?

    lastScreamTime = millis();                     // Delay Function, Common to all data types

  }
}




void serialRestart() {    // restarts serial data if serial restart has been set. suggest running in the "menu off" function so it only
  // runs on exiting the menu after changing the baud rate.

  if (serialChanged) {


    Serial.print("Serial Restart Baud: ");
    Serial.println(baudRates[baudRateSelection]);
    Serial.print(".");
    delay(100);
    Serial.print(".");
    delay(100);
    Serial.print(".");
    delay(100);
    Serial.print(".");
    delay(100);
    Serial.print("[]");
    Serial.end();
    delay(5);    // ? needed who knows

    Serial.begin(baudRates[baudRateSelection]);   // restarts serial at the new baud rate

    Serial.print("Serial Reset Baud: ");
    Serial.println(baudRates[baudRateSelection]);

    if (serialPause) {             // restarts serial output if it has been paused.
      serialScream = true;
      serialPause = false;
    }
    serialChanged = false;

  }

}



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



//---------------------------------Print Serial Data to Screen------------------


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
