#include "drawMatrix.h"
#include "EEPROMMemo.h"
#include "joystickMoves.h"
#include "lcdComands.h"
#include "settingsMenu.h"
#include "Menu.h"
#include "miniGame.h"
#include "player.h"
#include "gameLogic.h"

void setup() {
 initialize();

  byte sounds = EEPROM.read(3);
  pinMode(pinSw, INPUT_PULLUP);
  if (sounds == 1) {
    sound = true;
  }
  else {
    sound = false;
  }

  contrastPosition = EEPROM.read(0);
  brightnessPosition = EEPROM.read(1);
  difficultyPosition = EEPROM.read(34);
  brightnessMatrixPosition = EEPROM.read(2);

//joystick
//lcd
  pinMode(contrastPin, OUTPUT);
  pinMode(brightPin, OUTPUT);

  lcd.begin(columnsLCD, rowsLCD);
  lcd.clear();
  lcd.setCursor(0, 0);
  
  lcd.createChar(0, heart);
  lcd.createChar(1, sadFace);
  lcd.createChar(2, smiley);
  lcd.createChar(3, doubleArrows);
  lcd.createChar(4, downArrow);
  lcd.createChar(5, upArrow);
  lcd.createChar(6,buttonPress);
//stop lcd
//matrix
  lc.shutdown(0, false);                 // turn off power saving, enables display
  lc.setIntensity(0, matrixBrightnessValue[brightnessMatrixPosition]);  // sets brightness (0~15 possible values)
  lc.clearDisplay(0);                    // clear screen
  analogWrite(brightPin, lcdBrightnessValue[brightnessPosition]);
  analogWrite(contrastPin, lcdContrastValue[contrastPosition]);
//stopMatrix

//stopjoystick
  greeting();
  menuPart();
  Serial.begin(9600);
}

void loop() {
  gameStates();
  //Serial.println(settingPartPosition);

}
