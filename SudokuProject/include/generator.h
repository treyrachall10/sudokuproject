/**
* @file generator.h
 * @brief Function prototypes for generating random solvable Sudoku boards.
 *
 * This header defines functions to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * - Solve and generate a complete Sudoku board.
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
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
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
