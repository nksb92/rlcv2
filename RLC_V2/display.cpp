#include "display.h"

uint8_t offset = 4;
uint8_t offset_y = 26;

void init_display(Adafruit_SSD1306& dp){
  dp.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  dp.clearDisplay();
  dp.setTextSize(1);
  dp.setTextColor(WHITE);
  dp.setFont(&FreeMonoBold9pt7b);  
  // dp.
  dp.display();
}

void hsv_display_update(Adafruit_SSD1306& dp, C_HSV out_val, uint8_t current_state) {
  
  uint8_t spacing = 44;
  
  dp.setTextColor(WHITE);
  dp.clearDisplay();
  dp.setCursor(offset, 10);
  dp.print("HUE|SAT|VAL");

  for (int i = 0; i < 3; i++) {
    if (i == current_state) {
      dp.fillRoundRect(i * spacing + offset, offset_y - 13, 33, 16, 3, WHITE);
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

void dmx_display_update(Adafruit_SSD1306& dp, DMX_V dmx_val){
  dp.setTextColor(WHITE);
  dp.clearDisplay();
  dp.setCursor(offset, 11);
  dp.print("DMX|");
  dp.print(dmx_val.start_address);
  dp.print("-");
  dp.print(dmx_val.start_address+dmx_val.used_addresses-1);
  dp.setCursor(offset, offset_y);
  dp.print("Using:");
  dp.print(dmx_val.used_addresses);
  dp.display();
}