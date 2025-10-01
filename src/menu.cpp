#include "menu.h"
#include "ui.h"
#include "auth.h"
#include "phone_data.h"
#include "filter.h"
#include "export.h"
#include <iostream>
#include <conio.h>
#include <dos.h>
#include <process.h>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

void displayWelcomeScreen() {
    clrscr();
    char s[80];
    delay(1500);
    textmode(C80);

    drawHalfBorder(1, 1, 80, 24, 1, 30);
    drawHalfBorder(1, 3, 80, 24, 10, 30);
    drawHalfBorder(1, 5, 80, 24, 9, 30);

    ifstream fin("data\\text\\ls.dat");
    for (int i = 0; i <= 23; i++) {
        gotoxy(34, 1);
        if (i > 0 && i < 11)    gotoxy(34, i);
        if (i >= 11 && i < 17)  gotoxy(22, i);
        if (i >= 17 && i <= 23) gotoxy(16, i);
        fin.getline(s, 60, 'p');
        for (int j = 0; s[j] != NULL; j++) {
            if (s[j] == 'l' || s[j] == 's')
                s[j] = 'Û';
        }
        textcolor(10); textbackground(1);
        cprintf(s);
        delay(30);
    }
    fin.close();
    delay(700);
    drawSlidingCurtain(6, true);

    displayTextArt("presents", 18, 7, 3, 6);
    displayTextArt("a", 9, 14, 3, 6);
    displayTextArt("guide", 23, 14, 3, 6);
    displayTextArt("on", 61, 14, 3, 6);
    delay(700);
    drawSlidingCurtain(4, false);

    displayTextArt("smart", 26, 7, 0, 12);
    displayTextArt("phones", 23, 14, 0, 12);
    delay(700);
    drawSlidingCurtain(4, true);

    fin.open("data\\text\\bp.dat");
    for (int i = 0; i < 20; i++) {
        fin.getline(s, 80, 'p');
        for (int j = 0; s[j] != NULL; j++) {
            if (s[j] == 'l') s[j] = 'Û';
            if (s[j] == 'k') s[j] = char(223);
            if (s[j] == 'o') s[j] = char(220);
        }
        textcolor(14);
        gotoxy(28, 3);
        if (i > 1)    gotoxy(28, 2 + i);
        cprintf(s);
        delay(30);
    }
    delay(700);
    drawSlidingCurtain(3, false);
}

void displayOverview() {
    char s[80], s2[81];
    drawBorderedBox(2, 1, 80, 24, "Û", 1, 14);
    drawBorderedBox(3, 2, 79, 23, ":", 1, 3);
    displayTextArt("overview", 18, 5, 0, 3);
    drawBorderedBox(11, 18, 65, 11, "Û", 1, 14);

    ifstream fin("data\\text\\ov.dat");
    for (int i = 0; i < 6; i++) {
        int n;
        fin >> n;
        fin.getline(s, 80, '*');
        for (int j = 0; j < n; j++)
            s2[j] = ' ';
        int k = j;
        for (j = 0; s[j] != NULL; j++)
            s2[k + j] = s[j];
        s2[k + j] = NULL;
        textcolor(0);
        textbackground(3);
        gotoxy(4, 14 + i);
        cprintf(s2);
        delay(40);
    }
    delay(700);
    fin.close();
    drawSlidingCurtain(2, true);
}

void displayGuidelines() {
    char s[80];
    drawBorderedBox(2, 1, 80, 24, "Û", 10, 14);
    drawBorderedBox(3, 2, 79, 23, ":", 10, 2);
    displayTextArt("guideline", 15, 5, 0, 10);
    drawBorderedBox(11, 15, 67, 11, "Û", 0, 14);

    ifstream fin("data\\text\\gl.dat");
    for (int i = 0; i < 6; i++) {
        int n;
        char s2[81];
        fin >> n;
        fin.getline(s, 80, '*');
        for (int j = 0; j < n; j++)
            s2[j] = ' ';
        int k = j;
        for (j = 0; s[j] != NULL; j++)
            s2[k + j] = s[j];
        s2[k + j] = NULL;
        textcolor(0); textbackground(2);
        gotoxy(11, 14 + i);
        cprintf(s2);
        delay(30);
    }
    fin.close();
    delay(700);
}

