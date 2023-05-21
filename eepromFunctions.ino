// Functions to save settings to EEprom Here:

/*
int eeAddress = 0;
int eepromSize = 512;   // ATmega




struct configStore {     // structure to save all of the config data

  bool serialScreamS;

  unsigned long screamDelayS;

  byte numberOfBytesS;

  int dataSelectionS;

  int baudRateSelectionS;

};




struct configStore savedSettings;  // variable to store the saved settings

// this can be accessed now as

// savedSettings.rocketControlConfig[0] = whatever(uint8_t)w   --- I think, haha
//

/*
   There is another very useful function in C called “sizeof(var)”. That tells you how big variables are.
   For instance it would return 2 for a uint16_t, 4 for a float, etc. For our struct it would return 12.

    Atchully, I think for this structure it should return 27 bytes the text above is just copied. Helpful I know.
*/

/*

char memoryPointer = "S";




// This fucntion saves the current user settings on menu exit

// These might be overkill
bool newSave = false;
bool recallSave = false;


void saveSettings() {



 // Serial.print("Saving Settings: Slot");
  Serial.println(eeAddress);
//  Serial.print("...");




  savedSettings.serialScreamS = serialScream ;
  savedSettings.screamDelayS = screamDelay;
  savedSettings.numberOfBytesS = numberOfBytes;
  savedSettings.dataSelectionS = dataSelection;
  savedSettings.baudRateSelectionS = baudRateSelection;



 // Serial.print("Size of Data Package");
  Serial.println(sizeof(configStore));

  //  EEPROM.write(n, writeByte);   // using EEprom put instead of .write. Only writes data if different to location.



  EEPROM.put(eeAddress, savedSettings);            // //One simple call, with the address first and the object second.

  eeAddress += sizeof(savedSettings);                // advance the eeprom memory counter.

  if (eeAddress >= 512) {
    eeAddress = 0;
  }

  EEPROM.put(eeAddress, memoryPointer);                 //



}





// This function finds the last saved settings and applys them

void recallSettings() {

  //   = EEPROM.read(i);

  int i = 0;     // loop counter

  while (EEPROM.read(i) != memoryPointer) {

    i++;
 //   Serial.print("Checking for Save Data");
    Serial.println(i);

      if (i >= 512) {
      break;
    }

  }


  if (i <= 512) {
    recallSave = true;
  //  Serial.print("Recall Save");
  }



  if (recallSave) {

    eeAddress = (i - sizeof(savedSettings));

    EEPROM.get(eeAddress, savedSettings);


    serialScream = savedSettings.serialScreamS;
    screamDelay = savedSettings.screamDelayS;
    numberOfBytes = savedSettings.numberOfBytesS;
    dataSelection =  savedSettings.dataSelectionS;
    baudRateSelection = savedSettings.baudRateSelectionS;




  //  Serial.print("Serial Scream: ");
    Serial.println(serialScream);
  //  Serial.print("Scream Delay: ");
    Serial.println(screamDelay);
 //   Serial.print("Number Of Bytes: ");
    Serial.println(numberOfBytes);
  //  Serial.print("Data Selection: ");
    Serial.println(dataSelection);
 //   Serial.print("Baud Rate: ");
    Serial.println(baudRateSelection);

 //   Serial.println("...");

  //  Serial.println("Settings Recalled");

  } else {

 //   Serial.println("No Settings To Recall");
  }

}

*/
