#pragma once

#include <string>
#include <vector>

using IpParts = std::vector<std::string>;

// разбивает строку по символу-разделителю
std::vector<std::string> split(const std::string& str, char d);

// обратная лексикографическая сортировка 
void sort_ips(std::vector<IpParts>& ip_pool);

// фильтр первый байт == 1
std::vector<IpParts> filter_1(const std::vector<IpParts>& pool);

// фильтр первый байт == 46 и второй байт == 70
std::vector<IpParts> filter_2(const std::vector<IpParts>& pool);

// фильтр любой из 4 байтов == 46
std::vector<IpParts> filter_3(const std::vector<IpParts>& pool);