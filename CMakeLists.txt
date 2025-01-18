# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(Physics CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create library from source files
add_library(physics_lib
    src/Vector2D.cpp
    src/Particle.cpp
)

# Create executable for tests
add_executable(physics_tests
    tests/main.cpp
)

# Link the test executable with the library
target_link_libraries(physics_tests physics_lib)