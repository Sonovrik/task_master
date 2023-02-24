cmake_minimum_required(VERSION 3.22)
project(task_master)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 17)

if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
    set(ADDITIONAL_LIB rt)
endif()

add_executable(${PROJECT_NAME}
        logging/Logger.cpp
        main.cpp)

target_include_directories(${PROJECT_NAME}
        PRIVATE
            logging)