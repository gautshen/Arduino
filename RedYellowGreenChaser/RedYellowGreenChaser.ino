#define NUM_LEDS_PER_COLOR  4

/*
 * Red-Yellow-Green LED Chaser.
 * Author: Gautham R. Shenoy
 * 
 * Connect LEDs Green, Yellow, Red in that order along the long end of the breadboard. Place all the cathodes in the -ve rail of the breadboard.
 *     The anodes connect them to Pins 2-13 (We are using 4 LEDs of each colour)  with a 220Ohm resister in between  as follows
 *     
 *     
 *     ---------------------------------------  -ve rail 
 *     |  |  |  |  |  |  |  |  |  |  |  |
 *     G  Y  R  G  Y  R  G  Y  R  G  Y  R
 *     |  |  |  |  |  |  |  |  |  |  |  | 
 *     Rs Rs Rs Rs Rs Rs Rs Rs Rs Rs Rs Rs  (Rs = 220 Ohms Resistor)
 *     |  |  |  |  |  |  |  |  |  |  |  |
 *     2  3  4  5  6  7  8  9  10 11 12 13
 */ 

int green_pins[NUM_LEDS_PER_COLOR] = {2, 5, 8, 11};
int yellow_pins[NUM_LEDS_PER_COLOR] = {3, 6, 9, 12};
int red_pins[NUM_LEDS_PER_COLOR] = {4, 7, 10, 13};

#define PATTERN1_DELAY   100
#define PATTERN2_DELAY   500
#define PATTERN3_DELAY   100
#define PATTERN4_DELAY   200

void setup() {
  int i;
  // put your setup code here, to run once:

  for (i = 0; i < NUM_LEDS_PER_COLOR; i++) {
    pinMode(green_pins[i], OUTPUT);
    pinMode(yellow_pins[i], OUTPUT);
    pinMode(red_pins[i], OUTPUT);
  }

}

void switch_on_led(int pin_number, int sleep_ms)
{
  digitalWrite(pin_number, HIGH);
  delay(sleep_ms);
}

void switch_off_led(int pin_number, int sleep_ms)
{
  digitalWrite(pin_number, LOW);
  delay(sleep_ms);
}

/*
 * Pattern1: Start with the leftmost LED switch it on from left to right.
 *           then switch it off from Left to right.
 *           Next switch on the LEDs from right to left. 
 *           Then switch it off from right to left.
 */
void show_pattern_1()
{
  int i;
  for (i = 0; i < NUM_LEDS_PER_COLOR; i++) {
    switch_on_led(green_pins[i], PATTERN1_DELAY);
    switch_on_led(yellow_pins[i], PATTERN1_DELAY);
    switch_on_led(red_pins[i], PATTERN1_DELAY);
  }
  
  for (i = 0; i < NUM_LEDS_PER_COLOR; i++) {
    switch_off_led(green_pins[i], PATTERN1_DELAY);
    switch_off_led(yellow_pins[i], PATTERN1_DELAY);
    switch_off_led(red_pins[i], PATTERN1_DELAY);
  }
  
  for (i = NUM_LEDS_PER_COLOR-1; i >=0 ; i--) {
    switch_on_led(red_pins[i], PATTERN1_DELAY);
    switch_on_led(yellow_pins[i], PATTERN1_DELAY);
    switch_on_led(green_pins[i], PATTERN1_DELAY);
    
    
  }

  for (i = NUM_LEDS_PER_COLOR-1; i >=0 ; i--) {
    switch_off_led(red_pins[i], PATTERN1_DELAY);
    switch_off_led(yellow_pins[i], PATTERN1_DELAY);
    switch_off_led(green_pins[i], PATTERN1_DELAY);
  }

}



/*
 * Patter2: All LEDs are simultaneously on, then all LEDs are off.
 */
void show_pattern_2()
{
  int i;
  
  for (i = 0; i < NUM_LEDS_PER_COLOR; i++) {
    switch_on_led(green_pins[i], 0);
    switch_on_led(yellow_pins[i], 0);
    switch_on_led(red_pins[i], 0);
  }
 
  delay(PATTERN2_DELAY);
  
  for (i = 0; i < NUM_LEDS_PER_COLOR; i++) {
    switch_off_led(green_pins[i], 0);
    switch_off_led(yellow_pins[i], 0);
    switch_off_led(red_pins[i], 0);
  }

  delay(PATTERN2_DELAY);
}

/*
 * Pattern3: Traffic Light Pattern. Switch on and off Red, Yellow, Green chasers in that order.
 */
void show_pattern_3()
{
  int i;
  
  for (i = 0; i < NUM_LEDS_PER_COLOR; i++)
    switch_on_led(red_pins[i], PATTERN3_DELAY);
  for (i = 0; i < NUM_LEDS_PER_COLOR; i++)
    switch_off_led(red_pins[i], PATTERN3_DELAY);
  
  for (i = 0; i < NUM_LEDS_PER_COLOR; i++)
    switch_on_led(yellow_pins[i], PATTERN3_DELAY);
  for (i = 0; i < NUM_LEDS_PER_COLOR; i++)
    switch_off_led(yellow_pins[i], PATTERN3_DELAY);

  for (i = 0; i < NUM_LEDS_PER_COLOR; i++)
    switch_on_led(green_pins[i], PATTERN3_DELAY);
  for (i = 0; i < NUM_LEDS_PER_COLOR; i++)
    switch_off_led(green_pins[i], PATTERN3_DELAY);
    
  
  
}

/*
 * Pattern4: Switch on the Extremes to the means and then swith off from Means to extremes
 */
void show_pattern_4()
{
  int start_pin = 2;
  int end_pin = 13;
  int total_pins = NUM_LEDS_PER_COLOR * 3;
  int i;

  for (i = 0; i < total_pins/2; i++){
    switch_on_led(start_pin + i, 0);
    switch_on_led(end_pin - i, 0);
    delay(PATTERN4_DELAY);
  }

  for (i = total_pins/2; i < total_pins; i++){
    switch_off_led(start_pin + i, 0);
    switch_off_led(end_pin - i, 0);
    delay(PATTERN4_DELAY);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  show_pattern_1();
  show_pattern_2();
  show_pattern_3();
  show_pattern_4();
}
