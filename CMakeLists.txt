cmake_minimum_required(VERSION 3.14)
project(ip_filter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED PATCH_VERSION)
    set(PATCH_VERSION 0)
endif()
set(PROJECT_VERSION_PATCH ${PATCH_VERSION})

add_library(ip_filter_lib ip_filter.cpp)
target_include_directories(ip_filter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(ip_filter main.cpp)
target_link_libraries(ip_filter PRIVATE ip_filter_lib)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

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

set(CPACK_PACKAGE_NAME "ip_filter")
set(CPACK_PACKAGE_VENDOR "Student")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "IP filter (lab 2, C++11)")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "student@example.com")

if(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR "DEB;ZIP")
else()
    set(CPACK_GENERATOR "ZIP")
endif()

include(CPack)