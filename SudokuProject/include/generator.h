/**
* @file generator.h
 * @brief Function prototypes for generating random solvable Sudoku boards.
 *
 * This header defines functions to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * -  and generate a complete Sudoku board.
 * - Randomly delete cells to create a solvable puzzle.
 * - Generate a complete Sudoku puzzle with a specific number of empty cells.
 *
 * Detailed function descriptions and parameters are provided below.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>

 /**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
int** getEmptyBoard();

/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
std::vector<int> getShuffledVector();

/**
 * @brief fills diagonal 3x3 boxes with random values 1-9.
 *
 * Iterates over 3 diagonal 3x3 boxes. Iterates over each row and column in box.
 * Fills cells with random numbers 1-9
 *
 * @param BOARD A pointer to the 2D Sudoku board (int**) to fill.
 */
void fillBoardWithIndependentBox(int** BOARD);

/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
void deleteRandomItems(int** BOARD, const int& n);

/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
int** generateBoard(const int& empty_boxes);

#endif // GENERATOR_H
