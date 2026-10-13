#pragma once

#include <string>
#include <vector>

// разбивает строку по символу-разделителю
std::vector<std::string> split(const std::string& str, char d);

// обратная лексикографическая сортировка 
void sort_ips(std::vector<std::vector<std::string>>& ip_pool);

// фильтр первый байт == value
std::vector<std::vector<std::string>> filter_by_first_byte(
    const std::vector<std::vector<std::string>>& pool, int value);

// фильтр первый байт == b1 и второй байт == b2
std::vector<std::vector<std::string>> filter_by_first_two_bytes(
    const std::vector<std::vector<std::string>>& pool, int b1, int b2);

// фильтр любой из 4 байтов == value
std::vector<std::vector<std::string>> filter_by_any_byte(
    const std::vector<std::vector<std::string>>& pool, int value);