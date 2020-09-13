#define BUTTON 2
#define LED  3

int buttonPressed = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}


#define YES 1
#define NO  0

int is_button_pressed(int button)
{
  int value = digitalRead(button);
  if (!value)
    return NO;

  while(digitalRead(button))
    ;
  return YES;
}

int state = 0;
void loop() {

  //buttonPressed = digitalRead(BUTTON);
  if (is_button_pressed(BUTTON))
    state++;
    
//  if (buttonPressed != 0) //Button was pressed
//    digitalWrite(LED, HIGH);
//  else //Button was not Pressed
//    digitalWrite(LED, LOW);

  if (state % 2 == 1)
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
}
