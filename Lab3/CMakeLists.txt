cmake_minimum_required(VERSION 3.10)

project(Lab3 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SOURCES
    main.cpp
    src/priority_queue.cpp
    src/vector.cpp    
)

add_executable(Lab3 ${SOURCES})

target_include_directories(Lab3 PUBLIC templates)