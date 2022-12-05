byte xPos = 0;
byte yPos = 0;
byte xLastPos = 0;
byte yLastPos = 0;
unsigned long previousMillis2 = 0;
const byte moveInterval = 100;
unsigned long long lastMoved = 0;

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
  { 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};


void updateMatrix() {
  for (int row = 0; row < matrixSize; row++) {
    for (int col = 0; col < matrixSize; col++) {
      lc.setLed(0, row, col, matrix[row][col]);
    }
  }
}


void foodBlink() {
  matrix[currentPosX][currentPosY] = !matrix[currentPosX][currentPosY];
  matrixChanged = true;
}
// theoretical example
void generateFood() {
  lastFoodPosX = currentPosX;
  lastFoodPosY = currentPosY;

  newFoodPosX = random(minValue, maxValue);
  newFoodPosY = random(minValue, maxValue);

  while (newFoodPosX == xPos && newFoodPosY == yPos) {
    newFoodPosX = random(minValue, maxValue);
    newFoodPosY = random(minValue, maxValue);
  }

  matrix[newFoodPosX][newFoodPosY] = 1;
  matrix[lastFoodPosX][lastFoodPosY] = 0;
  matrix[xPos][yPos] = 1;  // we want to keep the player dot active

  currentPosX = newFoodPosX;
  currentPosY = newFoodPosY;

  matrixChanged = true;
}

void updatePositions() {
  xLastPos = xPos;
  yLastPos = yPos;
  if (joystickDown()) {
    if (xPos < matrixSize - 1) {
      xPos++;
    } else {
      xPos = 0;
    }
  }
  if (joystickUp()) {
    if (xPos > 0) {
      xPos--;
    } else {
      xPos = matrixSize - 1;
    }
  }
  if (joystickRight()) {
    if (yPos < matrixSize - 1) {
      yPos++;
    } else {
      yPos = 0;
    }
  }
  if (joystickLeft()) {
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
void setupGame()
{if (millis() - lastMoved > moveInterval) {
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
  scorePrint(score);
  // if (score == 10) {
  //   congratsScreen(score);                               //congrats screen
  // }
 // Serial.println(score);
  generateFood();
}

if (matrixChanged == true) {
  // matrix display logi
  updateMatrix();
  matrixChanged = false;
}}

