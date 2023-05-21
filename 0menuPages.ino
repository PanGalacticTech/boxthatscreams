

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~### Menu Pages ###~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~





// Menu Constants

// Full Lines
const char           menuTitle[23] = {" Menu                "};


// Page 0

// Half Lines
const char      menuShortTitle[13] = {"Menu        "};

const char    serialScreamMenu[13] = {" ScreamData "};
const char        baudRateMenu[13] = {"   BaudRate "};
const char      dataStringMenu[13] = {"Data Output "};




// Variable Lines

const char            True[10] = {"    True "};
const char           False[10] = {"   False "};
const char            Null[10] = {"         "};

const char            Save[10] = {"    Save "};
const char            Back[10] = {"    Back "};
const char            Exit[10] = {"    Exit "};

const char       baud9600T[10] = {"    9600 "};
const char      baud19200T[10] = {"   19200 "};
const char     baud115200T[10] = {"  115200 "};

char *baudRatesText[4] = {baud9600T, baud19200T, baud115200T};


// Page 1 - Data Output Type

const char      dataTitle[13] = {"Data Output "};

const char     screamDelayMenu[13] = {"ScreamDelay "};
const char   numberOfBytesMenu[13] = {"No. Bytes   "};
const char        dataTypeMenu[13] = {"Data type   "};


// Page One Numbers as Char Strings

char        screamDelayChar[10] = {"         "};
char          noOfBytesChar[10] = {"         "};

// Page 1 Variables

const char           Text[10] = {"     Text"};
const char        Numbers[10] = {"  Numbers"};
const char     NumberText[10] = {"Numb&Text"};

const char          uint8[10] = {"  uint8_t"};
const char         uint16[10] = {" uint16_t"};
const char          int16[10] = {"  int16_t"};
const char         uint32[10] = {" uint32_t"};     //
const char          int32[10] = {"  int32_t"};
const char         floatT[10] = {"    float"};
const char          charT[10] = {"     char"};
const char        structT[10] = {"   Struct"};

char *dataTypesText[12] = {Text, Numbers, NumberText, uint8, uint16, int16, uint32, int32, floatT, charT, structT};







/*

  uint8_t byteOne = 0;  // a single byte

  uint16_t intTwo = 0;   // a single unsigned int

  int16_t intThree = 0;    // a single signed int

  uint32_t intFour = 0;   // a single unsigned long

  int32_t intFive = 0;    // a single signed long

  float floatSix = 0.0;     // a float value



*/





const char            lineWipe[23] = {"                     "};  // used to wipe old messages line by line


//############################## Empty Screen Buffers #########################################################
char oledLine0[23] = {"                     "}; // Title / Page   // 128 pixles, 5/6 pxl per character
char oledLine1[23] = {"                     "}; //  SAS/RCS Status
char oledLine2[23] = {"                     "}; //  Action triggered or SAS heading
char oledLine3[23] = {"                     "}; //  Staging


// Previous Screen Buffers;
char PoledLine0[23];
char PoledLine1[23];
char PoledLine2[23];
char PoledLine3[23];
//############################## Empty Screen Buffers #########################################################

int numberOfItems = 3;    //Number of items on any menu page

int lineAdjust;    // This variable makes sure correct line is highlighted on OLED, while itemNumber is pointing to the item that is currently selected.

//bool inversionAdjusted = false; // variable goes true on making an edit to control inversions. Triggers  controlsUnassigned = true to run controls assigned when page navigates away from control inverts;

int pageNumber = 0;
int itemNumber = 0;

int previousPage;





