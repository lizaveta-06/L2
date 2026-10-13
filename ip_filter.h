#pragma once

#include <string>
#include <vector>

// Разбивает строку по символу-разделителю.
std::vector<std::string> split(const std::string& str, char d);

// Обратная лексикографическая сортировка IP.
void sort_ips(std::vector<std::vector<std::string>>& ip_pool);

// Фильтр: первый байт == value.
std::vector<std::vector<std::string>> filter_by_first_byte(
    const std::vector<std::vector<std::string>>& pool, int value);

// Фильтр: первый байт == b1 и второй байт == b2.
std::vector<std::vector<std::string>> filter_by_first_two_bytes(
    const std::vector<std::vector<std::string>>& pool, int b1, int b2);

// Фильтр: любой из 4 байтов == value.
std::vector<std::vector<std::string>> filter_by_any_byte(
    const std::vector<std::vector<std::string>>& pool, int value);