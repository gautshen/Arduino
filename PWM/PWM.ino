#define PWM_LED  3
#define DELAY 50
#define MAX_DELAY 1000

byte duty_cycle = 0;
int up_phase = 1;
int down_phase = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PWM_LED, OUTPUT);

}

void loop() {

  if (up_phase && duty_cycle == 255) {
    up_phase = 0;
    down_phase = 1;
  }

  if (down_phase && duty_cycle == 0) {
    down_phase = 0;
    up_phase = 1;
  }
  
  // put your main code here, to run repeatedly:
  analogWrite(PWM_LED,duty_cycle);
  if (duty_cycle == 0 || duty_cycle == 255)
    delay(MAX_DELAY);
  else
    delay(DELAY);
  if (up_phase)
    duty_cycle++;
  else if (down_phase)
    duty_cycle--;


}
