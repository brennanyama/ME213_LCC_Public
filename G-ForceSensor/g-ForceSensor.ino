// Created by: Brennan Yamamoto
// Last update: 2018.04.11
//
// Arduino tutorial code with an ADXL 335 accelerometer and buzzer

// Pin definitions
const int groundPin = A4;   // analog input pin 4 -- ground
const int powerPin = A5;    // analog input pin 5 -- voltage
const int xPin = A3;        // x-axis of the accelerometer
const int yPin = A2;        // y-axis
const int zPin = A1;        // z-axis
const int buzzerPin = 11;   // buzzer pin

void setup() {
  
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);

  // Instantiate pins
  pinMode(groundPin, OUTPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(groundPin, LOW);   // this will make groundPin behave as a ground (+0V)
  digitalWrite(powerPin, HIGH);   // this will make powerPin behave as +5V
  digitalWrite(buzzerPin, LOW);   // this will turn buzzer off

  // note that you do NOT need to instantiate input pins (they are input by default), you can if it makes you comfortable
  
}

void loop() {

  // Instantiate code variables
  int x = 0;
  int y = 0;
  int z = 0;

  // Read accelerometer
  x = analogRead(xPin);
  y = analogRead(yPin);
  z = analogRead(zPin);

  // Calibrate the signal
  // 600 bits ~= 1G
  // 500 bits ~= 0G
  x = x - 505;
  y = y - 515;
  z = z - 508;
    
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
  Serial.print("absolute value: ");
  Serial.print(abs(x)+abs(y)+abs(z));
  Serial.println();

  if (abs(x+y+z) >= 250) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
  }
  
  // Short delay
  delay(50);

}
