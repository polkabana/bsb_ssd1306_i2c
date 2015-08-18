Python SSD1306
==============

This project contains a python module for interfacing with SSD1306 OLED device connected via I2C bus.

Partially based on Adafruit Arduino code

All code is GPLv2 licensed unless explicitly stated otherwise.

Building
--------

Use Black-Swift [VirtualBox VM] (http://www.black-swift.com/wiki/index.php?title=C/C%2B%2B_Building_and_Remote_Debugging_with_Eclipse)
In virtual machine change directory to /home/openwrt/openwrt
Copy sources to package/bsb_ssd1306_i2c/ directory, for example

Run and say yes for new bsb_ssd1306_i2c package:
```make oldconfig```

Run for compile package:
```make *package/bsb_ssd1306_i2c/compile V=s*.```

Check bin/ar71xx/packages/base/ for results (like ssd1306-i2c_0.1-1_ar71xx.ipk)

Usage
-----

First, setup I2C on your Black Swift board:

```
opkg install kmod-i2c-gpio-custom i2c-tools
insmod i2c-dev
insmod i2c-gpio-custom bus0=0,18,19
```

This mean that SDA connected to GPIO18 and SCL to GPIO19

Connect your SSD1306 OLED display. Don't forget about pull-up resistors!

Check your connections:
```
i2cdetect -y 0
```

Example programm

```python
from ssd1306_i2c import SSD1306
ssd = SSD1306(0, 0x3c) # /dev/i2c-0, device address 0x3c
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

    rect(x, y, w, h, color)

Draws rect at specified location, width, height and color on OLED display.

    rect_fill(x, y, w, h, color)

Draws and fills rect at specified location, width, height and color on OLED display.

    cursor(x, y)

Set text cursor at specified location.

    font(n, size=1)

Set text font (1 = 5x7) and size.

    char(ch, x=0, y=0, color=1)

Set text font (FONT_5x7, FONT_NUM8x16, etc) and size.

    write(string, x=0, y=0, color=1)

Draw string at current or specified position with current font and size.
