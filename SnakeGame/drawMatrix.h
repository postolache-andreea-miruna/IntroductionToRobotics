//drawMatrix
#include "LedControl.h" 
const int dinPin = 12;
const int clockPin = 11;
const int loadPin = 10;


LedControl lc = LedControl(dinPin, clockPin, loadPin, 1);  // DIN, CLK,LOAD, No.DRIVER

// byte matrixBrightness = 2;

const byte matrixSize = 8;



const byte greetings[matrixSize][matrixSize] = {
  { 1, 1, 0, 0, 0, 0, 1, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 0, 0, 1, 0, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 1, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 1, 1, 0, 0 },
  { 1, 0, 1, 0, 1, 1, 0, 1 },
  { 1, 1, 0, 0, 0, 0, 1, 1 }
};

const byte game[matrixSize][matrixSize] = {
  { 1, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 0, 1, 1, 1, 1, 1, 0 },
  { 1, 0, 1, 0, 0, 0, 1, 0 },
  { 1, 0, 1, 0, 1, 0, 1, 0 },
  { 1, 0, 1, 1, 1, 0, 1, 0 },
  { 1, 0, 0, 0, 0, 0, 1, 0 },
  { 1, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

const byte crown[matrixSize][matrixSize] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 1, 0, 1, 1, 1, 0, 1, 0 },
  { 1, 1, 1, 1, 1, 1, 1, 0 },
  { 1, 1, 1, 1, 1, 1, 1, 0 },
  { 1, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

const byte setting[matrixSize][matrixSize] = {//settings
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
};
const byte setting2[matrixSize][matrixSize] = {//settings
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 1 },
  { 0, 0, 0, 0, 1, 1, 1, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
};

const byte setting4[matrixSize][matrixSize] = {//settings
  { 0, 0, 1, 0, 0, 0, 0, 0 },
  { 1, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 1, 0 },
  { 0, 0, 0, 1, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
};

const byte setting3[matrixSize][matrixSize] = {//settings
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 1, 0, 0, 0, 0, 1, 1 },
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 1, 1, 0, 0, 0, 0, 1, 1 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
};



const byte about[matrixSize][matrixSize] = { //about
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
};

const byte howToPlay[matrixSize][matrixSize] = { //how to play
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 1, 0, 0, 1, 0, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 1, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 0, 1, 0, 1, 0, 0, 1, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 },
};

const byte smile[matrixSize][matrixSize] = { //how to play
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 1, 0, 1, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 1, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 },
};

void matrixMessage(const byte matrix[matrixSize][matrixSize]) {
   /* Switch all Leds on the display off.
 * Params:
 *   addr The address of the display to control 
*/ 
  lc.clearDisplay(0); 
  for (int row = 0; row < matrixSize; row++) {
    for (int col = 0; col < matrixSize; col++) {
      lc.setLed(0, row, col, matrix[row][col]);
    }
  }
}