/*
 * Simple code to read the lm35 temperature, Serial only.
 */
const byte sensorPin = A0;

void setup() {
  Serial.begin(9600);
  
  pinMode(sensorPin,INPUT);        // Just in case
  analogReference(INTERNAL);       // Set to the built-in 1.1 V reference
}

void loop() {
  float temperature = analogRead(sensorPin) * (110.00 / 1024.00);

  // Print the temperature in the Serial Monitor:
  Serial.print(temperature);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.println("C");

  delay(500); // wait half a second between readings
}
