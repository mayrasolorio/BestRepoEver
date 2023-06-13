# Final Project: Read My Mind
## Author
Mayra Solorio

## What Does it Do?
The game is similar to many “repeat after me” games, in which after something is done or said, you must copy the action. In this CPX game, there are four regions of the board, each with different colored LEDs and different capacitator inputs. The focus of the game is to keep 4 fingers on the capacitators and only let go of one when you're switching the LED for your next pattern. The goal is to not lift off your finger from the next LED that will play as this will cause a long beep and you will lose the game. You can start over by moving the switches position once again. 

## Inputs and Outputs
The 4 main inputs of the game are the four capacitance sensors in each corner of the board that are attached to the 4 sections of LED colors in the game. The first input is pin A5 and is connected to the red LED output and "region 1" of the board, or the top left corner. Moving counter-clockwise, the second input is pin A6 and is connected to the blue LED outputs and "region 2" of the board, or the bottom left corner. The third input is pin A7 and is connected to the green LED outputs and "region 3" of the board, or the bottom right corner; And the last input is sensor A4 and is connected to the blue LED outputs. The other important input in this game is the switch on D7. The switch is going to allow for an LED to light up after it has been moved so that you can continue the game. 
All LEDs are used as outputs in this game, with four different colors appearing on the board. LEDs 0-2 appear as red, LEDs 2-4 appearing as blue, LEDs 5-7 appearing as green, and finally LEDs 7-9 appearing as yellow. There is also a few sound outputs in the game. Each region is associated with a note played through the CPX board's tone feature. The notes range from a C4 to an F4 increasing in note for every region. If at any point you make an incorrect guess, the board will play a long beep in the note of that region, signaling that you have lost. Similarly to the losing sounds, there is also a speech output that will enunciate the words "correct", after every correct answer. 

## Player Instructions
1. Place 4 fingers on the board, one on each of the capacitator pins (A1, A2, A5, and A6). 
2. With one finger, slide the switch to begin. (Attempt to guess the next light that is going to light up, so that you don't lift that finger up).
3. Continue placing all fingers on the board, moving the switch with one, until you lose. You will know you lose when there is a pause and a long beep. Or else, nothing will happen and you can move the switch after about 2 seconds.


## Rules of the Game
The capacitance of the section must break 700 out of the possible 1016. This can be done by simply touching the sensor. 
You must use one finger to move the switch, you can lift more for more of a challenge, although this starts to get difficult as the LEDs that light up next are randomized and there is no pattern to follow.  
If the capacitance sensor does not detect capacitance on the board, then a beep with no light will play and you have lost. You can restart after a bit by moving the switch. 
The game's objective is simple: Try to guess where the next LED region will light up, and don't lift your finger from there. 

## Contact Information
For questions about any of the above, or the code, you can email me at mayrasolorio03@gmail.com

