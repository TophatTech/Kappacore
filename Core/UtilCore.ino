/*            
 *         UTILITY FUNCTIONS
 *             
 *            READ INPUTS 
 *          MANAGE USER I/O
 */



/*
 * 
 *            READ INPUTS
 * 
 */

  
  
void readButtons(){
  btnU = digitalRead(ubuttonPin);
  btnD = digitalRead(dbuttonPin);
  btnL = digitalRead(lbuttonPin);
  btnR = digitalRead(rbuttonPin);
  btnJ = !digitalRead(jbuttonPin);
  btnST = digitalRead(stbuttonPin);
  btnSL = digitalRead(slbuttonPin);
}

void readJoy(){
  btnJ = !digitalRead(jbuttonPin);
  joyX = (((analogRead(joyXPin)-offsetX) * 16 / 1024) + 0);
  joyY = (((analogRead(joyYPin)-offsetY) * 16 / 1024) + 0);
}

void readJoyRaw(){
  btnJ = !digitalRead(jbuttonPin);
  joyX = analogRead(joyXPin);
  joyY = analogRead(joyYPin);
}

void readInput(){
  btnU = digitalRead(ubuttonPin);
  btnD = digitalRead(dbuttonPin);
  btnL = digitalRead(lbuttonPin);
  btnR = digitalRead(rbuttonPin);
  btnST = digitalRead(stbuttonPin);
  btnSL = digitalRead(slbuttonPin);
  btnJ = !digitalRead(jbuttonPin);
  joyX = analogRead(joyXPin);
  joyY = analogRead(joyYPin);
}
  
  



/*
 * 
 *            I2C EEPROM COMMANDS
 * 
 */  
  void i2c_eeprom_write_byte( int deviceaddress, unsigned int eeaddress, byte data ) {
    int rdata = data;
    Wire.beginTransmission(deviceaddress);
    Wire.send((int)(eeaddress >> 8)); // MSB
    Wire.send((int)(eeaddress & 0xFF)); // LSB
    Wire.send(rdata);
    Wire.endTransmission();
  }

  // WARNING: address is a page address, 6-bit end will wrap around
  // also, data can be maximum of about 30 bytes, because the Wire library has a buffer of 32 bytes
  void i2c_eeprom_write_page( int deviceaddress, unsigned int eeaddresspage, byte* data, byte length ) {
    Wire.beginTransmission(deviceaddress);
    Wire.send((int)(eeaddresspage >> 8)); // MSB
    Wire.send((int)(eeaddresspage & 0xFF)); // LSB
    byte c;
    for ( c = 0; c < length; c++)
      Wire.send(data[c]);
    Wire.endTransmission();
  }

  byte i2c_eeprom_read_byte( int deviceaddress, unsigned int eeaddress ) {
    byte rdata = 0xFF;
    Wire.beginTransmission(deviceaddress);
    Wire.send((int)(eeaddress >> 8)); // MSB
    Wire.send((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(deviceaddress,1);
    if (Wire.available()) rdata = Wire.receive();
    return rdata;
  }

  // maybe let's not read more than 30 or 32 bytes at a time!
  void i2c_eeprom_read_buffer( int deviceaddress, unsigned int eeaddress, byte *buffer, int length ) {
    Wire.beginTransmission(deviceaddress);
    Wire.send((int)(eeaddress >> 8)); // MSB
    Wire.send((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(deviceaddress,length);
    int c = 0;
    for ( c = 0; c < length; c++ )
      if (Wire.available()) buffer[c] = Wire.receive();
  }




