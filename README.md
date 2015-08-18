Python SSD1306
=============+

This project contains a python module for interfacing with SSD1306 OLED device connected via I2C bus.

Partialy based on Adafruit Arduino code

All code is GPLv2 licensed unless explicitly stated otherwise.

Usage
-----

First, setup I2C on your Black Swift board:

opkg install kmod-i2c-gpio-custom i2c-tools
insmod i2c-dev
insmod i2c-gpio-custom bus0=0,18,19

This mean than SDA connected to GPIO18 and SCL to GPIO19

Connect your SSD1306 OLED display. Don't forget about pull-up resistors!

```python
from ssd1306_i2c import SSD1306
ssd = SSD1306(0, 0x3c) # /dev/i2c-0, device addres 0x3c
ssd.clear()
ssd.circle(25, 25, 15, 1)
ssd.line(0, 0, 127, 20, 1);
ssd.update()
ssd.write("SSD1306 I2C", x=5, y=6)
ssd.update()
```


Methods
-------

    SSD1306(bus, address)

Connects to the specified I2C bus using device address

    update()

Update OLED display image from buffer.

    clear()

Clear OLED display.

    pixel(x, y, color)

Draws pixel at specified location and color on OLED display.

    line(x0, y0, x1, y1, color)

Draws line at specified locations and color on OLED display.

    line_vertical(x, y, len, color)

Draws vertical line at specified location, length and color on OLED display.

    line_horisontal(x, y, len, color)

Draws horisontal line at specified location, length and color on OLED display.

    rect_fill(x, y, w, h, color)

Draws and fills rect at specified location, width, height and color on OLED display.

    cursor(x, y)

Set text cursor at specified location.

    font(n, size=1)

Set text font (1 = 5x7) and size.

    char(ch)

Draw char at current position with current font and size.

    write(string, x=0, y=0)

Draw string at current or specified position with current font and size.
