#include "menu.h"
#include "ui.h"
#include "auth.h"
#include "phone_data.h"
#include "filter.h"
#include "export.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <dos.h>
#include <cstdlib>

namespace menu {

using namespace ui;

// Forward declarations for functions in this file
void drawMainMenuUI();
void drawInformationMenuUI();
void drawFeaturesMenuUI();
void drawDataManagementMenuUI();
void drawFilterMenuUI(const std::vector<int>& applied_filters);

void displayWelcomeScreen() {
    clrscr();
    delay(1500);
    textmode(C80);

    drawHalfBorder(1, 1, 80, 24, 1, 30);
    drawHalfBorder(1, 3, 80, 24, 10, 30);
    drawHalfBorder(1, 5, 80, 24, 9, 30);

    std::ifstream fin("data/text/ls.dat");
    if (!fin) return;

    std::string line;
    for (int i = 0; i <= 23; ++i) {
        if (i > 0 && i < 11)    gotoxy(34, i);
        if (i >= 11 && i < 17)  gotoxy(22, i);
        if (i >= 17 && i <= 23) gotoxy(16, i);

        std::getline(fin, line, 'p');
        if (fin.fail()) break;

        for (char& c : line) {
            if (c == 'l' || c == 's') c = 'Û';
        }
        textcolor(10);
        textbackground(1);
        cprintf("%s", line.c_str());
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

    drawImage("data/images/bp.dat", 14, 28, 3);
    delay(700);
    drawSlidingCurtain(3, false);
}

void displayOverview() {
    drawBorderedBox(2, 1, 80, 24, "Û", 1, 14);
    drawBorderedBox(3, 2, 79, 23, ":", 1, 3);
    displayTextArt("overview", 18, 5, 0, 3);
    drawBorderedBox(11, 18, 65, 11, "Û", 1, 14);

    std::ifstream fin("data/text/ov.dat");
    if (!fin) return;

    for (int i = 0; i < 6; ++i) {
        int n;
        fin >> n;
        if (fin.fail()) break;

        std::string line;
        std::getline(fin, line, '*');
        if (fin.fail()) break;

        std::string padded_line(n, ' ');
        padded_line += line;

        textcolor(0);
        textbackground(3);
        gotoxy(4, 14 + i);
        cprintf("%s", padded_line.c_str());
        delay(40);
    }
    fin.close();
    delay(700);
    drawSlidingCurtain(2, true);
}

void displayGuidelines() {
    drawBorderedBox(2, 1, 80, 24, "Û", 10, 14);
    drawBorderedBox(3, 2, 79, 23, ":", 10, 2);
    displayTextArt("guideline", 15, 5, 0, 10);
    drawBorderedBox(11, 15, 67, 11, "Û", 0, 14);

    std::ifstream fin("data/text/gl.dat");
    if (!fin) return;

    for (int i = 0; i < 6; ++i) {
        int n;
        fin >> n;
        if (fin.fail()) break;

        std::string line;
        std::getline(fin, line, '*');
        if (fin.fail()) break;

        std::string padded_line(n, ' ');
        padded_line += line;

        textcolor(0); textbackground(2);
        gotoxy(11, 14 + i);
        cprintf("%s", padded_line.c_str());
        delay(30);
    }
    fin.close();
    delay(700);
}

void drawLoginUI(int selected_option) {
    const std::vector<std::string> options = {
        ">> NEW USER? CREATE A NEW ACCOUNT NOW!",
        ">> EXISTING USER? LOGIN NOW!",
        ">> CHANGE PASSWORD",
        ">> FORGOT PASSWORD? RENEW IT!"
    };

    drawBorderedBox(2, 1, 80, 24, "Û", 15, 1, 0);
    displayTextArt("login", 26, 4, 15, 1);
    drawBorderedBox(10, 26, 55, 10, "Û", 7, 7, 0);
    drawFilledBox(12, 18, 62, 22, "Û", 0, 7, 0);
    drawBorderedBox(12, 18, 62, 22, "Û", 15, 2, 0);

    for (size_t i = 0; i < options.size(); ++i) {
        gotoxy(22, 14 + i * 2);
        if (i + 1 == selected_option) {
            textcolor(15); textbackground(0);
        } else {
            textcolor(15); textbackground(1);
        }
        cprintf("%s", options[i].c_str());
    }

    textcolor(15); textbackground(1);
    gotoxy(3, 23); cprintf("(ARROW KEYS / W,A,S,D)-SELECTION  || 'C'-CONFIRMATION  || 'M'-ADMINISTRATOR");
    gotoxy(70, 4); cprintf("'E'-EXIT");
}

void displayLoginScreen() {
    clrscr();
    for (int i = 0; i <= 14; ++i) {
        textbackground(i);
        clrscr();
        delay(40);
    }
    textbackground(1);
    clrscr();

    int choice = 1;
    drawLoginUI(choice);

    while (true) {
        char k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && choice > 1) {
            choice--;
        } else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && choice < 4) {
            choice++;
        } else if (k == 'c' || k == 'C' || k == 13) {
            drawFilledBox(12, 3, 78, 23, "Û", 1, 1);
            drawBorderedBox(10, 26, 55, 10, "Û", 7, 1);
            textcolor(0); textbackground(6);
            switch (choice) {
                case 1: auth::registerNewUser(); break;
                case 2: auth::loginUser(); break;
                case 3: auth::changePassword(); break;
                case 4: auth::forgotPassword(); break;
            }
            drawLoginUI(choice);
        } else if (k == 'e' || k == 'E') {
            exitApplication();
        } else if (k == 'm' || k == 'M') {
            auth::adminMenu();
            drawLoginUI(choice);
        }
        drawLoginUI(choice);
    }
}

