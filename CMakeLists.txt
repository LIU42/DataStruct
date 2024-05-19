cmake_minimum_required(VERSION 3.0.0)
project(DataStruct VERSION 0.1.0)

include_directories(
    ${PROJECT_SOURCE_DIR}/Headers
)

add_executable(DataStruct
    "Sources/Main.c"
    "Sources/ArrayList.c"
    "Sources/LinkedList.c"
    "Sources/Stack.c"
    "Sources/Queue.c"
    "Sources/String.c"
)
