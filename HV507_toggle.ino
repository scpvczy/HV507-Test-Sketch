#include <SPI.h>
#include "pins_arduino.h"

const uint8_t DIR_PIN = 14;
const uint8_t POL_PIN = 15;
const uint8_t BL_PIN = 16;
const uint8_t LE_PIN = 17;

void setup (void)
{
  Serial.begin (115200);
  Serial.println ();

  pinMode(DIR_PIN, OUTPUT);
  pinMode(POL_PIN, OUTPUT);
  pinMode(BL_PIN, OUTPUT);
  pinMode(LE_PIN, OUTPUT);

  // set DIOA as data in
  digitalWrite(DIR_PIN, LOW);

  // set not blank to HIGH (no blanking)
  digitalWrite(BL_PIN, HIGH);

  // set polarity to ?
  digitalWrite(POL_PIN, HIGH);

  digitalWrite(LE_PIN, HIGH);  // ensure SS stays high for now

  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on
  SPI.begin ();
}  // end of setup

void loop (void)
{  
  for (uint8_t i = 0; i < 2; i++) {
    // enable Slave Select
    digitalWrite(LE_PIN, LOW);
    for (uint8_t j = 0; j < 8; j++) {
      byte a = SPI.transfer(i * 255);
    }
    digitalWrite(LE_PIN, HIGH);    
  }  
}  // end of loop
