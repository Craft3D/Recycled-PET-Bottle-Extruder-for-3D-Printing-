/*
Filament Winder by Craft3D V1.0

This is a simple code used to control the speed of rotation of the filament guider in combination
with the speed and direction of the filament guider. This code was written for controlling steppers motor
with pololu a4988 drivers along with Ramps 1.4 and artduinoMega2560 Board

The process of filament winding can be started or stopped by using pushbuttons.


*/


//ButtonFlags
int buttonState = 0;     
int buttonState2 = 0; 

//LimitSwitch
int LimitSwitch1 = 0;
int LimitSwitch2 = 0; 

//LimitSwitch Flags
int number = 0;
bool increase = false;
bool decrease = false;

const int buttonPin = 14; //right direction
const int buttonPin2 = 15; //left direction
const int buttonPin3 = 3; //start
const int buttonPin4 = 2; //stop
bool start = false;


//Winder E0
int enPinE =  24;
int dirPinE = 28;
int stepPinE = 26;

//Winder E1
int enPinG = 30;
int dirPinG = 34;
int stepPinG = 36;

bool direct;

void setup() {

// Set Output Pins for E0
 pinMode(enPinE, OUTPUT);
 pinMode(dirPinE, OUTPUT);
 pinMode(stepPinE, OUTPUT);

//Set Output Pins for E1
 pinMode(enPinG, OUTPUT);
 pinMode(dirPinG, OUTPUT);
 pinMode(stepPinG, OUTPUT);

digitalWrite(enPinG,HIGH);

}

void loop(){

  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  LimitSwitch1 = digitalRead(buttonPin3);
  LimitSwitch2 = digitalRead(buttonPin4);


if(LimitSwitch1 == LOW)
  {
    start = true;
  }
  
  if(LimitSwitch2 == LOW)
  {
    start = false;
  }
  
  if(start){

  if(buttonState == HIGH){
    direct=true;
  }

  if(buttonState2 == HIGH){
    direct=false;
  }
  
digitalWrite(enPinG, LOW);
digitalWrite(dirPinG, direct);
int stepper_speed = 1800;

digitalWrite(stepPinG, HIGH);
delayMicroseconds(stepper_speed);
digitalWrite(stepPinG, LOW);
delayMicroseconds(stepper_speed);
digitalWrite(enPinG, HIGH);

digitalWrite(enPinE, LOW);
digitalWrite(dirPinE, HIGH);

int stepper_speed2= 500;
digitalWrite(stepPinE, HIGH);
delayMicroseconds(stepper_speed2);
digitalWrite(stepPinE, LOW);
delayMicroseconds(stepper_speed2);
digitalWrite(enPinE, HIGH);


  }
}


