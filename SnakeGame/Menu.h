const int totalMeniuParts = 5;
const String menuParts[totalMeniuParts] = { "START GAME", "HIGH SCORE", "SETTINGS", "ABOUT", "HOW TO PLAY" };
int menuPartPosition = 0;
const int firstMenuPosition = 0;
const int lastMenuPosition = 4;

int person = 0;
const int firstPerson = 0;
const int lastPerson = 5;

int details = 0;
const int firstDetail = 0;
const int lastDetail = 3;

unsigned long previousMillis = 0;


bool state1Menu = false;  //menu with 5 menuParts
bool state2Menu = false;  //menu for Parts of the menu

void menuPart() {  //menu with 5 menuParts
  state1Menu = true;
  state2Menu = false;
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("Menu");

  lcd.setCursor(1, 1);
  lcd.print(">");
  lcd.print(menuParts[menuPartPosition]);

  lcd.setCursor(14, 1);
  if (menuPartPosition == 0) {
    lcd.write(byte(4));
    matrixMessage(game);
  } else if (menuPartPosition == 1) {
    lcd.write(byte(3));
    matrixMessage(crown);
  } else if (menuPartPosition == 2) {
    lcd.write(byte(3));
    matrixMessage(setting);
  } else if (menuPartPosition == 3) {
    lcd.write(byte(3));
    matrixMessage(about);
  } else if (menuPartPosition == 4) {
    lcd.write(byte(5));
    matrixMessage(howToPlay);
  }
}


//////////////////////////////
void startGameMenu() {                       //startGame = true !
  lcd.clear();                                
  lcd.setCursor(4, 0);
  lcd.print("START GAME");
  matrixMessage(howToPlay);
  delay(menuDelay);
  startGame = true;
}

void startPlayGame() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SCORE ");
  lcd.print(0);
  lcd.setCursor(10,0);
  lcd.print("HS ");
  lcd.print(EEPROM.read(4));

  lcd.setCursor(0,1);
  lcd.print("LEVEL ");
  lcd.print(difficulty[EEPROM.read(34)]);

}

void highScoreMenu() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Top 5 SNAKE game");

  if (person == 0) {
    lcd.setCursor(1, 1);
    lcd.print(person + 1);
   
    lcd.setCursor(3, 1);
    // lcd.print(char(EEPROM.read(14)));
    // lcd.print(char(EEPROM.read(15)));
    // lcd.print(char(EEPROM.read(16)));
    // lcd.print(char(EEPROM.read(17)));
    nameOfThePlayer(9);

     lcd.setCursor(10, 1);
    scoreOfThePlayer(4);
  }

  else if (person == 1) {
    lcd.setCursor(1, 1);
    lcd.print(person + 1);
    lcd.setCursor(3, 1);

    lcd.print(char(EEPROM.read(18)));
    lcd.print(char(EEPROM.read(19)));
    lcd.print(char(EEPROM.read(20)));
    lcd.print(char(EEPROM.read(21)));
    //nameOfThePlayer(10);
    lcd.setCursor(10, 1);
    scoreOfThePlayer(5);
    matrixMessage(game);
  }

  else if (person == 2) {
    lcd.setCursor(1, 1);
    lcd.print(person + 1);
    lcd.setCursor(3, 1);
    //nameOfThePlayer(11);

    lcd.print(char(EEPROM.read(22)));
    lcd.print(char(EEPROM.read(23)));
    lcd.print(char(EEPROM.read(24)));
    lcd.print(char(EEPROM.read(25)));
    lcd.setCursor(10, 1);
    scoreOfThePlayer(6);
  }

 else  if (person == 3) {
    lcd.setCursor(1, 1);
    lcd.print(person + 1);
    lcd.setCursor(3, 1);

    lcd.print(char(EEPROM.read(26)));
    lcd.print(char(EEPROM.read(27)));
    lcd.print(char(EEPROM.read(28)));
    lcd.print(char(EEPROM.read(29)));
  //  nameOfThePlayer(12);
    lcd.setCursor(10, 1);
    scoreOfThePlayer(7);
  }

  else if (person == 4) {
    lcd.setCursor(1, 1);
    lcd.print(person + 1);
    lcd.setCursor(3, 1);

    lcd.print(char(EEPROM.read(30)));
    lcd.print(char(EEPROM.read(31)));
    lcd.print(char(EEPROM.read(32)));
    lcd.print(char(EEPROM.read(33)));
   // nameOfThePlayer(13);
    lcd.setCursor(10, 1);
    scoreOfThePlayer(8);

  }
  else if (person == 5) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("< EXIT <");
  }
}


