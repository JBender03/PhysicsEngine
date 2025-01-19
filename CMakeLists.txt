# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(PhysicsEngine CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set SFML path for MSYS2/UCRT64
set(SFML_DIR "C:/msys64/ucrt64/lib/cmake/SFML")
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};C:/msys64/ucrt64")

# Add SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add the include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create library from source files
add_library(physics_lib
    src/Vector2D.cpp
    src/Particle.cpp
    src/GravityForce.cpp
    src/Renderer.cpp
)

# Link SFML to your library
target_link_libraries(physics_lib sfml-graphics sfml-window sfml-system)

# Create executable for tests
add_executable(renderer_test
    tests/renderer_test.cpp
)

# Link the test executable with the library
target_link_libraries(renderer_test physics_lib)