#ifndef PHONE_DATA_H
#define PHONE_DATA_H

#include <string>
#include <vector>
#include <array>

namespace phone_data {

#include <fstream>

class Smartphone {
public:
    std::string company_name;
    std::string model_name;
    std::string processor;
    std::string os;
    std::string sensors;
    int year;
    int battery;
    std::array<int, 5> price;
    std::array<int, 3> dimensions;
    int weight;
    std::array<int, 2> camera;
    std::array<int, 2> memory;
    int network;
    float os_version;

    void serialize(std::ofstream& fout) const;
    void deserialize(std::ifstream& fin);
};

void promptForSmartphoneDetails(Smartphone &phone);
void displaySmartphoneDetails(const Smartphone& phone);
void displaySmartphonesByBrand(const std::string& brand);
void addSmartphoneRecord();
void modifySmartphoneRecord();
void displayFilteredSmartphones(const std::vector<int>& phone_indices);

} // namespace phone_data

#endif // PHONE_DATA_H