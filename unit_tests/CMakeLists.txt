# Define source files for the unit tests
set(TEST_SOURCES vector_unit_tests.cpp)

# Create executable target for the unit tests
add_executable(vector_unit_tests ${TEST_SOURCES})

# Link GoogleTest libraries and the Vector library
target_link_libraries(vector_unit_tests
    gtest_main
    vector
)

# Specify include directories for the unit tests
target_include_directories(vector_unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Discover and run GoogleTest tests
include(GoogleTest)
gtest_discover_tests(vector_unit_tests)

