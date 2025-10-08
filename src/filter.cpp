#include "filter.h"
#include "phone_data.h"
#include "ui.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>

namespace filter {

using namespace ui;
using namespace phone_data;

// Helper to get string input, since gets is unsafe
void cgets(char* buffer, int max_len) {
    int i = 0;
    char c;
    while ((c = getche()) != '\r' && i < max_len - 1) {
        if (c == '\b' && i > 0) {
            std::cout << "\b \b";
            i--;
        } else if (c != '\b') {
            buffer[i++] = c;
        }
    }
    buffer[i] = '\0';
}

std::vector<int> filterByCompanyName(const std::vector<int>& existing_filters) {
    char s[30];
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER COMPANY'S NAME:                          "); gotoxy(26, 22); cgets(s, 30);

    std::string company_name_str(s);
    std::transform(company_name_str.begin(), company_name_str.end(), company_name_str.begin(), ::toupper);

    std::vector<int> b;
    if (existing_filters.empty() || (existing_filters.size() == 1 && existing_filters[0] == 10)) {
        std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
        Smartphone m;
        while (fin.peek() != EOF) {
            long pos = fin.tellg();
            m.deserialize(fin);
            if(fin.fail()) break;
            std::string current_company = m.company_name;
            std::transform(current_company.begin(), current_company.end(), current_company.begin(), ::toupper);
            if (company_name_str == current_company) {
                b.push_back(pos);
            }
        }
        fin.close();
    } else {
        for (int pos : existing_filters) {
            if(pos == 10) continue;
            std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(pos);
            Smartphone m;
            m.deserialize(fin);
            if(fin.fail()) continue;
            std::string current_company = m.company_name;
            std::transform(current_company.begin(), current_company.end(), current_company.begin(), ::toupper);
            if (company_name_str == current_company) {
                b.push_back(pos);
            }
            fin.close();
        }
    }
    b.push_back(10);
    return b;
}

std::vector<int> filterByProcessor(const std::vector<int>& existing_filters) {
    char s[30];
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER PROCESSOR'S NAME:                          "); gotoxy(28, 22); cgets(s, 30);

    std::string processor_str(s);
    std::transform(processor_str.begin(), processor_str.end(), processor_str.begin(), ::toupper);

    std::vector<int> b;
    if (existing_filters.empty() || (existing_filters.size() == 1 && existing_filters[0] == 10)) {
        std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
        Smartphone m;
        while (fin.peek() != EOF) {
            long pos = fin.tellg();
            m.deserialize(fin);
            if(fin.fail()) break;
            std::string current_processor = m.processor;
            std::transform(current_processor.begin(), current_processor.end(), current_processor.begin(), ::toupper);
            if (processor_str == current_processor) {
                b.push_back(pos);
            }
        }
        fin.close();
    } else {
        for (int pos : existing_filters) {
            if(pos == 10) continue;
            std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(pos);
            Smartphone m;
            m.deserialize(fin);
            if(fin.fail()) continue;
            std::string current_processor = m.processor;
            std::transform(current_processor.begin(), current_processor.end(), current_processor.begin(), ::toupper);
            if (processor_str == current_processor) {
                b.push_back(pos);
            }
            fin.close();
        }
    }
    b.push_back(10);
    return b;
}

std::vector<int> filterByOS(const std::vector<int>& existing_filters) {
    char s[30];
    float v;
    char k;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER OPERATING SYSTEM'S NAME:                          "); gotoxy(36, 22); cgets(s, 30);
    gotoxy(4, 22); cprintf("ENTER OPERATING SYSTEM'S VERSION:                          "); gotoxy(38, 22); std::cin >> v;
    gotoxy(4, 22); cprintf("ENTER OS VERSION'S NO. (0 FOR SAME,1 FOR GREATER AND 2 FOR LESSER):     "); gotoxy(73, 22); k = getch();

    std::string os_str(s);
    std::transform(os_str.begin(), os_str.end(), os_str.begin(), ::toupper);

    std::vector<int> b;
    auto check_os = [&](const Smartphone& m) {
        std::string current_os = m.os;
        std::transform(current_os.begin(), current_os.end(), current_os.begin(), ::toupper);
        if (os_str != current_os) return false;
        if (k == '0' && m.os_version == v) return true;
        if (k == '1' && m.os_version >= v) return true;
        if (k == '2' && m.os_version <= v) return true;
        return false;
    };

    if (existing_filters.empty() || (existing_filters.size() == 1 && existing_filters[0] == 10)) {
        std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
        Smartphone m;
        while (fin.peek() != EOF) {
            long pos = fin.tellg();
            m.deserialize(fin);
            if(fin.fail()) break;
            if (check_os(m)) {
                b.push_back(pos);
            }
        }
        fin.close();
    } else {
        for (int pos : existing_filters) {
            if(pos == 10) continue;
            std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(pos);
            Smartphone m;
            m.deserialize(fin);
            if(fin.fail()) continue;
            if (check_os(m)) {
                b.push_back(pos);
            }
            fin.close();
        }
    }
    b.push_back(10);
    return b;
}

std::vector<int> filterByCamera(const std::vector<int>& existing_filters) {
    int rl, ru, fl, fu;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER REAR CAMERA'S LOWER LIMIT:                          ");  gotoxy(37, 22); std::cin >> rl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER REAR CAMERA'S UPPER LIMIT:                          "); gotoxy(37, 22); std::cin >> ru;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER FRONT CAMERA'S LOWER LIMIT:                          "); gotoxy(38, 22); std::cin >> fl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER FRONT CAMERA'S UPPER LIMIT:                          "); gotoxy(38, 22); std::cin >> fu;

