cmake_minimum_required(VERSION 3.9...3.19)
project(Project6 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# build test executable
add_executable(unit_tests catch.hpp unit_tests.cpp
  dictionary.hpp dictionary.cpp
  test_spell.cpp)

# build command line executable
add_executable(myspell myspell.cpp
  dictionary.hpp dictionary.cpp)

# enable testing
enable_testing()

# register Catch tests with cmake
include(Catch)
catch_discover_tests(unit_tests)
