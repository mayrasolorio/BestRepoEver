// I am using the Adafruit library for functions
#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

//variables stored are for the switch on the CPX board
int switchPin = 7;
volatile bool switchFlag = 0;
volatile bool switchState = 0;
//speech demo 
const uint8_t spCORRECT[] PROGMEM = { 0x0A,0x28,0x71,0xD9,0x00,0xB9,0x39,0x97,0xA8,0xD4,0x66,0xF3,0x68,0x32,0xA2,0x94,0xCD,0x35,0x62,0xF2,0x4A,0x4A,0xD1,0x22,0xB7,0xC5,0x2D,0xCD,0x87,0x93,0xD3,0x5A,0xA7,0x34,0x2E,0x0A,0x75,0xEB,0x12,0xD2,0x30,0x31,0x2C,0xBC,0x73,0x48,0xC2,0xC0,0x0C,0x8B,0x4E,0x25,0x4A,0x13,0x4B,0xD2,0x5A,0x8F,0xA0,0x14,0x4E,0x2E,0x5F,0x7C,0xA2,0x56,0x2C,0x34,0x6C,0xF1,0x89,0x5B,0x90,0xF0,0xC8,0x29,0x27,0xEB,0x49,0x2D,0x3D,0xEA,0xB4,0xA2,0x25,0xD6,0xCE,0x9A,0x8C,0x0A,0xA1,0xDC,0x5D,0x44,0x36,0x00,0x00,0x00,0x28,0xE0,0x8A,0x34,0x0D,0x20,0xA0,0x9A,0x86,0xFF,0x11};

 void speech() {
    CircuitPlayground.speaker.say(spCORRECT);
 }

// This function lights up LEDs 0, 1, and 2, to the color red and plays a C4 note then clears the pixels.
// These 3 LEDs are considered region 1 of the board (the top left corner)
void region1() {
  CircuitPlayground.setPixelColor(0, 255, 0, 0);
  CircuitPlayground.setPixelColor(1, 255, 0, 0);
  CircuitPlayground.setPixelColor(2, 255, 0, 0);
  CircuitPlayground.playTone(261.63, 200);
  delay(2000);
  CircuitPlayground.clearPixels();
}

// This function lights up LEDs 2, 3, and 4, to the color blue and plays a D4 note then clears the pixels.
// These 3 LEDs are considered region 2 of the board (the bottom left corner)
void region2() {
  CircuitPlayground.setPixelColor(2, 0, 0, 255);
  CircuitPlayground.setPixelColor(3, 0, 0, 255);
  CircuitPlayground.setPixelColor(4, 0, 0, 255);
  CircuitPlayground.playTone(293.67, 200);
  delay(2000);
  CircuitPlayground.clearPixels();
}

// This function lights up LEDs 5, 6, and 7, to the color green and plays a E4 note then clears the pixels.
// These 3 LEDs are considered region 3 of the board (bottom right corner)
void region3() {
  CircuitPlayground.setPixelColor(5, 0, 255, 0);
  CircuitPlayground.setPixelColor(6, 0, 255, 0);
  CircuitPlayground.setPixelColor(7, 0, 255, 0);
  CircuitPlayground.playTone(329.63, 200);
  delay(2000);
  CircuitPlayground.clearPixels();
}

// This function lights up LEDs 7, 8, and 9, to the color yellow and plays a F4 note then clears the pixels.
// These 3 LEDs are considered region 4 of the board (the top right corner)
void region4() {
  CircuitPlayground.setPixelColor(7, 255, 255, 0);
  CircuitPlayground.setPixelColor(8, 255, 255, 0);
  CircuitPlayground.setPixelColor(9, 255, 255, 0);
  CircuitPlayground.playTone(349.23, 200);
  delay(2000);
  CircuitPlayground.clearPixels();
}


void setup() {
  CircuitPlayground.begin();
  randomSeed(analogRead(0)); // used to randomly seed the randon function (makes it more random)
  pinMode(switchPin, INPUT_PULLUP); // allows the switch to be used
  attachInterrupt(digitalPinToInterrupt(7), onOff, CHANGE); //interrupt pin for detecing change in the switch
}


void loop() {
  int cap1 = CircuitPlayground.readCap(2); //reads capactiance of the first region: pin A5 on the board
  int cap2 = CircuitPlayground.readCap(0); //reads capactiance of the second region: pin A6 on the board
  int cap3 = CircuitPlayground.readCap(6); //reads capactiance of the third region: pin A1 on the board
  int cap4 = CircuitPlayground.readCap(9); //reads capactiance of the fourth region: pin A2 on the board


    if(switchFlag) {
    delay(5);
    switchState = digitalRead(switchPin);
  switch (random(4)) {                                    //randomly picks the next LED to light up
    for (int i = 0; i < 4; i++); {
      case 0:                                             // lights up region 1 of the board and plays the noise. If the capacitance of the region is over 700 (it is tapped),  
        region1();                                        // then nothing happens and you can switch the switch to get your next LED, if it is not then a long beep will play, signaling you've lost.
        delay(1000);
        if (cap1 > 700) {
          delay(1000);
          speech();
        } else {
          delay(1000);
          CircuitPlayground.clearPixels();
          CircuitPlayground.playTone(261.63, 1000);
          delay(100);
          break;
        } }
      case 1:                                             // lights up region 2 of the board and plays the noise. If the capacitance of the region is over 700 (it is tapped),  
        region2();                                        // then nothing happens and you can switch the switch to get your next LED, if it is not then a long beep will play, signaling you've lost.
        delay(1000);
        if (cap2 > 500) {
          delay(1000);
          speech();
        } else {
          delay(1000);
          CircuitPlayground.clearPixels();
          CircuitPlayground.playTone(293.67, 1000);
          delay(100);
          } 
        break;
      case 2:                                             // lights up region 3 of the board and plays the noise. If the capacitance of the region is over 700 (it is tapped), 
        region3();                                        // then nothing happens and you can switch the switch to get your next LED, if it is not then a long beep will play, signaling you've lost.
        delay(1000);
        if (cap3 > 700) {
            delay(1000);
            speech();
          } else {
            delay(1000);
            CircuitPlayground.clearPixels();
            CircuitPlayground.playTone(329.63, 1000);
            delay(100);
            } 
          break;
          case 3:                                           // lights up region 4 of the board and plays the noise. If the capacitance of the region is over 700 (it is tapped), 
            region4();                                      // then nothing happens and you can switch the switch to get your next LED, if it is not then a long beep will play, signaling you've lost.
            delay(1000);                
            if (cap4 > 700) {
              delay(1000);
              speech();
            } else {
              delay(1000);
              CircuitPlayground.clearPixels();
              CircuitPlayground.playTone(349.23, 1000);
              delay(100);
              break;
              default:
                break;
            }
        }
            switchFlag = 0;                                   
    }
}
  
    //ISR function used in interrupt
  void onOff() {                                            
    switchFlag = 1;
  }


 