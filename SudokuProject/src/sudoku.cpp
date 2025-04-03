/**
 * @file sudoku.cpp
 * @brief Implementation of core Sudoku solving and validation functions.
 *
 * Contains the logic for validating moves and solving Sudoku puzzles using
 * a backtracking algorithm. Detailed function descriptions are provided in
 * the corresponding header file.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
*/

#include "../include/sudoku.h"
#include <iostream>
#include <tuple>
using namespace std;

bool isValid(int** BOARD, const int& r, const int& c, const int& k)
{
    // Check if 'k' already exists in the same row or column
    for (int i = 0; i < 9; i++)
    {
        if (k == BOARD[r][i] || k == BOARD[i][c])
            return false;  // Invalid placement
    }

    // Determine starting indices for the 3x3 subgrid
    int startRow = 3 * (r / 3);
    int startCol = 3 * (c / 3);

    // Check if 'k' exists in the 3x3 subgrid
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (k == BOARD[i][j])
                return false;  // Invalid placement
        }
    }

    return true;  // Placement is valid
}

bool solveBoard(int** BOARD, const int& r, const int& c)
{
    // If we've reached beyond the last row, the board is solved
    if (r == 9)
        return true;

    // Move to the next row if we've reached the end of the current row
    if (c == 9)
        return solveBoard(BOARD, r + 1, 0);

    // Skip already filled cells and move to the next column
    if (BOARD[r][c] != 0)
        return solveBoard(BOARD, r, c + 1);

    // Try placing numbers 1 to 9 in the current empty cell
    for (int k = 1; k <= 9; k++)
    {
        if (isValid(BOARD, r, c, k))
        {
            BOARD[r][c] = k;  // Place number 'k'

            // Recursively attempt to solve the rest of the board
            if (solveBoard(BOARD, r, c + 1))
                return true;  // Found a valid solution

            // Backtrack: Remove the number if no solution is found
            BOARD[r][c] = 0;
        }
    }

    // Trigger backtracking if no valid number can be placed
    return false;
}



tuple<int, int, int> findNextCell(int** BOARD) {
    /**
     * @brief Finds the next empty cell using the Minimum Remaining Value (MRV) heuristic.
     *
     * The MRV heuristic selects the empty cell with the fewest valid number options left,
     * which helps in optimizing the backtracking process by reducing the branching factor.
     *
     * TODO:
     * - Complete the nested for-loop to:
     *   1. Iterate over the Sudoku board.
     *   2. For each empty cell (value == 0), count the number of valid options (1-9) using `isValid()`.
     *   3. Track the cell with the fewest valid options.
     *   4. Return the position (row, col) and number of options for that cell.
     *
     * Early Exit:
     * - If a cell with only one valid option is found, return it immediately for efficiency.
     *
     * @param BOARD A 9x9 Sudoku board.
     * @return std::tuple<int, int, int> A tuple containing:
     *         - Row index of the selected cell.
     *         - Column index of the selected cell.
     *         - Number of valid options for that cell.
     *
     * @usage Example should be something like following:
     * @code
     *     int** BOARD = ...;  // Initialize a 9x9 Sudoku board
     *
     *     // Call the function and unpack the tuple
     *     auto [row, col, options] = findNextCell(BOARD);
     *
     *     if (row != -1) {
     *         std::cout << "Next cell to fill: (" << row << ", " << col << ") "
     *                   << "with " << options << " possible options." << std::endl;
     *     } else {
     *         std::cout << "No empty cells found. The board is complete!" << std::endl;
     *     }
     * @endcode
     */
    int minOptions = INT_MAX;
    int bestRow = -1, bestCol = -1;

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            // TODO: DDDDOOOOOONNNNEEEEE?
            /**
             * - Check if BOARD[r][c] is empty (value == 0).
             * - If empty, iterate over numbers 1 to 9.
             * - Use isValid(BOARD, r, c, k) to count valid options.
             * - Track the cell with the minimum number of options.
             * - Implement early exit if a cell with only one option is found.
             */
            if (BOARD[r][c] == 0) {
                int validOptions = 0;
                for (int numCheck = 1; numCheck < 10; numCheck++) {
                    if (isValid(BOARD, r, c, numCheck)) {
                        validOptions += 1;
                    }
                }

                if (validOptions == 1) {
                    return {r, c, validOptions};
                }

                if (validOptions <= minOptions) {
                    bestRow = r;
                    bestCol = c;
                    minOptions = validOptions;
                }
            }
        }
    }
    return {bestRow, bestCol, minOptions};
}


bool solveBoardEfficient(int** BOARD)
{
    /**
     * @brief Efficiently solves the Sudoku board using backtracking and the MRV heuristic.
     *
     * This function uses a recursive backtracking approach combined with the Minimum Remaining Value (MRV)
     * heuristic to optimize the solving process by always selecting the cell with the fewest valid options.
     *
     * TODO: DOOOOOOONNNNNNNEEEEEEE
     * - Implement the backtracking logic using the following steps:
     *   1. Use `findNextCell(BOARD)` to select the next cell with the fewest valid options.
     *   2. If no empty cells are left, the board is solved.
     *   3. Try placing numbers 1 to 9 in the selected cell using `isValid()`.
     *   4. Recursively call `solveBoardEfficient()` after placing a valid number.
     *   5. If the recursive call fails, backtrack by resetting the cell to 0.
     *   6. If no valid number fits, return false to trigger further backtracking.
     *
     * @param BOARD A 9x9 Sudoku board to be solved.
     * @return true if the board is successfully solved, false otherwise.
     */
    auto [r, c, k] = findNextCell(BOARD);
    if (r == -1 || c == -1) {
        return true;
    }
    for (int i = 1; i < 10; i++) {
        if (isValid(BOARD, r, c, i)) {
            BOARD[r][c] = i;
            if (solveBoardEfficient(BOARD)) {
                return true;
            }
            BOARD[r][c] = 0;
        }
    }
    return false;
}


bool solve(int** board, const bool& efficient) {
    if (efficient) {
        return solveBoardEfficient(board);
    }
        return solveBoard(board, 0, 0);
}