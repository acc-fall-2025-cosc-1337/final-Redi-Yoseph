# Build test executable
add_executable(craps_tests craps_test.cpp)

# Link test executable with your library
target_link_libraries(craps_tests craps_library)

# Allow `ctest` or `make test`
add_test(NAME craps_tests COMMAND craps_tests -s)
