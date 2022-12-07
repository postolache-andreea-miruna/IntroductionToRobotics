# Menu 
 I create a menu for my game. 

 I scroll on the LCD with the joystick. 

 The menu include the following functionality (when I scroll the menu it will make a sound):

	1. When powering up a game, a greeting message appears for a few moments.
	2. Contains the following categories:
		(a) Start game, starts the difficulty saved of the game
		(b) Highscore:
			– Initially, I print them with the saved values from EEPROM.
			– I update it when the player makes a new highscore. 
			– Save the top 5 values in EEPROM with name and score.
		(c) Settings:

			– Starting difficulty: Set the starting difficulty value. I save it to EEPROM. 
			– LCD contrast control and save it to eeprom.
			– LCD brightness control and save it to eeprom.
			– Matrix brightness control and save it to eeprom.
			– Sounds on or off and save it to eeprom.
			- Reset high scores - when I press the highscores will reset

		(d) About: include details about me: game name, my name and github user
		(e) How to play: short and informative description
	3. While playing the game: I display all relevant info
		– Level ( means difficulty)
		– Score
		- Highscore
	4. Upon game ending:
		(a) Screen 1: a message to congratulate the player and switches to screen 2 after a few moments.
		(b) Screen 2: display relevant game info: score, highscore and also enter the name of the player if he/she makes a new highscore. When pressing the button go to the screen "back to menu" and after pressing again the button it will go to the main menu.
				If the person do no make a new highscore then it will enter the menu "back to menu".



# Eating Dots minigame

## Task Requirements

Control a LED with the joystick and generate random food which blinks.
When the player pass over it, the food disappears ans the score increases by 1.
After that, the food will be randomly generated in another space.

Used components:
 - 1 MAX7219 Driver
 - 1 joystick
 - 1 matrix display
 - 1 electrolytic capacitor of 10 μF
 - 1 electrolytic capacitor of 50 μF
 - 1 ceramic capacitor of 104 pF
 - wires

## 🔌 Setup

Setup view 

1.

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/af8fba5e94bc9d2ec765a5f1c4f0a9c522d26785/Homework5/setup1up.jpg" width=50% height=50%>

2.

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/af8fba5e94bc9d2ec765a5f1c4f0a9c522d26785/Homework5/setup2side.jpg" width=50% height=50%>


Common Cathod

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/a9754a096874029d0d95e6474ce6ebd501884944/Matrix/commonCathod.png" width=50% height=50%>


Driver

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/a9754a096874029d0d95e6474ce6ebd501884944/Matrix/Driver.png" width=50% height=50%>


How to connect Matrix to Driver

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/a9754a096874029d0d95e6474ce6ebd501884944/Matrix/matrixToDriver.png" width=50% height=50%>



How to connest Driver to Arduino

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/a9754a096874029d0d95e6474ce6ebd501884944/Matrix/DriverArduino.png" width=50% height=50%>


How to connect LCD to Arduino

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/306fd6581a411fb0410732c41ad6df798d0b594d/Homework5/lcdconect.png" width=50% height=50%>


## Let's see how it works

[Complete Snake Menu 12/07](https://youtu.be/dwG_YwjKPK4)


