#include <IRremote.h>
 
#define RECV_PIN  3               
#define LED_PIN   9

IRrecv irrecv(RECV_PIN);
decode_results results;

#define POWER_BUTTON       33441975
#define MODE_BUTTON        33446055
#define MUTE_BUTTON        33454215

#define PLAY_PAUSE_BUTTON  33456255
#define BACK_BUTTON        33439935
#define FORWARD_BUTTON     33472575

#define EQ_BUTTON          33431775
#define VOL_DOWN_BUTTON    33464415
#define VOL_UP_BUTTON      33448095

#define ZERO_BUTTON        33480735
#define RPT_BUTTON         33427695
#define USD_BUTTON         33460335

#define ONE_BUTTON         33444015
#define TWO_BUTTON         33478695
#define THREE_BUTTON       33486855

#define FOUR_BUTTON        33435855
#define FIVE_BUTTON        33468495
#define SIX_BUTTON         33452175

#define SEVEN_BUTTON       33423615
#define EIGHT_BUTTON       33484815
#define NINE_BUTTON        33462375

void setup()
{
   pinMode(LED_PIN, OUTPUT);
   Serial.begin(9600);
  irrecv.enableIRIn();                      // Start the receiver
}


byte led_val = 0;

void take_action(unsigned long remote_button)
{
  switch (remote_button) {
      case POWER_BUTTON:
        if (led_val == 0)
          led_val = 64;
        else
          led_val = 0;
        Serial.write("POWER-BUTTON\n");
        break; 
        
      case VOL_UP_BUTTON:
        if (led_val == 255)
          led_val = 255;
        else if (led_val == 128)
          led_val = 255;
        else
          led_val = led_val * 2;
        Serial.write("VOLUME-UP\n");
        break;
        
      case VOL_DOWN_BUTTON:
        if (led_val == 255)
          led_val = 128;
        else if (led_val == 2)
          led_val = 2;
        else
          led_val = led_val / 2;
        Serial.write("VOLUME-DOWN\n");
        break;
  }

  analogWrite(LED_PIN, led_val);

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);

    take_action(results.value);
    delay(500);
    irrecv.resume();                        // Receive the next value
  }
}
