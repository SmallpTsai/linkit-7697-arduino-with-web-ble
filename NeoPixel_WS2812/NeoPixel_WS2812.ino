/*
  This example configures LinkIt 7697 to act as a simple GATT server with 1 characteristic.
*/
#include <LBLE.h>
#include <LBLEPeriphral.h>
#include <Adafruit_NeoPixel.h>

// Define a simple GATT service with only 1 characteristic
LBLEService ledService("19B10030-E8F2-537E-4F6C-D104768A1214");
LBLECharacteristicBuffer controlCharacteristic("19B10031-E8F2-537E-4F6C-D104768A1214", LBLE_READ | LBLE_WRITE);

#define ADV_NAME "BLE WS2812"

#define PIN            5
#define NUMPIXELS      16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
uint8_t valueBuffer[4];

void setup() {

  // Initialize LED pin
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.clear();
  pixels.show();

  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  // Initialize BLE subsystem
  LBLE.begin();
  while (!LBLE.ready()) {
    delay(100);
  }
  Serial.println("BLE ready");

  Serial.print("Device Address = [");
  Serial.print(LBLE.getDeviceAddress());
  Serial.println("]");

  // configure our advertisement data.
  // In this case, we simply create an advertisement that represents an
  // connectable device with a device name
  LBLEAdvertisementData advertisement;
  advertisement.configAsConnectableDevice(ADV_NAME);

  // Configure our device's Generic Access Profile's device name
  // Ususally this is the same as the name in the advertisement data.
  LBLEPeripheral.setName(ADV_NAME);

  // Add characteristics into ledService
  ledService.addAttribute(controlCharacteristic);

  // Add service to GATT server (peripheral)
  LBLEPeripheral.addService(ledService);

  // start the GATT server - it is now 
  // available to connect
  LBLEPeripheral.begin();

  // start advertisment
  LBLEPeripheral.advertise(advertisement);
}

void loop() {
  delay(100);
  if (controlCharacteristic.isWritten()) {

    controlCharacteristic.getValue(valueBuffer, 4, 0);
    if(valueBuffer[0] > NUMPIXELS)
      valueBuffer[0] = NUMPIXELS;

    pixels.clear();
    for(int i=0;i<valueBuffer[0];i++){
      pixels.setPixelColor(i, pixels.Color(valueBuffer[1], valueBuffer[2], valueBuffer[3]));
    }
    pixels.show();    
  }
}
