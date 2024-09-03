cmake_minimum_required(VERSION 3.10)
project(vector)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the Vector3D library
add_library(vector STATIC src/Vector.cpp)

# Specify include directories for the Vector3D library
target_include_directories(vector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include Google Test:
add_subdirectory(external/googletest)

# Include Unit Test directory:
add_subdirectory(unit_tests)

