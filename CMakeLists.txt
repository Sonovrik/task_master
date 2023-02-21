cmake_minimum_required(VERSION 3.22)
project(task_master)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(GeneralOptions)

add_subdirectory(utils)

add_executable(task_master
        main.cpp)
