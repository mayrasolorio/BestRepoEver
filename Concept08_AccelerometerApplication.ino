// Circuit Playground Total Acceleration
// Author: Carter Nelson
// MIT License (https://opensource.org/licenses/MIT)

#include <Adafruit_CircuitPlayground.h>

float X, Y, Z, totalAccel;
  
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
}

//Calculates total acceleration and detects shaking
void shaking() {
  X = 0;
  Y = 0;
  Z = 0;
  for (int i=0; i<10; i++) {
    X += CircuitPlayground.motionX();
    Y += CircuitPlayground.motionY();
    Z += CircuitPlayground.motionZ();
    delay(1);
  }
  X /= 10;
  Y /= 10;
  Z /= 10;

  totalAccel = sqrt(X*X + Y*Y + Z*Z);

  Serial.println(totalAccel);

  delay(100);
}

//Sets random pixels to green if not shaking hard, otherwise if shaking they turn red
void loop() {
  shaking();
  int LED_num = random(10);
  if(totalAccel < 15) {
        CircuitPlayground.setPixelColor(LED_num, 0, 255, 0);
        delay(50);
        CircuitPlayground.setPixelColor(LED_num, 0, 0, 0);
        delay(50);
  } else {
        CircuitPlayground.setPixelColor(LED_num, 255, 0, 0);
        delay(50);
        CircuitPlayground.setPixelColor(LED_num, 0, 0, 0);
        delay(50);
  }
}

