/*
 * TrafficLight.ino : Simulates the blinking of Traffic Lights (Red,  Yellow, Green)
 *
 * Author : Gautham R. Shenoy
 *
 * Materials Needed:
 *		- Arduino UNO
 *		- Breadboard
 *		- Red LED x 1
 *		- Yellow LED x 1
 *		- Green LED x 1
 *		- 330 Ohms 1/4th Watt Resistor x 3
 *		- Jumper Wires
 *		- USB-A to USB-B cable for uploading the program into
 *		  the Arduino board.
 */
#define RED_LED    4
#define YELLOW_LED 3
#define GREEN_LED 2

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED_LED, HIGH);
  delay(5000);
  digitalWrite(RED_LED, LOW);
  
  digitalWrite(YELLOW_LED, HIGH);
  delay(2000);
  digitalWrite(YELLOW_LED, LOW);
  
  digitalWrite(GREEN_LED, HIGH);
  delay(13000);
  digitalWrite(GREEN_LED, LOW);

  digitalWrite(YELLOW_LED, HIGH);
  delay(2000);
  digitalWrite(YELLOW_LED, LOW);
}
