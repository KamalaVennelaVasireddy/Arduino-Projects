#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
const int trigPin = 3;
const int echoPin = 2;
long duration, Cm, Inch;
void setup() {
  lcd.init();
  lcd.begin(16, 2); // Initializes the interface to the LCD display
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Cm = duration * 0.0340 / 2;
  Inch = duration * 0.01330 / 2;
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  Serial.println(Cm);
  lcd.print(Cm);
  lcd.print(" centimeter");
  lcd.setCursor(0, 1);
  lcd.print("    ");
  lcd.print(Inch);
  lcd.print(" inch");
  delay(1000);
}
