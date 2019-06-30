cmake_minimum_required(VERSION 3.0)

# Initial Setup ============================================

set(PROJECT_NAME errors)
project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE Debug)

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
  # using clang
  set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Weverything")
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  # using gcc
  set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra")
endif()

set(CMAKE_CXX_STANDARD 14)

# Building the executable ===================================

include_directories(include/)

# Building the tests ========================================

add_subdirectory(external/gtest)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include( cmake/CodeCoverage.cmake )
SET(CMAKE_CXX_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage")

add_subdirectory(tests)

