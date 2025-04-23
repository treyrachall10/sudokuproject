# Sudoku Project

This project implements a Sudoku puzzle solver and generator using C++. The solver includes both basic and optimized backtracking algorithms for solving Sudoku puzzles efficiently. Additionally, the program generates solvable Sudoku puzzles with varying degrees of complexity.

## Key Features
**Sudoku Puzzle Generation**:
- Generates Sudoku boards with customizable difficulty (number of empty boxes).
- Ensures puzzles are solvable by initially solving a fully generated board.

**Puzzle Solving**
- Includes two solving strategies:
    - Basic backtracking (`solveBoard`)
    - Optimized backtracking (`solveBoardEfficient`)

**Solution Checker**
- Verifies if solved puzzles are correct 
- Solves puzzles and saves the solutions

**Solver Comparison**

- Compares the efficiency of both solving algorithms

**DEBUG Mode**
- Includes a debug mode for testing individual components



## File Structure 
- `main.cpp`: Starts and manages the puzzle generation, solving, and comparisons.
- `sudoku.cpp`: Contains the puzzle-solving logic.
- `generator.cpp`: Creates solvable Sudoku puzzles.
- `sudoku_io.cpp`: Handles reading puzzles from files and saving solutions.
- `utils.cpp`: Memory management and directory setup.
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

## Output
The program will:

- Generate puzzles and save them to `data/puzzles/`.
- Solve puzzles and save solutions to `data/solutions/`.
- Show comparisons between the two solver methods.`

## Authors
- [Trey Rachall](https://github.com/treyrachall10)
- [Seth Hirani](https://github.com/sethhirani)
- [Adan Torres](https://github.com/adanTorres)
