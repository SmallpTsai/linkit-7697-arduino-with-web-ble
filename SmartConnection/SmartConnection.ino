/*
  This example configures LinkIt 7697 to act as a simple GATT server with 1 characteristic.

  To use it, open AppInventor project:

    * 

  Build & install it on Android id

  created Mar 2017
*/
#include <LWiFi.h>
#include <LBLE.h>
#include <LBLEPeriphral.h>

#define BLE_ADV_NAME "BLE SMTCN"

// Define a simple GATT service with only 1 characteristic
LBLEService mainService("29ab0000-257d-403f-8057-d1ab4ce78aa5");
LBLECharacteristicBuffer wifiSetupCharacteristic("29ab0001-257d-403f-8057-d1ab4ce78aa5", LBLE_WRITE);

void setup() {

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
  advertisement.configAsConnectableDevice(BLE_ADV_NAME);

  // Configure our device's Generic Access Profile's device name
  // Ususally this is the same as the name in the advertisement data.
  LBLEPeripheral.setName(BLE_ADV_NAME);

  // Add characteristics into ledService
  mainService.addAttribute(wifiSetupCharacteristic);

  // Add service to GATT server (peripheral)
  LBLEPeripheral.addService(mainService);

  // start the GATT server - it is now 
  // available to connect
  LBLEPeripheral.begin();

  // start advertisment
  Serial.print("Start to advertise as: ");
  Serial.println(BLE_ADV_NAME);
  LBLEPeripheral.advertise(advertisement);
}

void loop() {
  delay(100);
  if (wifiSetupCharacteristic.isWritten()) {
    LBLECharacteristicWrittenInfo info = wifiSetupCharacteristic.getLastWrittenInfo();
    char buf[256];
    wifiSetupCharacteristic.getValue((uint8_t*)buf, info.size, 0);

    String ssid = String(buf + buf[0]);
    String pwd = String(buf + buf[1]);

    Serial.println("Received Wi-Fi setup!");
    Serial.print("> SSID: ");
    Serial.println(ssid);
    Serial.print("> PWD:  ");
    Serial.println(pwd);

    int status;
    do {
      Serial.print("Attempting to connect to: ");
      Serial.println(ssid);
      status = WiFi.begin((char*)ssid.c_str(), pwd.c_str());
      
    } while(status != WL_CONNECTED);
    
    Serial.println("Wi-Fi connected!");        
  }
}