void displayLoginScreen() {
    clrscr();
    char k = '0';
    char s1[50] = ">> NEW USER? CREATE A NEW ACCOUNT NOW!";
    char s2[30] = ">> EXISTING USER? LOGIN NOW!";
    char s3[30] = ">> CHANGE PASSWORD";
    char s4[30] = ">> FORGOT PASSWORD? RENEW IT!";
    char s5[80] = "(ARROW KEYS / W,A,S,D)-SELECTION  || 'C'-CONFIRMATION  || 'M'-ADMINISTRATOR";

    int ch = 1, f = 0;
    for (int i = 0; i <= 14; i++) {
        textbackground(i);
        clrscr();
        delay(40);
    }
    textbackground(1);
    clrscr();
    textcolor(1);

    drawBorderedBox(2, 1, 80, 24, "Û", 15, 1);
    displayTextArt("login", 26, 4, 15, 1);
    drawBorderedBox(10, 26, 55, 10, "Û", 7, 7);
    drawFilledBox(12, 18, 62, 22, "Û", 0, 7);
    drawBorderedBox(12, 18, 62, 22, "Û", 15, 2);
    textcolor(15); textbackground(0);
    gotoxy(22, 14); cprintf(s1);
    textcolor(15); textbackground(1);
    gotoxy(22, 16); cprintf(s2);
    gotoxy(22, 18); cprintf(s3);
    gotoxy(22, 20); cprintf(s4);

    textcolor(15); textbackground(1);
    gotoxy(3, 23); cprintf(s5);
    gotoxy(70, 4); cprintf("'E'-EXIT");

    while (1) {
        k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && ch != 1)
            ch -= 1;
        else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && ch != 4)
            ch += 1;
        else if (k == 'c' || k == 'C' || k == 13) {
            drawFilledBox(12, 3, 78, 23, "Û", 1, 1);
            drawBorderedBox(10, 26, 55, 10, "Û", 7, 1);
            textcolor(0); textbackground(6);
            switch (ch) {
            case 1: registerNewUser(); break;
            case 2: loginUser(); break;
            case 3: changePassword(); break;
            case 4: forgotPassword(); break;
            }
            f = 1;
        }
        else if (k == 'e' || k == 'E')
            exitApplication();
        else if (k == 'm' || k == 'M')
        {
            adminMenu(); f = 1;
        }
        if (f) {
            drawBorderedBox(10, 26, 55, 10, "Û", 7, 1, 0);
            drawFilledBox(12, 4, 76, 23, "Û", 1, 1, 0);
            drawFilledBox(12, 18, 62, 22, "Û", 0, 7, 0);
            drawBorderedBox(12, 18, 62, 22, "Û", 15, 2, 0);
            textcolor(15); textbackground(0);
            gotoxy(22, 14); cprintf(s1);
            textcolor(0); textbackground(7);
            gotoxy(22, 16); cprintf(s2);
            gotoxy(22, 18); cprintf(s3);
            gotoxy(22, 20); cprintf(s4);
            textcolor(15); textbackground(1);
            gotoxy(3, 23); cprintf(s5);
            gotoxy(70, 4); cprintf("'E'-EXIT");
            gotoxy(70, 5); cprintf("        ");
            f = 0;
        }

        switch (ch) {
        case 1:
            textcolor(15); textbackground(0);
            gotoxy(22, 14); cprintf(s1);
            textcolor(15); textbackground(1);
            gotoxy(22, 16); cprintf(s2);
            gotoxy(22, 18); cprintf(s3);
            gotoxy(22, 20); cprintf(s4);
            break;
        case 2:
            textcolor(15); textbackground(1);
            gotoxy(22, 14); cprintf(s1);
            textcolor(15); textbackground(0);
            gotoxy(22, 16); cprintf(s2);
            textcolor(15); textbackground(1);
            gotoxy(22, 18); cprintf(s3);
            gotoxy(22, 20); cprintf(s4);
            break;
        case 3:
            textcolor(15); textbackground(1);
            gotoxy(22, 14); cprintf(s1);
            gotoxy(22, 16); cprintf(s2);
            textcolor(15); textbackground(0);
            gotoxy(22, 18); cprintf(s3);
            textcolor(15); textbackground(1);
            gotoxy(22, 20); cprintf(s4);
            break;
        case 4:
            textcolor(15); textbackground(1);
            gotoxy(22, 14); cprintf(s1);
            gotoxy(22, 16); cprintf(s2);
            gotoxy(22, 18); cprintf(s3);
            textcolor(15); textbackground(0);
            gotoxy(22, 20); cprintf(s4);
            break;
        }
    }
}

