#include "include/generator.h"
#include "include/sudoku.h"
#include "include/sudoku_io.h"
#include "include/utils.h"
#include <iostream>

using namespace std;

// Define DEBUG_MODE to enable debug main, comment following to run the actual program
#define DEBUG_MODE

string PATH_TO_PUZZLES = "data/puzzles/";
string PATH_TO_SOLUTIONS = "data/solutions/";

string PUZZLE_PREFIX = "PUZZLE";
string SOLUTION_PREFIX = "SOLUTION";

int NUM_PUZZLE_TO_GENERATE = 10;

int COMPLEXITY_EMPTY_BOXES = 45;

#ifdef DEBUG_MODE
/**
 * @brief Debug main function for testing and experimenting.
 *
 * This function is designed to help developers quickly test and experiment
 * with different functions across the program without running the full production flow.
 *
 * Use this space to:
 * - Test specific functions (e.g., board generation, solving, printing).
 * - Experiment with new features or changes.
 * - Verify function integration from different headers.
 * - Run isolated tests to debug specific issues.
 */
int main() {
    // You can modify this main function to access all other function implemented
    //
    cout << "Running in DEBUG MODE...\n";

    int** BOARD = new int*[9];
    for(int i = 0; i < 9; i++){
        BOARD[i] = new int[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
    }//Initialization ends here

    for (int start = 0; start < 9; start +=3){
        for (int row = start; row < start + 3; row++) {
            for (int col = start; col < start + 3; col++) {
                BOARD[row][col] = rand() % 9 + 1;
            }
        }
    }


    // Clean up memory
    deallocateBoard(BOARD);

    return 0;
}
#else
/**
 * @brief Main function for production use.
 *
 * Generates, solves, and compares Sudoku puzzles.
 */
int main() {
    initDataFolder();
    createAndSaveNPuzzles(NUM_PUZZLE_TO_GENERATE, COMPLEXITY_EMPTY_BOXES, PATH_TO_PUZZLES, PUZZLE_PREFIX);
    solveAndSaveNPuzzles(NUM_PUZZLE_TO_GENERATE, PATH_TO_PUZZLES, PATH_TO_SOLUTIONS, SOLUTION_PREFIX);

    // Run experiments to compare solvers
    compareSudokuSolvers(10, 64);
    compareSudokuSolvers(100, 45);
    compareSudokuSolvers(1000, 32);
    compareSudokuSolvers(10000, 16);

    return 0;
}
#endif
