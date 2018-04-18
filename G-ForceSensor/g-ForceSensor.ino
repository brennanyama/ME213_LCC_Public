// Created by: Brennan Yamamoto
// Last update: 2018.04.16
//
// Tutorial code for an Arduino UNO with an ADXL335 accelerometer and buzzer

// Pin definitions
const int zPin = A1;        // input analog pin A1 to ADXL335 Z (z-axis) pin
const int yPin = A2;        // input analog pin A2 to ADXL335 Y (y-axis) pin
const int xPin = A3;        // input analog pin A3 to ADXL335 X (x-axis) pin
const int groundPin = A4;   // output analog pin A4 to ADXL335 GND (ground) pin
const int powerPin = A5;    // output analog pin A5 to ADXL335 VCC (voltage) pin
const int buzzerPin = 11;   // output digital pin 11 to buzzer HIGH pin

// Code variables
long x = 0;
long y = 0;
long z = 0;
long total = 0;

void setup() {
  
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);

  // Instantiate pins (see https://www.arduino.cc/en/Tutorial/DigitalPins)
  pinMode(groundPin, OUTPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(groundPin, LOW);   // this will make groundPin behave as a ground (+0V)
  digitalWrite(powerPin, HIGH);   // this will make powerPin behave as +5V
  digitalWrite(buzzerPin, LOW);   // this will turn buzzer off

  // note that you do NOT need to instantiate input pins (they are input by default), you can if it makes you comfortable
  
}

void loop() {

  // Read accelerometer
  x = analogRead(xPin);
  y = analogRead(yPin);
  z = analogRead(zPin);

  // Calibrate the signal
  // 600 bits ~= 1G
  // 500 bits ~= 0G
  x = x - 500;
  y = y - 500;
  z = z - 500;
  total = sqrt(sq(x)+sq(y)+sq(z));
    
  // print the accerometer values:
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("\t");
  Serial.print("y: ");
  Serial.print(y);
  Serial.print("\t");
  Serial.print("z: ");
  Serial.print(z);
  Serial.print("\t");
  Serial.print("sqrt of sum of squares: ");
  Serial.print(total);
  Serial.println();

  if (total >= 250) {
    digitalWrite(buzzerPin, HIGH);
    delay(150);
    digitalWrite(buzzerPin, LOW);
  }
  
  // Short delay
  delay(10);

}
