#ifndef PHONE_DATA_H
#define PHONE_DATA_H

class Smartphone {
public:
    char company_name[40];
    char model_name[40];
    char processor[40];
    char os[40];
    char sensors[40];
    int year;
    int battery;
    int price[5];
    int dimensions[3];
    int weight;
    int camera[2];
    int memory[2];
    int network;
    float os_version;
};

void promptForSmartphoneDetails(Smartphone &phone);
void displaySmartphoneDetails(Smartphone phone);
void displaySmartphonesByBrand(const char* brand);
void addSmartphoneRecord();
void modifySmartphoneRecord();
void displayFilteredSmartphones(int phone_indices[]);

#endif // PHONE_DATA_H