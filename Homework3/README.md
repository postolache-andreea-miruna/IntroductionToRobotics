# Homework 3

## Task Requirements

With the joystick I control the position of the segment and I draw ✏️ ✏️ on the display.

There are 2 states:

### 🥇 state (default state and also initiated after pressing the button in 🥈 state )

 - The current segment 🚶‍♀️ is blinking
 - I can use the joystick to move on a neigbour 👭 of the current segment 🚶‍♀️
 - If I press for a short time, then I move to 🥈 state
 - If I press for a long time in 🥇 state, then the despay is reset (all segments are OFF and the current position is the decimal point)

### 🥈 state (initiated after the button is press in 🥇 state)

 - The currentt segment stops blinking and it will have the state before the selection
 - If I move the joystick to the ⬅️ (left)  => the segment is ON,
 - If I move the joystick to the ➡️ (right) => the segment is OFF.
 - When I click the joystick the segment state will be saved and I move to 🥇 state.

Used components:
 - 1 7-segment display
 - 1 joystick
 - 2 x 1 kΩ
 - 17 wires


## Setup


![Setup](/Homework3/schem.jpg)


## Let's see how it works


[Demo](https://youtu.be/TSNSQOE1npg)
