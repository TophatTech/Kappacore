/* ProtoCore - Core Development Program
  by [B]Code (http://bcode.work)
  This code is in the public domain.

  modified 29 October 2016
  by BAS
*/

/*-----( Import needed libraries )-----*/
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library
#include <SPI.h>
#include <EEPROM.h>           //EEPROM Library
#include <Wire.h>             //I2C library

/*-----(Font Library)-----*/
#include <Fonts/FreeMono12pt7b.h>
#include <Fonts/FreeSansBoldOblique12pt7b.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSansBoldOblique9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeSansOblique12pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeSansOblique9pt7b.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>
#include <Fonts/FreeMonoBoldOblique9pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeMonoOblique12pt7b.h>
#include <Fonts/FreeSerifBold12pt7b.h>
#include <Fonts/FreeMonoOblique9pt7b.h>
#include <Fonts/FreeSerifBold9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerifBoldItalic12pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSerifBoldItalic9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSerifItalic12pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeSerifItalic9pt7b.h>

/*-----( Initialize LCD/SD Pins )-----*/
#define sclk  13
#define mosi  11
#define cs    10      // Chip select line for TFT display
#define dc    8       // Data/command line for TFT
#define rst   9       // Reset line for TFT (or connect to +5V)
#define sd_cs 4       // Chip select line for SD card


/*-----( Assign a unique ID's where needed )-----*/
Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, mosi, sclk, rst);
//Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst);
//TFT tft = TFT(cs, dc, rst);

/*-----( Declare Constants )-----*/
const byte ubuttonPin = 25;     // the number of the up pushbutton pin
const byte dbuttonPin = 26;     // the number of the down pushbutton pin
const byte lbuttonPin = 27;     // the number of the left pushbutton pin
const byte rbuttonPin = 28;     // the number of the right pushbutton pin
const byte stbuttonPin = 7;     // the number of the start pushbutton pin
const byte slbuttonPin = 6;     // the number of the select pushbutton pin
const byte jbuttonPin = 30;     // the number of the joystick pushbutton pin
const byte joyXPin = 31;        // X Axis Joystick
const byte joyYPin = 32;        // Y Axis Joystick

/*-----( Declare objects )-----*/


/*-----( Declare Non-Image Variables )-----*/

boolean btnU = 0;         // variable for reading the up pushbutton status
boolean btnD = 0;         // variable for reading the down pushbutton status
boolean btnL = 0;         // variable for reading the left pushbutton status
boolean btnR = 0;         // variable for reading the right pushbutton status
boolean btnST = 0;         // variable for reading the start pushbutton status
boolean btnSL = 0;         // variable for reading the select pushbutton status
boolean btnJ = 0;         // variable for reading the joystick pushbutton status

int joyX = 0;             // variable to read the value from the x axis
int joyY = 0;             // variable to read the value from the y axis

int offsetX = 0;             // correction value for x axis
int offsetY = 0;             // correction value for y axis



/*-----( Declare Image Variables )-----*/





/*-----( Test / Debug Variables - Can Be Removed )-----*/


void setup() {
  /*Bootup Init*/
  init_boot();

  /*Bootup Screen*/
  init_screen();

  //Home Screen
  main_menu_root();
  //draw_controls(2);
  //main_menu_selector();
}

void loop() {
  delay(100);
}



