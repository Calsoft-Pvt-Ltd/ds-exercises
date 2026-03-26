cmake_minimum_required(VERSION 3.14)
project(ds-exercises-cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Fetch Google Test automatically
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Exercise library — students implement the TODO methods in these files
add_library(exercises
  exercises/fixed_array.cpp
  exercises/linked_list.cpp
  exercises/stack.cpp
  exercises/queue.cpp
  exercises/trie.cpp
  exercises/bst.cpp
)
target_include_directories(exercises PUBLIC exercises)

# Test runner
add_executable(run_tests
  tests/test_array.cpp
  tests/test_linked_list.cpp
  tests/test_stack.cpp
  tests/test_queue.cpp
  tests/test_trie.cpp
  tests/test_bst.cpp
)
target_link_libraries(run_tests exercises GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(run_tests)
