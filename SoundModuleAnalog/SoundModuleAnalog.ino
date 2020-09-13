#define SOUND_PIN   A0
#define LED_PIN 3
int sound_val;

int ambient_val = 580;

int compute_ambient_val()
{
  int i;
  int sum = 0;
  for ( i = 0; i < 10; i++) {
    int sound_val = analogRead(SOUND_PIN);
    sum += sound_val;
    delay(100);
  }
  
  ambient_val = sum/10;
}



void setup() {
  // put your setup code here, to run once:
  //pinMode(SOUND_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  compute_ambient_val();

}


int compute_sound_delta(int amb_val, int s_val)
{
  if (s_val < amb_val)
    return 0;
  return (s_val - amb_val);
  
}

byte compute_led_val(int sound_delta)
{
  if (sound_delta < 5)
    return 0;

  if (sound_delta < 10)
    return 16;

  if (sound_delta < 15)
    return 32;

  if (sound_delta < 20)
    return 64;

  if (sound_delta < 25)
    return 128;

  return 255;
}
void loop() {
  sound_val = analogRead(SOUND_PIN);
  int sound_delta = compute_sound_delta(ambient_val, sound_val);
  byte led_val = compute_led_val(sound_delta);
  analogWrite(LED_PIN, led_val);
  Serial.println(sound_val);
  delay(10);  
}
