# SmartConnection

This demo send Wi-Fi configuration to LinkIt 7697 via BLE. LinkIt 7697 then use the configuration to connect to wireless network.

## How to Use

* Build and upload `SmartConnection.ino` sketch to LinkIt 7697

* Visit https://smallptsai.github.io/linkit-7697-arduino-with-web-ble/SmartConnection/web_ble.html with Web Bluetooth API enabled browser <br>(screenshot taken from Chrome on Mac OS X)
  
* Click `Connect` button, select `BLE SMTCN` device and pair.
  
* Input SSID and password of your wireless network. Click `Send` button.

* LinkIt 7697 will receive the configuration and try to connect to the SSID.

