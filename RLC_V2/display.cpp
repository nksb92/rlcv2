#include "display.h"

void init_display(Adafruit_SSD1306& dp) {
  dp.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  dp.clearDisplay();
  dp.setTextSize(1);
  dp.setTextColor(WHITE);
  dp.setFont(&FreeMonoBold9pt7b);
  dp.display();
}

void hsv_display_update(Adafruit_SSD1306& dp, C_HSV out_val, uint8_t current_state) {
  uint8_t offset = 4;
  uint8_t offset_y = 26;
  uint8_t spacing = 44;
  
  dp.setTextColor(WHITE);
  dp.clearDisplay();
  dp.setCursor(offset, 10);
  dp.print("HUE|SAT|VAL");

  for (int i = 0; i < 3; i++) {
    if (i == current_state) {
      dp.fillRect(i * spacing + offset, offset_y - 13, 33, 16, WHITE);
      dp.setTextColor(BLACK);
      dp.setCursor(i * spacing + offset, offset_y);
      if (i == 0) {
        dp.print(out_val.hue);
      } else if (i == 1) {
        dp.print(out_val.sat_p);
      } else {
        dp.print(out_val.val_p);
      }
    } else {
      dp.setTextColor(WHITE);
      dp.setCursor(i * spacing + offset, offset_y);
      if (i == 0) {
        dp.print(out_val.hue);
      } else if (i == 1) {
        dp.print(out_val.sat_p);
      } else {
        dp.print(out_val.val_p);
      }
    }
  }
  dp.display();
}