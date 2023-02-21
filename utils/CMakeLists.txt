cmake_minimum_required(VERSION 3.22)
project(utils)

include(GeneralOptions)

# third-party lib
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/parser/yaml-cpp)

set(PARSER_SOURCES
        parser/ConfigParser.cpp)

add_library(${PROJECT_NAME}
        SHARED
            ${PARSER_SOURCES})

target_include_directories(${PROJECT_NAME}
        PUBLIC
            ${PROJECT_SOURCE_DIR}
            ${PROJECT_SOURCE_DIR}/parser)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
            yaml-cpp)

#target_link_directories(${PROJECT_NAME}
#        PUBLIC
#            yaml-cpp)