void drawMainMenuUI(int selected_option) {
    const std::vector<std::string> options = {
        "SMART PHONES BRIEF INFORMATION",
        "SOME POPULAR SMART PHONES DESCRIPTION",
        "SMART PHONES FILTERING",
        "ADD / MODIFY / EXPORT DATA",
        "STATUS",
        "AMAZE ME"
    };

    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
    displayTextArt("main", 15, 4, 10, 6);
    displayTextArt("menu", 44, 4, 10, 6);
    drawFilledBox(11, 3, 43, 23, "Û", 3, 1, 0);
    drawFilledBox(11, 44, 78, 23, "Û", 2, 1, 0);

    for (size_t i = 0; i < options.size(); ++i) {
        gotoxy(4, 12 + i * 2);
        if (i + 1 == selected_option) {
            textcolor(11);
            textbackground(1);
        } else {
            textcolor(1);
            textbackground(3);
        }
        cprintf("Û %s", options[i].c_str());
    }

    textbackground(2);
    gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
    gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
    gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
    gotoxy(45, 17); cprintf(">> 'E'- EXIT");
    gotoxy(45, 19); cprintf(">> 'L'-HELP | 'B'-ABOUT");
}

void displayMainMenu() {
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

    drawImage("data/images/sp.im", 11, 6, 8);
    drawImage("data/images/pro.im", 11, 60, 4);
    drawImage("data/images/bat.im", 11, 60, 14);

    delay(300);
    drawMosaic(1);

    int choice = 1;
    drawMainMenuUI(choice);

    while (true) {
        char k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && choice > 1) {
            choice--;
        } else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && choice < 6) {
            choice++;
        } else if (k == 'c' || k == 'C' || k == 13) {
            switch (choice) {
                case 1: displayInformationMenu(); break;
                case 2: displayDescriptionMenu(); break;
                case 3: displayFilterMenu(); break;
                case 4: displayDataManagementMenu(); break;
                case 5: displayStatus(); break;
                case 6: displayAmazeMe(); break;
            }
            drawMainMenuUI(choice);
        } else if (k == 'e' || k == 'E') {
            exitApplication();
        } else if (k == 'l' || k == 'L') {
            displayHelp();
            drawMainMenuUI(choice);
        } else if (k == 'b' || k == 'B') {
            displayAbout();
            drawMainMenuUI(choice);
        }
        drawMainMenuUI(choice);
    }
}

