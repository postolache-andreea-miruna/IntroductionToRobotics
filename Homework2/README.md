# Homework 2

## Task Requirements
Building the traffic lights for a crosswalk. 
I used:
- two LEDs to represent traffic lights for people 🔴 🟢
- three LEDs to represent traffic lights for cars 🔴 🟡 🟢

Used components:
 - 5 LEDs
 - 1 button
 - 1 buzzer (passive)
 - 5 x 330 Ω resistors and 1 x 100 Ω resistor
 - 12 wires

### The traffic lights system has 4 states:

#### State 1 - default, reinstated after state 4 ends
 - 🟢 for 🚗
 - 🔴 for 👫
 -  Duration = indefinite (changed by pressing the button)

#### State 2 - initiated after 8 seconds after the button is pressed in state 1
 - 🟡 for 🚗
 - 🔴 for 👫
 -  No sounds
 -  Duration = 3 seconds

#### State 3 - initiated after state 2 ends
  - 🔴 for 🚗
  - 🟢 for 👫
  - Constant beeping from the buzzer
  - Duration = 8 seconds

#### State 4 - initiated after state 3 ends
  - 🔴 for 🚗
  - Blinking 🟢 for 👫
  - Constant beeping from the buzzer, faster then in state 3
  - Duration = 4 seconds

‼ If I press the button in any state rather than STATE 1 should NOT yield any actions.

## Setup

![Setup](https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/f1b8480a2f143dadddc08c584751ca1d77802894/Homework2/Semafoarele.jpg)

## Let's see how it works

[Demo for one button press](https://youtu.be/jeSTIqOnYK0)

[Demo for multiple button press](https://youtu.be/TSNSQOE1npg)

🔼 In this demo I press the button multiple times to show that if the system is not in state 1 then nothing is happening
