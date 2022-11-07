const int pinA = 4;
const int pinB = 5;
const int pinC = 6;
const int pinD = 7;
const int pinE = 8;
const int pinF = 9;
const int pinG = 10;
const int pinDP = 11;

const int pinX = A0;
const int pinY = A1;
const int pinSw = 2;

const int segSize = 8;
const int noOfPositions = 4;

bool commonAnode = false;

byte joystickOX = LOW;
byte joystickOY1 = LOW;
byte joystickOY2 = LOW;
byte state = HIGH;

int xValue = 0;
int yValue = 0;

int pressJoystick = 0;
int stopPJoystick = 0;

byte swState = HIGH;
byte lastSwState = HIGH;
byte reading = LOW;
unsigned long lastDebounceTime = 0;
const int debounceInterval = 50;
const int longInterval = 5000;  //5s
const int smallInterval = 50;


int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

byte statePinA = LOW;
byte statePinB = LOW;
byte statePinC = LOW;
byte statePinD = LOW;
byte statePinE = LOW;
byte statePinF = LOW;
byte statePinG = LOW;
byte statePinDP = LOW;

int posA = 0;
int posB = 1;
int posC = 2;
int posD = 3;
int posE = 4;
int posF = 5;
int posG = 6;
int posDP = 7;
int posUnable = 10;

byte blinkState = LOW;
byte currentSegmentState = LOW;
int currentSegmentPos = posA;
int currentState = 1;

int up = 0;
int down = 1;
int left = 2;
int right = 3;

byte moveMatrix[segSize][noOfPositions] = {
  //up         down       left       right
  { posUnable, posG,      posF,      posB },          // a
  { posA,      posG,      posF,      posUnable },     // b
  { posG,      posD,      posE,      posDP },         // c
  { posG,      posUnable, posE,      posC },          // d
  { posG,      posD,      posUnable, posC },          // e
  { posA,      posG,      posUnable, posB },          // f
  { posA,      posD,      posUnable, posUnable },     // g
  { posUnable, posUnable, posC,      posUnable }      // dp
};

const int minThreshold = 400;
const int maxThreshold = 600;

unsigned long currentMillis;
unsigned long previousMillis = 0;
const unsigned long interval = 1000;  // interval at which to blink

int buttonPress = 0;


void setup() {
  if (commonAnode == true) {
    state = !state;
  }

  pinMode(pinSw, INPUT_PULLUP);

  for (int i = 0; i < segSize; i++) {
    pinMode(segments[i], OUTPUT);
  }

  Serial.begin(9600);
}

/*
  In ledsState() function I attribute to the pin its state. 
  If the pin is on the position of the current pin then it will just blink, else it will have his saved state from state 2.
*/
void ledsState() {
  if (currentSegmentPos != posA)
    digitalWrite(pinA, statePinA);

  if (currentSegmentPos != posB)
    digitalWrite(pinB, statePinB);

  if (currentSegmentPos != posC)
    digitalWrite(pinC, statePinC);

  if (currentSegmentPos != posD)
    digitalWrite(pinD, statePinD);

  if (currentSegmentPos != posE)
    digitalWrite(pinE, statePinE);

  if (currentSegmentPos != posF)
    digitalWrite(pinF, statePinF);

  if (currentSegmentPos != posG)
    digitalWrite(pinG, statePinG);

  if (currentSegmentPos != posDP)
    digitalWrite(pinDP, statePinDP);
  
  digitalWrite(segments[currentSegmentPos], currentSegmentState);//the segment that blinks
  
 
}

void blinking() {
  currentMillis = millis();  

  if (currentMillis - previousMillis > interval && blinkState == LOW) { //if the system is in state 1 then I let it to blink on the given interval  
    previousMillis = currentMillis;  
    if (currentSegmentState == HIGH) //the change of states
      currentSegmentState = LOW;
    else 
      currentSegmentState = HIGH; 
  }
}


