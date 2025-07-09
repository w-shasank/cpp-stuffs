cmake_minimum_required(VERSION 3.10)
project(ATM_SFML)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add executable
add_executable(atm atm.cpp)

# Link SFML libraries
target_link_libraries(atm sfml-graphics sfml-window sfml-system)
