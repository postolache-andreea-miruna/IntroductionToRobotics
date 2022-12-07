void gameStates() {
  if (startGame == false) {
    if (millis() - previousMillis > 300) {
      if (state1Menu == true || (state2Menu == true && menuPartPosition == 4))  //menu principal
        scrollMenu();
      if (toMainMenu == true && joystickPress()) {
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

      if (startSetting == true && state2Setting == false ) {
        settingPart();
        startSetting = false;
      }
      if (state1Setting == true && state2Setting == false &&  startSetting == false)
        scrollSettings();
      if (joystickRight() && state1Setting == true && state2Setting == false && settingPartPosition != 5 && settingPartPosition != 6 && firstEnterSettings == 1) {
        delay(300);
        firstEnterSettings = 2;
      }
      if (joystickRight() && state1Setting == true && state2Setting == false && settingPartPosition != 5 && settingPartPosition != 6 && firstEnterSettings != 1 && firstEnterSettings != 0) 
        settingsCommandsSwitch();

      if (state2Setting == true && settingPartPosition == 0 )
        difficultyMenu();
      if (state2Setting == true && settingPartPosition == 1)
        contrastMenu();
      if (state2Setting == true && settingPartPosition == 2)
        brightLCDMenu();
      if (state2Setting == true && settingPartPosition == 3)
        brightMatrixMenu();
      if (state2Setting == true && settingPartPosition == 4)
        soundMenu();

      if (state1Setting == true && state2Setting == false && joystickPress() && settingPartPosition == 5) { // reset highscore
        initializeNameAndScores();
      }

       if (state1Setting == true && state2Setting == false && joystickLeft() && settingPartPosition == 6) { //back to menu
        
        settingPartPosition = 0;
        state1Menu = true;
        state2Menu = false;
        state1Setting = false;
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