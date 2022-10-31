const int carRedPin = 10;
const int carYellowPin = 9; 
const int carGreenPin = 8;

const int humanRedPin = 5;
const int humanGreenPin = 4;

const int buttonPin = 2;

const int buzzerPin = 6;
const int buzzerTone = 200;
const int buzzerDurationState3 = 600;
const int buzzerIntervalState3 = 1000;
const int buzzerDurationState4 = 250;
const int buzzerIntervalState4 = 600;

byte carRedState = LOW;
byte carYellowState = LOW;
byte carGreenState = HIGH;

byte humanRedState = HIGH;
byte humanGreenState = LOW;

byte lastReading = LOW;
byte buttonState = HIGH;
byte reading; 
byte prevReading = HIGH;

int lastDebounceTime = 0;
const int debounceInterval = 50;

const int state12Begin = 8000;                         // state 2 begins after 8s after the button is pressed
const int state12Duration = state12Begin + 3000;       // from the moment the button is pressed including state 2
const int state123Duration = state12Duration + 8000;   // from the moment the button is pressed including state 3
const int state1234Duration = state123Duration + 4000; // from the moment the button is pressed including state 4

bool startTraffic = false;     // when the light game start this variable will be true
int startProgram;              // time from the point when the button was pressed
bool state3Start = false;      // at the beggining the system is not in the state 3 
bool state4Start = false;      // at the beggining the system is not in the state 4
int previousMillisState3;
int previousMillisState4;

void setup() {
  pinMode(carRedPin, OUTPUT);
  pinMode(carYellowPin, OUTPUT);
  pinMode(carGreenPin, OUTPUT);
  
  pinMode(humanRedPin, OUTPUT);
  pinMode(humanGreenPin, OUTPUT);
  
  pinMode(buttonPin, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void state1() {
  /*
  Green light for cars,
  Red light for people
  No sounds
  */
  carRedState = LOW;
  carYellowState = LOW;
  carGreenState = HIGH;

  humanRedState = HIGH;
  humanGreenState = LOW;
  
  digitalWrite(carRedPin,carRedState);
  digitalWrite(carYellowPin,carYellowState);
  digitalWrite(carGreenPin,carGreenState);
  
  digitalWrite(humanRedPin,humanRedState);
  digitalWrite(humanGreenPin,humanGreenState);
}

void state2() {   //Wait for 8s; Duration = 3s
  /*
  Yellow for cars,
  Red for people,
  No sounds.
  */
  carYellowState = HIGH;
  carGreenState = LOW;

  digitalWrite(carYellowPin,carYellowState);
  digitalWrite(carGreenPin,carGreenState);
}

void state3(int currentMillis) {  //Duration: 8s
  /*
  Red for cars,
  Green for people,
  Sound from buzzer constant interval.
  */
  if (state3Start == false) {         // if the system is for the first time in state 3 
    previousMillisState3 = millis();
    state3Start = true;
    tone(buzzerPin, buzzerTone, buzzerDurationState3);
  }
    
  carRedState = HIGH;
  carYellowState = LOW;
  
  humanRedState = LOW;
  humanGreenState = HIGH;
  
  digitalWrite(carRedPin,carRedState);
  digitalWrite(carYellowPin,carYellowState);
  
  digitalWrite(humanRedPin,humanRedState);
  digitalWrite(humanGreenPin,humanGreenState);
  
  if (currentMillis - previousMillisState3 > buzzerIntervalState3){
    previousMillisState3 = currentMillis;
    tone(buzzerPin, buzzerTone, buzzerDurationState3);
  }
}

void state4(int currentMillis) {    //Duration: 4s
   /*
   Red for cars,
   Blinking green for people,
   Beeping sound from the buzzer faster than in state3
   */
   if (state4Start == false) {            // if the system is for the first time in state 4
    previousMillisState4 = millis();
    state4Start = true;
    noTone(buzzerPin);                    // in this state the tone is different
    tone(buzzerPin, buzzerTone, buzzerDurationState4);
  }  
  
  if (currentMillis - previousMillisState4 > buzzerIntervalState4) {
  	previousMillisState4 = currentMillis; 
    if (humanGreenState == LOW)  // the led will blink
      humanGreenState = HIGH;
    else
       humanGreenState = LOW;
  	digitalWrite(humanGreenPin,humanGreenState);
    tone(buzzerPin, buzzerTone, buzzerDurationState4);
  }
}

void reset() {
  noTone(buzzerPin);
  
  startTraffic = false; // the light game is stopped
  state3Start = false;
  state4Start = false;
  
  buttonState = HIGH;
}

void loop() {
  if (startTraffic == false) {      //the light game does not start
    state1();

    /*debounce for button it is done here because we don't want that pressing 
    the button in any state other than state 1 to yield any actions*/
    reading = digitalRead(buttonPin);

    if (reading != lastReading) {
      lastDebounceTime = millis();
    }
    if (millis() - lastDebounceTime > debounceInterval) {
      if (reading != buttonState) {
        buttonState = reading;
        if (buttonState == LOW){    //if the button was pressed
          startTraffic = true;
          startProgram = millis();  //time from the moment when the button was pressed
        }
      }
    }
  }
  else{                            //the light game starts
   int currentMillis = millis();
    
   if (currentMillis - startProgram >= state12Begin 
      && currentMillis - startProgram <= state12Duration) 
     state2();

   if (currentMillis - startProgram > state12Duration 
      && currentMillis - startProgram <= state123Duration) 
     state3(currentMillis);
    
   if (currentMillis - startProgram > state123Duration 
      && currentMillis - startProgram <= state1234Duration) 
     state4(currentMillis);
    
   if (currentMillis - startProgram > state1234Duration) 
     reset();
  }
  prevReading = reading;
}