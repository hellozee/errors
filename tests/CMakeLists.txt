add_executable(errors_tests errors_test.cc)
target_link_libraries(errors_tests gtest gtest_main)

SETUP_TARGET_FOR_COVERAGE(
    errors_tests_coverage  
    errors_tests
    coverage
)

add_test(ErrorsTest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/errors_tests)
