const int latchPin = 11;  // STCP
const int clockPin = 10;  // SHCP
const int dataPin = 12;   // DS

const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;

const byte regSize = 8;  

const int displayCount = 4;
int displayDigits[displayCount] = {
  segD1, segD2, segD3, segD4
};

const int encodingsNumber = 16;
int byteEncodings[encodingsNumber] = {
  //A B C D E F G DP
  B11111100,  // 0
  B01100000,  // 1
  B11011010,  // 2
  B11110010,  // 3
  B01100110,  // 4
  B10110110,  // 5
  B10111110,  // 6
  B11100000,  // 7
  B11111110,  // 8
  B11110110,  // 9
  B11101110,  // A
  B00111110,  // b
  B10011100,  // C
  B01111010,  // d
  B10011110,  // E
  B10001110   // F
};


//joystick
const int pinX = A0;
const int pinY = A1;
const int pinSw = 2;

int xValue = 0;
int yValue = 0;

const int minThreshold = 400;
const int maxThreshold = 600;

int pressJoystick = 0;
int stopPJoystick = 0;

bool moveJoyX = false;
bool moveJoyY = false;

byte swState = HIGH;
byte lastSwState = HIGH;
byte reading = LOW;
unsigned long lastDebounceTime = 0;
const int debounceInterval = 50;
const int longInterval = 5000;  //5s
const int smallInterval = 50;

unsigned long currentMillis;
unsigned long previousMillis = 0;
unsigned long previousMillisBlink = 0;
const unsigned long interval = 1000;  // interval at which to blink
const unsigned long intervalBlink = 400;

int digitsOfDesplay[displayCount] = { //the values that are on the display 0,1,2,3
  0, 0, 0, 0
};

int buttonPress = 0;
int currentState = 1;
int currentDisplay = 0; //the right most

void setup() {
  pinMode(pinSw, INPUT_PULLUP);

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  for (int i = 0; i < displayCount; i++) {
    pinMode(displayDigits[i], OUTPUT);
    digitalWrite(displayDigits[i], LOW);
  }

  Serial.begin(9600);
}


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

      if (stopPJoystick - pressJoystick > longInterval && currentState == 1) { //restart
        digitsOfDesplay[0] = 0;
        digitsOfDesplay[1] = 0;
        digitsOfDesplay[2] = 0;
        digitsOfDesplay[3] = 0;
        currentDisplay = 0;
      } 
      else if (stopPJoystick - pressJoystick > smallInterval) {
        buttonPress = buttonPress + 1;
        if (buttonPress % 2 == 0) {
          currentState = 1;
        } 
        else {
          currentState = 2;
        }
      }
    }
  }
  lastSwState = reading;
}

/*
  In state 1 I can move on OY axis: min == left, max == right
*/
void moveState1() {
  if (currentState == 1) {
    if (yValue > maxThreshold && moveJoyY == false) {
      moveJoyY = true;
      if (currentDisplay > 0) {
        currentDisplay = currentDisplay - 1;  //if we go with joystick to the right then the display number will go from high to low  
      }
      //if the current display is 0 then nothing happens when we go with joystick to the right
    }

    if (yValue < minThreshold && moveJoyY == false) {
      moveJoyY = true;
      if (currentDisplay < displayCount - 1) {
        currentDisplay = currentDisplay + 1;  //if we go with joystick to the left then the display number will go from low to high 
      }
      //if the current display is 3 then nothing happens when we go with joy left
    }

    if (yValue >= minThreshold && yValue <= maxThreshold && moveJoyY == true) {
      moveJoyY = false;
    }
  }
}

/*
  On state 2 I can move on OX axis: min == down, max == up
  Joystick up => increment
  Joystick down => decrement
*/
void moveState2() {
  if (currentState == 2) {
    if (xValue > maxThreshold && moveJoyX == false) {
      moveJoyX = true;
      if (digitsOfDesplay[currentDisplay] < encodingsNumber - 1) {
        digitsOfDesplay[currentDisplay]++;  
      }
    }

    if (xValue < minThreshold && moveJoyX == false) {
      moveJoyX = true;
      if (digitsOfDesplay[currentDisplay] > 0) {
        digitsOfDesplay[currentDisplay]--;
      }
    }

    if (xValue >= minThreshold && xValue <= maxThreshold && moveJoyX == true) {
      moveJoyX = false;
    }
  }
}

/*
  Write the character on the currentDisplay which must be active.
*/
void characterWrite(int currentDisplay) {
  for (int i=0; i < displayCount; i++) {
    int digit = 0;
    
    if (i == currentDisplay) {
      if (currentState == 2) {
        digit = byteEncodings[digitsOfDesplay[i]] + 1; //decimal point is on
      }
      else if (currentState == 1) {
        digit = byteEncodings[digitsOfDesplay[i]];
        if (millis() - previousMillisBlink > interval) {
          digit = byteEncodings[digitsOfDesplay[i]] + 1; //decimal point blinks
        }

        if (millis() - previousMillisBlink > interval+intervalBlink) {
          previousMillisBlink = millis();
          digit = byteEncodings[digitsOfDesplay[i]]; //decimal point stop blink
        }
      }
    }
    else {
      digit = byteEncodings[digitsOfDesplay[i]];  //digits stay at it value
    }
    writeReg(digit);
    activateDisplay(i);
    delay(3);
  }
}

void writeReg(int encoding) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, encoding);
  digitalWrite(latchPin, HIGH);
}

void activateDisplay(int displayNumber) {
  for (int i = 0; i < displayCount; i++) {
    digitalWrite(displayDigits[i], HIGH); // turn off all the displays
  }
  digitalWrite(displayDigits[displayNumber], LOW); // activate the display I want to use
}

void loop() {
  xValue = analogRead(pinX);
  yValue = analogRead(pinY);
  reading = digitalRead(pinSw);
  button();
  moveState1();
  moveState2();
  characterWrite(currentDisplay);
}