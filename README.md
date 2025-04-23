# Sudoku Project

## Objective
This project is a Sudoku solver that creates and solves sudoku boards.

## Key Features
- Generates Sudoku puzzles with configurable difficulty (via number of empty boxes)
- Solves puzzles and saves the solutions
- Compares different Sudoku solving algorithms
- Includes a debug mode for testing individual components

## Project Structure
```
main()
│
├── initDataFolder()
│   └──createFolder
│
├── createAndSaveNPuzzles()
│   ├── generateBoard()
│   │   ├── getEmptyBoard()
│   │   ├── fillBoardWithIndependentBox()
│   │   │   └── getShuffledVector()
│   │   ├── solve()
│   │   │   └── solveBoard() 
│   │   └── deleteRandomItems()
│   ├── writeSudokuToFile()
│   └── deallocateBoard()
│
├── solveAndSaveNPuzzles()
│   ├── getAllSudokuInFolder()
│   ├── readSudokuFromFile()
│   ├── solve()
│   │   ├── solveBoardEfficient() 
│   │   └── solveBoard() 
│   ├── checkIfSolutionIsValid()
│   └── writeSudokuToFile()
│
└── compareSudokuSolvers()
    ├── generateBoard()
    ├── deepCopyBoard()
    ├── solveBoardEfficient()
    ├── solveBoard()
    └── checkIfSolutionIsValid()
```

## How to Build
- Ensure you have a C++ compiler installed (e.g., g++, clang).
- You can compile the project with the following command:  
  ```
  g++ -std=c++11 -o sudoku main.cpp src/*.cpp
  ```
- Make sure to replace `src/*.cpp` with the correct paths to your `.cpp` files if necessary.

## How to Run
- To generate puzzles, solve them, and perform algorithm comparisons, run the compiled program:  
  ```
  ./sudoku
  ```

## Run in Debug Mode
- If you'd like to test specific functions without running the entire flow, uncomment the `#define DEBUG_MODE` line in `main.cpp` and recompile:
  ```cpp
  //#define DEBUG_MODE
  ```
  Then run:
  ```
  g++ -std=c++11 -o sudoku main.cpp src/*.cpp
  ./sudoku
  ```

## Configuration
Modify the following constants in `main.cpp` to adjust the number of puzzles and their complexity:
```cpp
int NUM_PUZZLE_TO_GENERATE = 10;       // Number of puzzles to generate
int COMPLEXITY_EMPTY_BOXES = 45;       // Difficulty (higher = more empty boxes)
```

## Dependencies
- This project uses only standard C++ libraries (no third-party dependencies).

## Example Output
- Generated puzzles are saved to: `data/puzzles/`
- Solved puzzles are saved to: `data/solutions/`
- Example files:
  - `data/puzzles/PUZZLE_001.txt`
  - `data/solutions/SOLUTION_001.txt`

## Authors
- [Trey Rachall](https://github.com/treyrachall10)
- [Seth Hirani](https://github.com/sethhirani)
- [Adan Torres](https://github.com/adanTorres)