void displayMainMenu() {
    int i, j, ch = 1;
    char s[20], k = '0';
    drawMosaic(1);
    drawBorderedBox(2, 2, 79, 24, "Û", 10, 1);
    displayTextArt("welcome", 4, 4, 14, 1);
    displayTextArt("to", 47, 4, 10, 1);
    displayTextArt("the", 60, 4, 14, 1);
    displayTextArt("wonderful", 15, 11, 10, 1);
    displayTextArt("world", 14, 18, 14, 1);
    displayTextArt("of", 58, 18, 10, 1);
    delay(300);
    drawMosaic(2);
    drawBorderedBox(2, 2, 79, 24, "Û", 1, 10);
    displayTextArt("smart", 26, 7, 1, 10);
    displayTextArt("phones", 23, 14, 1, 10);

    drawImage("data\\images\\sp.im", 11, 6, 8);
    drawImage("data\\images\\pro.im", 11, 60, 4);
    drawImage("data\\images\\bat.im", 11, 60, 14);

    int f = 0;
    delay(300);
    drawMosaic(1);
    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("main", 15, 4, 10, 6);
    displayTextArt("menu", 44, 4, 10, 6);
    drawFilledBox(11, 3, 43, 23, "Û", 3, 1);
    drawFilledBox(11, 44, 78, 23, "Û", 2, 1);
    textcolor(1); textbackground(3);
    gotoxy(4, 12); cprintf("Û SMART PHONES BRIEF INFORMATION");
    textcolor(11); textbackground(1);
    gotoxy(4, 12); cprintf("Û");
    textcolor(1); textbackground(3);
    gotoxy(4, 14); cprintf("Û SOME POPULAR SMART PHONES DESCRIPTION");
    gotoxy(4, 16); cprintf("Û SMART PHONES FILTERING ");
    gotoxy(4, 18); cprintf("Û ADD / MODIFY / EXPORT DATA ");
    gotoxy(4, 20); cprintf("Û STATUS");
    gotoxy(4, 22); cprintf("Û AMAZE ME");
    textbackground(2);
    gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
    gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
    gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
    gotoxy(45, 17); cprintf(">> 'E'- EXIT");
    gotoxy(45, 19); cprintf(">> 'L'-HELP | 'B'-ABOUT");

    while (1) {
        k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && ch != 1)
            ch -= 1;
        else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && ch != 6)
            ch += 1;
        else if (k == 'c' || k == 'C' || k == 13) {
            textcolor(1); textbackground(3);
            switch (ch) {
            case 1: displayInformationMenu();    break;
            case 2: displayDescriptionMenu();    break;
            case 3: displayFilterMenu();  break;
            case 4:    displayDataManagementMenu();     break;
            case 5: displayStatus();     break;
            case 6: displayAmazeMe();   break;
            }
            f = 1;
        }
        else if (k == 'e' || k == 'E')
            exitApplication();
        else if (k == 'l' || k == 'L') {
            displayHelp(); f = 1;
        }
        else if (k == 'b' || k == 'B') {
            displayAbout(); f = 1;
        }

        if (f) {
            drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
            drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
            drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
            displayTextArt("main", 15, 4, 10, 6);
            displayTextArt("menu", 44, 4, 10, 6);
            drawFilledBox(11, 3, 43, 23, "Û", 3, 1, 0);
            drawFilledBox(11, 44, 78, 23, "Û", 2, 1, 0);
            textcolor(1); textbackground(3);
            gotoxy(4, 12); cprintf("Û SMART PHONES BRIEF INFORMATION");
            textcolor(11); textbackground(1);
            gotoxy(4, 12); cprintf("Û");
            textcolor(1); textbackground(3);
            gotoxy(4, 14); cprintf("Û SOME POPULAR SMART PHONES DESCRIPTION");
            gotoxy(4, 16); cprintf("Û SMART PHONES FILTERING ");
            gotoxy(4, 18); cprintf("Û ADD / MODIFY /EXPORT DATA ");
            gotoxy(4, 20); cprintf("Û STATUS");
            gotoxy(4, 22); cprintf("Û AMAZE ME");
            textbackground(2);
            gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
            gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
            gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
            gotoxy(45, 17); cprintf(">> 'E'- EXIT");
            gotoxy(45, 19); cprintf(">> 'L'-HELP | 'B'-ABOUT");
            f = 0;
        }

        for (i = 0; i <= 5; i++) {
            gotoxy(4, 12 + (2 * i));
            if (i == ch - 1) textcolor(11);
            else     textcolor(1);
            cprintf("Û");
        }
    }
}

