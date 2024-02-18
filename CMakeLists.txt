cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME Minesweeper)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} main.cpp
    game.cpp             game.h
    gameUI.cpp           gameUI.h
    gameInputStream.cpp  gameInputStream.h
    converter.cpp        converter.h
    map.cpp              map.h
)