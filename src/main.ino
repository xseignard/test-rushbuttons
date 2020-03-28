#include <Adafruit_TLC59711.h>

Adafruit_TLC59711 tlc = Adafruit_TLC59711(1, 5, 4);

void setup() {
  SerialUSB.begin(9600);
  tlc.begin();
  tlc.write();
}
void loop() {
  tlc.simpleSetBrightness(128);
  tlc.write();
  for (int i = 0; i < 4; i++) {
    tlc.setLED(i, 65535, 65535, 65535);
    tlc.write();
  }
  delay(5000);
  for (int i = 0; i < 4; i++) {
    tlc.setLED(i, 0, 0, 0);
    tlc.write();
  }
  delay(5000);
}