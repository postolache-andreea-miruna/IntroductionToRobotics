String namePl = "    ";
int namePosition = 0;
const int firstNamePosition = 0;
const int lastNamePosition = namePl.length() - 1;

const String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
int characterPosition = 0;
const int firstCharacterPosition = 0;
const int lastCharacterPosition = characters.length() - 1;


void scrollPlayer() {

  placeNamePlayer();
  if (joystickUp()) {
    characterPosition --;
    if (characterPosition < firstCharacterPosition) {
      characterPosition = firstCharacterPosition;
    }
    namePl[namePosition] = characters[characterPosition];
  printNamePlayer(namePl);
  }
  else if (joystickDown()) {
    characterPosition ++;
    if (characterPosition > lastCharacterPosition) {
      characterPosition = lastCharacterPosition;
    }
    namePl[namePosition] = characters[characterPosition];
  printNamePlayer(namePl);
  }

  else if (joystickRight()) {
    namePosition ++;
    if (namePosition > lastNamePosition) {
      namePosition = lastNamePosition;
    }
    namePl[namePosition] = characters[characterPosition];
  printNamePlayer(namePl);
  }
  else if (joystickLeft()) {
    namePosition --;
    if (namePosition > firstNamePosition) {
      namePosition = firstNamePosition;
    }
    namePl[namePosition] = characters[characterPosition];
  printNamePlayer(namePl);
  }

  else if (joystickPress()) {
    newHighScore(score,namePl);
    writePlayerName = false;
    goToMenu();//in lcd
   }

  
}
