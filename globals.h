

// User Options // Preferences


bool menuActive = true;    // if true boots to menu options.


bool debuggingEnable =true;   // if true prints serial debug output


unsigned long debuggingDelay = 1000;    // delay between debugging printouts


// Serial Controls

bool serialScream = true;   // if true data is screamed 


// these not used I dont thoink
int screamDelaySeconds = 1;             // number of seconds of delay                  // this is used to print a float value to the screen for UI. screamDelay calculated from these.
int screamDelayTenths = 2;         // number of 10ths of a second delay


unsigned long screamDelay = 200;    // delay in uS between sending data packets. This is now not user set but is calculated from values above ,NOT anymore your not




byte numberOfBytes = 8;   // number of bytes that will be screamed, if char array is set as data output


int dataSelection = 2;   // used to choose between different char arrays. at the moment set to 0, 1 or 2 to print both 3 to 9 to select other data types


int baudRateSelection = 0;  // used to cycle though baud rates in the menu   0 = 9600, 1 = 19200, 2 = 115200


const unsigned long baud9600 = 9600;
const unsigned long baud19200 = 19200;
const unsigned long baud115200 = 115200;

long baudRates[3] = {baud9600, baud19200, baud115200};






//---------------- possible data to send-------------------------

uint8_t    byteOne = 150;  // a single byte                            1 byte                   0 - 255

uint16_t    intTwo = 45866;   // a single unsigned int                 2 bytes                  0 - 65,535
  
int16_t   intThree = -22548;    // a single signed int                 2 bytes            -32,768 - 32,767

uint32_t   intFour = 3265456845;   // a single unsigned long           4 bytes                  0 - 4,294,967,295 

int32_t    intFive = -2147483648;    // a single signed long           4 bytes    -2,147,483,648  - 2,147,483,647

float     floatSix = 56.9834;     // a float value                     4 bytes              6 decimal places
// used to hold the golden ratio of the universe
// most of the time
          
char     charSeven = 'C';     // a single char                      1 byte                      0 - 255


char arrayEightZero[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};   // a char array with one octave of the A minor scale and h

char arrayEightOne[8] = {'1', '1', '2', '3', '5', '8', '1', '3'};   // a different char array for veriaty



struct color {       // a data structure containing 3 bytes of RGB color data
  byte red;
  byte green;
  byte blue;

};


color colourNine = { 255, 100, 150};    // a random colour using the structure above

//------------------------------------- ^^ Data to send ^^ -------------------------










// Control Bools

// these values are used to manage the states of various functions.

bool itemChanged;




//~~~~~~~~~~~~~~~~~~~~~~~ OLED management Functions~~~~~~~~~~~~~~~~~~~~~~~~~~


bool screenUpdate = false;
bool screenWipe = true;

bool lineChanged = false;   // sets true if a new line has started < bug fix.






//~~~~~~~~~~## OLED Display Variables ##~~~~~~~~~~~~~~~~~~~~

int line0colour = 1;
int line1colour = 1;
int line2colour = 1;
int line3colour = 1;

int lineColours[4] = {line0colour, line1colour, line2colour, line3colour};  // this can be used to pass
// line colour info to oledUpdate
//if set at 1, Text is WHITE with black background,
//if set to 0, Text is BLACK with a WHITE background