void staticMenu() {                     // Function to replace the OLED buffer with the page information, based on pagenumber

  //  Serial.println(itemNumber);

  // Clear the text buffer if page number has changed, before printing new pages
  if (previousPage != pageNumber) {
    messageReplace(0 , lineWipe);   // recently addedm remove if problems occur
    messageReplace(1 , lineWipe);
    messageReplace(2 , lineWipe);
    messageReplace(3 , lineWipe);

  }

  if (pageNumber == 0) {                                                            // Page 0 = Kerbal Space Program Homepage
    numberOfItems = 3;
    //  itemNumber = 0;   /// bug fix sets itemNumber as always 0 on page 1

    lineDualreplace(0, menuShortTitle, Exit);

    if (serialScream) {
      lineDualreplace(1, serialScreamMenu, True);
    } else {
      lineDualreplace(1, serialScreamMenu, False);
    }

    lineDualreplace(2, baudRateMenu, baudRatesText[baudRateSelection]);

    lineDualreplace(3,  dataStringMenu, 0);
  }

  if (pageNumber == 1) {                                        // Page 1 = Data Specifics Page
    numberOfItems = 3;

    lineDualreplace(0, dataTitle, Exit);

    // Line here to copy screamDelay into a char string //screamDelayChar

    sprintf(screamDelayChar, "  %d uS", screamDelay);     // %d   = signed int   %u = unsigned int %c = character


    if (screamDelay < 1000) {

      for (int i = 9; i > 0; i--) {     // move the characters along the string

        screamDelayChar[i] = screamDelayChar [i - 1];

      }
      screamDelayChar[2] = {'0'};
    }

    if (screamDelay == 0) {

      sprintf(screamDelayChar, "  0000 uS");
    }


    lineDualreplace(1, screamDelayMenu, screamDelayChar);


    // Line here to copy number of bytes into a char string //

    sprintf(noOfBytesChar, "     %d  ", numberOfBytes);


    lineDualreplace(2, numberOfBytesMenu, noOfBytesChar);
    lineDualreplace(3, dataTypeMenu, dataTypesText[dataSelection]);
  }

  


  previousPage = pageNumber;


}




// Navigation for menu items





void itemNav() {   // Function to select active ITEM NUMBER



  if (pageNumber >= 0) {

    if (itemNumber > numberOfItems) {

      itemNumber = 0;

    } else if (itemNumber < 0) {

      itemNumber = numberOfItems;

    }


    if (itemChanged) {
      lineColours[itemNumber] = 0;    // added line
      lineColours[itemNumber - 1] = 1;    // added line
      if (itemNumber == 0) {                     // bug fix. clunky but should work, this turns off line 3 white bar as item number rolls over
        lineColours[3] = 1;
      }

      screenUpdate = true;
      itemChanged = false;
    }

    if (itemNumber <= 3) {
      lineAdjust = itemNumber;
      display.fillRoundRect(120, 8 * (itemNumber - 4), 8, 32, 2, BLACK); //(x , y, width, height, cornerRadius, color)
      display.fillRoundRect(120, 8 * itemNumber, 8, 8, 2, WHITE); //(x , y, width, height, cornerRadius, color)
      display.fillRoundRect(120, 8 * (itemNumber + 1), 8, 32, 2, BLACK); //(x , y, width, height, cornerRadius, color)

    } else if (itemNumber > 3 && itemNumber <= 6) {

      lineAdjust = itemNumber - 3;

      display.fillRoundRect(120, 8 * (lineAdjust - 4), 8, 32, 2, BLACK); //(x , y, width, height, cornerRadius, color)
      display.fillRoundRect(120, (8 * lineAdjust), 8, 8, 2, WHITE); //(x , y, width, height, cornerRadius, color)
      display.fillRoundRect(120, 8 * (lineAdjust + 1), 8, 32, 2, BLACK); //(x , y, width, height, cornerRadius, color)

    } else if (itemNumber > 6) {

      lineAdjust = itemNumber - 6;

      display.fillRoundRect(120, 8 * (lineAdjust - 4), 8, 32, 2, BLACK); //(x , y, width, height, cornerRadius, color)
      display.fillRoundRect(120, (8 * lineAdjust), 8, 8, 2, WHITE); //(x , y, width, height, cornerRadius, color)
      display.fillRoundRect(120, 8 * (lineAdjust + 1), 8, 32, 2, BLACK); //(x , y, width, height, cornerRadius, color)
    }


    //  screenUpdate = true;



  } else {
    // itemNumber = 0;
    // lineAdjust = itemNumber;  // bug fix

  }
} //--------------------------





bool itemSelected;       // if button has been pressed while in menu
bool serialChanged;       // Serial Settings have been changed, sets flag to reset serial output with new settings.
bool serialPause;       // flag to set serial as paused rather than just turned off in menu

// Selection scrip for menu items

// This checks if the button has been switched and then enacts commands based on what item was selected.

