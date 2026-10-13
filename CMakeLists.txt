cmake_minimum_required(VERSION 3.14)
project(ip_filter CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Библиотека с логикой ---
add_library(ip_filter_lib ip_filter.cpp)
target_include_directories(ip_filter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# --- Основная программа ---
add_executable(ip_filter main.cpp)
target_link_libraries(ip_filter PRIVATE ip_filter_lib)

# --- Тесты ---
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(ip_filter_tests tests/test_ip_filter.cpp)
target_link_libraries(ip_filter_tests
    PRIVATE ip_filter_lib
    PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ip_filter_tests)