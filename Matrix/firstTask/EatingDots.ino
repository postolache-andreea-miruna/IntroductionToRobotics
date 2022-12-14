#include "LedControl.h" 
const int dinPin = 12;
const int clockPin = 11;
const int loadPin = 10;

const int xPin = A0;
const int yPin = A1;

LedControl lc = LedControl(dinPin, clockPin, loadPin, 1);  // DIN, CLK,LOAD, No.DRIVER

byte matrixBrightness = 2;

byte xPos = 0;
byte yPos = 0;
byte xLastPos = 0;
byte yLastPos = 0;

const int minThreshold = 200;
const int maxThreshold = 600;

const byte moveInterval = 100;
unsigned long long lastMoved = 0;

const byte matrixSize = 8;
bool matrixChanged = true;

//food
byte lastFoodPosX;
byte lastFoodPosY;

byte newFoodPosX;
byte newFoodPosY;

byte currentPosX = 0;
byte currentPosY = 5;

//random interval
const int minValue = 0;
const int maxValue = 8;

int score = 0;

const int blinkInterval = 200;
unsigned long lastBlink;


byte matrix[matrixSize][matrixSize] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

void setup() {
  Serial.begin(9600);
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0, false);                 // turn off power saving, enables display
  lc.setIntensity(0, matrixBrightness);  // sets brightness (0~15 possible values)
  lc.clearDisplay(0);                    // clear screen
  matrix[xPos][yPos] = 1;
}
void loop() {

  if (millis() - lastMoved > moveInterval) {
    // game logic
    updatePositions();
    lastMoved = millis();
  }

  if (millis() - lastBlink > blinkInterval) {
    // game logic
    foodBlink();
    lastBlink = millis();
  }

  if (currentPosX == xPos && currentPosY == yPos) {
    score++;
    Serial.println(score);
    generateFood();
  }

  if (matrixChanged == true) {
    // matrix display logi
    updateMatrix();
    matrixChanged = false;
  }

}
void foodBlink(){
  matrix[currentPosX][currentPosY] = !matrix[currentPosX][currentPosY];
  matrixChanged = true;
}
// theoretical example
void generateFood() {
  lastFoodPosX = currentPosX;
  lastFoodPosY = currentPosY;

  newFoodPosX = random(minValue,maxValue); 
  newFoodPosY = random(minValue,maxValue);

  while (newFoodPosX == xPos && newFoodPosY == yPos){
    newFoodPosX  = random(minValue, maxValue);
    newFoodPosY  = random(minValue, maxValue);
  }
  
  matrix[newFoodPosX][newFoodPosY] = 1;
  matrix[lastFoodPosX][lastFoodPosY] = 0;
  matrix[xPos][yPos] = 1; // we want to keep the player dot active

  currentPosX = newFoodPosX;
  currentPosY = newFoodPosY;
  
  matrixChanged = true;
}


void updateMatrix() {
  for (int row = 0; row < matrixSize; row++) {
    for (int col = 0; col < matrixSize; col++) {
      lc.setLed(0, row, col, matrix[row][col]);
    }
  }
}
void updatePositions() {
  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);
  xLastPos = xPos;
  yLastPos = yPos;
  if (xValue < minThreshold) {
    if (xPos < matrixSize - 1) {
      xPos++;
    } else {
      xPos = 0;
    }
  }
  if (xValue > maxThreshold) {
    if (xPos > 0) {
      xPos--;
    } else {
      xPos = matrixSize - 1;
    }
  }
  if (yValue > maxThreshold) {
    if (yPos < matrixSize - 1) {
      yPos++;
    } else {
      yPos = 0;
    }
  }
  if (yValue < minThreshold) {
    if (yPos > 0) {
      yPos--;
    } else {
      yPos = matrixSize - 1;
    }
  }
  if (xPos != xLastPos || yPos != yLastPos) {
    matrixChanged = true;
    matrix[xLastPos][yLastPos] = 0;
    matrix[xPos][yPos] = 1;
  }
}