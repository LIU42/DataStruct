cmake_minimum_required(VERSION 3.0.0)
project(DataStruct VERSION 0.1.0)

file(GLOB SOURCES_FILES
    ${PROJECT_SOURCE_DIR}/*.c
)
add_executable(DataStruct ${SOURCES_FILES})