void drawInformationMenuUI(int selected_option) {
    const std::vector<std::string> options = {
        "HISTORY OF SMART PHONES",
        "FEATURES OF SMART PHONES"
    };

    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
    displayTextArt("information", 9, 4, 10, 6);
    drawFilledBox(11, 3, 43, 23, "Û", 3, 1, 0);
    drawFilledBox(11, 44, 78, 23, "Û", 2, 1, 0);

    for (size_t i = 0; i < options.size(); ++i) {
        gotoxy(4, 12 + i * 2);
        if (i + 1 == selected_option) {
            textcolor(11);
            textbackground(1);
        } else {
            textcolor(1);
            textbackground(3);
        }
        cprintf("Û %s", options[i].c_str());
    }

    textcolor(1);
    textbackground(3);
    gotoxy(4, 22); cprintf("'B'-BACK");

    textbackground(2);
    gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
    gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
    gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
    gotoxy(45, 17); cprintf(">> 'E'- EXIT");
}

void displayInformationMenu() {
    int choice = 1;
    drawInformationMenuUI(choice);

    while (true) {
        char k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && choice > 1) {
            choice--;
        } else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && choice < 2) {
            choice++;
        } else if (k == 'c' || k == 'C' || k == 13) {
            drawFilledBox(3, 3, 78, 23, "Û", 6, 7);
            switch (choice) {
                case 1: displayHistory(); break;
                case 2: displayFeaturesMenu(); break;
            }
            drawInformationMenuUI(choice);
        } else if (k == 'e' || k == 'E') {
            exitApplication();
        } else if (k == 'b' || k == 'B') {
            return;
        }
        drawInformationMenuUI(choice);
    }
}

void displayDescriptionMenu() {
    drawFilledBox(2, 2, 79, 24, "Û", 7, 1);
    drawBorderedBox(2, 2, 79, 24, "Û", 15, 0);
    displayTextArt("description", 8, 4, 0, 15);
    drawFilledBox(11, 3, 78, 23, "Û", 0, 1, 0);
    drawText("data/text/dguide.dat", 15, 8, 12, 0, 0);
    getch();
    drawFilledBox(2, 2, 79, 24, "Û", 7, 1, 0);
    drawBorderedBox(2, 2, 79, 24, "Û", 15, 0, 0);
    displayTextArt("brands", 23, 4, 0, 15);
    drawFilledBox(11, 3, 78, 20, "Û", 0, 1, 0);
    drawFilledBox(21, 3, 78, 23, "Û", 7, 1, 0);

    const std::vector<std::string> brands = {
        "APPLE", "MICROMAX",
        "ASUS", "MICROSOFT",
        "BLACKBERRY", "ONE PLUS",
        "GIONEE", "OPPO",
        "HTC", "SAMSUNG",
        "Le ECO", "SONY",
        "LENOVO", "XIAOMI",
        "LG", "OTHER"
    };

    auto drawUI = [&](int selected) {
        for (size_t i = 0; i < brands.size() / 2; ++i) {
            gotoxy(5, 12 + i);
            if (i + 1 == selected) textcolor(2); else textcolor(15);
            cprintf("Û %-12s", brands[i * 2].c_str());

            gotoxy(20, 12 + i);
            if (i + 9 == selected) textcolor(2); else textcolor(15);
            cprintf("Û %s", brands[i * 2 + 1].c_str());
        }
        textcolor(0); textbackground(15);
        gotoxy(20, 22); cprintf("'B'-BACK || 'E'-EXIT || 'C'-CONFIRMATION");
    };

    int choice = 1;
    drawUI(choice);

    while (true) {
        char k = getch();
        if ((k == '2' || k == 'w' || k == 'W' || k == 72) && choice > 1 && choice < 9) { // Up
            choice--;
        } else if ((k == '2' || k == 'w' || k == 'W' || k == 72) && choice > 8) {
             choice-=8;
        } else if ((k == '5' || k == 's' || k == 'S' || k == 80) && choice < 8) { // Down
            choice++;
        } else if ((k == '5' || k == 's' || k == 'S' || k == 80) && choice > 7 && choice < 16) {
             choice+=8;
        } else if ((k == '4' || k == 'a' || k == 'A' || k == 75) && choice > 8) { // Left
            choice -= 8;
        } else if ((k == '6' || k == 'd' || k == 'D' || k == 77) && choice < 9) { // Right
            choice += 8;
        } else if (k == 'c' || k == 'C' || k == 13) {
            phone_data::displaySmartphonesByBrand(brands[choice - 1].c_str());
            drawFilledBox(2, 2, 79, 24, "Û", 7, 1, 0);
            drawBorderedBox(2, 2, 79, 24, "Û", 15, 0, 0);
            displayTextArt("brands", 23, 4, 0, 15);
            drawFilledBox(11, 3, 78, 20, "Û", 0, 1, 0);
            drawFilledBox(21, 3, 78, 23, "Û", 7, 1, 0);
            drawUI(choice);
        } else if (k == 'e' || k == 'E') {
            exitApplication();
        } else if (k == 'b' || k == 'B') {
            return;
        }
        drawUI(choice);
    }
}

