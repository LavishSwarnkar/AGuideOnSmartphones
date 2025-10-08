#ifndef UI_H
#define UI_H

#include <string_view>

namespace ui {

void drawHalfBorder(int top, int left, int right, int bottom, int color, int delay_ms = 5);
void drawSlidingCurtain(int color, bool down = true);
void drawBorderedBox(int top = 2, int left = 1, int right = 80, int bottom = 24, std::string_view pattern = "", int color = 7, int bg_color = 0, int delay_ms = 5);
void drawFilledBox(int top = 2, int left = 1, int right = 80, int bottom = 24, std::string_view pattern = "", int color = 7, int bg_color = 0, int delay_ms = 5);
void displayTextArt(std::string_view text, int x, int y, int color, int bg_color);
void drawMosaic(int color);
void drawImage(std::string_view file_path, int color = 15, int x = 35, int y = 12);
void drawText(std::string_view file_path, int color = 14, int x = 7, int y = 12, int text_bg_color = 14, int box_bg_color = 6);

} // namespace ui

#endif // UI_H