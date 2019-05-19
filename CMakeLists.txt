cmake_minimum_required(VERSION 3.13)
project(vk_internship_test_2019)

set(CMAKE_CXX_STANDARD 17)

add_executable(vk_internship_test_2019 tests.cpp CommonElementsCounter.h
        gtest-all.cc
        gtest_main.cc)
