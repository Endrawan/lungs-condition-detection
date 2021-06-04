#ifndef _MONITOR_LCD_
#define _MONITOR_LCD_

#include <LiquidCrystal_I2C.h>

class MonitorLCD {
  private:
  LiquidCrystal_I2C* _lcd;
  
  public:
  MonitorLCD(uint8_t address, uint8_t cols, uint8_t rows) {
    _lcd = new LiquidCrystal_I2C(address, cols, rows);
    _lcd->init();
    _lcd->backlight();
  }

  void showText(uint8_t row, uint8_t col, const char text[]) {
    _lcd->setCursor(col, row);
    _lcd->print(text);
  }

  void clear() {
    _lcd->clear();
  }
};

#endif
