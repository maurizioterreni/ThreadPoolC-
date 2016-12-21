cmake_minimum_required(VERSION 3.7)
project(ThreadPool_Terreni)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    queue.h
    ThreadPool.cpp
    ThreadPool.h
    Work.cpp
    Work.h)

add_executable(ThreadPool_Terreni ${SOURCE_FILES})