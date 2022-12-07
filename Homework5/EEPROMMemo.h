#include <EEPROM.h>
/*
EEPROM.update(address, value);

First 5 players & their scors:
  - scores: 4 - 8 (address)
  - lenght of name - 9-13
  - players names 
LCD contrast  - 0
LCD brightness -1
Matrix brightness -2
Sounds -3
LEVEL  of difficulty - 34
*/

const byte fisrtLetterPl1 = 14;

String readFromEEPROM(int addressOffset) {  //give the string at the indicate address
  int len = EEPROM.read(addressOffset);     //take the len value

  char name[len+1]={};
  byte begin;
  if (addressOffset == 9) {
    begin = fisrtLetterPl1;
  } 
  else if (addressOffset == 10) {
    begin = fisrtLetterPl1 + len;
  } 
  else if (addressOffset == 11) {
    begin = fisrtLetterPl1 + 2 * len;
  } 
  else if (addressOffset == 12) {
    begin = fisrtLetterPl1 + 3 * len;
  } 
  else if (addressOffset == 13) {
    begin = fisrtLetterPl1 + 4 * len;
  }
  for (int pos = 0; pos < len; pos++) {
    name[pos] = char(EEPROM.read(begin + pos));
  }

  String namePlayer = name;
  return namePlayer;
}
void updateHighScoreEEPROM(int points) {
  EEPROM.update(8, EEPROM.read(7));
  EEPROM.update(7, EEPROM.read(6));
  EEPROM.update(6, EEPROM.read(5));
  EEPROM.update(5, EEPROM.read(4));
  EEPROM.update(4, points);  //new score
}
void updatePlayerNameEEPROPM(String playerName) {

  String sndPlayer = readFromEEPROM(9);  //now the second player is the one who was the first one
  String thrdPlayer = readFromEEPROM(10);
  String fourthdPlayer = readFromEEPROM(11);
  String fifthdPlayer = readFromEEPROM(12);

  byte len = playerName.length();
  if (len != EEPROM.read(9)) {
    int diff = EEPROM.read(9) - len;
    char strDiff = ' ' * diff;
    playerName = playerName.concat(strDiff);
  }

  for (int i = 0; i < len; i++) {
    EEPROM.update(fisrtLetterPl1 + i, playerName[i]);
    EEPROM.update(fisrtLetterPl1 + len + i, sndPlayer[i]);
    EEPROM.update(fisrtLetterPl1 + 2 * len + i, thrdPlayer[i]);
    EEPROM.update(fisrtLetterPl1 + 3 * len + i, fourthdPlayer[i]);
    EEPROM.update(fisrtLetterPl1 + 4 * len + i, fifthdPlayer[i]);
  }
}

/*
use in scrollPlayer() (player.h) when the button is pressed
for saving the data in memory
*/
void newHighScore(int points, String playerName) {
  updateHighScoreEEPROM(points);
  updatePlayerNameEEPROPM(playerName);
}
void initializeNameAndScores() {
  EEPROM.update(4,0);
  EEPROM.update(5,0);
  EEPROM.update(6,0);
  EEPROM.update(7,0);
  EEPROM.update(8,0);

  //length
  EEPROM.update(9, 4);   
  EEPROM.update(10, 4);  
  EEPROM.update(11, 4);  
  EEPROM.update(12, 4);
  EEPROM.update(13, 4);

  //1 player
  EEPROM.update(14, 'N');   
  EEPROM.update(15, 'N');    
  EEPROM.update(16, 'N');  
  EEPROM.update(17, 'N');

  //2 player
  EEPROM.update(18, 'N');   
  EEPROM.update(19, 'N');  
  EEPROM.update(20, 'N');  
  EEPROM.update(21, 'N');

  //3 player
  EEPROM.update(22, 'N');   
  EEPROM.update(23, 'N');  
  EEPROM.update(24, 'N');  
  EEPROM.update(25, 'N');

  //4 player
  EEPROM.update(26, 'N');  
  EEPROM.update(27, 'N');  
  EEPROM.update(28, 'N'); 
  EEPROM.update(29, 'N');

  //5 player
  EEPROM.update(30, 'N');   
  EEPROM.update(31, 'N');  
  EEPROM.update(32, 'N');  
  EEPROM.update(33, 'N');
}

void initialize() {
  EEPROM.update(0,0);
  EEPROM.update(1,3);
  EEPROM.update(2,0);
  EEPROM.update(3,1); //sound on
  EEPROM.update(34,0);

  //scores
  EEPROM.update(4,0);
  EEPROM.update(5,0);
  EEPROM.update(6,0);
  EEPROM.update(7,0);
  EEPROM.update(8,0);

  //length
  EEPROM.update(9, 4);   
  EEPROM.update(10, 4);  
  EEPROM.update(11, 4);  
  EEPROM.update(12, 4);
  EEPROM.update(13, 4);

  //1 player
  EEPROM.update(14, 'N');   
  EEPROM.update(15, 'N');    
  EEPROM.update(16, 'N');  
  EEPROM.update(17, 'N');

  //2 player
  EEPROM.update(18, 'N');   
  EEPROM.update(19, 'N');  
  EEPROM.update(20, 'N');  
  EEPROM.update(21, 'N');

  //3 player
  EEPROM.update(22, 'N');   
  EEPROM.update(23, 'N');  
  EEPROM.update(24, 'N');  
  EEPROM.update(25, 'N');

  //4 player
  EEPROM.update(26, 'N');  
  EEPROM.update(27, 'N');  
  EEPROM.update(28, 'N'); 
  EEPROM.update(29, 'N');

  //5 player
  EEPROM.update(30, 'N');   
  EEPROM.update(31, 'N');  
  EEPROM.update(32, 'N');  
  EEPROM.update(33, 'N');

}