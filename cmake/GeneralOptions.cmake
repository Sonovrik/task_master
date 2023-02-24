# Cmake for default options
# Using: include (GeneralOptions)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 17)

if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
    set(ADDITIONAL_LIB rt)
endif()
