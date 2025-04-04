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
 * @brief creates a 9x9 sudoku board.
 *
 * Defines a 2d array of type integer. Initializes array by looping through
 * each row and filling them with an array of integers of size 9.
 *
 * @return board A 2d integer array.
 */
int** getEmptyBoard();

/**
 * @brief creates a shuffled vector 1-9 inclusive.
 *
 * Initialized vector of type int of values ranging 1-9.
 * Generates a random seed, generates a random sequence using that seed,
 * uses sequence to shuffle start to end of vector
 *
 * @return shuffled vector.
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
 * @brief randomly selects cells to be deleted.
 *
 * Checks if inputs are valid (BOARD is not nullptr, n greater than 0 but less than 82).
 * Generates array of 9 bitsets of size 9. Generates a random column and row number.
 * Checks if bit at that column and row position in bitset has not been set.
 * If it hasn't then set BOARD at that position to 0, otherwise do nothing and repeat iteration.
 *
 * @param BOARD A pointer to the 2D Sudoku board (int**) to fill.
 * @param n An integer representing number of cells to delete.
 */
void deleteRandomItems(int** BOARD, const int& n);

/**
 * @brief generates solvable sudoku board.
 *
 * Initializes empty 9x9 sudoku board using getEmptyBoard(). Fills 3x3 diagonal boxes
 * (top left, middle, bottom right) on board with random values 1-9 using
 * fillBoardWithIndependentBox(). Solves board using solve(). Deletes random cells using
 * deleteRandomItems()
 *
 * @param empty_boxes Integer indicating how many empty boxes to remove from sudoku board.
 * @return A solvable board
 */
int** generateBoard(const int& empty_boxes);

#endif // GENERATOR_H
