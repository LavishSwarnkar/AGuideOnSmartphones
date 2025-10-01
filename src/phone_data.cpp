#include "phone_data.h"
#include "ui.h"
#include <iostream>
#include <conio.h>
#include <cstring>
#include <fstream>
#include <cstdio>

using namespace std;

void promptForSmartphoneDetails(Smartphone &phone) {
    textcolor(15); textbackground(14);
    gotoxy(12, 12);
    cprintf("Enter Company's Name:               ");
    gotoxy(34, 12); gets(phone.company_name);
    gotoxy(12, 13);
    cprintf("Enter Mobile's Name:                            ");
    gotoxy(33, 13); gets(phone.model_name);
    gotoxy(12, 14);
    cprintf("Enter Mobile's Year:                           ");
    gotoxy(33, 13); cin >> phone.year;
    gotoxy(12, 14);
    cprintf("Enter Processor's Name:                                   ");
    gotoxy(36, 14); gets(phone.processor);
    gotoxy(12, 15);
    cprintf("Enter Operating System's Name:                              ");
    gotoxy(43, 15); gets(phone.os);
    gotoxy(12, 15); cprintf("Enter Operating System's Version:                    ");
    gotoxy(45, 15); cin >> phone.os_version;
    gotoxy(12, 16);
    cprintf("Enter Weight(in grams):               ");
    gotoxy(36, 16); cin >> phone.weight;
    gotoxy(12, 17);
    cprintf("Enter Size in order (L,B,H) (in mm):        ");
    gotoxy(49, 17); cin >> phone.dimensions[0];
    gotoxy(12, 17);
    cprintf("Enter Size in order (L,B,H):                   ");
    gotoxy(41, 17); cin >> phone.dimensions[1];
    gotoxy(12, 17);
    cprintf("Enter Size in order (L,B,H):                    ");
    gotoxy(41, 17); cin >> phone.dimensions[2];
    gotoxy(12, 18);
    unsigned long p1, p2, p3, p4;
    cprintf("Enter Price in order (A,E,SD,MI/FK) :              ");
    gotoxy(50, 18); cin >> p1;
    gotoxy(12, 18);
    cprintf("Enter Price in order (A,E,SD,MI/FK):                        ");
    gotoxy(50, 18); cin >> p2;
    gotoxy(12, 18);
    cprintf("Enter Price in order (A,E,SD,MI/FK):                         ");
    gotoxy(50, 18); cin >> p3;
    gotoxy(12, 18);
    cprintf("Enter Price in order (A,E,SD,MI/FK):                        ");
    gotoxy(50, 18); cin >> p4;
    p1 /= 1000; p2 /= 1000;
    p3 /= 1000; p4 /= 1000;
    phone.price[0] = p1;
    phone.price[1] = p2;
    phone.price[2] = p3;
    phone.price[3] = p4;
    phone.price[4] = (phone.price[0] + phone.price[1] + phone.price[2] + phone.price[3]) / 4;
    gotoxy(12, 19);
    cprintf("Enter Camera in order (Rear,Front) (Leave 0, if not available):   ");
    gotoxy(75, 19); cin >> phone.camera[0];
    gotoxy(12, 19);
    cprintf("Enter Camera in order (Rear,Front) (Leave 0, if not available):   ");
    gotoxy(75, 19); cin >> phone.camera[1];
    gotoxy(12, 20);
    cprintf("Enter Memory in order (ROM,RAM) (In GBs/MBs):        ");
    gotoxy(58, 20); cin >> phone.memory[0];
    gotoxy(12, 20);
    cprintf("Enter Memory in order (ROM,RAM) (In GBs/MBs):        ");
    gotoxy(58, 20); cin >> phone.memory[1];
    gotoxy(12, 21);
    cprintf("Enter Battery Capacity (in mAh):            ");
    gotoxy(45, 21); cin >> phone.battery;
    gotoxy(12, 22);
    cprintf("Enter specific Sensors (if any):                       ");
    gotoxy(45, 22); gets(phone.sensors);
    if (strcmp(phone.sensors, "Y") == 0) strcpy(phone.sensors, "FINGERPRINT AND COMMON");
    if (strcmp(phone.sensors, "N") == 0) strcpy(phone.sensors, "COMMON");
    gotoxy(12, 23);
    cprintf("Enter Network Type (Eg.4 for 4G):          ");
    gotoxy(46, 23);
    cin >> phone.network;
}

