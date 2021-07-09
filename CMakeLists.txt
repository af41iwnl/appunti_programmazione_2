cmake_minimum_required(VERSION 3.12)

project(
    test_cpp_sanitizer
    VERSION 0.0.0
    DESCRIPTION "Test of sanitizers in C++."
    LANGUAGES CXX)
message(STATUS "${PROJECT_NAME} version ${PROJECT_VERSION}")
message(STATUS "build type: ${CMAKE_BUILD_TYPE}")

set(BUILDNAME
    "${CMAKE_HOST_SYSTEM_NAME}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}-${CMAKE_BUILD_TYPE}"
)
include(CTest)

set(CMAKE_CXX_STANDARD
    17
    CACHE STRING "C++ standard")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}/bin>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}/lib>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}/bin>)

add_executable(test_ouf_of_bound out_of_bound.cpp)
target_compile_options(test_ouf_of_bound PRIVATE -fsanitize=address)
target_link_options(test_ouf_of_bound PRIVATE -fsanitize=address)