void drawDataManagementMenuUI(int selected_option) {
    const std::vector<std::string> options = {
        "ADD DATA",
        "MODIFY DATA",
        "EXPORT DATA"
    };

    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
    displayTextArt("modification", 5, 4, 10, 6);
    drawFilledBox(11, 3, 43, 23, "Û", 3, 1, 0);
    drawFilledBox(11, 44, 78, 23, "Û", 2, 1, 0);

    for (size_t i = 0; i < options.size(); ++i) {
        gotoxy(4, 12 + i * 2);
        if (i + 1 == selected_option) {
            textcolor(11);
            textbackground(1);
        } else {
            textcolor(1);
            textbackground(3);
        }
        cprintf("Û %s", options[i].c_str());
    }

    textcolor(1);
    textbackground(3);
    gotoxy(4, 22); cprintf("'B'-BACK");

    textbackground(2);
    gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
    gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
    gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
    gotoxy(45, 17); cprintf(">> 'E'- EXIT");
}

void displayDataManagementMenu() {
    int choice = 1;
    drawDataManagementMenuUI(choice);

    while (true) {
        char k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && choice > 1) {
            choice--;
        } else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && choice < 3) {
            choice++;
        } else if (k == 'c' || k == 'C' || k == 13) {
            drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
            switch (choice) {
                case 1: phone_data::addSmartphoneRecord(); break;
                case 2: phone_data::modifySmartphoneRecord(); break;
                case 3: export_file::exportData(); break;
            }
            drawDataManagementMenuUI(choice);
        } else if (k == 'e' || k == 'E') {
            exitApplication();
        } else if (k == 'b' || k == 'B') {
            return;
        }
        drawDataManagementMenuUI(choice);
    }
}


void drawFilterMenuUI() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1, 0);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
    displayTextArt("filteration", 8, 4, 10, 6);
    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
    drawFilledBox(12, 3, 78, 23, "Û", 6, 1, 0);
    drawFilledBox(11, 3, 43, 23, "Û", 3, 1, 0);
    drawFilledBox(11, 44, 78, 23, "Û", 2, 1, 0);

    const std::vector<std::string> filters = {
        "FILTER BY COMPANY NAME",
        "FILTER BY PROCESSOR",
        "FILTER BY OPERATING SYSTEM",
        "FILTER BY CAMERA",
        "FILTER BY MEMORY",
        "FILTER BY PRICE",
        "FILTER BY NETWORK",
        "FILTER BY BATTERY",
        "FILTER BY YEAR"
    };

    textcolor(1); textbackground(3);
    for(size_t i=0; i < filters.size(); ++i) {
        gotoxy(4, 12 + i);
        cprintf("%zu %s", i+1, filters[i].c_str());
    }
    gotoxy(4, 21); cprintf("> ENTER FILTERATION SEQUENCE:           ");

    textbackground(2);
    gotoxy(45, 12); cprintf(">> WRITE FILTERATION SEQUENCE ");
    gotoxy(45, 13); cprintf("   FOR FILTERING IN THAT ");
    gotoxy(45, 14); cprintf("   ORDER");
    gotoxy(45, 15); cprintf(">> 'E'- EXIT");
    gotoxy(45, 17); cprintf(">> 'B'- BACK");
    gotoxy(45, 18); cprintf(">> 0 - FINGERPRINT SCANNER");
}


