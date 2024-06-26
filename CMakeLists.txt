cmake_minimum_required(VERSION 3.0.0)
project(DataStruct VERSION 0.1.0)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(DataStruct
    "src/main.c"
    "src/arraylist.c"
    "src/linkedlist.c"
    "src/stack.c"
    "src/queue.c"
    "src/stringbuffer.c"
)
