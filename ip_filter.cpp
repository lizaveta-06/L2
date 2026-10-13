#include "ip_filter.h"

#include <algorithm>
#include <tuple>
#include <type_traits>

static int to_int(const std::string& s)
{
    return std::stoi(s);
}

static bool has_byte(const std::vector<std::string>& ip, int value)
{
    for (std::size_t i = 0; i < ip.size(); ++i)
    {
        if (to_int(ip[i]) == value)
            return true;
    }
    return false;
}

std::vector<std::string> split(const std::string& str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void sort_ips(std::vector<std::vector<std::string>>& ip_pool)
{
    using Ip = std::remove_reference<decltype(ip_pool)>::type::value_type;

    std::sort(ip_pool.begin(), ip_pool.end(),
              [](const Ip& a, const Ip& b)
              {
                  for (std::size_t i = 0; i < 4; ++i)
                  {
                      const int ai = to_int(a[i]);
                      const int bi = to_int(b[i]);
                      if (ai != bi)
                          return ai > bi; 
                  }
                  return false;
              });
}

std::vector<std::vector<std::string>> filter_by_first_byte(
    const std::vector<std::vector<std::string>>& pool, int value)
{
    std::vector<std::vector<std::string>> result;
    for (const auto& ip : pool)
    {
        if (to_int(ip[0]) == value)
            result.push_back(ip);
    }
    return result;
}

std::vector<std::vector<std::string>> filter_by_first_two_bytes(
    const std::vector<std::vector<std::string>>& pool, int b1, int b2)
{
    // кортеж эталлон
    const auto prefix = std::make_tuple(b1, b2);
    std::vector<std::vector<std::string>> result;

    for (const auto& ip : pool)
    {
        const auto first_two = std::make_tuple(to_int(ip[0]), to_int(ip[1]));
        if (first_two == prefix)
            result.push_back(ip);
    }
    return result;
}

std::vector<std::vector<std::string>> filter_by_any_byte(
    const std::vector<std::vector<std::string>>& pool, int value)
{
    std::vector<std::vector<std::string>> result;
    for (const auto& ip : pool)
    {
        if (has_byte(ip, value))
            result.push_back(ip);
    }
    return result;
}