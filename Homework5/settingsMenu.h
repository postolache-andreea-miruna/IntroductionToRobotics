const int totalSettingsParts = 7;
String const settingsParts[totalSettingsParts] = { "DIFFICULTY", "LCD CONTRAST", "LCD BRIGHT", "MATRIX BRIGHT", "SOUNDS", "RESET HS", "BACK TO MENU" };
int settingPartPosition = 0;
const int firstSettingPosition = 0;
const int lastSettingPosition = 6;

const int totalDifficultyTypes = 3;
String const difficulty[totalDifficultyTypes] = { "EASY", "MEDIUM", "HARD" };
int difficultyPosition = 0;
const int firstDifficultyPosition = 0;
const int lastDifficultyPosition = 2;

bool state1Setting = false;  //settings with 5 SettingsParts
bool state2Setting = false;  //menu for Parts of the settings

//contrast lcd
const byte totalContrastValues = 4;
int const lcdContrastValue[totalContrastValues] = { 5, 10, 30, 50 };
int contrastPosition = 0;
const byte firstContrastPosition = 0;
const byte lastContrastPosition = 3;
//brightness lcd
const byte totalBrightnessValues = 4;
int const lcdBrightnessValue[totalBrightnessValues] = { 100, 150, 200, 255 };
int brightnessPosition = 0;
const byte firstBrightnessPosition = 0;
const byte lastBrightnessPosition = 3;


const int totalBrightnessMatrixValues = 4;
int const matrixBrightnessValue[totalBrightnessMatrixValues] = { 4, 6, 8, 12 };
int brightnessMatrixPosition = 0;
const int firstBrightnessMatrixPosition = 0;
const int lastBrightnessMatrixPosition = 3;

void settingPart() {
  state1Setting = true;
  state2Setting = false;

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Settings");

  lcd.setCursor(0, 1);
  lcd.print(">");
  lcd.print(settingsParts[settingPartPosition]);

  lcd.setCursor(14, 1);
  if (settingPartPosition == 0) {
    scroll();
    lcd.write(byte(4));
  } 
  else if (settingPartPosition == 1) {
    scroll();
    lcd.write(byte(3));
  } 
  else if (settingPartPosition == 2) {
    scroll();
    lcd.write(byte(3));
  } 
  else if (settingPartPosition == 3) {
    scroll();
    lcd.write(byte(3));
  } 
  else if (settingPartPosition == 4) {
    scroll();
    lcd.write(byte(3));
  } 
  else if (settingPartPosition == 5) {//reset highscore
    scroll();
    lcd.setCursor(10,1);
    lcd.print("PRESS");
    lcd.setCursor(15, 1);
    lcd.write(byte(3));
  }
  else if (settingPartPosition == 6) { //back to menu
    scroll();
    lcd.setCursor(0, 1);
    lcd.print("<");
    lcd.setCursor(1, 1);
    lcd.print(settingsParts[settingPartPosition]);
    lcd.setCursor(14, 1);
    lcd.write(byte(4));
  }
}

void saveToMemory() {

  if (settingPartPosition == 0) {  //difficulty
    EEPROM.update(34, difficultyPosition);
  } 
  else if (settingPartPosition == 1) {  //lcdContrast
    EEPROM.update(0, contrastPosition);
  } 
  else if (settingPartPosition == 2) {  //lcd bright
    EEPROM.update(1, brightnessPosition);
  } 
  else if (settingPartPosition == 3) {  //matrix bright
    EEPROM.update(2, brightnessMatrixPosition);
  } 
  else if (settingPartPosition == 4) {  //sound
    if (sound == true) {
      EEPROM.update(3, 1);
    } 
    else {
      EEPROM.update(3, 0);
    }
  }
}

void difficulties() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TYPE: ");
  lcd.setCursor(6, 0);
  lcd.print(difficulty[difficultyPosition]);
  if (difficultyPosition == 0) 
    lcd.write(byte(4));
  else if (difficultyPosition == 1) 
    lcd.write(byte(3));
  else if (difficultyPosition == 2) 
    lcd.write(byte(5));
  lcd.setCursor(0, 1);
  lcd.print("EXIT< OR");
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
  lcd.print("TO SAVE");
}

void difficultyMenu() {
  difficulties();
  if (joystickUp() && state2Setting == true) {
    difficultyPosition--;
    if (difficultyPosition < firstDifficultyPosition) {
      difficultyPosition = firstDifficultyPosition;
    }
    difficulties();
  }

  if (joystickDown() && state2Setting == true) {
    difficultyPosition++;
    if (difficultyPosition > lastDifficultyPosition) {
      difficultyPosition = lastDifficultyPosition;
    }
    difficulties();
  }
  if (joystickLeft() && state2Setting == true) {
    settingPart();
  }
  if (joystickPress() && state2Setting == true) {
    saveToMemory();
    settingPart();
  }
}

void contrastLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LCDContrast ");

  analogWrite(contrastPin, lcdContrastValue[contrastPosition]);
  lcd.setCursor(13, 0);
  lcd.print(lcdContrastValue[contrastPosition]);

  if (contrastPosition == 0) 
    lcd.write(byte(4));
  else if (contrastPosition == 1) 
    lcd.write(byte(3));
  else if (contrastPosition == 2) 
    lcd.write(byte(3));
  else if (contrastPosition == 3) 
    lcd.write(byte(5));

  lcd.setCursor(0, 1);
  lcd.print("EXIT< OR");
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
  lcd.print("TO SAVE");
}

