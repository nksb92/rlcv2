#include "display.h"

void init_display(Adafruit_SSD1306& dp){
  dp.clearDisplay();
  dp.setTextSize(1);
  dp.setTextColor(WHITE);
  dp.setFont(&FreeMonoBold9pt7b);  
  dp.display();
}

void hsv_display_update(Adafruit_SSD1306& dp, CHSV& out_val){
  uint8_t sel_rect = 1;
  uint8_t offset_text = 4;
  uint8_t offset = offset_text;
  uint8_t offset_y = 26;
  uint8_t spacing = 44;
  dp.clearDisplay();
  dp.setCursor(offset_text, 10);
  dp.print("HUE|SAT|VAL");
  for (int i = 0; i < 3; i++)
  {
    if (i == sel_rect)
    {
      dp.fillRect(i * spacing + offset, offset_y-13, 33, 16, WHITE);
      dp.setTextColor(BLACK);
      dp.setCursor(i * spacing + offset, offset_y);
      if (i == 0)
      {
        dp.print(out_val[i]);
      }
      else
      {
        dp.print(map(out_val[i], 0, 255, 0, 100));
      }
    }
    else
    {
      dp.setTextColor(WHITE);
      dp.setCursor(i * spacing + offset, offset_y);
      if (i == 0)
      {
        dp.print(out_val[i]);
      }
      else
      {
        dp.print(map(out_val[i], 0, 255, 0, 100));
      }
    }
  }
  dp.display();
}