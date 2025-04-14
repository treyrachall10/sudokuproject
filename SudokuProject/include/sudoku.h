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
 * @brief Checks if a given number can be placed at a specific position on the Sudoku board.
 *
 * Verifies whether placing the number 'k' at position (r, c) violates Sudoku rules.
 * Ensures 'k' does not already exist in the same row, column, or 3x3 subgrid.
 *
 * @param BOARD Pointer to a dynamically allocated 9x9 Sudoku board.
 * @param r Row index of the cell.
 * @param c Column index of the cell.
 * @param k The number to be validated for placement.
 * @return true if placement is valid, false otherwise.
 */
bool isValid(int** BOARD, const int& r, const int& c, const int& k);

/**
 * @brief Recursively solves a Sudoku board using backtracking.
 *
 * Attempts to fill the Sudoku board by placing digits 1 through 9 in each empty cell,
 * checking if the placement is valid. Proceeds cell by cell in a row-wise fashion.
 * Backtracks if no valid number can be placed in a cell.
 *
 * @param BOARD Pointer to a dynamically allocated 9x9 Sudoku board.
 * @param r Row index to start solving from (default is 0).
 * @param c Column index to start solving from (default is 0).
 * @return true if the board is solved successfully, false otherwise.
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
  * @brief indicates which solver to use when solving sudoku board.
  *
  * Calls solveBoardEfficient() if efficient equals true. otherwise calls solveBoard().
  *
  * @param board pointer to the dynamically allocated 2D array.
  * @param efficient boolean indicating which solver to use(false if not provided).
  * @return solved board.
  */
bool solve(int** board, const bool& efficient = false);

#endif //SUDOKUPROJECT_SUDOKU_H