void displayInformationMenu() {
    char k = '0';
    int ch = 1, f = 0;
    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("information", 9, 4, 10, 6);
    drawFilledBox(11, 3, 43, 23, "Û", 3, 1);
    drawFilledBox(11, 44, 78, 23, "Û", 2, 1);
    textcolor(1); textbackground(3);
    gotoxy(4, 12); cprintf("Û HISTORY OF SMART PHONES");
    textcolor(11); textbackground(1);
    gotoxy(4, 12); cprintf("Û");
    textcolor(1); textbackground(3);
    gotoxy(4, 14); cprintf("Û FEATURES OF SMART PHONES");
    gotoxy(4, 22); cprintf("'B'-BACK");
    textbackground(2);
    gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
    gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
    gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
    gotoxy(45, 17); cprintf(">> 'E'- EXIT");

    while (1) {
        k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && ch != 1)
            ch -= 1;
        else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && ch != 2)
            ch += 1;
        else if (k == 'c' || k == 'C' || k == 13) {
            drawFilledBox(3, 3, 78, 23, "Û", 6, 7);
            textcolor(1); textbackground(3);
            switch (ch) {
            case 1: displayHistory();  f = 1; break;
            case 2: displayFeaturesMenu(); f = 1; break;
            }
        }
        else if (k == 'e' || k == 'E')
            exitApplication();
        else if (k == 'b' || k == 'B')
            return;

        if (f) {
            drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
            drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
            drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
            displayTextArt("information", 9, 4, 10, 6);
            drawFilledBox(11, 3, 43, 23, "Û", 3, 1, 0);
            drawFilledBox(11, 44, 78, 23, "Û", 2, 1, 0);
            textcolor(1); textbackground(3);
            gotoxy(4, 12); cprintf("Û HISTORY OF SMART PHONES");
            textcolor(11); textbackground(1);
            gotoxy(4, 12); cprintf("Û");
            textcolor(1); textbackground(3);
            gotoxy(4, 14); cprintf("Û FEATURES OF SMARTPHONES");
            gotoxy(4, 22); cprintf("'B'-BACK");
            textbackground(2);
            gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
            gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
            gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
            gotoxy(45, 17); cprintf(">> 'E'- EXIT");
            f = 0;
        }

        for (int i = 0; i < 2; i++) {
            gotoxy(4, 12 + (2 * i));
            if (i == ch - 1)  textcolor(11);
            else      textcolor(1);
            cprintf("Û");
        }
    }
}

