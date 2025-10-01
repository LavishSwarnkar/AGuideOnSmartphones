#include "export.h"
#include "phone_data.h"
#include "ui.h"
#include <fstream>
#include <conio.h>

using namespace std;

void exportData() {
    Smartphone m;
    ofstream fout("data.xls");
    ifstream fin("data\\text\\mobinfo.dat", ios::binary);
    fout << "COMPANY NAME" << "\t" << "MOBILE NAME" << "\t" << "PROCESSOR NAME" << "\t" << "OS NAME" << "\t" << "OS VERSION" << "\t" << "SENSORS" << "\t" << "YEAR OF LAUNCH" << "\t" << "BATTERY" << "\t" << "PRICE ON AMAZON" << "\t" << ",EBAY" << "\t" << ",SNAPDEAL" << "\t" << ",FLIPKART OR MI SHOP (IN RS )" << "\t" << "LENGTH," << "\t" << "BREADTH AND" << "\t" << "WIDTH (IN mm)" << "\t" << "WEIGHT (IN GRAMS)" << "\t" << "CAMERA (REAR)," << "\t" << "(FRONT) (IN MPs)" << "\t" << "MEMORY (ROM)," << "\t" << "(RAM)" << "\t" << "NETWORK GENRATION" << "\t";
    while (fin.read((char*)&m, sizeof(m))) {
        fout << "\n" << m.company_name << "\t" << m.model_name << "\t" << m.processor << "\t" << m.os << "\t" << m.os_version << "\t" << m.sensors << "\t" << m.year << "\t" << m.battery << "\t";
        for (int i = 0; i < 4; i++) {
            fout << m.price[i];
            if (m.price[i] > 0) fout << ",000";
            fout << "\t";
        }
        fout << m.dimensions[0] << "\t" << m.dimensions[1] << "\t" << m.dimensions[2] << "\t" << m.weight << "\t" << m.camera[0] << "\t" << m.camera[1];
        for (int i = 0; i < 2; i++) {
            if (m.memory[i] < 0) {
                m.memory[i] *= -1;
                fout << m.memory[i] << " MBs" << "\t";
            }
            else
                fout << m.memory[i] << " GBs" << "\t";
        }
        fout << m.network << " G" << "\t";
    }
    fin.close();
    fout.close();
    drawText("data\\text\\expguide.dat", 14, 9, 7);
    getch();
}