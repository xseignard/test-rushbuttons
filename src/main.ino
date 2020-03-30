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
// SPIClass SPI2(&sercom2, 3, 5, 4, SPI_PAD_0_SCK_3, SERCOM_RX_PAD_1);

Adafruit_TLC59711 tlc = Adafruit_TLC59711(1, &SPI);

void setup() {
  SerialUSB.begin(9600);
  // pinPeripheral(3, PIO_SERCOM_ALT);
  // pinPeripheral(4, PIO_SERCOM_ALT);
  // pinPeripheral(5, PIO_SERCOM);
  tlc.begin();
  tlc.write();
  tlc.simpleSetBrightness(127);
  tlc.write();
}
void loop() {
  SerialUSB.println("White");
  tlc.setLED(0, 65535, 65535, 65535);
  tlc.setLED(1, 65535, 65535, 65535);
  tlc.setLED(2, 65535, 65535, 65535);
  tlc.setLED(3, 65535, 65535, 65535);
  tlc.write();
  delay(5000);
  SerialUSB.println("Black");
  tlc.setLED(0, 0, 0, 0);
  tlc.setLED(1, 0, 0, 0);
  tlc.setLED(2, 0, 0, 0);
  tlc.setLED(3, 0, 0, 0);
  tlc.write();
  delay(5000);
}