

// Debugging Printouts



//bool debuggingEnable = true;


//unsigned long debuggingDelay = 1000;    // delay between debugging printouts

unsigned long lastDebugPrint;




void debugging() {



  if (debuggingEnable) {

    if (millis() - lastDebugPrint >= debuggingDelay) {

      // Put all Debugging Printouts here and comment in the ones being used


     //   Serial.print("Page Number: ");
      //   Serial.println(pageNumber);
//
      //   Serial.print("Item Number ");
    //     Serial.println(itemNumber);



    ////    Serial.print("screamDelayChar: ");
   //    Serial.println(screamDelayChar);
      //
     //   Serial.print("screamDelay: ");
    //     Serial.println(screamDelay);

    //      Serial.print(" ");
    //       Serial.println( );


      lastDebugPrint = millis();
    }
  }
}
