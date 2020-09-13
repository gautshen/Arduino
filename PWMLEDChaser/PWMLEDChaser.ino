#define NR_LEDS  6
#define INITIAL 40
#define STEP 1
#define DELAY_MS 5
int led_pins[NR_LEDS] = {3, 5, 6, 9 , 10, 11};
byte led_values[NR_LEDS] = {0*INITIAL,
                            1*INITIAL,
                            2*INITIAL,
                            3*INITIAL,
                            4*INITIAL,
                            5*INITIAL};
#define UP_PHASE   0
#define DOWN_PHASE 1

void setup() {
  // put your setup code here, to run once:
  int i;

  for (i = 0; i < NR_LEDS; i++) {
    pinMode(led_pins[i], OUTPUT);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  int i;

  
  for (i = 0; i < NR_LEDS; i++) {
     analogWrite(led_pins[i], 255-led_values[i]);
     led_values[i] += STEP;
  }

  delay(DELAY_MS);

}
