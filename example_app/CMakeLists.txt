cmake_minimum_required(VERSION 3.5.0>=)
project(example_app VERSION 0.1.0 LANGUAGES C CXX)

find_library(NAMES gmp gmpxx REQUIRED)
add_executable(example_app main.cpp)

target_link_libraries(example_app gmp gmpxx)
target_include_directories(example_app PRIVATE src)
add_library(Point src/Point/Point.h src/Point/Point.cpp)
target_link_libraries(example_app Point)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