void contrastMenu() {
  contrastLCD();
  if (joystickUp() && state2Setting == true) {
    contrastPosition--;
    if (contrastPosition < firstContrastPosition) {
      contrastPosition = firstContrastPosition;
    }
    contrastLCD();
  }

  if (joystickDown() && state2Setting == true) {
    contrastPosition++;
    if (contrastPosition > lastContrastPosition) {
      contrastPosition = lastContrastPosition;
    }
    contrastLCD();
  }
  if (joystickLeft() && state2Setting == true) {
    settingPart();
  }
  if (joystickPress() && state2Setting == true) {
    saveToMemory();
    settingPart();
  }
}

void brightLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LCDBright ");

  analogWrite(brightPin, lcdBrightnessValue[brightnessPosition]);
  lcd.setCursor(12, 0);
  lcd.print(lcdBrightnessValue[brightnessPosition]);

  if (brightnessPosition == 0) 
    lcd.write(byte(4));
  else if (brightnessPosition == 1) 
    lcd.write(byte(3));
  else if (brightnessPosition == 2) 
    lcd.write(byte(3));
  else if (brightnessPosition == 3) 
    lcd.write(byte(5));

  lcd.setCursor(0, 1);
  lcd.print("EXIT< OR");
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
  lcd.print("TO SAVE");
}

void brightLCDMenu() {
  brightLCD();
  if (joystickUp() && state2Setting == true) {
    brightnessPosition--;
    if (brightnessPosition < firstBrightnessPosition) {
      brightnessPosition = firstBrightnessPosition;
    }
    brightLCD();
  }

  if (joystickDown() && state2Setting == true) {
    brightnessPosition++;
    if (brightnessPosition > lastBrightnessPosition) {
      brightnessPosition = lastBrightnessPosition;
    }
    brightLCD();
  }
  if (joystickLeft() && state2Setting == true) {
    settingPart();
  }
  if (joystickPress() && state2Setting == true) {
    saveToMemory();
    settingPart();
  }
}

void brightMatrix() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Matrix bright");
  if (brightnessMatrixPosition == 0) 
    lcd.write(byte(4));
  else if (brightnessMatrixPosition == 1) 
    lcd.write(byte(3));
  else if (brightnessMatrixPosition == 2) 
    lcd.write(byte(3));
  else if (brightnessMatrixPosition == 3) 
    lcd.write(byte(5));
  lc.setIntensity(0, matrixBrightnessValue[brightnessMatrixPosition]);
  lcd.print(matrixBrightnessValue[brightnessMatrixPosition]);

  lcd.setCursor(0, 1);
  lcd.print("EXIT< OR");
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
  lcd.print("TO SAVE");
}

void brightMatrixMenu() {
  brightMatrix();
  if (joystickUp() && state2Setting == true) {
    brightnessMatrixPosition--;
    if (brightnessMatrixPosition < firstBrightnessMatrixPosition) {
      brightnessMatrixPosition = firstBrightnessMatrixPosition;
    }
    brightMatrix();
  }

  if (joystickDown() && state2Setting == true) {
    brightnessMatrixPosition++;
    if (brightnessMatrixPosition > lastBrightnessMatrixPosition) {
      brightnessMatrixPosition = lastBrightnessMatrixPosition;
    }
    brightMatrix();
  }
  if (joystickLeft() && state2Setting == true) {
    settingPart();
  }
  if (joystickPress() && state2Setting == true) {
    saveToMemory();
    settingPart();
  }
}
void sounds() {
  lcd.clear();
  lcd.setCursor(8, 0);
  if (sound == true) {
    lcd.print("ON");
    lcd.write(byte(4));
  } 
  else {
    lcd.print("OFF");
    lcd.write(byte(5));
  }
  

  lcd.setCursor(0, 1);
  lcd.print("EXIT< OR");
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
  lcd.print("TO SAVE");
}

void soundMenu() {
  sounds();
  if (joystickUp() || joystickDown()) {
    sound = !sound;
    sounds();
  }
  if (joystickLeft() && state2Setting == true) {
    settingPart();
  }
  if (joystickPress() && state2Setting == true) {
    saveToMemory();
    settingPart();
  }
}

void settingsCommandsSwitch() {
  state1Setting = false;
  state2Setting = true;

  if (settingPartPosition == 0) {
    scroll();
    difficultyMenu();
  }
  else if (settingPartPosition == 1) {
    scroll();
    contrastMenu();
  }
  else if (settingPartPosition == 2) {
    scroll();
    brightLCDMenu();
  } 
  else if (settingPartPosition == 3) {
    scroll();
    brightMatrixMenu();
  } 
  else if (settingPartPosition == 4) {
    scroll();
    soundMenu();
  }
}

void scrollSettings() {
  if (joystickUp() && state2Setting == false) {
    settingPartPosition--;
    if (firstSettingPosition > settingPartPosition) {
      settingPartPosition = firstSettingPosition;
    }
    settingPart();
  } 
  else if (joystickDown() && state2Setting == false) {
    settingPartPosition++;
    if (lastSettingPosition < settingPartPosition) {
      settingPartPosition = lastSettingPosition;
    }
    settingPart();
  } 
}