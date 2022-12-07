#include <LiquidCrystal.h>
const byte RS = 13;
const byte enable = 8;
const byte d4 = 7;
const byte d5 = 6;
const byte d6 = 5; 
const byte d7 = 4;
const byte brightPin = 3; //lcdA is conected with arduino pin 3  
const byte contrastPin = 9;
const byte rowsLCD = 2;
const byte columnsLCD = 16;

const int menuDelay = 2000;
const int congratsDelay1 = 1500;
const int congratsDelay2 = 3000;
const int nameDelay = 100;
LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);

bool writePlayerName = false;
bool transitionToMenu = false;
bool toMainMenu = false;

byte doubleArrows[8] = {
	0b00100,
	0b01010,
	0b10001,
	0b00000,
	0b00000,
	0b10001,
	0b01010,
	0b00100
};
byte downArrow[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b10001,
	0b01010,
	0b00100,
	0b00000,
	0b00000
};
byte upArrow[8] = {
	0b00000,
	0b00000,
	0b00100,
	0b01010,
	0b10001,
	0b00000,
	0b00000,
	0b00000
};
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte buttonPress[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b01110,
	0b01110,
	0b11111,
	0b11111,
	0b11111
};

void greeting()  //use when the app is open
{
  openSound();
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("It's SNAKE Time ");
  lcd.setCursor(6, 1);
  lcd.write(byte(0)); 
  lcd.setCursor(7, 1);
  lcd.write(byte(2));
  lcd.setCursor(8, 1);
  lcd.write(byte(2));
  lcd.setCursor(9, 1);
  lcd.write(byte(0));

  matrixMessage(greetings);
  delay(menuDelay);

}
/*
use in highScoreMenu() (find in Menu.h)
to print the name of the players that makes a highscore.

It is used the function readFromEEPROM(int namePos) - 
- it can be found in EEPROMMemo.h
*/
void nameOfThePlayer(int namePos) {       
  String name = readFromEEPROM(namePos);
  for(int pos = 0; pos < 4; pos++) {
    lcd.print(name[pos]);
  }
}

/*
use in highScoreMenu() (find in Menu.h)
to print the score of the players that makes a highscore.

It is used EEPROM.read(scorePos) to acces the value from the memory
*/
void scoreOfThePlayer(int scorePos) {
  int score = EEPROM.read(scorePos);
  lcd.print(score);
}

/*
use in miniGame.h
to print the current score of the player
*/
void scorePrint(int score) {
  lcd.setCursor(6,0);
  lcd.print(score);
}

/*
Use in scrollPlayer() (in player.h) function to print the details
for the printing name page
*/
void placeNamePlayer() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Highscore ");
  lcd.print(EEPROM.read(4));
  lcd.setCursor(0,1);
  lcd.print("NAME:");

  lcd.setCursor(10,1);
  lcd.write(byte(6));
  lcd.print(" SAVE");

  matrixMessage(smile);
}

/*
Use in scrollPlayer() (in player.h) function to print the name
of the player that make a highscore
*/
void printNamePlayer(String name) {  //in player
  lcd.setCursor(5,1);
  lcd.print(name);
  delay(nameDelay);

  matrixMessage(smile);
}

/*
Use in gameLogic.h - when the player do not do a new highscore
*/
void goToMenu() {
  lcd.clear();
   
  lcd.setCursor(0, 0);
  lcd.print("PRESS TO GO");

  lcd.setCursor(0, 1);
  lcd.print("BACK TO MENU");

  matrixMessage(smile);

  startGame = false;
}

/*
Use in miniGame.h - when the player do a new highscore
*/
void congratsScreen(int score) {

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Congratulation!");
  lcd.setCursor(0,1);
  lcd.print("Your score ");
  lcd.print(score);
  matrixMessage(smile);

  delay(congratsDelay1);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Highscore ");
  lcd.print(EEPROM.read(4));
  lcd.setCursor(0,1);
  lcd.print("Your score ");
  lcd.print(score);
  matrixMessage(smile);

  delay(congratsDelay2);

  if (score > EEPROM.read(4)) {
    writePlayerName = true;
  }
  else {
    transitionToMenu = true;
  }
}

