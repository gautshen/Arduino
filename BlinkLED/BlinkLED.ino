#define LEDPIN  3


void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LEDPIN, HIGH);
  delay(250);
  digitalWrite(LEDPIN, LOW);
  delay(250);

}
