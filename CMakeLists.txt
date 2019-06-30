cmake_minimum_required(VERSION 3.0)

# Initial Setup ============================================

set(PROJECT_NAME errors)
project(${PROJECT_NAME})

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    if ("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
      # using clang
      set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Weverything")
    elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
      # using gcc
      set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra")
    elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "Intel")
      # using intel c compiler
    elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
      # using visual studio c compiler
    endif()
endif()

set(CMAKE_CXX_STANDARD 14)

# Building the executable ===================================

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Building the tests ========================================

add_subdirectory(external/gtest)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(errors_tests errors_test.cc)
target_link_libraries(errors_tests gtest gtest_main)
add_test(ErrorsTest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/errors_tests)
