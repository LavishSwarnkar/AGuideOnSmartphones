#include "filter.h"
#include "phone_data.h"
#include "ui.h"
#include <iostream>
#include <conio.h>
#include <cstring>
#include <fstream>
#include <cstdio>

using namespace std;

int* filterByCompanyName(int existing_filters[]) {
    Smartphone m;
    static int b[150];
    int i = 0, j = 0;
    char s[30];
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER COMPANY'S NAME:                          "); gotoxy(26, 22); gets(s);
    if (existing_filters[0] == 10) {
        ifstream fin("data\\text\\mobinfo.dat", ios::binary);
        while (fin.read((char*)&m, sizeof(m))) {
            if (strcmp(s, m.company_name) == 0) {
                b[i] = fin.tellg() - sizeof(m);
                i++;
            }
        }
        fin.close();
    }
    else {
        for (j = 0; existing_filters[j] != 10; j++) {
            ifstream fin("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(existing_filters[j]);
            fin.read((char*)&m, sizeof(m));
            if (strcmp(s, m.company_name) == 0) {
                b[i] = fin.tellg() - sizeof(m); i++;
            }
            fin.close();
        }
    }
    b[i] = 10;
    return b;
}

int* filterByProcessor(int existing_filters[]) {
    Smartphone m;
    static int b[150];
    int i = 0, j = 0;
    char s[30];
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER PROCESSOR'S NAME:                          "); gotoxy(28, 22); gets(s);
    if (existing_filters[0] == 10) {
        ifstream fin("data\\text\\mobinfo.dat", ios::binary);
        while (fin.read((char*)&m, sizeof(m))) {
            if (strcmp(s, m.processor) == 0) {
                b[j] = fin.tellg() - sizeof(m);  j++;
            }
        }
        fin.close();
    }
    else {
        for (i = 0; existing_filters[i] != 10; i++) {
            ifstream fin("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(existing_filters[i]);
            fin.read((char*)&m, sizeof(m));
            if (strcmp(s, m.processor) == 0) {
                b[j] = fin.tellg() - sizeof(m); j++;
            }
            fin.close();
        }
    }
    b[j] = 10;
    return b;
}

int* filterByOS(int existing_filters[]) {
    Smartphone m;
    static int b[150];
    int i = 0;
    float v;
    char s[30], k = '1';
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER OPERATING SYSTEM'S NAME:                          "); gotoxy(36, 22); gets(s);
    gotoxy(4, 22); cprintf("ENTER OPERATING SYSTEM'S VERSION:                          "); gotoxy(38, 22); cin >> v;
    gotoxy(36, 22); gotoxy(4, 22); cprintf("ENTER OS VERSION'S NO. (0 FOR SAME,1 FOR GREATER AND 2 FOR LESSER):     "); gotoxy(73, 22); k = getch();

    if (existing_filters[0] == 10) {
        ifstream fin("data\\text\\mobinfo.dat", ios::binary);
        while (fin.read((char*)&m, sizeof(m))) {
            if (k == '0') {
                if (strcmp(s, m.os) == 0 && m.os_version == v) {
                    b[i] = fin.tellg() - sizeof(m); i++;
                }
            }
            if (k == '2') {
                if (strcmp(s, m.os) == 0 && m.os_version <= v) {
                    b[i] = fin.tellg() - sizeof(m); i++;
                }
            }
            if (k == '1') {
                if (strcmp(s, m.os) == 0 && m.os_version >= v) {
                    b[i] = fin.tellg() - sizeof(m); i++;
                }
            }
        }
        fin.close();
    }
    else {
        for (int j = 0; existing_filters[j] != 10; j++) {
            ifstream fin("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(existing_filters[j]);
            fin.read((char*)&m, sizeof(m));
            if (k == '0') {
                if (strcmp(s, m.os) == 0 && m.os_version == v) {
                    b[i] = fin.tellg() - sizeof(m); i++;
                }
            }
            if (k == '2') {
                if (strcmp(s, m.os) == 0 && m.os_version <= v) {
                    b[i] = fin.tellg() - sizeof(m); i++;
                }
            }
            if (k == '1') {
                if (strcmp(s, m.os) == 0 && m.os_version >= v) {
                    b[i] = fin.tellg() - sizeof(m); i++;
                }
            }
            fin.close();
        }
    }
    b[i] = 10;
    return b;
}

int* filterByCamera(int existing_filters[]) {
    Smartphone m;
    static int b[150];
    int i = 0, rl, ru, fl, fu;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER REAR CAMERA'S LOWER LIMIT:                          ");  gotoxy(37, 22); cin >> rl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER REAR CAMERA'S UPPER LIMIT:                          "); gotoxy(37, 22); cin >> ru;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER FRONT CAMERA'S LOWER LIMIT:                          "); gotoxy(38, 22); cin >> fl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER FRONT CAMERA'S UPPER LIMIT:                          "); gotoxy(38, 22); cin >> fu;
    int j = 0;
    if (existing_filters[0] == 10) {
        ifstream fin("data\\text\\mobinfo.dat", ios::binary);
        while (fin.read((char*)&m, sizeof(m))) {
            if ((m.camera[0] >= rl && m.camera[0] <= ru) && (m.camera[1] >= fl && m.camera[1] <= fu)) {
                b[j] = fin.tellg() - sizeof(m);  j++;
            }
        }
        fin.close();
    }
    else {
        for (i = 0; existing_filters[i] != 10; i++) {
            ifstream fin("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(existing_filters[i]);
            fin.read((char*)&m, sizeof(m));
            if ((m.camera[0] >= rl && m.camera[0] <= ru) && (m.camera[1] >= fl && m.camera[1] <= fu)) {
                b[j] = fin.tellg() - sizeof(m); j++;
            }
            fin.close();
        }
    }
    b[j] = 10;
    return b;
}

int* filterByMemory(int existing_filters[]) {
    Smartphone m;
    static int b[150];
    int i = 0, rl, ru, fl, fu, j = 0;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER ROM'S LOWER LIMIT:                          "); gotoxy(29, 22); cin >> rl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER ROM'S UPPER LIMIT:                          ");  gotoxy(29, 22); cin >> ru;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER RAM'S LOWER LIMIT:                          "); gotoxy(29, 22); cin >> fl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER RAM'S UPPER LIMIT:                          ");    gotoxy(29, 22); cin >> fu;
    if (existing_filters[0] == 10) {
        ifstream fin("data\\text\\mobinfo.dat", ios::binary);
        while (fin.read((char*)&m, sizeof(m))) {
            if ((m.memory[0] >= rl && m.memory[0] <= ru) && (m.memory[1] >= fl && m.memory[1] <= fu)) {
                b[j] = fin.tellg() - sizeof(m);  j++;
            }
        }
        fin.close();
    }
    else {
        for (i = 0; existing_filters[i] != 10; i++) {
            ifstream fin("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(existing_filters[i]);
            fin.read((char*)&m, sizeof(m));
            if ((m.memory[0] >= rl && m.memory[0] <= ru) && (m.memory[1] >= fl && m.memory[1] <= fu)) {
                b[j] = fin.tellg() - sizeof(m); j++;
            }
            fin.close();
        }
    }
    b[j] = 10;
    return b;
}

int* filterByPrice(int existing_filters[]) {
    Smartphone m;
    static int b[150];
    int i = 0, j = 0, mpr = 0, k = 0;
    unsigned long rl, ru;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER PRICE'S LOWER LIMIT:                          "); gotoxy(31, 22); cin >> rl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER PRICE'S UPPER LIMIT:                          "); gotoxy(31, 22); cin >> ru;
    ru /= 1000;
    rl /= 1000;
    if (existing_filters[0] == 10) {
        ifstream fin("data\\text\\mobinfo.dat", ios::binary);
        while (fin.read((char*)&m, sizeof(m))) {
            for (j = 0; j < 4; j++) {
                if (m.price[j] != 0)
                    mpr = m.price[j];
            }
            if ((mpr >= rl && mpr <= ru)) {
                b[k] = fin.tellg() - sizeof(m);  k++;
            }
        }
        fin.close();
    }
    else {
        for (i = 0; existing_filters[i] != 10; i++) {
            ifstream fin("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(existing_filters[i]);
            fin.read((char*)&m, sizeof(m));
            for (j = 0; j < 4; j++) {
                if (m.price[j] != 0)
                    mpr = m.price[j];
            }
            if ((mpr >= rl && mpr <= ru)) {
                b[k] = fin.tellg() - sizeof(m); k++;
            }
            fin.close();
        }
    }
    b[k] = 10;
    return b;
}

int* filterByNetwork(int existing_filters[]) {
    Smartphone m;
    static int b[150];
    int i = 0, rl, j = 0;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER NETWORK'S GENERATION:                          "); gotoxy(32, 22); cin >> rl;
    if (existing_filters[0] == 10) {
        ifstream fin("data\\text\\mobinfo.dat", ios::binary);
        while (fin.read((char*)&m, sizeof(m))) {
            if (m.network == rl) {
                b[j] = fin.tellg() - sizeof(m);  j++;
            }
        }
        fin.close();
    }
    else {
        for (i = 0; existing_filters[i] != 10; i++) {
            ifstream fin("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(existing_filters[i]);
            fin.read((char*)&m, sizeof(m));
            if (m.network == rl) {
                b[j] = fin.tellg() - sizeof(m); j++;
            }
            fin.close();
        }
    }
    b[j] = 10;
    return b;
}

int* filterByBattery(int existing_filters[]) {
    Smartphone m;
    static int b[150];
    int i = 0, rl, ru, j = 0;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER BATTERY'S LOWER CAPACITY:                          "); gotoxy(36, 22); cin >> rl;
    gotoxy(4, 22); cprintf("ENTER BATTERY'S UPPER CAPACITY:                          "); gotoxy(36, 22); cin >> ru;
    if (existing_filters[0] == 10) {
        ifstream fin("data\\text\\mobinfo.dat", ios::binary);
        while (fin.read((char*)&m, sizeof(m))) {
            if (m.battery >= rl && m.battery <= ru) {
                b[j] = fin.tellg() - sizeof(m);  j++;
            }
        }
        fin.close();
    }
    else {
        for (i = 0; existing_filters[i] != 10; i++) {
            ifstream fin("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(existing_filters[i]);
            fin.read((char*)&m, sizeof(m));
            if (m.battery >= rl && m.battery <= ru) {
                b[j] = fin.tellg() - sizeof(m); j++;
            }
            fin.close();
        }
    }
    b[j] = 10;
    return b;
}

int* filterByYear(int existing_filters[]) {
    Smartphone m;
    static int b[150];
    int i = 0, rl, j = 0;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER YEAR OF LAUNCH:                          "); gotoxy(26, 22); cin >> rl;
    if (existing_filters[0] == 10) {
        ifstream fin("data\\text\\mobinfo.dat", ios::binary);
        while (fin.read((char*)&m, sizeof(m))) {
            if (m.year == rl) {
                b[j] = fin.tellg() - sizeof(m);  j++;
            }
        }
        fin.close();
    }
    else {
        for (i = 0; existing_filters[i] != 10; i++) {
            ifstream fin("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(existing_filters[i]);
            fin.read((char*)&m, sizeof(m));
            if (m.year == rl) {
                b[j] = fin.tellg() - sizeof(m);
                j++;
            }
            fin.close();
        }
    }
    b[j] = 10;
    return b;
}

int* filterBySensor(int existing_filters[]) {
    Smartphone m;
    static int b[150];
    int i = 0, j = 0;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    if (existing_filters[0] == 10) {
        ifstream fin("data\\text\\mobinfo.dat", ios::binary);
        while (fin.read((char*)&m, sizeof(m))) {
            if (strcmp(m.sensors, "FINGERPRINT AND COMMON") == 0) {
                b[j] = fin.tellg() - sizeof(m);  j++;
            }
        }
        fin.close();
    }
    else {
        for (i = 0; existing_filters[i] != 10; i++) {
            ifstream fin("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(existing_filters[i]);
            fin.read((char*)&m, sizeof(m));
            if (strcmp(m.sensors, "FINGERPRINT AND COMMON") == 0) {
                b[j] = fin.tellg() - sizeof(m); j++;
            }
            fin.close();
        }
    }
    b[j] = 10;
    return b;
}