void displayDescriptionMenu() {
    int ch = 1, g = 0;
    char k = '0';
    drawFilledBox(2, 2, 79, 24, "Û", 7, 1);
    drawBorderedBox(2, 2, 79, 24, "Û", 15, 0);
    displayTextArt("description", 8, 4, 0, 15);
    drawFilledBox(11, 3, 78, 23, "Û", 0, 1, 0);
    drawText("data\\text\\dguide.dat", 15, 8, 12, 0, 0);
    getch();
    drawFilledBox(2, 2, 79, 24, "Û", 7, 1, 0);
    drawBorderedBox(2, 2, 79, 24, "Û", 15, 0, 0);
    displayTextArt("brands", 23, 4, 0, 15);
    drawFilledBox(11, 3, 78, 20, "Û", 0, 1, 0);
    drawFilledBox(21, 3, 78, 23, "Û", 7, 1, 0);
    textcolor(15); textbackground(0);
    gotoxy(5, 12); cprintf("Û APPLE        Û MICROMAX ");
    textcolor(2); textbackground(0);
    gotoxy(5, 12); cprintf("Û");
    textcolor(15); textbackground(0);
    gotoxy(5, 13); cprintf("Û ASUS         Û MICROSOFT ");
    gotoxy(5, 14); cprintf("Û BLACKBERRY   Û ONE PLUS ");
    gotoxy(5, 15); cprintf("Û GIONEE       Û OPPO ");
    gotoxy(5, 16); cprintf("Û HTC          Û SAMSUNG ");
    gotoxy(5, 17); cprintf("Û Le ECO       Û SONY ");
    gotoxy(5, 18); cprintf("Û LENOVO       Û XIAOMI ");
    gotoxy(5, 19); cprintf("Û LG           Û OTHER ");
    textcolor(0); textbackground(15);
    gotoxy(20, 22); cprintf("'B'-BACK || 'E'-EXIT || 'C'-CONFIRMATION");

    while (1) {
        k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && ch != 1)
            ch -= 1;
        else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && ch != 16)
            ch += 1;
        else if (k == 'c' || k == 'C' || k == 13) {
            textcolor(1); textbackground(3);
            switch (ch) {
            case 1:  displaySmartphonesByBrand("APPLE");   break;
            case 2:  displaySmartphonesByBrand("ASUS");    break;
            case 3:  displaySmartphonesByBrand("BLACKBERRY");   break;
            case 4:  displaySmartphonesByBrand("GIONEE");   break;
            case 5:  displaySmartphonesByBrand("HTC");   break;
            case 6:  displaySmartphonesByBrand("Le ECO");   break;
            case 7:  displaySmartphonesByBrand("LENOVO");   break;
            case 8:  displaySmartphonesByBrand("LG");   break;
            case 9:  displaySmartphonesByBrand("MICROMAX");   break;
            case 10: displaySmartphonesByBrand("MICROSOFT");   break;
            case 11: displaySmartphonesByBrand("ONEPLUS");   break;
            case 12: displaySmartphonesByBrand("OPPO");   break;
            case 13: displaySmartphonesByBrand("SAMSUNG");   break;
            case 14: displaySmartphonesByBrand("SONY");   break;
            case 15: displaySmartphonesByBrand("XIAOMI");   break;
            case 16: displaySmartphonesByBrand("OTHER");   break;
            }
            g = 1;
        }
        else if (k == 'e' || k == 'E')
            exitApplication();
        else if (k == 'b' || k == 'B')
            return;

        if (g) {
            drawFilledBox(2, 2, 79, 24, "Û", 7, 1, 0);
            drawBorderedBox(2, 2, 79, 24, "Û", 15, 0, 0);
            displayTextArt("brands", 23, 4, 0, 15);
            drawFilledBox(11, 3, 78, 20, "Û", 0, 1, 0);
            drawFilledBox(21, 3, 78, 23, "Û", 7, 1, 0);
            textcolor(15); textbackground(0);
            gotoxy(5, 12); cprintf("Û APPLE        Û MICROMAX ");
            gotoxy(5, 13); cprintf("Û ASUS         Û MICROSOFT ");
            gotoxy(5, 14); cprintf("Û BLACKBERRY   Û ONE PLUS ");
            gotoxy(5, 15); cprintf("Û GIONEE       Û OPPO ");
            gotoxy(5, 16); cprintf("Û HTC          Û SAMSUNG ");
            gotoxy(5, 17); cprintf("Û Le ECO       Û SONY ");
            gotoxy(5, 18); cprintf("Û LENOVO       Û XIAOMI ");
            gotoxy(5, 19); cprintf("Û LG           Û OTHER ");
            textcolor(0); textbackground(15);
            gotoxy(20, 22); cprintf("'B'-BACK || 'E'-EXIT || 'C'-CONFIRMATION"); g = 0;
        }

        for (int i = 0; i <= 7; i++) {
            gotoxy(5, 12 + i);
            if (i == ch - 1) textcolor(2);
            else textcolor(15);
            cprintf("Û");
        }
        if (ch > 8) {
            for (int i = 0; i <= 7; i++) {
                gotoxy(20, 12 + i);
                if (i == ch - 9) textcolor(2);
                else textcolor(15);
                cprintf("Û");
            }
        }
    }
}

void displayDataManagementMenu() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("modification", 5, 4, 10, 6);
    int f = 0;
    drawFilledBox(11, 3, 43, 23, "Û", 3, 1);
    drawFilledBox(11, 44, 78, 23, "Û", 2, 1);
    textcolor(1); textbackground(3);
    gotoxy(4, 12); cprintf("Û ADD DATA");
    textcolor(11); textbackground(1);
    gotoxy(4, 12); cprintf("Û");
    textcolor(1); textbackground(3);
    gotoxy(4, 14); cprintf("Û MODIFY DATA");
    gotoxy(4, 16); cprintf("Û EXPORT DATA");
    gotoxy(4, 22); cprintf("'B'-BACK");
    textbackground(2);
    gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
    gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
    gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
    gotoxy(45, 17); cprintf(">> 'E'- EXIT");
    char k = '0';
    int ch = 1;
    while (1) {
        k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && ch != 1)
            ch -= 1;
        else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && ch != 3)
            ch += 1;
        else if (k == 'c' || k == 'C' || k == 13) {
            drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
            textcolor(1); textbackground(3);
            switch (ch) {
            case 1: addSmartphoneRecord(); f = 1; break;
            case 2: modifySmartphoneRecord(); f = 1; break;
            case 3: exportData(); f = 1; break;
            }
        }
        else if (k == 'e' || k == 'E')
            exitApplication();
        else if (k == 'b' || k == 'B')
            return;

        if (f) {
            drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
            drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
            drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
            displayTextArt("modification", 5, 4, 10, 6);
            drawFilledBox(11, 3, 43, 23, "Û", 3, 1, 0);
            drawFilledBox(11, 44, 78, 23, "Û", 2, 1, 0);
            textcolor(1); textbackground(3);
            gotoxy(4, 12); cprintf("Û ADD DATA");
            textcolor(11); textbackground(1);
            gotoxy(4, 12); cprintf("Û");
            textcolor(1); textbackground(3);
            gotoxy(4, 14); cprintf("Û MODIFY DATA");
            gotoxy(4, 16); cprintf("Û EXPORT DATA");
            gotoxy(4, 22); cprintf("'B'-BACK");
            textbackground(2);
            gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
            gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
            gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
            gotoxy(45, 17); cprintf(">> 'E'- EXIT");
            f = 0;
        }

        for (int i = 0; i <= 2; i++) {
            gotoxy(4, 12 + (i * 2));
            if (i == ch - 1) textcolor(11);
            else    textcolor(1);
            cprintf("Û");
        }
    }
}

