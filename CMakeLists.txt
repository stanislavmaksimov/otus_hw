cmake_minimum_required(VERSION 3.10)

project(otus_hw LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES_LIB
    src/quadratic_equation.hpp
)
add_library(${PROJECT_NAME}.lib STATIC ${SOURCES_LIB})
set_target_properties(${PROJECT_NAME}.lib PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()
include(cmake/gtest.cmake)
include(GoogleTest)
set(SOURCES_TEST
    src/quadratic_equation.test.cpp
)
add_executable(${PROJECT_NAME}.test ${SOURCES_TEST})
target_link_libraries(${PROJECT_NAME}.test ${PROJECT_NAME}.lib gtest_main gtest pthread)
gtest_discover_tests(${PROJECT_NAME}.test)
