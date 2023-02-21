cmake_minimum_required(VERSION 3.22)
include(GeneralOptions)

# third-party lib
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/yaml-cpp)

set(PARSER_SOURCES
        ConfigParser.cpp)

add_library(${PROJECT_NAME}
                ${PARSER_SOURCES})

target_link_libraries(${PROJECT_NAME}
                PRIVATE
                    yaml-cpp)
