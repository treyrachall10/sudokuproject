//
// Created by Keshav Bhandari on 2/19/25.
//

/**
 * @file generator.cpp
 * @brief Implementation of functions to generate random solvable Sudoku boards.
 *
 * This file should contain logic to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * - Solve the filled board to complete it.
 * - Randomly remove cells to create solvable Sudoku puzzles.
 *
 * - Replace the dummy code section with appropriate logic
 *
 * You should provide detailed function descriptions in the corresponding header file.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */


#include "../include/generator.h"
#include "../include/sudoku.h"
#include "../include/sudoku_io.h"
#include <random>
#include <bitset>

using namespace std;

int** getEmptyBoard() {
    int** board = new int*[9];
    for(int i = 0; i < 9; i++){
        board[i] = new int[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
    }//Initialization ends here
    return board;
}

// Hint 1:  Implement a function to return shuffled vectors
// Function to return a randomly shuffled vector from 1 to 9
std::vector<int> getShuffledVector() {
    // TODO: Implement shuffling logic here
    /**
     * TODO:
     * - Create a vector with numbers 1 to 9.
     * - Apply a shuffling algorithm to randomize the order.
     * - Return the shuffled vector.
     *
     * Example Output: {3, 1, 4, 2, 7, 6, 5, 9, 8}
     *
     * @return std::vector<int> Shuffled numbers from 1 to 9.
     */
    // Dummy implementation:
    // Temporary static return for testing
    vector<int> numbers {1, 4, 6, 2, 8, 5, 3, 9, 4, 7}; // vector of numbers 1-9

    random_device rd; // generates random seed
    mt19937 g(rd()); // uses random seed to generate random sequence
    shuffle(numbers.begin(), numbers.end(), g); // uses random sequence to shuffle start to end of vector

    return numbers; // returns shuffled vector


   // return {3, 1, 4, 2, 7, 6, 5, 9, 8};
}


// Hint 2:  Random Independent Box fill:
            /*
            Strategy:
            Create a function that takes a BOARD as input, iterates over independent boxes, and fills them with
            numbers 1 to 9 using a randomly shuffled vector generated by a helper function.

                Below are two side-by-side dummy 9x9 Sudoku boards illustrating the 3 independent diagonal box sets.
                The boxes in the diagonal paths are filled with 'X', and the remaining cells are filled with '.'.

                Example Boards:

                Board 1 (Top-Left to Bottom-Right)        Board 2 (Top-Right to Bottom-Left)

                +-------+-------+-------+          +-------+-------+-------+
                | X X X | . . . | . . . |          | . . . | . . . | X X X |
                | X X X | . . . | . . . |          | . . . | . . . | X X X |
                | X X X | . . . | . . . |          | . . . | . . . | X X X |
                +-------+-------+-------+          +-------+-------+-------+
                | . . . | X X X | . . . |          | . . . | X X X | . . . |
                | . . . | X X X | . . . |          | . . . | X X X | . . . |
                | . . . | X X X | . . . |          | . . . | X X X | . . . |
                +-------+-------+-------+          +-------+-------+-------+
                | . . . | . . . | X X X |          | X X X | . . . | . . . |
                | . . . | . . . | X X X |          | X X X | . . . | . . . |
                | . . . | . . . | X X X |          | X X X | . . . | . . . |
                +-------+-------+-------+          +-------+-------+-------+

                Explanation:
                - Board 1 highlights the 3x3 independent boxes along the main diagonal (Top-Left to Bottom-Right).
                - Board 2 highlights the 3x3 independent boxes along the anti-diagonal (Top-Right to Bottom-Left).

                Each 'X' marks a cell that belongs to the respective diagonal box sets. This visualization helps
                in understanding the independent nature of diagonal boxes in Sudoku variants that require unique
                digits along both diagonals.

				Sample Fill:
                Board 1 (Top-Left to Bottom-Right)

                +-------+-------+-------+
                | 1 5 6 | . . . | . . . |
                | 2 4 7 | . . . | . . . |
                | 8 3 9 | . . . | . . . |
                +-------+-------+-------+
                | . . . | 1 7 4 | . . . |
                | . . . | 6 2 8 | . . . |
                | . . . | 5 9 3 | . . . |
                +-------+-------+-------+
                | . . . | . . . | 1 6 7 |
                | . . . | . . . | 2 5 8 |
                | . . . | . . . | 3 4 9 |
                +-------+-------+-------+
            */

void fillBoardWithIndependentBox(int** BOARD) {
    // TODO: Implement logic to fill diagonal 3x3 boxes
    /**
     * TODO:
     * - Iterate over the three diagonal 3x3 boxes.
     * - Fill each box with unique numbers from 1 to 9.
     * - Use a shuffled vector for randomization.
     *
     * Example Pattern:
     * - Top-Left, Center, and Bottom-Right boxes should be filled.
     * - Remaining cells should remain empty.
     */


    for (int start = 0; start < 9; start +=3){
        vector<int> shuffledNum = getShuffledVector();
        int pos = 0;

        for (int row = start; row < start + 3; row++) {
            for (int col = start; col < start + 3; col++, pos++) {
                BOARD[row][col] = shuffledNum[pos];
            }
        }
    }

    // Dummy implementation:
    // Temporary static fill based on the provided example
    int staticBoard[9][9] = {
        {1, 5, 6, 0, 0, 0, 0, 0, 0},
        {2, 4, 7, 0, 0, 0, 0, 0, 0},
        {8, 3, 9, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 7, 4, 0, 0, 0},
        {0, 0, 0, 6, 2, 8, 0, 0, 0},
        {0, 0, 0, 5, 9, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 6, 7},
        {0, 0, 0, 0, 0, 0, 2, 5, 8},
        {0, 0, 0, 0, 0, 0, 3, 4, 9}
    };
    // Dummy implementation:
    // Copy static board to the provided BOARD
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            BOARD[i][j] = staticBoard[i][j];
        }
    }
}