void displayFilterMenu() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1, 0);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
    displayTextArt("filteration", 8, 4, 10, 6);
    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
    drawText("data\\text\\fguide.dat", 14, 7, 12);
    getch(); drawFilledBox(12, 3, 78, 23, "Û", 6, 1, 0);
    while (1) {
        drawFilledBox(3, 3, 78, 23, "Û", 6, 1, 0);
        drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
        drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
        displayTextArt("filteration", 8, 4, 10, 6);
        drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
        drawFilledBox(12, 3, 78, 23, "Û", 6, 1, 0);
        int fno = 1, mno = 0, a[150], * p;
        char s[7];
        drawFilledBox(11, 3, 43, 23, "Û", 3, 1, 0);
        drawFilledBox(11, 44, 78, 23, "Û", 2, 1, 0);
        textcolor(1); textbackground(3);
        gotoxy(4, 12); cprintf("1 FILTER BY COMPANY NAME");
        textcolor(11); textbackground(1);
        gotoxy(4, 13); cprintf("Û");
        textcolor(1); textbackground(3);
        gotoxy(4, 13); cprintf("2 FILTER BY PROCESSOR");
        gotoxy(4, 14); cprintf("3 FILTER BY OPERATING SYSTEM");
        gotoxy(4, 15); cprintf("4 FILTER BY CAMERA");
        gotoxy(4, 16); cprintf("5 FILTER BY MEMORY");
        gotoxy(4, 17); cprintf("6 FILTER BY PRICE");
        gotoxy(4, 18); cprintf("7 FILTER BY NETWORK");
        gotoxy(4, 19); cprintf("8 FILTER BY BATTERY");
        gotoxy(4, 20); cprintf("9 FILTER BY YEAR");
        gotoxy(4, 21); cprintf("> ENTER FILTERATION SEQUENCE:           ");
        textbackground(2);
        gotoxy(45, 12); cprintf(">> WRITE FILTERATION SEQUENCE ");
        gotoxy(45, 13); cprintf("   FOR FILTERING IN THAT ");
        gotoxy(45, 14); cprintf("   ORDER");
        gotoxy(45, 15); cprintf(">> 'E'- EXIT");
        gotoxy(45, 17); cprintf(">> 'B'- BACK");
        gotoxy(45, 18); cprintf(">> 0 - FINGERPRINT SCANNER");
        gotoxy(34, 21);  gets(s);

        if (s[0] == 'e' || s[0] == 'E')
            exitApplication();
        else if (s[0] == 'b' || s[0] == 'B')
            return;

        a[0] = 10;
        for (int i = 0; s[i] != NULL; i++, fno++) {
            switch (s[i]) {
            case '0':  p = filterBySensor(a); break;
            case '1':  p = filterByCompanyName(a); break;
            case '2':  p = filterByProcessor(a); break;
            case '3':  p = filterByOS(a); break;
            case '4':  p = filterByCamera(a); break;
            case '5':  p = filterByMemory(a); break;
            case '6':  p = filterByPrice(a); break;
            case '7':  p = filterByNetwork(a); break;
            case '8':  p = filterByBattery(a); break;
            case '9':  p = filterByYear(a); break;
            default:  drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
                textcolor(0); textbackground(15);
                gotoxy(4, 22); cprintf("NO MOBILES FOUND. PRESS ANY KEY TO RETURN");
                getch(); return;
            }

            int j;
            for (j = 0; *(p + j) != 10; j++)
                a[j] = *(p + j);
            a[j] = 10;
            mno = j;
            if (fno >= 1 && mno == 0) {
                drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
                textcolor(0); textbackground(15);
                gotoxy(4, 22); cprintf("NO MOBILES FOUND. PRESS ANY KEY TO RETURN");
                getch(); return;
            }
        }
        displayFilteredSmartphones(a);
    }
}