void displaySmartphoneDetails(Smartphone phone) {
    textcolor(15); textbackground(0);
    clrscr();
    drawBorderedBox(2, 2, 79, 24, "Û", 7, 1, 0);
    int l = strlen(phone.model_name);
    l = (80 - l) / 2; textcolor(15); textbackground(0);
    gotoxy(l, 5); cprintf(phone.model_name);
    gotoxy(32, 6); cprintf("BROUGHT TO YOU BY");
    l = strlen(phone.company_name); l = (72 - l) / 2;
    gotoxy(l, 7); cprintf(phone.company_name); cprintf(" IN "); cout << phone.year;
    gotoxy(5, 9); cprintf(">> PROCESSOR: ");     cprintf(phone.processor);
    gotoxy(5, 10); cprintf(">> OPERATING SYSTEM: ");     cprintf(phone.os); cprintf(" ");
    cout << phone.os_version;
    if (strcmp(phone.os, "ANDROID") == 0) {
        if (phone.os_version == 4) cprintf(" JELLY BEAN / KITKAT");
        else if (phone.os_version == 5) cprintf(" LOLLIPOP");
        else if (phone.os_version == 6) cprintf(" MARSHMALLOW");
        else if (phone.os_version == 7) cprintf(" NOUGHAT");
    }

    gotoxy(5, 11); cprintf(">> BODY: ");
    gotoxy(13, 12); cprintf(">> SIZE (L,B,H):                    ");
    gotoxy(30, 12); cout << phone.dimensions[0] << ", " << phone.dimensions[1] << ", " << phone.dimensions[2] << " mm";
    gotoxy(13, 13); cprintf(">> WEIGHT:                    ");
    gotoxy(24, 13); cout << phone.weight << " Grams";
    gotoxy(5, 14); cprintf(">> STORAGE: ");
    gotoxy(16, 15); cprintf(">> ROM:                    ");
    gotoxy(24, 15); cout << phone.memory[0] << " GB";
    gotoxy(16, 16); cprintf(">> RAM:                    ");
    if (phone.memory[1] < 0) {
        phone.memory[1] *= -1;
        gotoxy(24, 16); cout << phone.memory[1] << " MB";
    }
    else {
        gotoxy(24, 16); cout << phone.memory[1] << " GB";
    }
    gotoxy(5, 17); cprintf(">> CAMERA: ");
    gotoxy(16, 17); cprintf(">> REAR:                    ");

    if (phone.camera[0] == 0) {
        gotoxy(26, 17); cout << "NONE";
    }
    else {
        gotoxy(26, 17); cout << phone.camera[0] << " MPs";
    }

    gotoxy(16, 18); cprintf(">> FRONT:                    ");

    if (phone.camera[1] == 0) {
        gotoxy(27, 18); cout << "NONE OR VGA";
    }
    else {
        gotoxy(27, 18); cout << phone.camera[1] << " MPs";
    }

    gotoxy(5, 19);
    cprintf(">> PRICE (A,E,SD,MI/FK)(0-NA):                        "); gotoxy(36, 19);

    unsigned long p1, p2, p3, p4;

    p1 = phone.price[0];
    p2 = phone.price[1];
    p3 = phone.price[2];
    p4 = phone.price[3];
    p1 *= 1000;
    p2 *= 1000;
    p3 *= 1000;
    p4 *= 1000;
    cout << p1 << " , " << p2 << " , " << p3 << " , " << p4 << " Rupees" << endl;

    gotoxy(5, 20);
    cprintf(">> BATTERY:        ");
    gotoxy(17, 20);
    cout << phone.battery << " mAh" << endl;
    gotoxy(5, 21);
    cprintf(">> SPECIFIC SENSORS: ");
    gotoxy(26, 21);
    cprintf(phone.sensors);
    gotoxy(5, 22);
    cprintf(">> NETWORK:         ");
    gotoxy(17, 22);
    cout << phone.network; cprintf(" G");
    getch();
    textbackground(1); clrscr();
}