// Hint 3:  SolveBoard by using function provided in sudoku.h
            /* Example Solve Board
            +-------+-------+-------+
            | 1 5 6 | 2 3 7 | 8 9 4 |
            | 2 4 7 | 8 1 9 | 5 3 6 |
            | 8 3 9 | 4 5 6 | 7 1 2 |
            +-------+-------+-------+
            | 3 6 2 | 1 7 4 | 9 8 5 |
            | 5 9 1 | 6 2 8 | 4 7 3 |
            | 7 8 4 | 5 9 3 | 6 2 1 |
            +-------+-------+-------+
            | 9 2 8 | 3 4 5 | 1 6 7 |
            | 4 7 3 | 9 6 1 | 2 5 8 |
            | 6 1 5 | 7 8 2 | 3 4 9 |
            +-------+-------+-------+
             */

// Hint 4:  Create a function that takes board and randomly delete (replacing digits through 1-9 with 0) 50% of cell
            /*
             To create a Sudoku puzzle from a solved board, write a function that randomly selects and clears cells
             (setting them to **0**) while ensuring the puzzle remains solvable. Although the minimum number of
             prefilled cells for a unique solution is **17**, more empty cells increase complexity. For a balanced
             challenge, consider deleting around **50%** of the cells (about **40-45**), creating a puzzle that's
             both engaging and solvable.

			Example:
                +-------+-------+-------+
                | 1 5 6 | . 3 7 | . 9 . |
                | 2 . . | 8 1 9 | . 3 6 |
                | . 3 . | . . 6 | . . . |
                +-------+-------+-------+
                | 3 . . | 1 7 . | . 8 5 |
                | . 9 . | 6 2 . | . . 3 |
                | . 8 4 | 5 . 3 | 6 2 . |
                +-------+-------+-------+
                | 9 2 . | . . 5 | 1 6 7 |
                | 4 . . | 9 . 1 | 2 . . |
                | 6 . . | . . . | . . 9 |
                +-------+-------+-------+

             */

// Function to randomly delete 'n' items from a 9x9 Sudoku board using bitsets
void deleteRandomItems(int** BOARD, const int& n) {
    // TODO: Implement logic to delete 'n' random cells from the board
    /**
     * TODO:
     * - Validate inputs (e.g., non-null board, valid 'n' between 1 and 81).
     * - Randomly select 'n' unique cells from the board.
     * - Replace selected cells with 0.
     * - Ensure cells aren't deleted more than once.
     *
     * Example Behavior:
     * - For n = 5, randomly select 5 filled cells and set them to 0.
     * - Ensure the board remains solvable after deletion (optional enhancement).
     *
     * @param BOARD A 9x9 Sudoku board.
     * @param n The number of cells to delete (should be between 1 and 81).
     */

    // Dummy implementation: Set the first 3 rows to 0
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 9; c++) {
            BOARD[r][c] = 0;
        }
    }
}


// Finally return the board
// Note you need add these function prototypes in generator.h files as well

int** generateBoard(const int& empty_boxes){
    /**
     * @brief Generates a solvable Sudoku board with a specified number of empty cells.
     *
     * TODO:
     * - Implement helper functions in the correct order to:
     *   1. Initialize an empty board.
     *   2. Fill the diagonal 3x3 boxes.
     *   3. Solve the board to complete it.
     *   4. Randomly delete cells to create a playable puzzle.
     *
     * Hints:
     * - Use `getEmptyBoard()`, `fillBoardWithIndependentBox()`, `solve()`, and `deleteRandomItems()`.
     * - Ensure the board remains solvable after deleting cells.
     *
     * @param empty_boxes The number of cells to be emptied in the generated puzzle.
     * @return int** A dynamically allocated 9x9 Sudoku board with 'empty_boxes' empty cells.
     */

    int** BOARD = getEmptyBoard();
    fillBoardWithIndependentBox(BOARD);
    solve(BOARD);
    deleteRandomItems(BOARD, empty_boxes);

    return BOARD;
}