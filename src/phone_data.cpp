#include "phone_data.h"
#include "ui.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>

namespace phone_data {

using namespace ui;

// --- Serialization helpers ---
void write_string(std::ofstream& fout, const std::string& s) {
    size_t len = s.length();
    fout.write(reinterpret_cast<const char*>(&len), sizeof(len));
    fout.write(s.c_str(), len);
}

std::string read_string(std::ifstream& fin) {
    size_t len;
    fin.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (!fin || fin.gcount() != sizeof(len)) return "";
    std::string s(len, '\0');
    fin.read(&s[0], len);
    return s;
}


void Smartphone::serialize(std::ofstream& fout) const {
    write_string(fout, company_name);
    write_string(fout, model_name);
    write_string(fout, processor);
    write_string(fout, os);
    write_string(fout, sensors);
    fout.write(reinterpret_cast<const char*>(&year), sizeof(year));
    fout.write(reinterpret_cast<const char*>(&battery), sizeof(battery));
    fout.write(reinterpret_cast<const char*>(&price), sizeof(price));
    fout.write(reinterpret_cast<const char*>(&dimensions), sizeof(dimensions));
    fout.write(reinterpret_cast<const char*>(&weight), sizeof(weight));
    fout.write(reinterpret_cast<const char*>(&camera), sizeof(camera));
    fout.write(reinterpret_cast<const char*>(&memory), sizeof(memory));
    fout.write(reinterpret_cast<const char*>(&network), sizeof(network));
    fout.write(reinterpret_cast<const char*>(&os_version), sizeof(os_version));
}

void Smartphone::deserialize(std::ifstream& fin) {
    company_name = read_string(fin);
    model_name = read_string(fin);
    processor = read_string(fin);
    os = read_string(fin);
    sensors = read_string(fin);
    fin.read(reinterpret_cast<char*>(&year), sizeof(year));
    fin.read(reinterpret_cast<char*>(&battery), sizeof(battery));
    fin.read(reinterpret_cast<char*>(&price), sizeof(price));
    fin.read(reinterpret_cast<char*>(&dimensions), sizeof(dimensions));
    fin.read(reinterpret_cast<char*>(&weight), sizeof(weight));
    fin.read(reinterpret_cast<char*>(&camera), sizeof(camera));
    fin.read(reinterpret_cast<char*>(&memory), sizeof(memory));
    fin.read(reinterpret_cast<char*>(&network), sizeof(network));
    fin.read(reinterpret_cast<char*>(&os_version), sizeof(os_version));
}

void cgets(char* buffer) {
    int i = 0;
    char c;
    while ((c = getche()) != '\r') {
        if (c == '\b' && i > 0) {
            std::cout << "\b \b";
            i--;
        } else if (c != '\b') {
            buffer[i++] = c;
        }
    }
    buffer[i] = '\0';
}


void promptForSmartphoneDetails(Smartphone &phone) {
    char buffer[50];

    textcolor(15); textbackground(14);

    gotoxy(12, 12); cprintf("Enter Company's Name:               ");
    gotoxy(34, 12); cgets(buffer); phone.company_name = buffer;

    gotoxy(12, 13); cprintf("Enter Mobile's Name:                            ");
    gotoxy(33, 13); cgets(buffer); phone.model_name = buffer;

    gotoxy(12, 14); cprintf("Enter Mobile's Year:                           ");
    gotoxy(33, 14); std::cin >> phone.year;

    gotoxy(12, 14); cprintf("Enter Processor's Name:                                   ");
    gotoxy(36, 14); cgets(buffer); phone.processor = buffer;

    gotoxy(12, 15); cprintf("Enter Operating System's Name:                              ");
    gotoxy(43, 15); cgets(buffer); phone.os = buffer;

    gotoxy(12, 15); cprintf("Enter Operating System's Version:                    ");
    gotoxy(45, 15); std::cin >> phone.os_version;

    gotoxy(12, 16); cprintf("Enter Weight(in grams):               ");
    gotoxy(36, 16); std::cin >> phone.weight;

    gotoxy(12, 17); cprintf("Enter Size in order (L,B,H) (in mm):        ");
    std::cin >> phone.dimensions[0] >> phone.dimensions[1] >> phone.dimensions[2];

    gotoxy(12, 18); cprintf("Enter Price in order (A,E,SD,MI/FK) :              ");
    unsigned long p1, p2, p3, p4;
    std::cin >> p1 >> p2 >> p3 >> p4;
    phone.price[0] = p1 / 1000;
    phone.price[1] = p2 / 1000;
    phone.price[2] = p3 / 1000;
    phone.price[3] = p4 / 1000;
    phone.price[4] = (phone.price[0] + phone.price[1] + phone.price[2] + phone.price[3]) / 4;

    gotoxy(12, 19); cprintf("Enter Camera in order (Rear,Front) (Leave 0, if not available):   ");
    std::cin >> phone.camera[0] >> phone.camera[1];

    gotoxy(12, 20); cprintf("Enter Memory in order (ROM,RAM) (In GBs/MBs):        ");
    std::cin >> phone.memory[0] >> phone.memory[1];

    gotoxy(12, 21); cprintf("Enter Battery Capacity (in mAh):            ");
    gotoxy(45, 21); std::cin >> phone.battery;

    gotoxy(12, 22); cprintf("Enter specific Sensors (if any):                       ");
    gotoxy(45, 22); cgets(buffer); phone.sensors = buffer;
    if (phone.sensors == "Y") phone.sensors = "FINGERPRINT AND COMMON";
    if (phone.sensors == "N") phone.sensors = "COMMON";

    gotoxy(12, 23); cprintf("Enter Network Type (Eg.4 for 4G):          ");
    gotoxy(46, 23); std::cin >> phone.network;
}

void displaySmartphoneDetails(const Smartphone& phone) {
    textcolor(15); textbackground(0);
    clrscr();
    drawBorderedBox(2, 2, 79, 24, "Û", 7, 1, 0);

    int l = (80 - phone.model_name.length()) / 2;
    gotoxy(l, 5); cprintf("%s", phone.model_name.c_str());

    gotoxy(32, 6); cprintf("BROUGHT TO YOU BY");
    l = (72 - phone.company_name.length()) / 2;
    gotoxy(l, 7); cprintf("%s IN %d", phone.company_name.c_str(), phone.year);

    gotoxy(5, 9); cprintf(">> PROCESSOR: %s", phone.processor.c_str());
    gotoxy(5, 10); cprintf(">> OPERATING SYSTEM: %s %.1f", phone.os.c_str(), phone.os_version);
    if (phone.os == "ANDROID") {
        if (phone.os_version == 4) cprintf(" JELLY BEAN / KITKAT");
        else if (phone.os_version == 5) cprintf(" LOLLIPOP");
        else if (phone.os_version == 6) cprintf(" MARSHMALLOW");
        else if (phone.os_version == 7) cprintf(" NOUGHAT");
    }

    gotoxy(5, 11); cprintf(">> BODY: ");
    gotoxy(13, 12); cprintf(">> SIZE (L,B,H): %d, %d, %d mm", phone.dimensions[0], phone.dimensions[1], phone.dimensions[2]);
    gotoxy(13, 13); cprintf(">> WEIGHT: %d Grams", phone.weight);

    gotoxy(5, 14); cprintf(">> STORAGE: ");
    gotoxy(16, 15); cprintf(">> ROM: %d GB", phone.memory[0]);
    gotoxy(16, 16); cprintf(">> RAM: ");
    if (phone.memory[1] < 0) {
        cprintf("%d MB", -phone.memory[1]);
    } else {
        cprintf("%d GB", phone.memory[1]);
    }

    gotoxy(5, 17); cprintf(">> CAMERA: ");
    gotoxy(16, 17); cprintf(">> REAR: %d MPs", phone.camera[0]);
    gotoxy(16, 18); cprintf(">> FRONT: %d MPs", phone.camera[1]);

    gotoxy(5, 19); cprintf(">> PRICE (A,E,SD,MI/FK)(0-NA): %lu, %lu, %lu, %lu Rupees", (unsigned long)phone.price[0]*1000, (unsigned long)phone.price[1]*1000, (unsigned long)phone.price[2]*1000, (unsigned long)phone.price[3]*1000);
    gotoxy(5, 20); cprintf(">> BATTERY: %d mAh", phone.battery);
    gotoxy(5, 21); cprintf(">> SPECIFIC SENSORS: %s", phone.sensors.c_str());
    gotoxy(5, 22); cprintf(">> NETWORK: %d G", phone.network);

    getch();
    textbackground(1); clrscr();
}

void displaySmartphonesByBrand(const std::string& brand) {
    std::vector<int> positions;
    std::vector<std::string> model_names;
    std::vector<std::string> company_names;

    std::string upper_brand = brand;
    std::transform(upper_brand.begin(), upper_brand.end(), upper_brand.begin(), ::toupper);

    std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
    Smartphone phone;
    while (fin.peek() != EOF) {
        long pos = fin.tellg();
        phone.deserialize(fin);
        if(fin.fail()) break;

        std::string current_company = phone.company_name;
        std::transform(current_company.begin(), current_company.end(), current_company.begin(), ::toupper);

        bool is_other = (current_company != "APPLE" && current_company != "ASUS" && current_company != "BLACKBERRY" && current_company != "HTC" && current_company != "GIONEE" && current_company != "LE ECO" && current_company != "LENOVO" && current_company != "LG" && current_company != "MICROMAX" && current_company != "MICROSOFT" && current_company != "ONEPLUS" && current_company != "OPPO" && current_company != "SAMSUNG" && current_company != "SONY" && current_company != "XIAOMI");

        if ((upper_brand == "OTHER" && is_other) || (upper_brand == current_company)) {
            positions.push_back(pos);
            model_names.push_back(phone.model_name);
            company_names.push_back(phone.company_name);
        }
    }
    fin.close();

    std::string mutable_brand = brand;
    if (mutable_brand == "Le ECO") mutable_brand = "LEECO";
    std::transform(mutable_brand.begin(), mutable_brand.end(), mutable_brand.begin(), ::tolower);

    while (true) {
        int len = (80 - ((mutable_brand.length() * 5) + mutable_brand.length() - 1)) / 2;
        drawFilledBox(2, 2, 79, 24, "Û", 7, 1, 0);
        drawBorderedBox(2, 2, 79, 24, "Û", 15, 0, 0);
        displayTextArt(mutable_brand, len, 4, 0, 15);
        drawFilledBox(11, 3, 78, 20, "Û", 0, 1, 0);
        drawFilledBox(21, 3, 78, 23, "Û", 7, 1, 0);

        if (positions.empty()) {
            textcolor(15); textbackground(0);
            gotoxy(5, 12); cprintf("SORRY! NO SMART PHONES IN THIS CATEGORY. PRESS ANY KEY TO RETURN BACK");
            getch(); return;
        }

        textcolor(15); textbackground(0);
        for (size_t i = 0; i < positions.size(); ++i) {
            int x = (i > 7) ? 35 : 5;
            int y = (i > 7) ? 4 + i : 12 + i;
            gotoxy(x, y);
            if (brand == "OTHER") {
                cprintf("%zu.) %s %s", i + 1, company_names[i].c_str(), model_names[i].c_str());
            } else {
                cprintf("%zu.) %s", i + 1, model_names[i].c_str());
            }
        }

        textcolor(0); textbackground(15);
        gotoxy(15, 22); cprintf(">> ENTER YOUR CHOICE (0 for back):       ");
        int choice;
        std::cin >> choice;

        if (choice >= 1 && choice <= positions.size()) {
            fin.open("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(positions[choice - 1]);
            phone.deserialize(fin);
            displaySmartphoneDetails(phone);
            fin.close();
        } else if (choice == 0) {
            return;
        } else {
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
    drawText("data/text/addguide.dat", 14, 7, 14);
    getch();
    drawFilledBox(12, 3, 78, 23, "Û", 6, 1, 0);

    std::ofstream fout("data/text/mobinfo.dat", std::ios::binary | std::ios::app);
    Smartphone phone;
    promptForSmartphoneDetails(phone);
    phone.serialize(fout);
    fout.close();

    drawFilledBox(12, 3, 78, 23, "Û", 6, 1, 0);
    textcolor(14); textbackground(14);
    gotoxy(25, 19);
    cprintf("\nMobile Info added successfully");
    getch();
}

void modifySmartphoneRecord() {
    drawFilledBox(3, 3, 78, 23, "Û", 6, 1);
    drawFilledBox(3, 3, 78, 10, "Û", 6, 1);
    drawBorderedBox(2, 2, 79, 10, "Û", 14, 1);
    displayTextArt("modify", 8, 4, 10, 6);
    displayTextArt("data", 50, 4, 10, 6);
    drawText("data/text/modguide.dat", 14, 7, 14);
    getch();
    drawFilledBox(12, 3, 78, 23, "Û", 6, 1, 0);

    Smartphone new_phone_data;
    promptForSmartphoneDetails(new_phone_data);

    std::vector<Smartphone> phones;
    std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
    while(fin.peek() != EOF) {
        Smartphone p;
        p.deserialize(fin);
        if(fin.fail()) break;
        phones.push_back(p);
    }
    fin.close();

    bool found = false;
    for(auto& phone : phones) {
        if (phone.model_name == new_phone_data.model_name) {
            if (new_phone_data.company_name != ".") phone.company_name = new_phone_data.company_name;
            if (new_phone_data.processor != ".") phone.processor = new_phone_data.processor;
            if (new_phone_data.os != ".") phone.os = new_phone_data.os;
            if (new_phone_data.sensors != ".") phone.sensors = new_phone_data.sensors;
            if (new_phone_data.battery != 0) phone.battery = new_phone_data.battery;
            for(int i=0; i<5; i++) if(new_phone_data.price[i] != 0) phone.price[i] = new_phone_data.price[i];
            for(int i=0; i<3; i++) if(new_phone_data.dimensions[i] != 0) phone.dimensions[i] = new_phone_data.dimensions[i];
            for(int i=0; i<2; i++) if(new_phone_data.camera[i] != 0) phone.camera[i] = new_phone_data.camera[i];
            for(int i=0; i<2; i++) if(new_phone_data.memory[i] != 0) phone.memory[i] = new_phone_data.memory[i];
            if (new_phone_data.weight != 0) phone.weight = new_phone_data.weight;
            if (new_phone_data.network != 0) phone.network = new_phone_data.network;
            if (new_phone_data.os_version != 0) phone.os_version = new_phone_data.os_version;
            if (new_phone_data.year != 0) phone.year = new_phone_data.year;
            found = true;
            break;
        }
    }

    if(found) {
        std::ofstream fout("data/text/mobinfo.dat", std::ios::binary | std::ios::trunc);
        for(const auto& p : phones) {
            p.serialize(fout);
        }
        fout.close();
    }

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

void displayFilteredSmartphones(const std::vector<int>& phone_indices) {
    std::vector<std::string> model_names;
    std::vector<std::string> company_names;
    Smartphone phone;

    std::vector<int> valid_indices;
    for (int index : phone_indices) {
        if (index == 10) continue;
        valid_indices.push_back(index);
        std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
        fin.seekg(index);
        phone.deserialize(fin);
        if(fin.fail()) {
            fin.close();
            continue;
        }
        model_names.push_back(phone.model_name);
        company_names.push_back(phone.company_name);
        fin.close();
    }

    while (true) {
        drawFilledBox(2, 2, 79, 24, "Û", 7, 1, 0);
        drawBorderedBox(2, 2, 79, 24, "Û", 15, 0, 0);
        displayTextArt("filter", 23, 4, 0, 15);
        drawFilledBox(11, 3, 78, 20, "Û", 0, 1, 0);
        drawFilledBox(21, 3, 78, 23, "Û", 7, 1, 0);
        textcolor(15); textbackground(0);

        if (model_names.empty()) {
             gotoxy(15, 22);
             cprintf("NO MOBILES FOUND! PRESS ANY KEY TO RETURN.       ");
             getch();
             return;
        }

        for (size_t i = 0; i < model_names.size(); ++i) {
            int x = (i > 7) ? 35 : 5;
            int y = (i > 7) ? 4 + (i-8) : 12 + i;
            gotoxy(x, y);
            cprintf("%zu.) %s %s", i + 1, company_names[i].c_str(), model_names[i].c_str());
        }

        textcolor(0); textbackground(15);
        gotoxy(15, 22); cprintf(">> ENTER YOUR CHOICE (0 for back):       ");
        int choice;
        std::cin >> choice;

        if (choice >= 1 && choice <= valid_indices.size()) {
            std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(valid_indices[choice - 1]);
            phone.deserialize(fin);
            displaySmartphoneDetails(phone);
            fin.close();
        } else if (choice == 0) {
            return;
        } else {
            gotoxy(15, 22);
            cprintf("OOPS! WRONG CHOICE ! TRY AGAIN BY PRESSING ANY KEY.       ");
            getch();
        }
    }
}

} // namespace phone_data