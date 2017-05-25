# NeoPixel WS2812

This demo control NeoPixel (WS2812) lights of LinkIt 7697 from a Web browser

## How to use

Please visit this [youtube video](https://www.youtube.com/watch?v=X2gVtvf1qUc) for demostration.

[![LinkIt 7697 + WS2812](https://img.youtube.com/vi/X2gVtvf1qUc/0.jpg)](https://www.youtube.com/watch?v=X2gVtvf1qUc "LinkIt 7697 + WS2812")

## Note

### Arduino side

The arduino sketch `NeoPixel_WS2812.ino` require modified `Adafruit_NeoPixel` library (with support of LinkIt 7697). Please goes to [here](https://github.com/SmallpTsai/Adafruit_NeoPixel) to download.

### Hardware setup

This demo assume an length=**16** WS2812 array, please connect **SIGNAL** pin to **P5** (or modify `PIN` in sketch), **VCC** to **5V**, GND to GND.