    std::vector<int> b;
    auto check_camera = [&](const Smartphone& m) {
        return (m.camera[0] >= rl && m.camera[0] <= ru) && (m.camera[1] >= fl && m.camera[1] <= fu);
    };

    if (existing_filters.empty() || (existing_filters.size() == 1 && existing_filters[0] == 10)) {
        std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
        Smartphone m;
        while (fin.peek() != EOF) {
            long pos = fin.tellg();
            m.deserialize(fin);
            if(fin.fail()) break;
            if (check_camera(m)) {
                b.push_back(pos);
            }
        }
        fin.close();
    } else {
        for (int pos : existing_filters) {
            if(pos == 10) continue;
            std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(pos);
            Smartphone m;
            m.deserialize(fin);
            if(fin.fail()) continue;
            if (check_camera(m)) {
                b.push_back(pos);
            }
            fin.close();
        }
    }
    b.push_back(10);
    return b;
}

std::vector<int> filterByMemory(const std::vector<int>& existing_filters) {
    int rl, ru, fl, fu;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER ROM'S LOWER LIMIT:                          "); gotoxy(29, 22); std::cin >> rl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER ROM'S UPPER LIMIT:                          ");  gotoxy(29, 22); std::cin >> ru;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER RAM'S LOWER LIMIT:                          "); gotoxy(29, 22); std::cin >> fl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER RAM'S UPPER LIMIT:                          ");    gotoxy(29, 22); std::cin >> fu;

    std::vector<int> b;
    auto check_memory = [&](const Smartphone& m) {
        return (m.memory[0] >= rl && m.memory[0] <= ru) && (m.memory[1] >= fl && m.memory[1] <= fu);
    };

    if (existing_filters.empty() || (existing_filters.size() == 1 && existing_filters[0] == 10)) {
        std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
        Smartphone m;
        while (fin.peek() != EOF) {
            long pos = fin.tellg();
            m.deserialize(fin);
            if(fin.fail()) break;
            if (check_memory(m)) {
                b.push_back(pos);
            }
        }
        fin.close();
    } else {
        for (int pos : existing_filters) {
            if(pos == 10) continue;
            std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(pos);
            Smartphone m;
            m.deserialize(fin);
            if(fin.fail()) continue;
            if (check_memory(m)) {
                b.push_back(pos);
            }
            fin.close();
        }
    }
    b.push_back(10);
    return b;
}

std::vector<int> filterByPrice(const std::vector<int>& existing_filters) {
    unsigned long rl, ru;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER PRICE'S LOWER LIMIT:                          "); gotoxy(31, 22); std::cin >> rl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER PRICE'S UPPER LIMIT:                          "); gotoxy(31, 22); std::cin >> ru;
    ru /= 1000;
    rl /= 1000;

    std::vector<int> b;
    auto check_price = [&](const Smartphone& m) {
        int mpr = 0;
        for (int j = 0; j < 4; j++) {
            if (m.price[j] != 0) {
                mpr = m.price[j];
                break;
            }
        }
        return (mpr >= rl && mpr <= ru);
    };

    if (existing_filters.empty() || (existing_filters.size() == 1 && existing_filters[0] == 10)) {
        std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
        Smartphone m;
        while (fin.peek() != EOF) {
            long pos = fin.tellg();
            m.deserialize(fin);
            if(fin.fail()) break;
            if (check_price(m)) {
                b.push_back(pos);
            }
        }
        fin.close();
    } else {
        for (int pos : existing_filters) {
            if(pos == 10) continue;
            std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(pos);
            Smartphone m;
            m.deserialize(fin);
            if(fin.fail()) continue;
            if (check_price(m)) {
                b.push_back(pos);
            }
            fin.close();
        }
    }
    b.push_back(10);
    return b;
}

