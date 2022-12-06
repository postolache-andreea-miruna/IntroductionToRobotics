const int totalSettingsParts = 6;
String const settingsParts[totalSettingsParts] = { "DIFFICULTY", "LCD CONTRAST", "LCD BRIGHT", "MATRIX BRIGHT", "SOUNDS", "BACK" };
int settingPartPosition = 0;
const int firstSettingPosition = 0;
const int lastSettingPosition = 5;

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
int const lcdBrightnessValue[totalBrightnessValues] = { 255, 200, 150, 100 };
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
  lcd.setCursor(5, 0);
  lcd.print("Settings");

  lcd.setCursor(0, 1);
  lcd.print(">");
  lcd.print(settingsParts[settingPartPosition]);

  lcd.setCursor(14, 1);
  if (settingPartPosition == 0) {
    lcd.write(byte(4));
  } 
  else if (settingPartPosition == 1) {
    lcd.write(byte(3));
  } 
  else if (settingPartPosition == 2) {
    lcd.write(byte(3));
  } 
  else if (settingPartPosition == 3) {
    lcd.write(byte(3));
  } 
  else if (settingPartPosition == 4) {
    lcd.write(byte(3));
  } 
  else if (settingPartPosition == 5) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Settings");
    lcd.setCursor(0, 1);
    lcd.print("<");
    lcd.setCursor(1, 1);
    lcd.print(settingsParts[settingPartPosition]);
    lcd.setCursor(14, 1);
    lcd.write(byte(5));
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
  lcd.setCursor(3, 1);
  lcd.print("EXIT");
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
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

  lcd.setCursor(3, 1);
  lcd.print("EXIT");
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
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
  lcd.setCursor(13, 0);
  lcd.print(lcdBrightnessValue[brightnessPosition]);

  lcd.setCursor(3, 1);
  lcd.print("EXIT");
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
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
  lcd.print("Matrix bright ");
  lc.setIntensity(0, matrixBrightnessValue[brightnessMatrixPosition]);
  lcd.print(matrixBrightnessValue[brightnessMatrixPosition]);

  lcd.setCursor(3, 1);
  lcd.print("EXIT");
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
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
  lcd.setCursor(0, 0);
  if (sound == true) {
    lcd.print("ON");
  } 
  else 
    lcd.print("OFF");

  lcd.setCursor(3, 1);
  lcd.print("EXIT");
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
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
    //delay(100);
    difficultyMenu();
  }
  else if (settingPartPosition == 1) {
    contrastMenu();
  }
  else if (settingPartPosition == 2) {
    brightLCDMenu();
  } 
  else if (settingPartPosition == 3) {
    brightMatrixMenu();
  } 
  else if (settingPartPosition == 4) {
    soundMenu();
  }
}

void scrollSettings() {
  //settingPart();
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
  else if (joystickRight() && state1Setting == true && settingPartPosition != 5) {

    settingsCommandsSwitch();
  }
  // else if (joystickPress() && state2Setting == true) { //if I press then I save
  //   saveToMemory();
  //   settingPart(); //i return to the initial setting menu
  // }
  // else if (joystickLeft() && state2Setting == true) { //if i do not press then I do not save
  //   settingPart(); //i return to the initial setting menu
  // }
}