void displayFilterMenu() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1, 0);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
    displayTextArt("filteration", 8, 4, 10, 6);
    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
    drawText("data/text/fguide.dat", 14, 7, 12);
    getch();

    while (true) {
        drawFilterMenuUI();

        std::string s;
        char buffer[8];
        gotoxy(34, 21);
        cgets(buffer);
        s = buffer;

        if (s[0] == 'e' || s[0] == 'E') {
            exitApplication();
        } else if (s[0] == 'b' || s[0] == 'B') {
            return;
        }

        std::vector<int> a;
        a.push_back(10);

        bool no_mobiles_found = false;
        for (char c : s) {
            std::vector<int> p;
            switch (c) {
                case '0':  p = filter::filterBySensor(a); break;
                case '1':  p = filter::filterByCompanyName(a); break;
                case '2':  p = filter::filterByProcessor(a); break;
                case '3':  p = filter::filterByOS(a); break;
                case '4':  p = filter::filterByCamera(a); break;
                case '5':  p = filter::filterByMemory(a); break;
                case '6':  p = filter::filterByPrice(a); break;
                case '7':  p = filter::filterByNetwork(a); break;
                case '8':  p = filter::filterByBattery(a); break;
                case '9':  p = filter::filterByYear(a); break;
                default:
                    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
                    textcolor(0); textbackground(15);
                    gotoxy(4, 22); cprintf("INVALID FILTER. PRESS ANY KEY TO RETURN");
                    getch();
                    no_mobiles_found = true;
                    break;
            }
            if(no_mobiles_found) break;

            a = p;
            if (a.empty() || (a.size() == 1 && a[0] == 10)) {
                drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
                textcolor(0); textbackground(15);
                gotoxy(4, 22); cprintf("NO MOBILES FOUND. PRESS ANY KEY TO RETURN");
                getch();
                no_mobiles_found = true;
                break;
            }
        }

        if (!no_mobiles_found) {
            phone_data::displayFilteredSmartphones(a);
        }
    }
}

void displayStatus() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1, 0);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
    displayTextArt("status", 23, 4, 10, 6);

    std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
    fin.seekg(0, std::ios::end);
    long long file_size = fin.tellg();
    fin.close();

    int n = file_size / sizeof(phone_data::Smartphone);

    if (n == 0) {
        textcolor(0); textbackground(6);
        gotoxy(7, 15); cprintf("THIS PROGRAM HAS NO SMART PHONES DESCRIPTION");
    } else {
        textcolor(0); textbackground(6);
        gotoxy(7, 15); cprintf("THIS PROGRAM IS MAINTAINED BY A TOTAL OF %d SMART PHONE'S DESCRIPTION", n);
    }
    getch();
}

void displayAmazeMe() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("amaze", 19, 4, 10, 6);
    displayTextArt("me", 51, 4, 10, 6);
    drawText("data/text/ama.dat", 14, 9, 16);
    getch();
    drawText("data/text/ama2.dat", 14, 4, 12);
    char k = getch();
    if (k == 'B' || k == 'b') return;
    drawFilledBox(12, 3, 78, 23, "Û", 6, 1);
    drawText("data/text/ama3.dat", 14, 4, 12);
    getch();
}

void displayHelp() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("help", 29, 4, 10, 6);
    drawText("data/text/help.dat");
    getch();
}

void displayAbout() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("about", 26, 4, 10, 6);
    drawText("data/text/about.dat");
    getch();
}

void displayHistory() {
    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("history", 20, 4, 10, 6);
    drawText("data/text/m.dat", 15);
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
        case 1: drawText("data/text/m1.dat"); break;
        case 2: drawText("data/text/m2.dat"); break;
        case 3: drawText("data/text/m3.dat"); break;
        case 4: drawText("data/text/m4.dat"); break;
        case 5: drawText("data/text/m5.dat"); break;
        case 6: drawText("data/text/m6.dat"); break;
        case 7: drawText("data/text/m7.dat"); break;
        case 8: drawText("data/text/m8.dat"); break;
        case 9: drawText("data/text/m9.dat"); break;
        }
    }
}