void displaySmartphonesByBrand(const char* brand) {
    Smartphone phone;
    int positions[150], i = 0, choice = 0;
    char model_names[150][30], company_names[150][30];
    char mutable_brand[40];
    strcpy(mutable_brand, brand);
    strupr(mutable_brand);
    ifstream fin("data\\text\\mobinfo.dat", ios::binary);

    while (fin.read((char*)&phone, sizeof(phone))) {
        if (strcmp(mutable_brand, "OTHER") == 0) {
            if (strcmp(phone.company_name, "APPLE") != 0 && strcmp(phone.company_name, "ASUS") != 0 && strcmp(phone.company_name, "BLACKBERRY") != 0 && strcmp(phone.company_name, "HTC") != 0 && strcmp(phone.company_name, "GIONEE") != 0 && strcmp(phone.company_name, "Le ECO") != 0 && strcmp(phone.company_name, "LENOVO") != 0 && strcmp(phone.company_name, "LG") != 0 && strcmp(phone.company_name, "MICROMAX") != 0 && strcmp(phone.company_name, "MICROSOFT") != 0 && strcmp(phone.company_name, "ONEPLUS") != 0 && strcmp(phone.company_name, "OPPO") != 0 && strcmp(phone.company_name, "SAMSUNG") != 0 && strcmp(phone.company_name, "SONY") != 0 && strcmp(phone.company_name, "XIAOMI") != 0) {
                positions[i] = fin.tellg() - sizeof(phone);
                strcpy(model_names[i], phone.model_name);
                strcpy(company_names[i], phone.company_name);
                i++;
            }
        }
        else if (strcmp(mutable_brand, phone.company_name) == 0) {
            positions[i] = fin.tellg() - sizeof(phone);
            strcpy(model_names[i], phone.model_name);
            i++;
        }
    }
    fin.close();

    if (strcmp(mutable_brand, "Le ECO") == 0) strcpy(mutable_brand, "LEECO");
    int total_phones = i;
    positions[i] = 10;
    strlwr(mutable_brand);

    while (1) {
        int len = strlen(mutable_brand);
        len = (80 - ((len * 5) + len - 1)) / 2;
        drawFilledBox(2, 2, 79, 24, "Û", 7, 1, 0);
        drawBorderedBox(2, 2, 79, 24, "Û", 15, 0, 0);
        displayTextArt(mutable_brand, len, 4, 0, 15);
        drawFilledBox(11, 3, 78, 20, "Û", 0, 1, 0);
        drawFilledBox(21, 3, 78, 23, "Û", 7, 1, 0);
        if (total_phones == 0) {
            textcolor(15); textbackground(0);
            gotoxy(5, 12); cprintf("SORRY! NO SMART PHONES IN THIS CATEGORY. PRESS ANY KEY TO RETURN BACK");
            getch(); return;
        }
        textcolor(15); textbackground(0);
        if (strcmp(mutable_brand, "other") == 0) {
            for (i = 0; positions[i] != 10; i++) {
                if (i > 7) {
                    gotoxy(35, 4 + i);
                    cprintf("                     ");
                    gotoxy(35, 4 + i); cout << i + 1;
                    cprintf(".) "); cprintf(company_names[i]); cprintf(" "); cprintf(model_names[i]);
                }
                else {
                    gotoxy(5, 12 + i);
                    cprintf("                     ");
                    gotoxy(5, 12 + i); cout << i + 1;
                    cprintf(".) "); cprintf(company_names[i]); cprintf(" "); cprintf(model_names[i]);
                }
            }
        }
        else {
            for (i = 0; positions[i] != 10; i++) {
                if (i > 7) {
                    gotoxy(35, 4 + i);
                    cprintf("                     ");
                    gotoxy(35, 4 + i); cout << i + 1;
                    cprintf(".) "); cprintf(model_names[i]);
                }
                else {
                    gotoxy(5, 12 + i);
                    cprintf("                     ");
                    gotoxy(5, 12 + i); cout << i + 1;
                    cprintf(".) "); cprintf(model_names[i]);
                }
            }
        }
        textcolor(0); textbackground(15);
        gotoxy(15, 22); cprintf(">> ENTER YOUR CHOICE (0 for back):       ");
        gotoxy(51, 22); cin >> choice;
        if (choice >= 1 && choice <= total_phones) {
            fin.open("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(positions[choice - 1]);
            fin.read((char*)&phone, sizeof(phone));
            displaySmartphoneDetails(phone);
            fin.close();
        }
        else if (choice == 0) return;
        else {
            gotoxy(15, 22);
            cprintf("OOPS! WRONG CHOICE ! TRY AGAIN BY PRESSING ANY KEY.       ");
            getch();
        }
    }
}

void addSmartphoneRecord() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("add", 18, 4, 10, 6);
    displayTextArt("data", 40, 4, 10, 6);
    Smartphone phone;
    drawText("data\\text\\addguide.dat", 14, 7, 14);
    getch();
    drawFilledBox(12, 3, 78, 23, "Û", 6, 1, 0);
    ofstream fout("data\\text\\mobinfo.dat", ios::binary | ios::app);
    promptForSmartphoneDetails(phone);
    fout.write((char*)&phone, sizeof(phone));
    drawFilledBox(12, 3, 78, 23, "Û", 6, 1, 0);
    textcolor(14); textbackground(14);
    gotoxy(25, 19);
    cprintf("\nMobile Info added successfully");
    fout.close();
    getch();
}

