#include "ip_filter.h"

#include <gtest/gtest.h>
// тест 1
TEST(SplitTest, BasicSplit)
{
    auto r = split("11.22.33.44", '.');
    ASSERT_EQ(r.size(), 4u);
    EXPECT_EQ(r[0], "11");
    EXPECT_EQ(r[1], "22");
    EXPECT_EQ(r[2], "33");
    EXPECT_EQ(r[3], "44");
}

// тест 2
TEST(SortTest, ReverseLexicographicByBytes)
{
    std::vector<std::vector<std::string>> pool = {
        {"1", "1", "1", "1"},
        {"1", "10", "1", "1"},
        {"1", "2", "1", "1"},
    };

    sort_ips(pool);

    EXPECT_EQ(pool[0][1], "10");
    EXPECT_EQ(pool[1][1], "2");
    EXPECT_EQ(pool[2][1], "1");
}

// тест 3
TEST(FilterTest, AnyByteEquals46)
{
    std::vector<std::vector<std::string>> pool = {
        {"186", "204", "34", "46"}, 
        {"186", "46", "222", "194"}, 
        {"1", "1", "1", "1"},  
        {"46", "70", "225", "39"},
    };

    auto r = filter_by_any_byte(pool, 46);
    ASSERT_EQ(r.size(), 3u);
}