cmake_minimum_required(VERSION 3.5.0)
project(build_system VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src/Exception)
add_subdirectory(cfg)
add_subdirectory(src/staff)
add_subdirectory(src/DependencyGraph)
add_subdirectory(src/PathFilter)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(${PROJECT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} Exception cfg staff DependencyGraph PathFilter)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
