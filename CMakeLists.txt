cmake_minimum_required(VERSION 3.22)
project(path_finder)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set C standard to C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Disable GNU extensions
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_EXTENSIONS OFF)

# Set default build type to Release With Debug Info
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Add compiler options based on compiler
if(MSVC)
    add_compile_options(/W4)  # MSVC
else()
    add_compile_options(-g -Wall -Wextra -Wpedantic)  # GCC/Clang
endif()

find_package(Curses REQUIRED)

include_directories(inc)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/a_star.cpp
    src/node.cpp
)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

# Disable the cache of build type and rely on either the default or the provided one
unset(CMAKE_BUILD_TYPE CACHE)

