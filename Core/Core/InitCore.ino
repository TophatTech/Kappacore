/*            
 *          BOOT (INIT) FUNCTIONS
 *             
 *            DECLARE PINMODES 
 *          INITIALIZE TFT DISPLAY 
 *       DISPLAY BOOTUP FIRMWARE SCREEN
 */


void init_boot(){
    // Init serial for serial monitor, so we can see debug text in the Serial Monitor Window
  Serial.begin(9600);

  /*while (!Serial) {
    // wait for serial port to connect. Needed for native USB port only
    }*/
  Serial.println("2016 Tophat Tech - https://tophat.tech");
  Serial.println("Serial Debugging Enabled");

  /*Initialize TFT screen by type */
  // If your TFT's plastic wrap has a Black Tab, use the following:
  //tft.initR(INITR_BLACKTAB);   // initialize a ST7735R chip, red tab                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            Q `tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  // If your TFT's plastic wrap has a Red Tab, use the following:
  //tft.initR(INITR_REDTAB);   // initialize a ST7735R chip, red tab
  // If your TFT's plastic wrap has a Green Tab, use the following:
  tft.initR(INITR_GREENTAB); // initialize a ST7735R chip, green tab
  Serial.println("INITR_GREENTAB");
  
  /*   PINMODE - INPUTS   */
  pinMode(ubuttonPin, INPUT);
  pinMode(dbuttonPin, INPUT);
  pinMode(lbuttonPin, INPUT);
  pinMode(rbuttonPin, INPUT);
  pinMode(jbuttonPin, INPUT);
  pinMode(stbuttonPin, INPUT);
  pinMode(slbuttonPin, INPUT);
  Serial.println("Button Pinmode Defined");
  
  /*Center Joystick*/
  readJoyRaw();
  offsetX = joyX - 512;
  offsetY = joyY - 512;
  Serial.println("Joystick Centered");
}


void init_screen(){
    
  /* Tophat Logo */
  static const uint8_t PROGMEM myBitmap[] = {0x00,0x00,0x00,0x00,0x0f,0x20,0x0f,0x38,0x0f,0xf8,0x0f,0xf8,0x0f,0xf8,0x37,0xf8,0x71,0xfe,0x78,0xfe,0x3e,0x0e,0x0f,0xfe,0x03,0xfc,0x00,0x00,0x00,0x00,0x00,0x00};
  Serial.println("Logo image declared");
  
  /*Clear Screen*/
  tft.fillScreen(ST7735_BLACK);
  Serial.println("Clear Screen");

  //drawImg(testBMP, sizeof(testBMP, 0, 0));
  /*Write Tophat, Logo, Dividers, and Firmware Version */
  tft.setCursor(0, 0);
  tft.setTextColor(ST7735_WHITE);
  tft.print("2016 TOPHAT TECH");
  tft.drawBitmap(108, 1, myBitmap, 16, 16, ST7735_WHITE);
  tft.setCursor(0, 7);
  tft.print("=================");
  tft.setCursor(0, 7);
  tft.print("_________________");
  tft.setCursor(0, 16);
  tft.print("TOPHAT FIRMWARE V2.0 ");
  
  /*Display System Information*/
  tft.setCursor(0, 28);
  tft.print("CPU:   ARM CTX-M4 FPU");
  tft.print("SPEED:         180MHz");
  tft.print("FLASH:  1048576 bytes");
  tft.print("SRAM:    262144 bytes");
  tft.print("EEPROM:    4096 bytes");
  tft.setCursor(0, 62);
  tft.print("_____________________");

  /*Display Input Button Definitions */
  tft.setCursor(0, 70);
  tft.print("  INPUT DEFINITIONS  ");
  tft.setTextColor(ST7735_CYAN);
  tft.print("BLU/UP 14   ");
  tft.setTextColor(ST7735_RED);
  tft.print("RED/RT 15");
  tft.setTextColor(ST7735_YELLOW);
  tft.print("YLW/DN 16   ");
  tft.setTextColor(ST7735_GREEN);
  tft.print("GRN/LT 2 ");
  tft.setTextColor(ST7735_WHITE);
  tft.print("WHT/ST 7    WHT/SL 6 ");

  /*Display Input Joystick Definitions */
  tft.drawRect(0,104,66,32,ST7735_WHITE);
  tft.setCursor(2, 106);
  tft.print("J     X:31");
  tft.setCursor(2, 116);
  tft.print("O     Y:32");
  tft.setCursor(2, 126);
  tft.print("Y   ");
  tft.setTextColor(ST7735_MAGENTA);
  tft.print("BTN:30");
  tft.fillCircle(24,114,6,ST7735_WHITE);
  tft.drawLine(24,108,24,106,ST7735_WHITE);
  tft.drawLine(24,106,30,106,ST7735_WHITE);
  tft.drawLine(30,106,36,108,ST7735_WHITE);
  tft.drawLine(24,114,24,108,ST7735_BLACK);
  tft.drawLine(30,114,32,114,ST7735_WHITE);
  tft.drawLine(32,114,36,116,ST7735_WHITE);
  tft.drawLine(24,114,30,114,ST7735_BLACK);
  tft.fillCircle(24,114,2,ST7735_MAGENTA);
  
  /*Display Sensor/Communication Definitions */
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(72, 104);
  tft.print("I2C 18/19");
  tft.setCursor(72, 112);
  tft.print("LED    XX");
  tft.setCursor(72, 120);
  tft.print("IR/R   XX");
  tft.setCursor(72, 128);
  tft.print("IR/E   XX");
  tft.setCursor(0, 132);
  tft.print("_____________________");
  /*Display Device ID From Local EEPROM*/
  tft.setCursor(0, 140);
  tft.print("EEPROM I2C:128Kb:0X50");
  /*
  tft.print("DEVICE ID:  565");
  byte i;
  for(i=0; i<=5; i++){
  tft.print(EEPROM.read(i));
  }
  */
  
  /*Display Contaact Info */
  tft.setCursor(0, 142);
  tft.print("_____________________");
  tft.setCursor(0, 150);
  tft.print("PROG:  CORE/PROTOTYPE");

  /*Delay 2 seconds*/
  delay(2000);
  
  /*Clear Screen */
  Serial.println("Drawing Main Menu");
  tft.fillScreen(0x5ACB);
}
