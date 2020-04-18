cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++11")

project(war)

add_executable(
    war
    main.cpp
    PlayingCard.cpp
    GameOfWar.cpp
    Player.cpp
)