/*Declare the pins of RGB led */
const int ledRedPin = 11;
const int ledGreenPin = 10;
const int ledBluePin = 9;

const int signalRedPin = A0; 
const int signalBluePin = A1; 
const int signalGreenPin = A5; 

/*Set the brightness and analog default values*/
const int lowBrightnessValue = 0;
const int highBrightnessValue = 255;
const int lowAnalogValue = 0;
const int highAnalogValue = 1023;

int signalRedValue;
int signalBlueValue;
int signalGreenValue;

int ledRedValue;
int ledBlueValue;
int ledGreenValue;

void setup(){

  pinMode(signalRedPin, INPUT);
  pinMode(signalBluePin, INPUT);
  pinMode(signalGreenPin, INPUT);

  pinMode(ledRedPin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
}

void loop(){
  /*Values for all three potentiometers*/
  signalRedValue = analogRead(signalRedPin); 
  signalBlueValue = analogRead(signalBluePin);  
  signalGreenValue = analogRead(signalGreenPin); 

  /*Map the value in [0,255] interval*/
  ledRedValue = map(signalRedValue, lowAnalogValue, highAnalogValue, lowBrightnessValue, highBrightnessValue);
  ledBlueValue = map(signalBlueValue, lowAnalogValue, highAnalogValue, lowBrightnessValue, highBrightnessValue);
  ledGreenValue = map(signalGreenValue,lowAnalogValue, highAnalogValue, lowBrightnessValue, highBrightnessValue);
 
  /*Set the colours values of RGB led depending on potentiometer value*/
  analogWrite(ledRedPin, ledRedValue);
  analogWrite(ledBluePin, ledBlueValue);
  analogWrite(ledGreenPin, ledGreenValue);
}