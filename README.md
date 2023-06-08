# Final Project: Repeat After Me

## Author
Mayra Solorio

## What Does it Do?
The game is similar to many “repeat after me” games, in which after something is done or said, you must copy the action. In this CPX game, LEDs will light up in a specific order, and similarly, you will have to repeat as the LEDs have lit up. The game will test memorization of the player by touching one of the four sections of the board in which the LEDs have lit up, and can be won by memorizing a pattern of 15 random LEDs while touching the capacitance sensors attached to those LEDs in the right order so that the capacitance breaks 950. 

## Inputs and Outputs
The 4 main inputs of the game are the four main capacitance sensors in each corner of the board that are attached to the 4 sections of LED colors in the game. The first input is sensor  A3 and is connected to the red LED outputs. The second input is sensor A1 and is connected to the green LED outputs. The third input is sensor A7 and is connected to the yellow LED outputs; And the last input is sensor A4 and is connected to the blue LED outputs. There are also 2 other outputs which use sound. One will be the losing sound that plays after a mistake is made and before the game resets, and the second is the celebratory sound which will play after all 15 levels have been passed. 

## Player Instructions
1. Carefully watch for the LED pattern of length one when the game begins. 
2. Hold the capacitance sensor that corresponds to the LEDs that just lit up, no more than a few seconds after the LEDs turn off. 
3. Carefully watch for the next LED pattern that will be the last LED that lit up, and one more additional light after it. 
4. Hold the capacitance sensor that corresponds to the first LED that lit up and then the second one with no more than a few seconds in between.
5. Repeat these steps of watching the LEDs and holding the capacitance sensors in the same order, until you have reached a pattern length of    15.
6. After this, begin the game from step 1 again, watching for a single LED light sequence. 


## Rules of the Game
The capacitance of the section must break 950 out of the possible 1016. This can be done by simply touching the sensors in the area. 
You must touch the sensors within a few seconds, leaving little room to think about your next move, truly testing memorization skills. 
The game starts at Level 1, in which one fourth of the LEDs will light up a certain color on the CPX board. After that color is lit up you must then press the capacitance sensors of that section within a few seconds. If the capacitance sensors do not detect that the area was pressed then all the LEDs will light up red and you will hear a losing sound. If the capacitance for the area is detected, then the CPX board will repeat the same lights that were just on, plus one more set. As long as the capacitance is detected for each pattern that the LEDs light up in, then the game will continue to add one extra LED to the existing pattern. The game will continue until the pattern is 15 random LED lights that you must touch in the exact order, with little time in between to remember. If the LED pattern of 15 is done correctly, all the LED lights will light up green and a celebratory noise will play. The game will restart from the beginning after that.

