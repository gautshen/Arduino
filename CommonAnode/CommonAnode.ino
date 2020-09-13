//
// Demo of RGB mixing using a Common-Anode LED, 3 Push-buttons
//
//
//    Wiring:
//
//   Common-Anode LED : 
//   Place in BB[j-5] : RED PIN    ---> Resistor (BB[i-5], BB[i-3]) --> Jumper wire : BB[f-3] to Arduino Pin ~3.
//            BB[j-6] : ANODE PIN  ---> Jumper Wire : BB[f-6] to BB[+-ve rail]
//            BB[j-7] : GREEN PIN, ---> Resistor (BB[h-7], BB[h-9]) --> Jumper wire : BB[g-9] to Arduino Pin ~5.
//            BB[j-8] : BLUE PIN, ---> Resistor (BB[f-8], BB[f-14]) --> Jumper wire : BB[g-9] to Arduino Pin ~5.
//
//                                                                             -

#define PWM_RED  3
#define PWM_GREEN  5
#define PWM_BLUE  6
#define ON_DELAY 2000
#define OFF_DELAY 50

byte red_cycle = 255;
byte green_cycle = 255;
byte blue_cycle = 255;

byte anodeValue(byte val) {
  return (255 - val);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(PWM_RED, OUTPUT);
  pinMode(PWM_GREEN, OUTPUT);
  pinMode(PWM_BLUE, OUTPUT);

}

void lightLED(byte red, byte green, byte blue)
{
        analogWrite(PWM_RED,anodeValue(red));
        analogWrite(PWM_GREEN,anodeValue(green));
        analogWrite(PWM_BLUE,anodeValue(blue));
    
}

void dutyCycleLED(byte red, byte green, byte blue)
{
   lightLED(red, green, blue);
   delay(ON_DELAY);
   lightLED(0, 0, 0);
   delay(OFF_DELAY);
}
void loop() {

  //red, orange, yellow, chartreuse, green, spring, cyan, azure, blue, violet, magenta, and rose
    dutyCycleLED(255, 0, 0); //RED
    dutyCycleLED(255, 69, 0); //ORANGE
    dutyCycleLED(255,255,0); //YELLOW
    dutyCycleLED(0,255,0); //GREEN
    dutyCycleLED(0, 255, 255); //CYAN
    dutyCycleLED(255, 255, 255); //WHITE
    dutyCycleLED(0, 128, 255); //AZURE
    dutyCycleLED(0, 0, 255); //BLUE
    dutyCycleLED(255, 0, 255); //MAGENTA
    dutyCycleLED(128, 0, 128); //PURPLE
}
