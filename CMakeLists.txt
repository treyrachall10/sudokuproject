cmake_minimum_required(VERSION 3.30)
project(project)

set(CMAKE_CXX_STANDARD 14)

include_directories(SudokuProject/include)

add_executable(project
    SudokuProject/include/generator.h
    SudokuProject/include/sudoku.h
    SudokuProject/include/sudoku_io.h
    SudokuProject/include/utils.h
    SudokuProject/src/generator.cpp
    SudokuProject/src/sudoku.cpp
    SudokuProject/src/sudoku_io.cpp
    SudokuProject/src/utils.cpp
    SudokuProject/main.cpp)
