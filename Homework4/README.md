# Homework 4

## Task Requirements

With the joystick I can move through the 4 digit 7 segment display digits.
When I press the button I lock the current digit and I increment or decrement the value of the digit.
If i am in 🥇 state and I press the button for a long time then the system is reset (all the digits = 0, current position = first digit)


There are 2 states:

### 🥇 state (default state and also initiated after pressing the button in 🥈 state )

 - I can use the joystick to move through the 4 digits with OY axis.
 - The current position is marked by the blinking decimal point.
 - If I press for a short time, then I lock on the current digit and I move to 🥈 state
 - If I press for a long time in 🥇 state, then the display is reset (all the digits are 0 and the current position is the right most digit))


### 🥈 state (initiated after the button is press in 🥇 state)

 - The decimal point is not blinking, is always on
 - Using the OX axis, 
	when the joystick is up then the digit value increment
	when the joystick is down then the digit value decrement
 - When I click the joystick the digit vakkue will be saved and I move to 🥇 state.

Used components:
 - 1 4 digit 7-segment display
 - 1 joystick
 - 1 74hc595 shift register
 - 31 wires


## Setup


![Setup](https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/e48ef90924974020c754049afdcf2959714ff948/Homework3/scheme.jpeg)


## Let's see how it works


[Demo](https://youtu.be/IgPZR6cD90k)

