cmake_minimum_required(VERSION 2.8.9)
project(akss)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "-Weverything -Wno-c++98-compat-bind-to-temporary-copy -Wno-global-constructors -Wno-c++98-compat -std=c++11")
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/")

include_directories(src)
find_package(GMP REQUIRED)

enable_testing()
add_test(NAME akss_test COMMAND akss_test)

add_subdirectory(src)
add_subdirectory(test)