std::vector<int> filterByNetwork(const std::vector<int>& existing_filters) {
    int rl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER NETWORK'S GENERATION:                          "); gotoxy(32, 22); std::cin >> rl;

    std::vector<int> b;
    if (existing_filters.empty() || (existing_filters.size() == 1 && existing_filters[0] == 10)) {
        std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
        Smartphone m;
        while (fin.peek() != EOF) {
            long pos = fin.tellg();
            m.deserialize(fin);
            if(fin.fail()) break;
            if (m.network == rl) {
                b.push_back(pos);
            }
        }
        fin.close();
    } else {
        for (int pos : existing_filters) {
            if(pos == 10) continue;
            std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(pos);
            Smartphone m;
            m.deserialize(fin);
            if(fin.fail()) continue;
            if (m.network == rl) {
                b.push_back(pos);
            }
            fin.close();
        }
    }
    b.push_back(10);
    return b;
}

std::vector<int> filterByBattery(const std::vector<int>& existing_filters) {
    int rl, ru;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER BATTERY'S LOWER CAPACITY:                          "); gotoxy(36, 22); std::cin >> rl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER BATTERY'S UPPER CAPACITY:                          "); gotoxy(36, 22); std::cin >> ru;

    std::vector<int> b;
    auto check_battery = [&](const Smartphone& m) {
        return m.battery >= rl && m.battery <= ru;
    };

    if (existing_filters.empty() || (existing_filters.size() == 1 && existing_filters[0] == 10)) {
        std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
        Smartphone m;
        while (fin.peek() != EOF) {
            long pos = fin.tellg();
            m.deserialize(fin);
            if(fin.fail()) break;
            if (check_battery(m)) {
                b.push_back(pos);
            }
        }
        fin.close();
    } else {
        for (int pos : existing_filters) {
            if(pos == 10) continue;
            std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(pos);
            Smartphone m;
            m.deserialize(fin);
            if(fin.fail()) continue;
            if (check_battery(m)) {
                b.push_back(pos);
            }
            fin.close();
        }
    }
    b.push_back(10);
    return b;
}

std::vector<int> filterByYear(const std::vector<int>& existing_filters) {
    int rl;
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);
    textcolor(0); textbackground(15);
    gotoxy(4, 22); cprintf("ENTER YEAR OF LAUNCH:                          "); gotoxy(26, 22); std::cin >> rl;

    std::vector<int> b;
    if (existing_filters.empty() || (existing_filters.size() == 1 && existing_filters[0] == 10)) {
        std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
        Smartphone m;
        while (fin.peek() != EOF) {
            long pos = fin.tellg();
            m.deserialize(fin);
            if(fin.fail()) break;
            if (m.year == rl) {
                b.push_back(pos);
            }
        }
        fin.close();
    } else {
        for (int pos : existing_filters) {
            if(pos == 10) continue;
            std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(pos);
            Smartphone m;
            m.deserialize(fin);
            if(fin.fail()) continue;
            if (m.year == rl) {
                b.push_back(pos);
            }
            fin.close();
        }
    }
    b.push_back(10);
    return b;
}

std::vector<int> filterBySensor(const std::vector<int>& existing_filters) {
    drawFilledBox(22, 3, 78, 23, "Û", 7, 0, 0);

    std::vector<int> b;
    if (existing_filters.empty() || (existing_filters.size() == 1 && existing_filters[0] == 10)) {
        std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
        Smartphone m;
        while (fin.peek() != EOF) {
            long pos = fin.tellg();
            m.deserialize(fin);
            if(fin.fail()) break;
            if (m.sensors == "FINGERPRINT AND COMMON") {
                b.push_back(pos);
            }
        }
        fin.close();
    } else {
        for (int pos : existing_filters) {
            if(pos == 10) continue;
            std::ifstream fin("data/text/mobinfo.dat", std::ios::binary);
            fin.seekg(pos);
            Smartphone m;
            m.deserialize(fin);
            if(fin.fail()) continue;
            if (m.sensors == "FINGERPRINT AND COMMON") {
                b.push_back(pos);
            }
            fin.close();
        }
    }
    b.push_back(10);
    return b;
}

} // namespace filter