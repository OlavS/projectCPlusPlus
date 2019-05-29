cmake_minimum_required(VERSION 3.13)
project(snake)

set(CMAKE_CXX_STANDARD 14)

add_executable(snake main.cpp Ticks/Ticks.cpp Ticks/Ticks.h Collision/Collision.cpp Collision/Collision.h  Position/Position.cpp Position/Position.h
        SnakeHead/SnakeHead.cpp SnakeHead/SnakeHead.h SnakeBody/SnakeBody.cpp SnakeBody/SnakeBody.h GameBoard/GameBoard.cpp)