void modifySmartphoneRecord() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("modify", 8, 4, 10, 6);
    displayTextArt("data", 50, 4, 10, 6);
    drawText("data\\text\\modguide.dat", 14, 7, 14);
    getch(); drawFilledBox(12, 3, 78, 23, "Û", 6, 1, 0);
    fstream file("data\\text\\mobinfo.dat", ios::in | ios::out | ios::binary);
    Smartphone phone, new_phone_data;
    promptForSmartphoneDetails(new_phone_data);
    bool found = false;
    while (file.read((char*)&phone, sizeof(phone))) {
        if (strcmp(phone.model_name, new_phone_data.model_name) == 0) {
            if (strcmp(new_phone_data.company_name, ".") == 0)
                strcpy(new_phone_data.company_name, phone.company_name);
            if (strcmp(new_phone_data.processor, ".") == 0)
                strcpy(new_phone_data.processor, phone.processor);
            if (strcmp(new_phone_data.os, ".") == 0)
                strcpy(new_phone_data.os, phone.os);
            if (strcmp(new_phone_data.sensors, ".") == 0)
                strcpy(new_phone_data.sensors, phone.sensors);
            if (new_phone_data.battery == 0)
                new_phone_data.battery = phone.battery;
            for(int i=0; i<5; i++)
                if(new_phone_data.price[i] == 0) new_phone_data.price[i] = phone.price[i];
            for(int i=0; i<3; i++)
                if(new_phone_data.dimensions[i] == 0) new_phone_data.dimensions[i] = phone.dimensions[i];
            for(int i=0; i<2; i++)
                if(new_phone_data.camera[i] == 0) new_phone_data.camera[i] = phone.camera[i];
            for(int i=0; i<2; i++)
                if(new_phone_data.memory[i] == 0) new_phone_data.memory[i] = phone.memory[i];
            if (new_phone_data.weight == 0)
                new_phone_data.weight = phone.weight;
            if (new_phone_data.network == 0)
                new_phone_data.network = phone.network;
            if (new_phone_data.os_version == 0)
                new_phone_data.os_version = phone.os_version;
            if (new_phone_data.year == 0)
                new_phone_data.year = phone.year;
            long l = -sizeof(phone);
            file.seekp(l, ios::cur);
            file.write((char*)&new_phone_data, sizeof(new_phone_data));
            found = true;
            break;
        }
    }
    file.close();

    drawFilledBox(12, 3, 78, 23, "Û", 6, 1, 0);
    textcolor(14); textbackground(14);
    if(found){
        gotoxy(25, 19);
        cprintf("\nMobile Info modified successfully...");
    } else {
        gotoxy(33, 19);
        cprintf("MOBILE NOT FOUND");
    }
    getch();
}

void displayFilteredSmartphones(int phone_indices[]) {
    Smartphone phone;
    int i = 0, choice;
    char model_names[150][30], company_names[150][30];
    for (i = 0; phone_indices[i] != 10; i++) {
        ifstream fin("data\\text\\mobinfo.dat", ios::binary);
        fin.seekg(phone_indices[i]);
        fin.read((char*)&phone, sizeof(phone));
        strcpy(model_names[i], phone.model_name);
        strcpy(company_names[i], phone.company_name);
        fin.close();
    }
    while (1) {
        drawFilledBox(2, 2, 79, 24, "Û", 7, 1, 0);
        drawBorderedBox(2, 2, 79, 24, "Û", 15, 0, 0);
        displayTextArt("filter", 23, 4, 0, 15);
        drawFilledBox(11, 3, 78, 20, "Û", 0, 1, 0);
        drawFilledBox(21, 3, 78, 23, "Û", 7, 1, 0);
        textcolor(15); textbackground(0);
        int total_phones = i;
        for (i = 0; phone_indices[i] != 10; i++) {
            if (i > 15) {
                textcolor(0); textbackground(15);
                gotoxy(15, 22);
                cprintf("OOPS! SO MANY MOBILES IN FILTERING. PLEASE APPLY MORE.");
                getch(); return;
            }
            if (i > 7) {
                gotoxy(35, 4 + i);
                cprintf("                     ");
                gotoxy(35, 4 + i); cout << i + 1;
                cprintf(".) "); cprintf(company_names[i]); cprintf(" "); cprintf(model_names[i]);
            }
            else {
                gotoxy(5, 12 + i);
                cprintf("                     ");
                gotoxy(5, 12 + i); cout << i + 1;
                cprintf(".) "); cprintf(company_names[i]); cprintf(" "); cprintf(model_names[i]);
            }
        }
        textcolor(0); textbackground(15);
        gotoxy(15, 22); cprintf(">> ENTER YOUR CHOICE (0 for back):       "); gotoxy(51, 22); cin >> choice;
        if (choice >= 1 && choice <= total_phones) {
            ifstream fin("data\\text\\mobinfo.dat", ios::binary);
            fin.seekg(phone_indices[choice - 1]);
            fin.read((char*)&phone, sizeof(phone));
            displaySmartphoneDetails(phone);
            fin.close();
        }
        else if (choice == 0) return;
        else {
            gotoxy(15, 22);
            cprintf("OOPS! WRONG CHOICE ! TRY AGAIN BY PRESSING ANY KEY.       ");
            getch();
        }
    }
}