#include "ui.h"

#include <conio.h>
#include <dos.h>
#include <fstream>
#include <string>
#include <string_view>

namespace ui {

void drawHalfBorder(int top, int left, int right, int bottom, int color, int delay_ms) {
    textcolor(color);
    for (int i = right / 2, k = (right / 2) + 1; i >= left; --i, ++k) {
        for (int j = top; j <= bottom; ++j) {
            gotoxy(i, j);
            cprintf("Û");
            if (k == 80 && j == 25) {
                gotoxy(k, j);
                cprintf("Û\b");
            } else {
                gotoxy(k, j);
                cprintf("Û");
            }
        }
        delay(delay_ms);
    }
}

void drawSlidingCurtain(int color, bool down) {
    textcolor(color);
    if (down) {
        for (int i = 24; i >= 1; --i) {
            for (int j = 1; j <= 80; ++j) {
                gotoxy(j, i);
                cprintf("Û");
            }
            delay(2);
        }
    } else {
        for (int i = 1; i <= 25; ++i) {
            for (int j = 1; j <= 80; ++j) {
                gotoxy(j, i);
                cprintf("Û");
            }
            delay(2);
        }
    }
}

void drawBorderedBox(int top, int left, int right, int bottom, std::string_view pattern, int color, int bg_color, int delay_ms) {
    textcolor(color);
    textbackground(bg_color);

    int horizontal_steps = ((right - left) / 2) + 1;
    int vertical_steps = ((bottom - top) / 2) + 1;

    int r = right;
    int b = bottom;

    for (int i = 1; i <= horizontal_steps; i++) {
        gotoxy(left + i - 1, top); cprintf(pattern.data());
        gotoxy(r, top); cprintf(pattern.data());
        gotoxy(left + i - 1, bottom); cprintf(pattern.data());
        gotoxy(r, bottom); cprintf(pattern.data());

        if (i <= vertical_steps) {
            gotoxy(left, top + i - 1); cprintf(pattern.data());
            gotoxy(left, b); cprintf(pattern.data());
            gotoxy(right, top + i - 1); cprintf(pattern.data());
            gotoxy(right, b); cprintf(pattern.data());
        }
        r--;
        b--;
        delay(delay_ms);
    }
}

void drawFilledBox(int top, int left, int right, int bottom, std::string_view pattern, int color, int bg_color, int delay_ms) {
    int steps;
    int height = bottom - top;
    int width = right - left;

    if (height < width) {
        steps = (height / 2) + 1;
    } else {
        steps = (width / 2) + 1;
    }

    for (int i = 0; i <= steps; ++i) {
        drawBorderedBox(top + i, left + i, right - i, bottom - i, pattern, color, bg_color, delay_ms);
    }
}

void displayTextArt(std::string_view text, int x, int y, int color, int bg_color) {
    textcolor(color);
    textbackground(bg_color);

    for (char c : text) {
        std::ifstream fin("data/text/ab.dat");
        if (!fin) {
            return;
        }

        char file_char;
        while (fin.get(file_char)) {
            if (file_char == c) {
                break;
            }
        }

        if (fin.eof() && file_char != c) {
            fin.close();
            x += 6;
            continue;
        }

        for (int j = 0; j < 5; ++j) {
            std::string line;
            std::getline(fin, line, '+');
            for (char& ch_in_line : line) {
                if (ch_in_line == '*') {
                    ch_in_line = 'Û';
                }
            }
            gotoxy(x, y + j);
            cprintf("%s", line.c_str());
            delay(5);
        }
        x += 6;
        fin.close();
    }
}

void drawMosaic(int color) {
    textcolor(color);
    std::ifstream fin("data/text/random.dat");
    if (!fin) return;

    int x, y;
    while (fin >> x >> y) {
        gotoxy(x, y);
        cprintf("Û");
    }
    fin.close();

    textbackground(color);
    clrscr();
}

void drawImage(std::string_view file_path, int color, int x, int y) {
    std::ifstream fin(file_path.data());
    if (!fin) return;

    textcolor(color);
    for (int i = 0; i < 20; ++i) {
        std::string line;
        std::getline(fin, line, 'p');
        if (fin.fail()) break;

        for (char& c : line) {
            if (c == 'l') c = 'Û';
            if (c == 'k') c = char(223);
            if (c == 'u') c = char(222);
        }

        if (i > 1) {
            gotoxy(x, y - 1 + i);
        } else {
            gotoxy(x, y);
        }
        cprintf("%s", line.c_str());
        delay(20);
    }
    delay(700);
    fin.close();
}

void drawText(std::string_view file_path, int color, int x, int y, int text_bg_color, int box_bg_color) {
    drawFilledBox(12, 7, 78, 23, "Û", box_bg_color, 1, 0);

    std::ifstream fin(file_path.data());
    if (!fin) return;

    for (int i = 0; i < 12; ++i) {
        int padding;
        fin >> padding;
        if (fin.fail()) break;

        fin >> std::ws;

        std::string line;
        std::getline(fin, line, 'p');
        if (fin.fail()) break;

        std::string padded_line(padding, ' ');
        padded_line += line;

        for (char& c : padded_line) {
            if (c == 'l') c = 'Û';
            if (c == 'k') c = char(223);
            if (c == 'o') c = char(220);
        }
        textcolor(color);
        textbackground(text_bg_color);
        gotoxy(x, y + i);
        cprintf("%s", padded_line.c_str());
        delay(20);
    }
    fin.close();
}

} // namespace ui