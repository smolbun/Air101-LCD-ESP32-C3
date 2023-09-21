# Simple test for Air101-LCD TFT display module with LuatOS ESP32 C3 board
[Air101-LCD display and ESP32 C3 board](https://a.aliexpress.com/_mNkDs3o)

https://wiki.luatos.com/chips/esp32c3/board.html

⚠️ GPIO11 is connected to backlight of Air101-LCD module by default, but GPIO11 is constantly high for my LuatOS ESP32 C3 board, therefore I'm using GPIO0 to control the brightness.
