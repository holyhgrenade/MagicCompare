cmake_minimum_required(VERSION 3.10)

project(MagicCompare)

# Set the C++ standard (you can change this if needed)
set(CMAKE_CXX_STANDARD 17)

# Define the source directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/test")

# Include the source directory for header files
include_directories(${SRC_DIR})

# Add your tests
add_executable(MagicCompareTest
    ${TEST_DIR}/test_main.cpp  # Add your test source files here
)

# Include the source directory for the tests
target_include_directories(MagicCompareTest PRIVATE ${SRC_DIR})

# Enable testing with CTest
enable_testing()

# Add a test that runs your test executable
add_test(NAME TestCreation COMMAND MagicCompareTest 0)
add_test(NAME TestBoolConversion COMMAND MagicCompareTest 1)
add_test(NAME TestSmallerThan COMMAND MagicCompareTest 2)
add_test(NAME TestGreaterThan COMMAND MagicCompareTest 3)
add_test(NAME TestSmallerThanOrEq COMMAND MagicCompareTest 4)
add_test(NAME TestGreaterThanOrEq COMMAND MagicCompareTest 5)
add_test(NAME TestEq COMMAND MagicCompareTest 6)
add_test(NAME TestNeq COMMAND MagicCompareTest 7)
add_test(NAME TestChain COMMAND MagicCompareTest 8)
add_test(NAME TestIncrement COMMAND MagicCompareTest 9)
add_test(NAME TestDecrement COMMAND MagicCompareTest 10)
add_test(NAME TestSum COMMAND MagicCompareTest 11)
add_test(NAME TestDiff COMMAND MagicCompareTest 12)
add_test(NAME TestMult COMMAND MagicCompareTest 13)
add_test(NAME TestDiv COMMAND MagicCompareTest 14)
add_test(NAME TestMathFunctions COMMAND MagicCompareTest 15)
