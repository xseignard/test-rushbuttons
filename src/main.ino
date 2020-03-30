#include <Adafruit_TLC59711.h>
#include <SPI.h>
#include <wiring_private.h>

// This one is working, e.g using default pins
// data: 11
// clock: 13
// Adafruit_TLC59711 tlc = Adafruit_TLC59711(1);

// The following is not working
// bit-banging mode
// Adafruit_TLC59711 tlc = Adafruit_TLC59711(1, 5, 4);

// SERCOM SPI
// SPIClass SPI (&PERIPH_SPI, PIN_SPI_MISO, PIN_SPI_SCK, PIN_SPI_MOSI, PAD_SPI_TX, PAD_SPI_RX);
// not working...
SPIClass SPI2(&sercom2, 3, 5, 4, SPI_PAD_0_SCK_3, SERCOM_RX_PAD_1);

Adafruit_TLC59711 tlc = Adafruit_TLC59711(1, &SPI2);

void setup() {
  SerialUSB.begin(9600);
  SPI2.begin();
  pinPeripheral(3, PIO_SERCOM_ALT);
  pinPeripheral(4, PIO_SERCOM_ALT);
  pinPeripheral(5, PIO_SERCOM);
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