/*
  neighbours() function show the movement from one segment (the blinking one) to its neighbours.
  The new currentSegment (the one who blinks) is determined with the moveMatrix.
  This function is available just in state 1.
*/
void neighbours() {

  if (xValue < minThreshold &&  moveMatrix[currentSegmentPos][down] != posUnable && currentState == 1 && joystickOX == LOW) {
    currentSegmentPos = moveMatrix[currentSegmentPos][down];
    joystickOX = HIGH;
  }
  else if (xValue > maxThreshold &&  moveMatrix[currentSegmentPos][up] != posUnable && currentState == 1 && joystickOX == LOW) {
    currentSegmentPos = moveMatrix[currentSegmentPos][up];
    joystickOX = HIGH;
  }
  else if (xValue > minThreshold && xValue < maxThreshold && currentState == 1 && joystickOX == HIGH) {
    joystickOX = LOW;
  }

  if (yValue < minThreshold &&  moveMatrix[currentSegmentPos][left] != posUnable && currentState == 1 && joystickOY1 == LOW) {
    currentSegmentPos = moveMatrix[currentSegmentPos][left];
    joystickOY1 = HIGH;
  }
  else if (yValue > maxThreshold  && moveMatrix[currentSegmentPos][right] != posUnable && currentState == 1 && joystickOY1 == LOW) {
    currentSegmentPos = moveMatrix[currentSegmentPos][right];
    joystickOY1 = HIGH;
  }
  else if (yValue > minThreshold && yValue < maxThreshold && currentState == 1 && joystickOY1 == HIGH) {
    joystickOY1 = LOW;
  }
}


/*
  When the button is pressed for more than 5s then the system is reset,
  when the button is pressed for short time the number of presses increases:
  if it is even then the system goes to state 1, otherwise to state 2.
*/
void button() {

  if (reading != lastSwState) {
    lastDebounceTime = millis();
  }

  if (millis() - lastDebounceTime > debounceInterval) {

    if (reading != swState) {
      swState = reading;
      if (swState == LOW) {
        pressJoystick = millis();
      }
      else {
        stopPJoystick = millis();
      }

      if(stopPJoystick - pressJoystick > longInterval && currentState == 1) {
        statePinA = LOW;
        statePinB = LOW;
        statePinC = LOW;
        statePinD = LOW;
        statePinE = LOW;
        statePinF = LOW;
        statePinG = LOW;
        statePinDP = LOW;
        currentSegmentPos = posDP;
      }
      else if (stopPJoystick - pressJoystick > smallInterval) {
        buttonPress = buttonPress + 1;
        if (buttonPress %2 == 0) {
          blinkState = LOW;
          currentState = 1;
        }
        else {
          blinkState = HIGH;
          currentState = 2;
        }
      }
    }
  }

  lastSwState = reading;

}

/*
  I used OY axis (left - HIGH, right - LOW)
  This function is available just in state 2.
*/
void state2Logic(){

  if (yValue > maxThreshold && currentState == 2 && joystickOY2 == LOW) {
    currentSegmentState = LOW;
    if (currentSegmentPos == posA) {
      statePinA = LOW;
    }

    else if (currentSegmentPos == posB) {
      statePinB = LOW;
    }

    else if (currentSegmentPos == posC) {
      statePinC = LOW;
    }

    else if (currentSegmentPos == posD) {
      statePinD = LOW;
    }

    else if (currentSegmentPos == posE) {
      statePinE = LOW;
    }

    else if (currentSegmentPos == posF) {
      statePinF = LOW;
    }

    else if (currentSegmentPos == posG) {
      statePinG = LOW;
    }

    else if (currentSegmentPos == posDP) {
      statePinDP = LOW;
    }
    joystickOY2 = HIGH;

  }
  else if (yValue < minThreshold && currentState == 2 && joystickOY2 == LOW){
    currentSegmentState = HIGH;
    if (currentSegmentPos == posA) {
      statePinA = HIGH;
 
    }

    else if (currentSegmentPos == posB) {
      statePinB = HIGH;

    }

    else if (currentSegmentPos == posC) {
      statePinC = HIGH;

    }

    else if (currentSegmentPos == posD) {
      statePinD = HIGH;

      
    }

    else if (currentSegmentPos == posE) {
      statePinE = HIGH;
    }

    else if (currentSegmentPos == posF) {
      statePinF = HIGH;
    }

    else if (currentSegmentPos == posG) {
      statePinG = HIGH;
    }

    else if (currentSegmentPos == posDP) {
      statePinDP = HIGH; 
    }
    joystickOY2 = HIGH;
  }
  else if (yValue > minThreshold && yValue < maxThreshold && currentState == 2 && joystickOY2 == HIGH) {
    joystickOY2 = LOW;
  }
}
void loop() {

  ledsState();
  blinking();

  xValue = analogRead(pinX);
  yValue = analogRead(pinY);

  neighbours();
  reading = digitalRead(pinSw);
  button();
  state2Logic();

}