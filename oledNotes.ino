

/*
 * 
 * display.clearDisplay() – all pixels are off
display.drawPixel(x,y, color) – plot a pixel in the x,y coordinates
display.setTextSize(n) – set the font size, supports sizes from 1 to 8
display.setCursor(x,y) – set the coordinates to start writing text
display.print(“message”) – print the characters at location x,y
display.display() – call this method for the changes to make effect
 */


 /* Min for writing text
  *  
  *  
  *  
           display.setTextSize(1);
           display.setTextColor(WHITE);
           display.print("Jeff");
  * 
  * 
  * 
  * 
  */


/*

    Guide for Drawing Shapes


*/


/*
  The drawRect(x, y, width, height, color) provides an easy way to draw a rectangle.
  The (x, y) coordinates indicate the top left corner of the rectangle.
  Then, you need to specify the width, height and color:

  display.drawRect(10, 10, 50, 30, WHITE);

  You can use the fillRect(x, y, width, height, color)
  to draw a filled rectangle.
  This method accepts the same arguments as drawRect().

  The library also provides methods to displays rectangles with round corners:
  drawRoundRect() and fillRoundRect().
  These methods accepts the same arguments as previous methods plus the radius of the corner.

  For example:

  display.drawRoundRect(10, 10, 30, 50, 2, WHITE);    // (x , y, width, height, cornerRadius, color)

  display.fillRoundRect(10, 10, 30, 50, 2, WHITE);  //(x , y, width, height, cornerRadius, color)

*/


// Fonts:

/*
FreeMono12pt7b.h    FreeSansBoldOblique12pt7b.h
FreeMono18pt7b.h    FreeSansBoldOblique18pt7b.h
FreeMono24pt7b.h    FreeSansBoldOblique24pt7b.h
FreeMono9pt7b.h     FreeSansBoldOblique9pt7b.h
FreeMonoBold12pt7b.h    FreeSansOblique12pt7b.h
FreeMonoBold18pt7b.h    FreeSansOblique18pt7b.h
FreeMonoBold24pt7b.h    FreeSansOblique24pt7b.h
FreeMonoBold9pt7b.h   FreeSansOblique9pt7b.h
FreeMonoBoldOblique12pt7b.h FreeSerif12pt7b.h
FreeMonoBoldOblique18pt7b.h FreeSerif18pt7b.h
FreeMonoBoldOblique24pt7b.h FreeSerif24pt7b.h
FreeMonoBoldOblique9pt7b.h  FreeSerif9pt7b.h
FreeMonoOblique12pt7b.h   FreeSerifBold12pt7b.h
FreeMonoOblique18pt7b.h   FreeSerifBold18pt7b.h
FreeMonoOblique24pt7b.h   FreeSerifBold24pt7b.h
FreeMonoOblique9pt7b.h    FreeSerifBold9pt7b.h
FreeSans12pt7b.h    FreeSerifBoldItalic12pt7b.h
FreeSans18pt7b.h    FreeSerifBoldItalic18pt7b.h
FreeSans24pt7b.h    FreeSerifBoldItalic24pt7b.h
FreeSans9pt7b.h     FreeSerifBoldItalic9pt7b.h
FreeSansBold12pt7b.h    FreeSerifItalic12pt7b.h
FreeSansBold18pt7b.h    FreeSerifItalic18pt7b.h
FreeSansBold24pt7b.h    FreeSerifItalic24pt7b.h
FreeSansBold9pt7b.h   FreeSerifItalic9pt7b.h


*/
