#include "ip_filter.h"

#include <iostream>
#include <string>
#include <vector>

int main(int, char const*[])
{
    try
    {
        std::vector<std::vector<std::string>> ip_pool;

        for (std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        // обратная лексикографическая сортировка
        sort_ips(ip_pool);

        auto print_ip = [](const std::vector<std::string>& ip)
        {
            for (std::size_t i = 0; i < ip.size(); ++i)
            {
                if (i != 0)
                    std::cout << ".";
                std::cout << ip[i];
            }
            std::cout << std::endl;
        };

        for (const auto& ip : ip_pool)
            print_ip(ip);

        for (const auto& ip : filter_1(ip_pool, 1))
            print_ip(ip);

        for (const auto& ip : filter_2(ip_pool, 46, 70))
            print_ip(ip);

        for (const auto& ip : filter_3(ip_pool, 46))
            print_ip(ip);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}