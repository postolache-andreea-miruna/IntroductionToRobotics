# Homework 3

## Task Requirements

With the joystick I control the position of the segment and I draw βοΈ βοΈ on the display.

There are 2 states:

### π₯ state (default state and also initiated after pressing the button in π₯ state )

 - The current segment πΆββοΈ is blinking
 - I can use the joystick to move on a neigbour π­ of the current segment πΆββοΈ
 - If I press for a short time, then I move to π₯ state
 - If I press for a long time in π₯ state, then the despay is reset (all segments are OFF and the current position is the decimal point)

### π₯ state (initiated after the button is press in π₯ state)

 - The currentt segment stops blinking and it will have the state before the selection
 - If I move the joystick to the β¬οΈ (left)  => the segment is ON,
 - If I move the joystick to the β‘οΈ (right) => the segment is OFF.
 - When I click the joystick the segment state will be saved and I move to π₯ state.

Used components:
 - 1 7-segment display
 - 1 joystick
 - 2 x 1 kΞ©
 - 17 wires


## Setup


![Setup](https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/e48ef90924974020c754049afdcf2959714ff948/Homework3/scheme.jpeg)


## Let's see how it works


[Demo](https://youtu.be/NsISoF0bN7k)

