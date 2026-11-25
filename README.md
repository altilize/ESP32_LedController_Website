# ESP32 LED Controller Website

An ESP32 that hosts its own Wi-Fi access point and a web page with buttons to turn an LED on, off, or blink it.

<!-- TODO: add demo GIF/photo -->

## Features

- ESP32 runs in SoftAP mode, so no router is needed
- Built-in `WebServer` on port 80 serving a single styled HTML page
- Three modes: ON, OFF and blink (300 ms period)
- Uses HTTP 303 redirects so each button returns to the main page

## Hardware

| Part | Pin |
| --- | --- |
| ESP32 dev board | |
| LED (with series resistor) | GPIO 14 |

## Endpoints

| Path | Action |
| --- | --- |
| `/` | Control page |
| `/turnon` | LED on |
| `/turnoff` | LED off |
| `/blink` | Blink mode |

## Build and run

1. Open `ESP32_LedController_Website.ino` in the Arduino IDE with the ESP32 board package installed.
2. Change the AP `ssid` and `password` at the top of the sketch.
3. Upload, then connect a phone or laptop to the AP.
4. Open the IP printed on the serial monitor (115200 baud), by default `http://192.168.4.1`.