void displayStatus() {
    Smartphone m;
    int i, n = 5;
    ifstream fin("data\\text\\mobinfo.dat", ios::binary);
    fin.seekg(0, ios::end);
    i = fin.tellg();
    fin.close();
    n = i / sizeof(m);
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1, 0);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
    displayTextArt("status", 23, 4, 10, 6);
    if (n == 0) {
        textcolor(0); textbackground(6);
        gotoxy(7, 15); cprintf("THIS PROGRAM IS HAS NO SMART PHONES DESCRIPTION");
    }
    else {
        textcolor(0); textbackground(6);
        gotoxy(7, 15); cprintf("THIS PROGRAM IS MAINTAINED BY A TOTAL OF      "); gotoxy(48, 15); cout << n;
        cprintf(" SMART PHONE'S DECRIPTION");
        getch();
        return;
    }
}

void displayAmazeMe() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("amaze", 19, 4, 10, 6);
    displayTextArt("me", 51, 4, 10, 6);
    drawText("data\\text\\ama.dat", 14, 9, 16);
    getch();
    drawText("data\\text\\ama2.dat", 14, 4, 12);
    char k = getch();
    if (k == 'B' || k == 'b') return;
    drawFilledBox(12, 3, 78, 23, "Û", 6, 1);
    drawText("data\\text\\ama3.dat", 14, 4, 12);
    getch();
}

void displayHelp() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("help", 29, 4, 10, 6);
    drawText("data\\text\\help.dat");
    getch();
}

void displayAbout() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("about", 26, 4, 10, 6);
    drawText("data\\text\\about.dat");
    getch();
}

void displayHistory() {
    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("history", 20, 4, 10, 6);
    drawText("data\\text\\m.dat", 15);
    int ch = 1;
    char k = '0';
    while (1) {
        k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && ch != 1)
            ch -= 1;
        else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && ch != 9)
            ch += 1;
        else if (k == 'e' || k == 'E')
            exitApplication();
        else if (k == 'b' || k == 'B')
            return;

        switch (ch) {
        case 1: drawText("data\\text\\m1.dat"); break;
        case 2: drawText("data\\text\\m2.dat"); break;
        case 3: drawText("data\\text\\m3.dat"); break;
        case 4: drawText("data\\text\\m4.dat"); break;
        case 5: drawText("data\\text\\m5.dat"); break;
        case 6: drawText("data\\text\\m6.dat"); break;
        case 7: drawText("data\\text\\m7.dat"); break;
        case 8: drawText("data\\text\\m8.dat"); break;
        case 9: drawText("data\\text\\m9.dat"); break;
        }
    }
}

