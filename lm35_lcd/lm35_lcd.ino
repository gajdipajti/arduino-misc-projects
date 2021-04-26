/*
 * Simple code to read the lm35 temperature with an LCD.
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
const byte sensorPin = A0;

void setup(){
  Serial.begin(9600);
  
  pinMode(sensorPin,INPUT);        // Just in case
  analogReference(INTERNAL);       // Set to the built-in 1.1 V reference

  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.clear();
}

void loop() {
  float temperature = analogRead(sensorPin) * (110.00 / 1024.00);

  // Print the temperature in the Serial Monitor:
  Serial.print(temperature);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.println("C");

  lcd.setCursor(0,0);
  lcd.print(temperature);
  lcd.print((char) 223);
  lcd.print("C");

  delay(500); // wait half a second between readings
}
