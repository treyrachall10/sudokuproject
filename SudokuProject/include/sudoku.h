/**
 * @file sudoku.h
 * @brief Core Sudoku solving and board generation functions.
 *
 * This header file declares functions essential for solving Sudoku puzzles
 * and validating board states. It includes:
 * - A backtracking Sudoku solver.
 * - A cell validation function to ensure valid number placement.
 * - A board generation stub for creating Sudoku puzzles.
 *
 * All functions operate on dynamically allocated 9x9 Sudoku boards
 * represented as `int**`, where empty cells are denoted by 0.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef SUDOKUPROJECT_SUDOKU_H
#define SUDOKUPROJECT_SUDOKU_H

#include <iostream>

/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
bool isValid(int** BOARD, const int& r, const int& c, const int& k);

/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
bool solveBoard(int** BOARD, const int& r=0, const int& c=0);

// ========================= Efficient Solutions ==========================


/**
  * @brief finds next cell with minimum amount of possibilities for number.
  *
  * Takes a pointer to dynamically created 2D array (BOARD)
  *
  * @param BOARD board pointer to the dynamically allocated 2D array
  * @return tuple of cell with minimum solutions for cell
  */
std::tuple<int, int, int> findNextCell(int** BOARD);


/**
 * @brief Solves the Sudoku board using recursive backtracking.
 *
 * Uses findNextCell() to select the next empty cell with the fewest valid options.
 * If no empty cells remain (r = -1, c = -1), the board is solved and returns true.
 *
 * Iterates through numbers 1 to 9, checking validity with isValid(). If valid, places
 * the number and recursively calls solveBoardEfficient(). If the call returns true,
 * the board is solved. If false, backtracks by resetting the cell to 0.
 *
 * Returns false if no valid number works.
 *
 * @param BOARD A pointer to the dynamically allocated 9x9 Sudoku board.
 * @return true if the board is solved, false otherwise.
 */
bool solveBoardEfficient(int** BOARD);

/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
bool solve(int** board, const bool& efficient = false);

#endif //SUDOKUPROJECT_SUDOKU_H