void displayFeaturesMenu() {
    int ch = 1, f = 0, i;
    char k = '0';

    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("features", 17, 4, 10, 6);
    drawFilledBox(11, 3, 43, 23, "Û", 3, 1);
    drawFilledBox(11, 44, 78, 23, "Û", 2, 1);
    textcolor(1); textbackground(3);
    gotoxy(4, 12); cprintf("Û PROCESSOR");
    textcolor(11); textbackground(1);
    gotoxy(4, 12); cprintf("Û");
    textcolor(1); textbackground(3);
    gotoxy(4, 13); cprintf("Û OPERATING SYSTEM");
    gotoxy(4, 14); cprintf("Û MEMORY");
    gotoxy(4, 15); cprintf("Û BATTERY");
    gotoxy(4, 16); cprintf("Û CAMERA");
    gotoxy(4, 17); cprintf("Û DISPLAY");
    gotoxy(4, 18); cprintf("Û BODY");
    gotoxy(4, 19); cprintf("Û NETWORK");
    gotoxy(4, 20); cprintf("Û SENSORS");
    gotoxy(4, 22); cprintf("'B'-BACK");
    textbackground(2);
    gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
    gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
    gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
    gotoxy(45, 17); cprintf(">> 'E'- EXIT");
    while (1) {
        k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && ch != 1)
            ch -= 1;
        else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && ch != 9)
            ch += 1;
        else if (k == 'c' || k == 'C' || k == 13) {
            drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
            textcolor(1); textbackground(3);
            switch (ch) {
            case 1: displayProcessorInfo();  break;
            case 2: displayOSInfo();   break;
            case 3: displayMemoryInfo();  break;
            case 4: displayBatteryInfo();  break;
            case 5: displayCameraInfo();  break;
            case 6: displayDisplayInfo();  break;
            case 7: displayBodyInfo();  break;
            case 8: displayNetworkInfo();   break;
            case 9: displaySensorsInfo();  break;
            }
            f = 1;
        }
        else if (k == 'e' || k == 'E')
            exitApplication();
        else if (k == 'b' || k == 'B')
            return;

        if (f) {
            drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
            drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
            drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
            displayTextArt("features", 17, 4, 10, 6);
            drawFilledBox(11, 3, 43, 23, "Û", 3, 1, 0);
            drawFilledBox(11, 44, 78, 23, "Û", 2, 1, 0);
            textcolor(1); textbackground(3);
            gotoxy(4, 12); cprintf("Û PROCESSOR");
            textcolor(11); textbackground(1);
            gotoxy(4, 12); cprintf("Û");
            textcolor(1); textbackground(3);
            gotoxy(4, 13); cprintf("Û OPERATING SYSTEM");
            gotoxy(4, 14); cprintf("Û MEMORY");
            gotoxy(4, 15); cprintf("Û BATTERY");
            gotoxy(4, 16); cprintf("Û CAMERA");
            gotoxy(4, 17); cprintf("Û DISPLAY");
            gotoxy(4, 18); cprintf("Û BODY");
            gotoxy(4, 19); cprintf("Û NETWORK");
            gotoxy(4, 20); cprintf("Û SENSORS");
            gotoxy(4, 22); cprintf("'B'-BACK");
            textbackground(2);
            gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
            gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
            gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
            gotoxy(45, 17); cprintf(">> 'E'- EXIT");
            f = 0;
        }

        for (i = 0; i <= 8; i++) {
            gotoxy(4, 12 + (i));
            if (i == ch - 1) textcolor(11);
            else    textcolor(1);
            cprintf("Û");
        }
    }
}

void displayProcessorInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("processor", 15, 4, 10, 6);
    drawImage("data\\images\\pro.im", 15, 33);
    drawText("data\\text\\pro.dat", 14, 5);
    getch();
}

void displayOSInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("os", 35, 4, 10, 6);
    drawImage("data\\images\\os.im", 10, 30);
    drawText("data\\text\\os.dat", 14, 5);
    getch();
}

void displayBatteryInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("battery", 20, 4, 10, 6);
    drawImage("data\\images\\bat.im");
    drawText("data\\text\\bat.dat", 14, 9);
    getch();
}

void displayCameraInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("camera", 23, 4, 10, 6);
    drawImage("data\\images\\cam.im", 15, 32, 13);
    drawText("data\\text\\cam.dat", 14, 8);
    getch();
}

void displayDisplayInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("display", 20, 4, 10, 6);
    drawText("data\\text\\disp.dat");
    getch();
}

void displayBodyInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("body", 29, 4, 10, 6);
    drawText("data\\text\\body.dat", 14, 9);
    getch();
}

void displayNetworkInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("network", 20, 4, 10, 6);
    drawImage("data\\images\\net.im", 15, 25, 14);
    drawText("data\\text\\net.dat");
    getch();
}

void displaySensorsInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("sensors", 20, 4, 10, 6);
    drawText("data\\text\\sens.dat", 14);
    getch();
}

void displayMemoryInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("memory", 23, 4, 10, 6);
    drawImage("data\\images\\mem.im");
    drawText("data\\text\\mem.dat", 14, 6);
    getch();
}

void exitApplication() {
    textbackground(1);
    clrscr();
    char s[10], s2[10], s3[10];
    strcpy(s, "do");
    strcpy(s2, "you");
    strcpy(s3, "know");
    int i = strlen(s) + strlen(s2) + strlen(s3) + 19;
    drawBorderedBox(2, 2, 79, 24, "Û", 15, 0);
    i = (80 - i) / 2;
    displayTextArt(s, i / 2, 4, 15, 1);
    displayTextArt(s2, i / 2 + 15, 4, 15, 1);
    displayTextArt(s3, i / 2 + 36, 4, 15, 1);
    drawText("data\\text\\dyk.dat", 15, 6, 12, 1, 1);
    getch();
    exit(1);
}