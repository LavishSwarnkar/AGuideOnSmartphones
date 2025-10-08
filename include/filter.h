#ifndef FILTER_H
#define FILTER_H

#include <vector>

namespace filter {

std::vector<int> filterByCompanyName(const std::vector<int>& existing_filters);
std::vector<int> filterByProcessor(const std::vector<int>& existing_filters);
std::vector<int> filterByOS(const std::vector<int>& existing_filters);
std::vector<int> filterByCamera(const std::vector<int>& existing_filters);
std::vector<int> filterByMemory(const std::vector<int>& existing_filters);
std::vector<int> filterByPrice(const std::vector<int>& existing_filters);
std::vector<int> filterByNetwork(const std::vector<int>& existing_filters);
std::vector<int> filterByBattery(const std::vector<int>& existing_filters);
std::vector<int> filterByYear(const std::vector<int>& existing_filters);
std::vector<int> filterBySensor(const std::vector<int>& existing_filters);

} // namespace filter

#endif // FILTER_H