void scrollHighScoreMenu() {
  highScoreMenu();
  if (joystickUp() && state2Menu == true) {

    person--;
    if (firstPerson > person) {
      person = firstPerson;
    }
    highScoreMenu();
  } 
  else if (joystickDown() && state2Menu == true) {

    person++;

    if (lastPerson < person) { person = lastPerson; }
    highScoreMenu();
  }
  else if (joystickLeft() && state2Menu == true && person == 5) {
    person = 0;
    menuPart();
  }
 
}

void aboutMenu() {
  lcd.clear();
  if (details == 0) {
    lcd.setCursor(0, 0);
    lcd.print("ABOUT GAME");
    lcd.setCursor(0, 1);
    lcd.print("Name: SNAKE");
    lcd.setCursor(15, 1);
    lcd.write(byte(4));
  }
     
  if (details == 1){
    lcd.setCursor(0, 0);
    lcd.print("BY: POSTOLACHE");
    lcd.setCursor(0, 1);
    lcd.print(" ANDREEA MIRUNA");
    lcd.setCursor(15, 1);
    lcd.write(byte(3));
  }
  if (details == 2){
    lcd.setCursor(0, 0);
    lcd.print("GIT: postolache-");
    lcd.setCursor(0, 1);
    lcd.print("andreea-miruna");
    lcd.setCursor(15, 1);
    lcd.write(byte(4));
  }
    if (details == 3){
    lcd.setCursor(0, 0);
    lcd.print("< EXIT <");
  }
}

void scrollAboutMenu() {
  aboutMenu();
  if (joystickUp() && state2Menu == true) {
    details--;
    if (firstDetail > details) {
      details = firstDetail;
    }
    aboutMenu();
  } 
  else if (joystickDown() && state2Menu == true) {
    details++;
    if (lastDetail < details) {
      details = lastDetail;
    }
    aboutMenu();
  } 
  else if (joystickLeft() && state2Menu == true && details == 3) {
    details = 0;
    menuPart();
  }

}

void howToPlayMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" SNAKE GAME IDEA   SNAKE GAME IDEA");
  lcd.setCursor(0, 1);
  lcd.print("The snake must eat as much as possible.");
  for(int pos = 0; pos < 23; pos++)
  {
    lcd.scrollDisplayLeft();
    delay(500);
  }

  delay(menuDelay);

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("GO TO PLAY!");
  lcd.setCursor(5, 1);
  lcd.print("< EXIT <");
}
////////////////////////////

void menuCommandsSwitch() {
  state1Menu = false;
  state2Menu = true;
  if (menuPartPosition == 0) {
    startGameMenu();
    startPlayGame();
  } else if (menuPartPosition == 1) {
    scrollHighScoreMenu();
  } else if (menuPartPosition == 2) {
    state1Menu = false;
    state2Menu = false;
    settingPart();                      ////////////modif din settingPart()
  } else if (menuPartPosition == 3) {
    scrollAboutMenu();
  } else if (menuPartPosition == 4) {
    howToPlayMenu();
  }
}

/////////////////////////////////

void scrollMenu() {

  if (joystickUp() && state2Menu == false){//&& state2Menu == false && state1Setting == false && state2Setting == false) {
    menuPartPosition--;
    if (firstMenuPosition > menuPartPosition) {
      menuPartPosition = firstMenuPosition;
    }
    menuPart();
  } else if (joystickDown() && state2Menu == false){// && state2Menu == false && state1Setting == false && state2Setting == false) {

    menuPartPosition++;

    if (lastMenuPosition < menuPartPosition) { menuPartPosition = lastMenuPosition; }

    menuPart();
  } else if (joystickRight() && state1Menu == true){// && state1Setting == false && state2Setting == false) {
    menuCommandsSwitch();
  } else if (joystickLeft() && state2Menu == true){// && state1Setting == false && state2Setting == false) {
    menuPart();
  }
}
//////////////////////////////////


