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
  }
  else if (joystickDown()) {
    characterPosition ++;
    if (characterPosition > lastCharacterPosition) {
      characterPosition = lastCharacterPosition;
    }
  }

  else if (joystickRight()) {
    namePosition ++;
    if (namePosition > lastNamePosition) {
      namePosition = lastNamePosition;
    }
  }
  else if (joystickLeft()) {
    namePosition --;
    if (namePosition > firstNamePosition) {
      namePosition = firstNamePosition;
    }
  }

  else if (joystickPress()) {
    newHighScore(score,namePl);
    writePlayerName = false;
   }

  namePl[namePosition] = characters[characterPosition];
  printNamePlayer(namePl);
}
