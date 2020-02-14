
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






void setup() {

  Serial.begin(9600);


}




void loop() {

  // send/print data
//  Serial.print("byteOne: ");
 // Serial.print(byteOne);

 // Serial.print("   floatSix: ");
 // Serial.print(floatSix, 7);   // full number of decimal digits



//  Serial.println(" ");

Serial.print("U");


  // change data in some way
 // byteOne = fibbonacciMe(byteOne);

//  floatSix = theGoldenOne(byteOne, lastInput);        // Generates a ratio between the current byte one
                                   // and its last input value to the fibbonacci engine
                                   // Should return the golden ratio alot of the time


  delay(500);

}  // Loop Forever, screaming into the void.








// Function to generate a fibbonachi sequence from an input number

uint8_t fibbonacciMe(uint8_t input) {

  //first make sure input value is not zero to avoid broken loops:
  if (input == 0 && lastInput == 0) {
    lastInput++;
  }

  int output = input + lastInput;
  
  lastInput = input;
  
  return output;
}


// Function to generate the golden ratio from a sequence of numbers

float theGoldenOne(uint8_t input, uint8_t lastInput){

float in = (float)input;
float lastIn = (float)lastInput;

 float ratio = in/lastIn;

 return ratio;  
}
