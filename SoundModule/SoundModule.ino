#define SOUND_PIN   2
#define LED_PIN 5
int sound_val;

void setup() {
  // put your setup code here, to run once:
  pinMode(SOUND_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  sound_val = digitalRead(SOUND_PIN);

  if (sound_val == LOW) { //It is dark
    digitalWrite(LED_PIN,HIGH); //Turn on the LED
    delay(50);
  } else { //It is bright
      digitalWrite(LED_PIN,LOW); //Turn off the LED
  }
  

 
}
