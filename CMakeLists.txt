cmake_minimum_required(VERSION 3.27)
project(untitled6)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled6 main.cpp
        cargo.cpp
        cargo.h
        storage.cpp
        storage.h
        json.hpp
        Storage.json
        Worker.cpp
        Worker.h
        Ui.cpp
        Ui.h
)
