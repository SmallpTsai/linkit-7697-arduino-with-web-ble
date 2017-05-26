# LinkIt 7697 Arduino with Web BLE

This repo contains some LinkIt 7697 Arduino project with Web BLE interface.

With an BLE-enabled **laptop** (ex. Macbook) or an BLE-enabled **mobile phone** (ex. Android phone), you can use them to interact with LinkIt 7697 devices.

* **_LinkIt 7697_**
  * An Wi-Fi / BLE HDK, with Arduino IDE, by MediaTek. see https://docs.labs.mediatek.com/resource/linkit7697-arduino/en.
* **_Web BLE_**
  * Web bluetooth API [Link](https://developers.google.com/web/updates/2015/07/interact-with-ble-devices-on-the-web) enables browser to use Bluetooth functionality.
  * It is NOT W3C standard, therefore only partial browsers/platforms support it. Currently it is only available on:
    * **Chrome** browser - Desktop version
    * **Chrome** browser - Android 6 (Marshmallow) and above
    * Check https://www.chromestatus.com/feature/5264933985976320 for latest status.

```diff
- iOS: Web Bluetooth API is not supported yet
- Android: require Android 6 (Marshmallow) and above
```

## SimplePeripheral

This demo shows how Web browser to toggles on/off LED on the LinkIt 7697.

visit [SimplePeripheral](SimplePeripheral) for more detail.

## SmartConnection

This demo shows how to send Wi-Fi configuration to LinkIt 7697 via BLE. LinkIt 7697 then use the configuration to connect to wireless network.

visit [SmartConnection](SmartConnection) for more detail.

## NeoPixel_WS2812

This demo shows how Web browser control NeoPixel (WS2812) lights with LinkIt 7697.

visit [NeoPixel_WS2812](NeoPixel_WS2812) for more detail.
