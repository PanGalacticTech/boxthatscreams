


const int buttonUP = 7;       //                 1000
const int buttonDWN = 6;   // unused           0100
const int buttonSEL = 5;        //                 0010
const int buttonBCK = 4;    // unused          0001



const int buttons[4] = {buttonUP, buttonDWN, buttonSEL, buttonBCK};


int buttonStatus[4];




void buttonRead() {



  for (int i = 0; i < 4; i++) {

    buttonStatus[i] = digitalRead(buttons[i]);


  }


  // for (int i = 0; i < 4; i++) {

  //     Serial.print(buttonStatus[i]);

  // }

  //  Serial.println(" ");

}







unsigned long buttonHoldTimer = 0;
unsigned long delayTime = 5000;
unsigned long lastButtonPress;
unsigned long buttonPressTime;

int buttonHoldCount = 4; // Sets length of time button hold requires to trigger. // simple acc++ function counts loops. use values from 1 - 5. 

bool buttonHold;
int buttonClick = 0;
bool buttonLockout = false;   // this is used to time out the menu button untill both buttons have been released.


void buttonControl() {

  if (!buttonLockout) {                                                   // if buttons have not been locked out.
    if (buttonStatus[0] == HIGH && buttonStatus[2] == HIGH) {           // IF both buttons are held down
      buttonPressTime = millis();                                   // if this is pressed at 10,000 mS,  this is now pressed at 11,000

      buttonClick++;

      if (buttonClick > buttonHoldCount) {
        buttonHold = true;
        buttonLockout = true;
      //  Serial.println("Button Hold");
        //  Serial.println(" ");
        buttonClick = 0;
      }
    } else if (buttonStatus[0] == HIGH && buttonStatus[2] == LOW) {          // this scrolls thorough menu items
      buttonClick = 0;
      if (menuActive) {

        itemNumber++;
        itemChanged = true;
        buttonLockout = true;
      }

    } else if (buttonStatus[0] == LOW && buttonStatus[2] == HIGH) {                   // this selects items
      buttonClick = 0;
      if (menuActive) {

        itemSelected = true;
        buttonLockout = true;     

      }
    }

    else {
      buttonClick = 0;
    }




  }



  if (buttonStatus[0] == LOW && buttonStatus[2] == LOW) {    // this stops menu flashing on and off if buttons held too long

    if (buttonLockout) {
      buttonLockout = false;
    }
  }

  //  Serial.println(buttonClick);
}








void menuMode() {

  if (buttonHold) {

    if (menuActive) {
      menuActive = false;
      screenWipe = true;
      pageNumber = 0;  // reset page number
   //   Serial.println("Menu Off");
    

      // Should probably add a function here to save settings to eeprom when menu is minimised.


    } else {
      menuActive = true;
      screenWipe = true;
  //    Serial.println("Menu On");
    //  lineColours[0] = 0;
    }

    buttonHold = false;

  }


}
