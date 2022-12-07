//drawMatrix
#include "LedControl.h" 
const int dinPin = 12;
const int clockPin = 11;
const int loadPin = 10;

LedControl lc = LedControl(dinPin, clockPin, loadPin, 1);  // DIN, CLK,LOAD, No.DRIVER

const byte matrixSize = 8;

const byte greetings[matrixSize] = {
  0b11000011,
  0b10000001,
  0b00101100,
  0b00101000,
  0b00111100,
  0b00101100,
  0b10101101,
  0b11000011
};

const byte game[matrixSize] = {
  0b10000000,
  0b10111110,
  0b10100010,
  0b10101010,
  0b10111010,
  0b10000010,
  0b11111110,
  0b00000000
};

const byte crown[matrixSize] = {
  0b00000000,
  0b00010000,
  0b10111010,
  0b11111110,
  0b11111110,
  0b11111110,
  0b00000000,
  0b00000000
};

const byte setting[matrixSize] = {//settings
  0b00100100,
  0b00100100,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00100100,
  0b00100100,
};

const byte about[matrixSize] = { //about
  0b00011100,
  0b00010100,
  0b00000100,
  0b00001000,
  0b00001000,
  0b00001000,
  0b00000000,
  0b00001000,
};

const byte howToPlay[matrixSize] = { //how to play
  0b00111100,
  0b01000010,
  0b10010001,
  0b10011001,
  0b10011101,
  0b10011001,
  0b01010010,
  0b00111100,
};

const byte smile[matrixSize] = { //how to play
  0b00111100,
  0b01000010,
  0b10100101,
  0b10000001,
  0b10100101,
  0b10011001,
  0b01000010,
  0b00111100,
};

void matrixMessage(const byte matrix[matrixSize]) {
  lc.clearDisplay(0);
  for (int row = 0; row < matrixSize; row++) {
    lc.setRow(0, row, matrix[row]); 
  }
}