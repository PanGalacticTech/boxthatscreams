

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
