const int pinX = A0;
const int pinY = A1;
const int pinSw = 2;

int xValue = 0;
int yValue = 0;

const int minThreshold = 400;
const int maxThreshold = 700;

byte reading = HIGH;

bool startGame = false;

bool joystickUp() {
  xValue = analogRead(pinX);
  if (xValue > maxThreshold) {
    Serial.println("up");
    return true;
  }
  else if (xValue < minThreshold || (xValue <= maxThreshold && xValue >= minThreshold)) {
    return false;
  }
}


bool joystickDown() {
  xValue = analogRead(pinX);
  if (xValue < minThreshold ) {
    Serial.println("down");
    return true;

  }
  else if ( xValue > maxThreshold || (xValue <= maxThreshold && xValue >= minThreshold))
  {
    return false;
  }
}


bool joystickLeft() {
  yValue = analogRead(pinY);
  if (yValue < minThreshold ) {
   Serial.println("left");
    return true;
  }
  else if ( yValue > maxThreshold || (yValue <= maxThreshold && yValue >= minThreshold))
  {
    return false;
  }
}

bool joystickRight() {
  yValue = analogRead(pinY);
  if (yValue > maxThreshold) {
    Serial.println("right");
    return true;
  }
  else if (yValue < minThreshold || (yValue <= maxThreshold && yValue >= minThreshold)) {
    return false;
  }
}

bool joystickPress() {
  reading = digitalRead(pinSw);
  
  if (reading == LOW) {
    Serial.println("preeeeesss");
    return true;
  } 
  else {
    return false;
  }
}

