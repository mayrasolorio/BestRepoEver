#include <Adafruit_CircuitPlayground.h>

int cap1;
int cap2;
int cap3;
int cap4;
float midi[127];
int A_four = 440;
int losing[3] = {63, 60, 65 };
int celebration[3] = {67, 69, 71 };


void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  generateMIDI();
  randomSeed(analogRead(0));
}



void loop() {
  cap1 = CircuitPlayground.readCap(A3);
  if (cap1 > 950) {
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    delay(200);
    CircuitPlayground.clearPixels();
    delay(200);
  }
  cap2 = CircuitPlayground.readCap(A1);
  if (cap2 > 950) {
    CircuitPlayground.setPixelColor(6, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0);
    delay(200);
    CircuitPlayground.clearPixels();
    delay(200);
  }
  cap3 = CircuitPlayground.readCap(A7);
  if (cap3 > 950) {
    for (int j = 0; j < sizeof(celebration) / sizeof(int); j++)
      CircuitPlayground.playTone(midi[celebration[j]], 100);
    CircuitPlayground.setPixelColor(4, 255, 255, 0);
    CircuitPlayground.setPixelColor(3, 255, 255, 0);
    delay(200);
    CircuitPlayground.clearPixels();
    delay(200);
  }
  cap4 = CircuitPlayground.readCap(A4);
  if (cap4 > 950) {
    for (int i = 0; i < sizeof(losing) / sizeof(int); i++)
      CircuitPlayground.playTone(midi[losing[i]], 250);
    CircuitPlayground.setPixelColor(1, 0, 0, 255);
    CircuitPlayground.setPixelColor(0, 0, 0, 255);
    delay(200);
    CircuitPlayground.clearPixels();
    delay(200);
  }
}



void generateMIDI() {
  for (int x = 0; x < 127; ++x) {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}
