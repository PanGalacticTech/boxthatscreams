


/*
 int reading = digitalRead(buttonPlusPin);

  //Serial.println(reading);

  if (reading != lastPlusState) {
    // reset the debouncing timer
    lastButtonPress = millis();
  }


  if ((millis() - lastButtonPress) > buttonTimeout) {

    if (reading != buttonPlusState) {
      buttonPlusState = reading;


      if (buttonPlusState == LOW) {

        Serial.println(buttonPlusState);

        currentdB = currentdB++;

      }

    }

    // save the reading.  Next time through the loop,
    // it'll be the lastButtonState:
    lastPlusState = reading;

  }

*/