void drawFeaturesMenuUI(int selected_option) {
    const std::vector<std::string> options = {
        "PROCESSOR",
        "OPERATING SYSTEM",
        "MEMORY",
        "BATTERY",
        "CAMERA",
        "DISPLAY",
        "BODY",
        "NETWORK",
        "SENSORS"
    };

    drawBorderedBox(2, 2, 79, 24, "Û", 14, 1, 0);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1, 0);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1, 0);
    displayTextArt("features", 17, 4, 10, 6);
    drawFilledBox(11, 3, 43, 23, "Û", 3, 1, 0);
    drawFilledBox(11, 44, 78, 23, "Û", 2, 1, 0);

    for (size_t i = 0; i < options.size(); ++i) {
        gotoxy(4, 12 + i);
        if (i + 1 == selected_option) {
            textcolor(11);
            textbackground(1);
        } else {
            textcolor(1);
            textbackground(3);
        }
        cprintf("Û %s", options[i].c_str());
    }

    textcolor(1);
    textbackground(3);
    gotoxy(4, 22); cprintf("'B'-BACK");

    textbackground(2);
    gotoxy(45, 12); cprintf(">> USE ARROW KEYS OR");
    gotoxy(45, 13); cprintf("   W/A/S/D FOR SELECTION");
    gotoxy(45, 15); cprintf(">> 'C'-CONFIRMATION");
    gotoxy(45, 17); cprintf(">> 'E'- EXIT");
}

void displayFeaturesMenu() {
    int choice = 1;
    drawFeaturesMenuUI(choice);

    while (true) {
        char k = getch();
        if ((k == '2' || k == '4' || k == 'w' || k == 'a' || k == 'W' || k == 'A' || k == 72 || k == 75) && choice > 1) {
            choice--;
        } else if ((k == '5' || k == '6' || k == 's' || k == 'd' || k == 'S' || k == 'D' || k == 80 || k == 77) && choice < 9) {
            choice++;
        } else if (k == 'c' || k == 'C' || k == 13) {
            drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
            switch (choice) {
                case 1: displayProcessorInfo(); break;
                case 2: displayOSInfo(); break;
                case 3: displayMemoryInfo(); break;
                case 4: displayBatteryInfo(); break;
                case 5: displayCameraInfo(); break;
                case 6: displayDisplayInfo(); break;
                case 7: displayBodyInfo(); break;
                case 8: displayNetworkInfo(); break;
                case 9: displaySensorsInfo(); break;
            }
            drawFeaturesMenuUI(choice);
        } else if (k == 'e' || k == 'E') {
            exitApplication();
        } else if (k == 'b' || k == 'B') {
            return;
        }
        drawFeaturesMenuUI(choice);
    }
}
void displayProcessorInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("processor", 15, 4, 10, 6);
    drawImage("data/images/pro.im", 15, 33);
    drawText("data/text/pro.dat", 14, 5);
    getch();
}

void displayOSInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("os", 35, 4, 10, 6);
    drawImage("data/images/os.im", 10, 30);
    drawText("data/text/os.dat", 14, 5);
    getch();
}

void displayMemoryInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("memory", 23, 4, 10, 6);
    drawImage("data/images/mem.im");
    drawText("data/text/mem.dat", 14, 6);
    getch();
}

void displayBatteryInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("battery", 20, 4, 10, 6);
    drawImage("data/images/bat.im");
    drawText("data/text/bat.dat", 14, 9);
    getch();
}

void displayCameraInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("camera", 23, 4, 10, 6);
    drawImage("data/images/cam.im", 15, 32, 13);
    drawText("data/text/cam.dat", 14, 8);
    getch();
}

void displayDisplayInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("display", 20, 4, 10, 6);
    drawText("data/text/disp.dat");
    getch();
}

void displayBodyInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("body", 29, 4, 10, 6);
    drawText("data/text/body.dat", 14, 9);
    getch();
}

void displayNetworkInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("network", 20, 4, 10, 6);
    drawImage("data/images/net.im", 15, 25, 14);
    drawText("data/text/net.dat");
    getch();
}

void displaySensorsInfo() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("sensors", 20, 4, 10, 6);
    drawText("data/text/sens.dat", 14);
    getch();
}

void exitApplication() {
    textbackground(1);
    clrscr();
    const std::string s1 = "do";
    const std::string s2 = "you";
    const std::string s3 = "know";
    int i = s1.length() + s2.length() + s3.length() + 19;
    drawBorderedBox(2, 2, 79, 24, "Û", 15, 0);
    i = (80 - i) / 2;
    displayTextArt(s1, i / 2, 4, 15, 1);
    displayTextArt(s2, i / 2 + 15, 4, 15, 1);
    displayTextArt(s3, i / 2 + 36, 4, 15, 1);
    drawText("data/text/dyk.dat", 15, 6, 12, 1, 1);
    getch();
    exit(1);
}

} // namespace menu