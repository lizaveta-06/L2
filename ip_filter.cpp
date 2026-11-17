#include "ip_filter.h"

#include <algorithm>
#include <tuple>
#include <iterator>

static int to_int(const std::string& s)
{
    return std::stoi(s);
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

void sort_ips(std::vector<IpParts>& ip_pool)
{
    
    std::sort(ip_pool.begin(), ip_pool.end(),
              [](const IpParts& a, const IpParts& b)
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

std::vector<IpParts> filter_1(const std::vector<IpParts>& pool)
{
    std::vector<IpParts> result;
    std::copy_if(pool.begin(), pool.end(), std::back_inserter(result),
                 [](const IpParts& ip) { return to_int(ip[0]) == 1; });
    return result;
}

std::vector<IpParts> filter_2(const std::vector<IpParts>& pool)
{
    // кортеж эталлон
    const auto prefix = std::make_tuple(46, 70);
    std::vector<IpParts> result;

    std::copy_if(pool.begin(), pool.end(), std::back_inserter(result),
                 [&prefix](const IpParts& ip)
                 {
                     return std::make_tuple(to_int(ip[0]), to_int(ip[1])) == prefix;
                 });
    return result;
}

std::vector<IpParts> filter_3(const std::vector<IpParts>& pool)
{
    std::vector<IpParts> result;
    std::copy_if(pool.begin(), pool.end(), std::back_inserter(result),
                 [](const IpParts& ip)
                 {
                     return std::any_of(ip.begin(), ip.end(),
                                        [](const std::string& s)
                                        { return to_int(s) == 46; });
                 });
    return result;
}