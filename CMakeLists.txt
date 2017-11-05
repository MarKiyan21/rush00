cmake_minimum_required(VERSION 3.8)
project(rush_00)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp AEntities.cpp Player.cpp Enemies.cpp Bullets.cpp)
add_executable(rush_00 ${SOURCE_FILES})