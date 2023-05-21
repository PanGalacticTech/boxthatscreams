



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#### OLED ####~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void oledUpdate(byte colour0, byte colour1, byte colour2, byte colour3) {  //colour = 1 white on black // colour = 0 black on white

  //if (screenUpdate == true) {

  if (strcmp(oledLine0, PoledLine0) != 0) {    // If char strings are not equal
    strcpy(PoledLine0,  oledLine0);
    screenUpdate = true;
  }
  if (strcmp(oledLine1, PoledLine1) != 0) {    // If char strings are not equal
    strcpy(PoledLine1,  oledLine1);
    screenUpdate = true;
  }
  if (strcmp(oledLine2, PoledLine2) != 0) {    // If char strings are not equal
    strcpy(PoledLine2,  oledLine2);
    screenUpdate = true;
  }
  if (strcmp(oledLine3, PoledLine3) != 0) {    // If char strings are not equal
    strcpy(PoledLine3,  oledLine3);
    screenUpdate = true;
  }


  display.setTextColor(colour0, !colour0);
  display.setCursor(0, 0);
  display.print(oledLine0);



  display.setTextColor(colour1, !colour1);
  display.setCursor(0, 8);
  display.print(oledLine1);


  display.setTextColor(colour2, !colour2);
  display.setCursor(0, 16);
  display.print(oledLine2);


  display.setTextColor(colour3, !colour3);
  display.setCursor(0, 24);
  display.print(oledLine3);

  if (screenUpdate == true) {
    display.display();
    //   Serial.print("Oled Updated");
    screenUpdate = false;
  }


}




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ These Scripts swap out contents of the screen buffer, ready to print to OLED when function is called


void messageReplace(int lineNumber, char newMessage[23]) {   // Replace message in oledArrary[0]-[4] (buffer for oled) - 22 char long with specific 22 char long presaved messages oledLine0[23]

  for (int i = 0; i < 21; i++) {   // i < 22 replaced

    if (lineNumber == 0) {           // heading line
      oledLine0[i] = newMessage[i];
    }

    if (lineNumber == 1) {
      //     if (oledLine1[i] != newMessage[i]) {
      oledLine1[i] = newMessage[i];
      //    screenUpdate = true;
      //   }
    }

    if (lineNumber == 2) {
      //     if (oledLine2[i] != newMessage[i]) {
      oledLine2[i] = newMessage[i];
      //      screenUpdate = true;
      //    }
    }

    if (lineNumber == 3) {
      ///     if (oledLine3[i] != newMessage[i]) {
      oledLine3[i] = newMessage[i];
      //       screenUpdate = true;
      ///     }
    }

    //  Serial.println("Message Replace");
    //   screenUpdate = true;


  }
}


void line1Replace(byte lineNumber, char slot1[], char slot2[], char slot3[]) {    // line 1 is split into 3 spaces. Of 3, 14 and 3 characters send "0" to ignore
  // byte linenumber should be 1 for SAS RCS messages
  // byte linenumber should be 2 for action messages & gear
  if (slot1 != 0) {
    for (int i = 0; i < 3; i++) {  // this does slot 1

      if (lineNumber == 1) {
        oledLine1[i] = slot1[i];
      } else if (lineNumber == 2) {
        oledLine2[i] = slot1[i];
      }

    }
  }

  if (slot2 != 0) {
    for (int i = 0; i < 14; i++) {  // this does slot 2
      if (lineNumber == 1) {
        oledLine1[i + 4] = slot2[i];
      } else if (lineNumber == 2) {
        oledLine2[i + 4] = slot2[i];
      }
    }
  }

  if (slot3 != 0) {
    for (int i = 0; i < 3; i++) {  // this does slot 3
      if (lineNumber == 1) {
        oledLine1[i + 18] = slot3[i];
      } else if (lineNumber == 2) {
        oledLine2[i + 18] = slot3[i];
      }
    }
  }

  //  screenUpdate = true;
  // Serial.println("line1replace");
}





void lineDualreplace(byte lineNumber, char slot1[], char slot2[]) {    // line 1 is split into 2 halves, 10 first each with space between them
  // byte linenumber should be 1 for SAS RCS messages
  // byte linenumber should be 2 for action messages & gear
  if (slot1 != 0) {
    for (int i = 0; i < 12; i++) {  // this does slot 1


      if (lineNumber == 0) {
        oledLine0[i] = slot1[i];
      } else if (lineNumber == 1) {
        oledLine1[i] = slot1[i];
      } else if (lineNumber == 2) {
        oledLine2[i] = slot1[i];
      } else if (lineNumber == 3) {
        oledLine3[i] = slot1[i];
      }

    }
  }

  if (slot2 != 0) {
    for (int i = 0; i < 9; i++) {  // this does slot 2


      if (lineNumber == 0) {
        oledLine0[i + 12] = slot2[i];
      } else if (lineNumber == 1) {
        oledLine1[i + 12] = slot2[i];
      } else if (lineNumber == 2) {
        oledLine2[i + 12] = slot2[i];
      } else if (lineNumber == 3) {
        oledLine3[i + 12] = slot2[i];
      }
    }
  }


  //  screenUpdate = true;
  // Serial.println("line1replace");
}



void screenClear() {

  if (screenWipe) {
    messageReplace(0 , lineWipe);   // recently addedm remove if problems occur
    messageReplace(1 , lineWipe);
    messageReplace(2 , lineWipe);
    messageReplace(3 , lineWipe);
    display.clearDisplay();           // functions above dont seem to do shit.
    screenUpdate = true;
    //   Serial.println("Screen Cleared");
    // display.display();
    screenWipe = false;
  }


}





/*

  // This clears messages from the screen after a set amount of time. Only clears entire lines.


  void timedMessageClear(int lineNumber) {

  if (timedMessageset) {

    if (millis() - lastMessage >= messageTimeout) {

      messageReplace(lineNumber, lineWipe);
      timedMessageset = false;
    }
  }
  }


*/
