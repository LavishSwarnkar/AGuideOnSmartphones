#include "ui.h"
#include <conio.h>
#include <dos.h>
#include <fstream>
#include <cstdio>

using namespace std;

void drawHalfBorder(int top, int left, int right, int bottom, int color, int delay_ms) {
    int i, j, k;
    textcolor(color);
    for (i = right / 2, k = (right / 2) + 1; i >= left; i--, k++) {
        for (j = top; j < bottom + 1; j++) {
            gotoxy(i, j); cprintf("Û");
            if (k == 80 && j == 25) {
                gotoxy(k, j); cprintf("Û\b");
            }
            else {
                gotoxy(k, j); cprintf("Û");
            }
        }
        delay(delay_ms);
    }
}

void drawSlidingCurtain(int color, bool down) {
    int i, j;
    textcolor(color);
    if (down) {
        for (i = 24; i >= 1; i--) {
            for (j = 1; j < 81; j++) {
                gotoxy(j, i); cprintf("Û");
            }
            delay(2);
        }
    }
    else {
        for (i = 1; i < 25; i++) {
            for (j = 1; j <= 80; j++) {
                gotoxy(j, i); cprintf("Û");
            }
            delay(2);
        }
    }
}

void drawBorderedBox(int top, int left, int right, int bottom, const char* pattern, int color, int bg_color, int delay_ms) {
    int i, j, tb = bottom, tr = right, rr, bb;
    textcolor(color);
    textbackground(bg_color);
    if ((right - left) % 2 == 0) rr = ((right - left) / 2) + 1;
    else rr = ((right - left) / 2) + 1;
    if ((bottom - top) % 2 == 0) bb = ((bottom - top) / 2) + 1;
    else bb = ((bottom - top) / 2) + 1;
    for (i = 1; i <= rr; i++) {
        gotoxy(i + left - 1, top); cprintf(pattern);
        gotoxy(tr, top); cprintf(pattern);
        gotoxy(i + left - 1, bottom); cprintf(pattern);
        gotoxy(tr, bottom); cprintf(pattern);
        if (i <= bb) {
            gotoxy(left, i + top - 1); cprintf(pattern);
            gotoxy(left, tb); cprintf(pattern);
            gotoxy(right, i + top - 1); cprintf(pattern);
            gotoxy(right, tb); cprintf(pattern);
        }
        tb--;
        tr--;
        delay(delay_ms);
    }
}

void drawFilledBox(int top, int left, int right, int bottom, const char* pattern, int color, int bg_color, int delay_ms) {
    int tt;
    if ((bottom - top) < (right - left))
        tt = ((bottom - top) / 2) + 1;
    else
        tt = ((right - left) / 2) + 1;
    for (int i = 0; i <= tt; i++)
        drawBorderedBox(top + i, left + i, right - i, bottom - i, pattern, color, bg_color, delay_ms);
}

void displayTextArt(const char* text, int x, int y, int color, int bg_color) {
    int i, j, k, n;
    textcolor(color);
    textbackground(bg_color);
    char ch, s2[100];
    for (i = 0; text[i] != NULL; i++) {
        ifstream fin("data\\text\\ab.dat");
        while (!fin.eof()) {
            fin.get(ch);
            if (ch == text[i])
                break;
        }

        for (j = 0; j < 5; j++) {
            fin.getline(s2, 6, '+');
            for (k = 0; s2[k] != NULL; k++)
                if (s2[k] == '*')
                    s2[k] = 'Û';
            gotoxy(x, y + j);
            cprintf(s2);
            delay(5);
        }
        x += 6;
        fin.close();
    }
}

void drawMosaic(int color) {
    textcolor(color);
    int x, y;
    ifstream fin("data\\text\\random.dat");
    for (int i = 0; i <= 10000; i++) {
        fin >> x;  fin >> y;
        gotoxy(x, y);
        cprintf("Û");
    }
    fin.close();

    textbackground(color);
    clrscr();
}

void drawImage(const char* file_path, int color, int x, int y) {
    int i, j;
    char s[80];
    ifstream fin(file_path);
    for (i = 0; i < 20; i++) {
        fin.getline(s, 80, 'p');
        for (j = 0; s[j] != NULL; j++) {
            if (s[j] == 'l')
                s[j] = 'Û';
            if (s[j] == 'k')
                s[j] = char(223);
            if (s[j] == 'u')
                s[j] = char(222);
        }
        textcolor(color);
        gotoxy(x, y);
        if (i > 1) gotoxy(x, y - 1 + i);
        cprintf(s);
        delay(20);
    }
    delay(700);
    fin.close();
}

void drawText(const char* file_path, int color, int x, int y, int text_bg_color, int box_bg_color) {
    drawFilledBox(12, 7, 78, 23, "Û", box_bg_color, 1, 0);
    int i, n, j;
    char s[80];
    ifstream fin(file_path);
    for (i = 0; i < 12; i++) {
        char s2[81];
        fin >> n;
        fin.getline(s, 80, 'p');
        for (j = 0; j < n; j++)
            s2[j] = ' ';

        int k = j;

        for (j = 0; s[j] != NULL; j++)
            s2[k + j] = s[j];

        s2[k + j] = NULL;

        for (j = 0; s[j] != NULL; j++) {
            if (s2[j] == 'l')
                s2[j] = 'Û';
            if (s2[j] == 'k')
                s2[j] = char(223);
            if (s2[j] == 'o')
                s2[j] = char(220);
        }
        textcolor(color);
        textbackground(text_bg_color);
        gotoxy(x, y + i);
        cprintf(s2);
        delay(20);
    }
    fin.close();
}