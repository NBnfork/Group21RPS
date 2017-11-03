cmake_minimum_required(VERSION 3.8)
project(Group21RPS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        Makefile
        paper.cpp
        rock.cpp
        RPSGame.cpp
        scissors.cpp
        tool.cpp
        validChar.cpp
        utilities.cpp
        )

add_executable(Group21RPS ${SOURCE_FILES})