/* Interfacing Pot to Arduino Uno with 2.5V external reference voltage and display value on LCD 
 * 
 * Hardware Component :
 * Arduino Uno
 * Potentiometer
 * 
 * Hardware Connection:
 *  A0 of Arduino Uno is connected to Pot
 *  D13(Aref) of Arduino Uno is connected to external reference voltage(2.5V)
 *  LCD is configured to work with 4 bit mode
 *  LCD D4 pin to digital pin 5 of Arduino Uno
 *  LCD D5 pin to digital pin 4 of Arduino Uno
 *  LCD D6 pin to digital pin 3 of Arduino Uno
 *  LCD D7 pin to digital pin 2 of Arduino Uno
 *  LCD RS pin to digital pin 12 of Arduino Uno
 *  LCD EN pin to digital pin 11 of Arduino Uno
 *  LCD R/W pin is grounded
 *  
 *  Author : Sahana B G
 *  Date   : 01 May 2021
 */

// Include the library code:
#include <LiquidCrystal.h>

// Initialize the library by associating any needed LCD interface pin
// with the Arduino Uno pin number it is connected to
const int RS = 12, EN = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

const int POTPIN = A0;    // Select the input pin for the potentiometer
float potValue = 0;  // Variable to store the value coming from the sensor

void setup() 
{
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  Serial.begin(9600);//Baudrate
  
  analogReference(EXTERNAL);// To set the external reference voltage ex:2.5V
}

void loop()
{
  // Read the value from the pot:
  potValue = analogRead(POTPIN);

  // Display pot value on Serial monitor
  Serial.println(potValue);
  
  // Set cursor column 0, and row 0
  lcd.setCursor(0,0);

  // Display pot value on screen
  lcd.print(potValue);
}
