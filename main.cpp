#include "ip_filter.h"

#include <iostream>
#include <string>
#include <vector>

int main(int, char const*[])
{
    std::vector<IpParts> ip_pool;

    for (std::string line; std::getline(std::cin, line);)
    {
        std::vector<std::string> v = split(line, '\t');
        ip_pool.push_back(split(v.at(0), '.'));
    }

    // обратная лексикографическая сортировка
    sort_ips(ip_pool);
 
    decltype(ip_pool) pool_copy = ip_pool;

    auto print_ip = [](const IpParts& ip)
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

    for (const auto& ip : filter_1(pool_copy))
        print_ip(ip);

    for (const auto& ip : filter_2(pool_copy))
        print_ip(ip);

    for (const auto& ip : filter_3(pool_copy))
        print_ip(ip);

    return 0;
}