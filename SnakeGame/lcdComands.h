//lcdComands
#include <LiquidCrystal.h>
const byte RS = 13;
const byte enable = 8;
const byte d4 = 7;
const byte d5 = 6;
const byte d6 = 5; 
const byte d7 = 4;
const byte brightPin = 3; //lcdA is conected with arduino pin 3  
const byte contrastPin = 9;//////////////////
const byte rowsLCD = 2;
const byte columnsLCD = 16;

const int menuDelay = 2000;
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
	0b00000,
	0b00000,
	0b00100,
	0b01110,
	0b01110
};

void greeting()
{
  openSound();
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("It's SNAKE Time ");
  lcd.setCursor(6, 1);//a sasea col al doilea rand
  lcd.write(byte(0)); 
  lcd.setCursor(7, 1);//a sasea col al doilea rand
  lcd.write(byte(2));
  lcd.setCursor(8, 1);//a sasea col al doilea rand
  lcd.write(byte(2));
  lcd.setCursor(9, 1);//a sasea col al doilea rand
  lcd.write(byte(0));

  matrixMessage(greetings);
  delay(menuDelay);

}

void nameOfThePlayer(int namePos) {
  String name = readFromEEPROM(namePos);
  for(int pos = 0; pos < 4; pos++) {
    lcd.print(name[pos]);
  }
}

void scoreOfThePlayer(int scorePos) {
  int score = EEPROM.read(scorePos);
  lcd.print(score);
}

void scorePrint(int score) {
  lcd.setCursor(6,0);
  lcd.print(score);
}

void placeNamePlayer() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Highscore ");
  lcd.print(EEPROM.read(4));
  lcd.setCursor(0,1);
  lcd.print("NAME:");

  matrixMessage(smile);
}
void printNamePlayer(String name) {
  lcd.setCursor(6,1);
  lcd.print(name);
  delay(100);

  matrixMessage(smile);
}
void goToMenu() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Go to menu");

  matrixMessage(smile);

  startGame = false;
}

void congratsScreen(int score) {

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Congratulation!");
  lcd.setCursor(0,1);
  lcd.print("Your score ");
  lcd.print(score);
  matrixMessage(smile);

  delay(1500);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Highscore ");
  lcd.print(EEPROM.read(4));
  lcd.setCursor(0,1);
  lcd.print("Your score ");
  lcd.print(score);
  matrixMessage(smile);

  delay(3000);

  if (score > EEPROM.read(4)) {
    writePlayerName = true;
  }
  else {
    transitionToMenu = true;//in lcd
  }
}

