void gameStates() {
  if (startGame == false) {
    if (millis() - previousMillis > 300) {
      if (state1Menu == true || (state2Menu == true && menuPartPosition == 4))  //menu principal
        scrollMenu();
      if (toMainMenu == true && joystickLeft()) {
        state1Menu = true;
        state2Menu = false;

        toMainMenu = false;
        score = 0;
        menuPart();
      } 
      else if (state2Menu == true && menuPartPosition == 1)
        scrollHighScoreMenu();
      else if (state2Menu == true && menuPartPosition == 3)
        scrollAboutMenu();

      else if (state2Menu == false && state1Menu == false && menuPartPosition == 2 && state1Setting == true)
        scrollSettings();

      else if (state2Setting == true && settingPartPosition == 0)
        difficultyMenu();
      else if (state2Setting == true && settingPartPosition == 1)
        contrastMenu();
      else if (state2Setting == true && settingPartPosition == 2)
        brightLCDMenu();
      else if (state2Setting == true && settingPartPosition == 3)
        brightMatrixMenu();
      else if (state2Setting == true && settingPartPosition == 4)
        soundMenu();

      if (state1Setting == true && state2Setting == false && joystickLeft() && settingPartPosition == 5) {
        settingPartPosition = 0;
        state1Menu = true;
        state2Menu = false;
        menuPart();
      }
      previousMillis = millis();
    }
  } 
  else {
    if (writePlayerName == true) {
      if (millis() - previousMillis2 > 300) {
        scrollPlayer();
        blink();
        previousMillis2 = millis();
      }
    }
    else if (transitionToMenu == true) {
      if (millis() - previousMillis2 > 300) {
        goToMenu();
        transitionToMenu = false;
        toMainMenu = true;
        previousMillis2 = millis();
      }
    } 
    else
      setupGame();
  }
}