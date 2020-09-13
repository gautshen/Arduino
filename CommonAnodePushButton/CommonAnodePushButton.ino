//
// Demo of RGB mixing using a Common-Anode LED, 3 Push-buttons
// Each Button will make the Common-Anode LED produce one of the RGB colours.
// When pressed in combination, it will cause the Common-Anode LED to produce Yellow, Cyan, Magenta and White colours.
//
// Author : Gautham R. Shenoy
//
//
//    Wiring:
//
//   Common-Anode LED : 
//   Place in BB[j-5] : RED PIN    ---> Resistor (BB[i-5], BB[i-3]) --> Jumper wire : BB[f-3] to Arduino Pin ~3.
//            BB[j-6] : ANODE PIN  ---> Jumper Wire : BB[f-6] to BB[+ve rail]
//            BB[j-7] : GREEN PIN, ---> Resistor (BB[h-7], BB[h-9]) --> Jumper wire : BB[g-9] to Arduino Pin ~5.
//            BB[j-8] : BLUE PIN, ---> Resistor (BB[f-8], BB[f-14]) --> Jumper wire : BB[i-14] to Arduino Pin ~6.
//
//  Push-Button 1:
//        BB[e-30], BB[e-28], BB[f-30], BB[f-28] 
//             Jumper Wire : BB[c-30] to BB[+ve rail], Jumper Wire : BB[c-28] to Arduino Pin 12, Resistor (BB[a-28], BB[-ve rail])
//  Push-Button 2:
//        BB[e-26], BB[e-24], BB[f-26], BB[f-24] 
//             Jumper Wire : BB[c-26] to BB[+ve rail], Jumper Wire : BB[c-24] to Arduino Pin 10, Resistor (BB[a-24], BB[-ve rail])
//  Push-Button 3:
//        BB[e-22], BB[e-20], BB[f-22], BB[f-20] 
//             Jumper Wire : BB[c-22] to BB[+ve rail], Jumper Wire : BB[c-20] to Arduino Pin  8, Resistor (BB[a-20], BB[-ve rail])
//Where BB = Breadboard.

#define PWM_RED  3
#define PWM_GREEN  5
#define PWM_BLUE  6

#define RED_BUTTON 12
#define GREEN_BUTTON 10
#define BLUE_BUTTON 8

// In the case of CommonAnode LED, the data-pins are connected to the Cathodes.
// Hence we need to subtract the desired value from 255 to obtain the corresponding colour
// This is a helper function.
byte anodeValue(byte val) {
  return (255 - val);
}

void setup() {
  // The RGB PINs of the Anode-LED are the Outpus
  pinMode(PWM_RED, OUTPUT);
  pinMode(PWM_GREEN, OUTPUT);
  pinMode(PWM_BLUE, OUTPUT);

  // The Three pushbuttons should be treated as Inputs.
  pinMode(RED_BUTTON, INPUT);
  pinMode(GREEN_BUTTON, INPUT);
  pinMode(BLUE_BUTTON, INPUT);

}

// Helper function to program the Common-Anode LED with the desired RGB values.
void lightAnodeLED(byte red, byte green, byte blue)
{
  analogWrite(PWM_RED, anodeValue(red));
  analogWrite(PWM_GREEN, anodeValue(green));
  analogWrite(PWM_BLUE, anodeValue(blue));
}

void loop() {
  int red, green, blue;

  int red_pressed = digitalRead(RED_BUTTON);
  int green_pressed = digitalRead(GREEN_BUTTON);
  int blue_pressed = digitalRead(BLUE_BUTTON);

  if (red_pressed)
    red = 255;
  else
    red = 0;

  if (green_pressed)
    green = 255;
  else
    green = 0;

  if (blue_pressed)
    blue = 255;
  else
    blue = 0;

  lightAnodeLED(red, green, blue); //Make the Anode LED glow with the desired colour
}
