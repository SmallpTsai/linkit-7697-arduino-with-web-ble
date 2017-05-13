# LinkIt 7697 Arduino with Web BLE

This repo contains some LinkIt 7697 Arduino project with Web BLE interface.

With an BLE-enabled laptop (ex. Macbook) or an BLE-enabled mobile phone, you can interact with LinkIt 7697 devices.

* LinkIt 7697: An Wi-Fi / BLE HDK, with Arduino IDE, by MediaTek. see https://docs.labs.mediatek.com/resource/linkit7697-arduino/en.
* Web BLE: Web bluetooth API [Link](https://developers.google.com/web/updates/2015/07/interact-with-ble-devices-on-the-web) enables browser to use Bluetooth functionality.
  * Web Bluetooth API is not W3C standard, only partial browser/platform support it. Currently it is available on:
    * Chrome browser (Desktop version)
    * Chrome browser (Android)
    * check https://www.chromestatus.com/feature/5264933985976320 for more detail.

## SimplePeripheral

This demo control USR LED of LinkIt 7697 by Web browser.

### How to Use

* Build and upload `SimplePeripheral/SimplePeripheral.ino` sketch to LinkIt 7697
* Visit https://smallptsai.github.io/linkit-7697-arduino-with-web-ble/SimplePeripheral/web_ble.html with Web Bluetooth API enabled browser


