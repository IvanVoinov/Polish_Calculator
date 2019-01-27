cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 11)
project(Polish_Calculator)

option(CMAKE_USE_WIN32_THREADS_INIT "using WIN32 threads" ON)
option(gtest_disable_pthreads "Disable uses of pthreads in gtest." ON)

add_subdirectory(googletest)

set(SOURCES
    calculator.cc)

add_executable(calculator_test
               calculator_test.cc
               ${SOURCES})

target_link_libraries(calculator_test gtest gmock_main)
add_test(NAME calculator_test COMMAND test)