void itemSelect() {         // script for triggering actions based on menu item selected.   // generate bools, then use bools to trigger actions elsewhere



  if (itemSelected) {                          // if the rotary button has been clicked

    //  Serial.println("item selected");

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~### Page 1 ###~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if (pageNumber == 0) {            // Page 1 settings

      if (itemNumber == 0) {                 // item 0, Close Menu

       // saveSettings();                       // save the settings
        menuActive = false;
        screenWipe = true;
        serialRestart();                   // this restarts serial if baud rate has been changed.
        itemSelected = false;           // This resets the rotary Button push, ready for retrigger
        //  pageScroll = false;              // sets this ready to scroll through menu items again
        //  lineColours[1] = 1;                     // Resets line colour  << Eventually this could be done right at end of routein, It depends on if it works with others
      }



      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~### Item 1 ###~~~~~~~~~~~~~~~~~~~~~~~~ Scream Data SELECT ~~~~~~

      if (itemNumber == 1) {                 // item 1,

        if (serialScream) {
          serialScream = false;
        } else {
          serialScream = true;
        }

        itemSelected = false;           // This resets the rotary Button push, ready for retrigger
        //  pageScroll = false;              // sets this ready to scroll through menu items again
        //  lineColours[1] = 1;                     // Resets line colour  << Eventually this could be done right at end of routein, It depends on if it works with others
      }


      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~### Item Baud Rate ###~~~~~~~~~~~~~~~~~~~~~~~~

      if (itemNumber == 2) {                 // item 2, Baud Rate

        baudRateSelection++;

        if (baudRateSelection >= 3) {
          baudRateSelection = 0;
        }
        Serial.print("Serial baudrate: ");
        Serial.println(baudRates[baudRateSelection]);
        Serial.println("Settings applied on menu exit...");

        if (serialScream) {
          serialPause = true;
          serialScream = false;   // pauses serial output mostly to help with debugging
        }



        serialChanged = true;
        itemSelected = false;           // This resets the rotary Button push, ready for retrigger
        //      pageScroll = false;              // sets this ready to scroll through menu items again
        // lineColours[2] = 1;                     // Resets line colour  << Eventually this could be done right at end of routein, It depends on if it works with others
      }

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~### Item 3 ###~~~~~~~~~~~~~~~~~~~~~~~~

      if (itemNumber == 3) {                 // item 3, Data Output
        pageNumber = 1;                        //
        itemNumber = 0;
        screenWipe = true;
        // screenClear();                      // clear the screen if flag has been set
        itemSelected = false;           // This resets the rotary Button push, ready for retrigger
        //      pageScroll = false;              // sets this ready to scroll through menu items again
        lineColours[3] = 1;                     // Resets line colour  << Eventually this could be done right at end of routein, It depends on if it works with others
      }
    }   //###~~~~~~~ End of Page 1 ~~~~~~~~~###
    //  }

  }

  if (itemSelected) {                          // if the rotary button has been clicked This line needs reiterating, otherwise it has a broken loop

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~### Page 2 ###~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if (pageNumber == 1) {            // Page 2 Inversions

      if (itemNumber == 0) {              // go back

        pageNumber = 0;
        itemSelected = false;
      }


      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~### Item 1 - Scream Delay ###~~~~~~~~~~~~~~~~~~~~~~~~
      if (itemNumber == 1) {
        // Rocket Mode go to page 3
        //     pageScroll = false;              // sets this ready to scroll through menu items again



        //  screamDelayTenths = screamDelayTenths + 2;

        //  if (screamDelayTenths > 6) {
        //     screamDelaySeconds++;
        //    screamDelayTenths = 0;
        //   }

        //   if (screamDelaySeconds >= 9) {
        //     screamDelaySeconds = 0;
        //     screamDelayTenths = 0;
        //   }

        screamDelay = screamDelay + 200;

        if (screamDelay >= 6200) {

          screamDelay = 0;
        }


        itemSelected = false;
        //  lineColours[1] = 1;                     // Resets lin
      }

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~### Item 2 - Number of Bytes ###~~~~~~~~~~~~~~~~~~~~~~~~
      if (itemNumber == 2) {

        //      pageScroll = false;              // sets this ready to scroll through menu items again

        numberOfBytes++;

        if (numberOfBytes > 8) {
          numberOfBytes = 1;
        }
        itemSelected = false;
      }

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~### Item 3 ###~~~~~~~~~~~~~~~~~~~~~~~~
      if (itemNumber == 3) {

        dataSelection++;

        if (dataSelection >= 11) {
          dataSelection = 0;
        }

        itemSelected = false;
        //   lineColours[3] = 1;

      }

    }

  } //###~~~~~~~ End of Page 2 ~~~~~~~~~###

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~### Page 3  Rocket Inversions ###~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




} // End of item Select Script
