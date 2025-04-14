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
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()


using namespace std;

int** getEmptyBoard() {
    int** board = new int*[9];
    for(int i = 0; i < 9; i++){
        board[i] = new int[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
    }
    return board;
}

std::vector<int> getShuffledVector() {
    vector<int> numbers {1, 2, 3, 4, 5, 6, 7, 8, 9};

    random_device rd;
    mt19937 g(rd());
    shuffle(numbers.begin(), numbers.end(), g);

    return numbers;
}

void fillBoardWithIndependentBox(int** BOARD) {
    for (int start = 0; start < 9; start +=3){
        vector<int> shuffledVector = getShuffledVector();
        int pos = 0;

        for (int row = start; row < start + 3; row++) {
            for (int col = start; col < start + 3; col++, pos++) {
                BOARD[row][col] = shuffledVector[pos];
            }
        }
    }
}

void deleteRandomItems(int** BOARD, const int& n) {
    if (BOARD != nullptr && n > 0 && n < 82) {
        bitset<9> bitBoard[9];
        random_device rd;
        mt19937 g(rd());
        uniform_int_distribution<> dis(0, 8);
        for (int i = 0; i < n; i++) {
            int randRow = dis(g);
            int randCol = dis(g);
            if (!bitBoard[randRow].test(randCol)) {
                bitBoard[randRow].set(randCol);
                BOARD[randRow][randCol] = 0;
            } else i--;
        }
    }
}

int** generateBoard(const int& empty_boxes){

    int** BOARD = getEmptyBoard();
    fillBoardWithIndependentBox(BOARD);
    solve(BOARD);
    deleteRandomItems(BOARD, empty_boxes);

    return BOARD;
}