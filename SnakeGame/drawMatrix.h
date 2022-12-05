//drawMatrix
#include "LedControl.h" 
const int dinPin = 12;
const int clockPin = 11;
const int loadPin = 10;


LedControl lc = LedControl(dinPin, clockPin, loadPin, 1);  // DIN, CLK,LOAD, No.DRIVER

// byte matrixBrightness = 2;

const byte matrixSize = 8;



// const byte greetings[matrixSize][matrixSize] = {
//   { 1, 1, 0, 0, 0, 0, 1, 1 },
//   { 1, 0, 0, 0, 0, 0, 0, 1 },
//   { 0, 0, 1, 0, 1, 1, 0, 0 },
//   { 0, 0, 1, 0, 1, 0, 0, 0 },
//   { 0, 0, 1, 1, 1, 1, 0, 0 },
//   { 0, 0, 1, 0, 1, 1, 0, 0 },
//   { 1, 0, 1, 0, 1, 1, 0, 1 },
//   { 1, 1, 0, 0, 0, 0, 1, 1 }
// };

// const byte game[matrixSize][matrixSize] = {
//   { 1, 0, 0, 0, 0, 0, 0, 0 },
//   { 1, 0, 1, 1, 1, 1, 1, 0 },
//   { 1, 0, 1, 0, 0, 0, 1, 0 },
//   { 1, 0, 1, 0, 1, 0, 1, 0 },
//   { 1, 0, 1, 1, 1, 0, 1, 0 },
//   { 1, 0, 0, 0, 0, 0, 1, 0 },
//   { 1, 1, 1, 1, 1, 1, 1, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 }
// };

// const byte crown[matrixSize][matrixSize] = {
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 0, 0, 0, 1, 0, 0, 0, 0 },
//   { 1, 0, 1, 1, 1, 0, 1, 0 },
//   { 1, 1, 1, 1, 1, 1, 1, 0 },
//   { 1, 1, 1, 1, 1, 1, 1, 0 },
//   { 1, 1, 1, 1, 1, 1, 1, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 }
// };

// const byte setting[matrixSize][matrixSize] = {//settings
//   { 0, 0, 1, 0, 0, 1, 0, 0 },
//   { 0, 0, 1, 0, 0, 1, 0, 0 },
//   { 0, 0, 0, 1, 1, 0, 0, 0 },
//   { 0, 0, 0, 1, 1, 0, 0, 0 },
//   { 0, 0, 0, 1, 1, 0, 0, 0 },
//   { 0, 0, 0, 1, 1, 0, 0, 0 },
//   { 0, 0, 1, 0, 0, 1, 0, 0 },
//   { 0, 0, 1, 0, 0, 1, 0, 0 },
// };
// const byte setting2[matrixSize][matrixSize] = {//settings
//   { 0, 0, 0, 0, 0, 1, 0, 0 },
//   { 0, 0, 0, 0, 1, 0, 0, 1 },
//   { 0, 0, 0, 0, 1, 1, 1, 0 },
//   { 0, 0, 0, 1, 1, 0, 0, 0 },
//   { 0, 1, 1, 1, 0, 0, 0, 0 },
//   { 0, 1, 0, 0, 1, 0, 0, 0 },
//   { 0, 0, 0, 1, 0, 0, 0, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
// };

// const byte setting4[matrixSize][matrixSize] = {//settings
//   { 0, 0, 1, 0, 0, 0, 0, 0 },
//   { 1, 0, 0, 1, 0, 0, 0, 0 },
//   { 0, 1, 1, 1, 0, 0, 0, 0 },
//   { 0, 0, 0, 1, 1, 0, 0, 0 },
//   { 0, 0, 0, 0, 1, 1, 1, 0 },
//   { 0, 0, 0, 1, 0, 0, 1, 0 },
//   { 0, 0, 0, 0, 1, 0, 0, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
// };

// const byte setting3[matrixSize][matrixSize] = {//settings
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 1, 1, 0, 0, 0, 0, 1, 1 },
//   { 0, 0, 1, 1, 1, 1, 0, 0 },
//   { 0, 0, 1, 1, 1, 1, 0, 0 },
//   { 1, 1, 0, 0, 0, 0, 1, 1 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
// };



// const byte about[matrixSize][matrixSize] = { //about
//   { 0, 0, 0, 1, 1, 1, 0, 0 },
//   { 0, 0, 0, 1, 0, 1, 0, 0 },
//   { 0, 0, 0, 1, 0, 0, 0, 0 },
//   { 0, 0, 0, 0, 1, 0, 0, 0 },
//   { 0, 0, 0, 0, 1, 0, 0, 0 },
//   { 0, 0, 0, 0, 1, 0, 0, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 0, 0, 0, 0, 1, 0, 0, 0 },
// };

// const byte howToPlay[matrixSize][matrixSize] = { //how to play
//   { 0, 0, 1, 1, 1, 1, 0, 0 },
//   { 0, 1, 0, 0, 0, 0, 1, 0 },
//   { 1, 0, 0, 1, 0, 0, 0, 1 },
//   { 1, 0, 0, 1, 1, 0, 0, 1 },
//   { 1, 0, 0, 1, 1, 1, 0, 1 },
//   { 1, 0, 0, 1, 1, 0, 0, 1 },
//   { 0, 1, 0, 1, 0, 0, 1, 0 },
//   { 0, 0, 1, 1, 1, 1, 0, 0 },
// };

// const byte smile[matrixSize][matrixSize] = { //how to play
//   { 0, 0, 1, 1, 1, 1, 0, 0 },
//   { 0, 1, 0, 0, 0, 0, 1, 0 },
//   { 1, 0, 1, 0, 0, 1, 0, 1 },
//   { 1, 0, 0, 0, 0, 0, 0, 1 },
//   { 1, 0, 1, 0, 0, 1, 0, 1 },
//   { 1, 0, 0, 1, 1, 0, 0, 1 },
//   { 0, 1, 0, 0, 0, 0, 1, 0 },
//   { 0, 0, 1, 1, 1, 1, 0, 0 },
// };

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
// const byte setting2[matrixSize] = {//settings
//   0b00000100,
//   0b00001001,
//   0b00001110,
//   0b00011000,
//   0b01110000,
//   0b01001000,
//   0b00010000,
//   0b00000000,
// };

// const byte setting4[matrixSize] = {//settings
//   0b00100000,
//   0b10010000,
//   0b01110000,
//   0b00011000,
//   0b00001110,
//   0b00010010,
//   0b00001000,
//   0b00000000,
// };

// const byte setting3[matrixSize] = {//settings
//   0b00000000,
//   0b00000000,
//   0b11000011,
//   0b00111100,
//   0b00111100,
//   0b11000011,
//   0b00000000,
//   0b00000000,
// };




const byte about[matrixSize] = { //about
  0b00011100,
  0b00010100,
  0b00010000,
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
   /* Switch all Leds on the display off.
 * Params:
 *   addr The address of the display to control 
*/ 
  // lc.clearDisplay(0); 
  // for (int row = 0; row < matrixSize; row++) {
  //   for (int col = 0; col < matrixSize; col++) {
  //     lc.setLed(0, row, col, matrix[row][col]);
  //   }
  // }
  lc.clearDisplay(0); 
  for (int row = 0; row < matrixSize; row++) {
    for (int col = 0; col < matrixSize; col++) {
      lc.setLed(0, row, col, (matrix[row] >> col) & 1);
    }
  }
}