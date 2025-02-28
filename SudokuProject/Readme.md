<!-- Red Background Warning -->
<div style="background-color:#ffcccc; padding:15px; border-radius:5px; font-weight:bold;">

⚠️ **IMPORTANT NOTICE**

**Use of Generative AI Tools (e.g., ChatGPT):**  
- You may use AI tools for **learning purposes only**.  
- **Do NOT** seek full solutions or copy-paste answers without understanding them.  
- If I suspect improper use, a **one-on-one session** will be scheduled, and if discrepancies are found, your project will be **disqualified**.

**Repository Contribution Rules:**  
- **DO NOT** push personal solutions or make changes to this repository.  
- This repo is strictly for **class collaborations only**.  
- Violating these rules may result in **academic penalties**.

💡 **"The real danger is not that computers will begin to think like humans, but that humans will begin to think like computers."**  
— **Sydney J. Harris**

</div>

# Sudoku Solver Project

## Overview

This project is a Sudoku solver where you will complete specific parts of the code marked with `TODO` comments. The goal is to implement functionalities to generate, solve, and handle Sudoku puzzles.

A `DEBUG` mode is available for verifying your implementation. When running in non-`DEBUG` mode, the program will output files in the `data` folder, typically found inside the `cmake-build-debug` directory.

> **Important:** This project is **strongly recommended** to be run using **CLion**. If you wish to use **VSCode**, utilize the provided `buildrun.sh` script. Feel free to reach out if you encounter any issues.

## Project Structure

```
├── CMakeLists.txt
├── main.cpp
├── include/
│   ├── generator.h
│   ├── sudoku.h
│   ├── sudoku_io.h
│   └── utils.h
├── src/
│   ├── generator.cpp
│   ├── sudoku.cpp
│   ├── sudoku_io.cpp
│   └── utils.cpp
├── cmake-build-debug/
│   └── data/ (Only if you run the program in non-debug mode)
│       ├── puzzles/
│       └── solutions/
└── buildrun.sh (for VSCode users)
```

## Files to Work On

You will find `TODO` comments in the following files:

1. **`generator.cpp` / `generator.h`**

   - **Header File (`generator.h`)**
       - [ ] Provide function prototypes for all functions in `generator.cpp`.
       - [ ] Add appropriate docstrings for each function prototype based on examples in the code.

   - **CPP File (`generator.cpp`)**

     - **`getShuffledVector()`**
         - [ ] Implement logic to create a vector with numbers `1-9`.
         - [ ] Shuffle the vector using `std::shuffle` and return it.

     - **`fillBoardWithIndependentBox(int** BOARD)`**
         - [ ] Fill the three diagonal 3x3 boxes (`(0,0)`, `(3,3)`, `(6,6)`) with unique shuffled numbers.
         - [ ] Use `getShuffledVector()` to randomize the numbers in each box.

     - **`deleteRandomItems(int** BOARD, const int& n)`**
         - [ ] Randomly select and clear `n` unique cells (set them to `0`).
         - [ ] Ensure no cell is cleared more than once and validate that `n` is between `1-81`.

     - **`generateBoard(const int& empty_boxes)`**
         - [ ] Initialize an empty board using `getEmptyBoard()`.
         - [ ] Fill diagonal boxes using `fillBoardWithIndependentBox()`.
         - [ ] Solve the filled board using a solving function from `sudoku.h`.
         - [ ] Delete `empty_boxes` cells using `deleteRandomItems()`.
         - [ ] Return the final Sudoku board.

2. **`utils.cpp` / `utils.h`**
   - **Header File (`utils.h`)**
     - [ ] Provide function prototypes for all functions in `utility.cpp`.
     - [ ] Add appropriate docstrings for each function prototype based on examples in the code.

   - **CPP File (`utils.cpp`)**

     - **`deallocateBoard(int** BOARD, const int& rows)`**
         - [ ] Implement memory deallocation for the 2D `BOARD`.
         - [ ] Check if `BOARD` is `nullptr` before deallocating.
         - [ ] Iterate through each row and deallocate using `delete[]`.
         - [ ] Deallocate the array of row pointers using `delete[]`.
         - [ ] Set `BOARD` to `nullptr` to avoid dangling pointers.

     - **`createFolder(const std::string& folderPath)`**
         - ✅ Already implemented — no changes needed.

     - **`initDataFolder()`**
         - ✅ Already implemented — no changes needed.
         - Creates the following folders if they don’t exist:
             - `data/`
             - `data/puzzles/`
             - `data/solutions/`

     - **`getFileName(const int& index, const string& destination, const string& prefix)`**
         - ✅ Already implemented — no changes needed.
         - Constructs a filename with leading zeros based on the `index` and appends `.txt`.
         - Example Output: `data/puzzles/0005_puzzle.txt`

3. **`sudoku.cpp` / `sudoku.h`**
   - **Header File (`sudoku.h`)**
     - [ ] Provide function prototypes for all functions in `sudoku.cpp`.
     - [ ] Add appropriate docstrings for each function prototype based on examples in the code.

   - **CPP File (`sudoku.cpp`)**

     - **`isValid(int** BOARD, const int& r, const int& c, const int& k)`**
         - ✅ Already implemented — no changes needed.
         - Validates if placing number `k` at cell `(r, c)` is valid.

     - **`solveBoard(int** BOARD, const int& r, const int& c)`**
         - ✅ Already implemented — no changes needed.
         - Solves the Sudoku board using a simple backtracking algorithm.

     - **`findNextCell(int** BOARD)`**
         - [ ] Implement logic to find the next empty cell using the Minimum Remaining Value (MRV) heuristic.
         - [ ] Iterate over the board and count valid options for each empty cell using `isValid()`.
         - [ ] Return the cell with the fewest valid options (`row`, `col`, `options`).
         - [ ] Implement early exit if a cell with only one valid option is found.

     - **`solveBoardEfficient(int** BOARD)`**
         - [ ] Implement efficient Sudoku solving using backtracking combined with the MRV heuristic.
         - [ ] Use `findNextCell()` to select the next cell with the fewest valid options.
         - [ ] Apply recursive backtracking to solve the board.
         - [ ] Implement proper backtracking by resetting cells to `0` when needed.

     - **`solve(int** board, const bool& efficient)`**
         - [ ] Implement logic to choose between the basic and efficient solver.
         - [ ] Call `solveBoardEfficient()` if `efficient == true`.
         - [ ] Otherwise, use the basic `solveBoard()` function.

4. **`sudoku_io.cpp` / `sudoku_io.h`**
   - **Header File (`sudoku_io.h`)**
     - [ ] Provide function prototypes for all functions in `sudoku_io.cpp`.
     - [ ] Add appropriate docstrings for each function prototype based on examples in the code.

   - **CPP File (`sudoku_io.cpp`)**

     - **`printBoard(int** BOARD, const int& r, const int& c, int k)`**
        - ✅ Already implemented — no changes needed.
        - Prints the Sudoku board with color coding for user interaction.

     - **`boardToString(int** BOARD, string &content)`**
        - ✅ Already implemented — no changes needed.
        - Converts the Sudoku board into a string format for file output.

     - **`writeSudokuToFile(int** BOARD, const string& filename)`**
        - ✅ Already implemented — no changes needed.
        - Writes the Sudoku board to a file in string format.

     - **`replaceCharacter(std::string& str, char oldChar, char newChar)`**
        - ✅ Already implemented — no changes needed.
        - Replaces all occurrences of `oldChar` with `newChar` in the given string.

     - **`extractNumbers(const string& input, vector<int>& numbers)`**
        - ✅ Already implemented — no changes needed.
        - Extracts all numerical values from a string using regular expressions.

     - **`fillBoard(const vector<int>& numbers, int **BOARD)`**
        - ✅ Already implemented — no changes needed.
        - Fills the Sudoku board using a vector of numbers.

     - **`readSudokuFromFile(const string& filename)`**
        - ✅ Already implemented — no changes needed.
        - Reads a Sudoku puzzle from a file and returns it as a 2D board.

     - **`checkIfSolutionIsValid(int** BOARD)`**
        - ✅ Already implemented — no changes needed.
        - Checks if a given Sudoku board is valid according to Sudoku rules.

     - **`getAllSudokuInFolder(const string& folderPath)`**
        - ✅ Already implemented — no changes needed.
        - Retrieves all Sudoku puzzle file paths from the specified folder.

     - **`createAndSaveNPuzzles(const int& num_puzzles, const int& complexity_empty_boxes, const string& destination, const string& prefix)`**
        - [ ] Implement memory deallocation using `deallocateBoard()` after each board is processed.
        - [ ] Ensure no memory leaks by freeing dynamically allocated boards after writing to files.

     - **`displayProgressBar(int current, int total, int barWidth = 50)`**
        - ✅ Already implemented — no changes needed.
        - Displays a console-based progress bar.

     - **`solveAndSaveNPuzzles(const int &num_puzzles, const string& source, const string& destination, const string& prefix)`**
        - [ ] Implement memory deallocation using `deallocateBoard()` after each puzzle is solved and written to file.
        - [ ] Ensure solved boards are properly validated and written to disk.

     - **`deepCopyBoard(int** original)`**
        - ✅ Already implemented — no changes needed.
        - Performs a deep copy of a given 9x9 Sudoku board.

     - **`compareSudokuSolvers(const int& experiment_size, const int& empty_boxes)`**
        - [ ] Implement memory deallocation using `deallocateBoard()` for both `board1` and `board2` after each experiment.
        - [ ] Ensure accurate performance comparison between basic and efficient solvers.
        - [ ] Display performance results, including average time and valid solution counts.

## Assignment Submission

The submission is divided into **three parts**:

### Part 1: Complete the Code

- Finish all sections marked with `TODO`.
- Implement the puzzle generator, solvers, and utility functions.
- Ensure your code runs correctly in both DEBUG and non-DEBUG modes.

### Part 2: Visualize Program Flow

- Use the following sample code to understand how to visualize program flow:

```cpp
#include <iostream>

void greet() {
    std::cout << "Hello from greet()\n";
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void compute() {
    std::cout << "Inside compute()\n";
    greet();
    int num = 5;
    int fact = factorial(num);
    std::cout << "Factorial of " << num << " is " << fact << "\n";
}

int main() {
    std::cout << "Starting main()\n";
    compute();
    std::cout << "Ending main()\n";
    return 0;
}
```

- Sample flow:

```text
main()
│
├── compute()
│   │
│   ├── greet()
│   │   └── [Prints "Hello from greet()"]
│   │
│   └── factorial(5)
│       └── [Recursively calls factorial(n-1) until n == 1]
│       └── [Returns result to compute()]
│
└── [Prints "Ending main()"]
```

- Create a similar flowchart to illustrate the execution flow of your Sudoku solver in non-DEBUG mode.

### Part 3: Reflective Questions

Answer the following questions in your report:

1. Group Photo
2. What contributions did your friends make? List them.
3. Why do you think `efficientSolver` took more time than the regular solver? What strategies would you implement to make `efficientSolver` actually efficient?
4. Can you make this a generalized solution, meaning board that can solve any NxN grid where N is a square number? Can you briefly share your ideas?
5. Did this project challenge and motivate you? We would appreciate your feedback on your experience. Feel free to share what you learned, what aspects of the project you found most engaging or challenging, and any suggestions you have for improving future projects. Your insights are valuable in helping us enhance future learning experiences.

## Submission Guidelines

- **Report (Submit as a PDF file):**

    - **Overview:** Provide a broader overview and your take on the project. Include the link to your GitHub repository.
    - **Part 2:** Visualize the flow of the program using a flowchart.
    - **Part 3:** Answer the reflective questions.
    - **Final Thoughts:** Share your concluding thoughts about the project experience.

- **GitHub Repository:**

  1. **Create a Private Repository:**
      - On GitHub, create an **empty private repository** named:  
        **`GroupNameSudokuProjectCS2308SPRING2025`** (replace *GroupName* with your group's name).

  2. **Clone and Add Project Files:**
      - Clone the empty repository:
        ```bash
        git clone https://github.com/YourUsername/GroupNameSudokuProjectCS2308SPRING2025.git
        ```
      - **Do NOT** copy the entire `SudokuProject` folder.
      - Instead, **open** the `SudokuProject` folder and **copy all contents** (files and subfolders) into the cloned repository.
      - **Include the `.gitignore`** file during the copy.

  3. **Add a `README.md`:**
      - Create a **`README.md`** file in the repository with an **overview of your project**, including objectives and key features.

  4. **Push the Changes to GitHub:**
     ```bash
     cd GroupNameSudokuProjectCS2308SPRING2025
     git add .
     git commit -m "Initial commit for Sudoku project"
     git push origin main
     ```

  5. **Add Collaborators:**
      - On GitHub, go to **Settings > Collaborators** and add:
          - **Instructor:** `keshavsbhandari`
          - **TA:** `tousifulhaque`
          - **All team members** as collaborators.

  6. **Submit the Repository Link:**
      - Include the **GitHub repository link** in your **PDF report** for submission.

  🔔 **Reminders:**
  - **Do NOT** copy the entire `SudokuProject` folder — only its **contents**.
  - Ensure the `.gitignore` and `README.md` are included.
  - Verify that all collaborators have access before submission.

## Rubric

The grading will be based on the following breakdown:

- **50% - Code Solution:**
    - Completeness and correctness of implemented features.
    - Code efficiency and optimization.
    - Proper handling of files in both DEBUG and non-DEBUG modes.

- **25% - Program Flow Visualization:**
    - Clarity and accuracy of the program flow diagram.
    - Representation of the main components and their interactions.

- **25% - Reflections:**
    - Depth and thoughtfulness in answering reflective questions.
    - Insightfulness in final thoughts and personal takeaways.

## Running the Project

### Using CLion (Recommended)

1. Open the project in **CLion**.
2. Set the configuration to `DEBUG` mode if you want to verify your implementation.
3. Run the project.
4. In **non-DEBUG** mode, output files will be saved in:
   ```
   cmake-build-debug/data/
   ```

### Using VSCode

1. Open the project in **VSCode**.
2. Use the provided `buildrun.sh` script to compile and run the project:
   ```bash
   ./buildrun.sh full/path/to/your/project/folder
   ```
   or,
   ```bash
   bash buildrun.sh full/path/to/your/project/folder
   ```
   or,
   ```bash
   sh buildrun.sh full/path/to/your/project/folder
   ```
3. If you face any issues, reach out for assistance.

## Debug Mode

- **DEBUG mode** includes a special `main` function for testing and verifying your code.
- This mode helps ensure your solutions work before running in production.

## Output

- In **non-DEBUG** mode, the program will read puzzles from `data/puzzles/` and write solutions to `data/solutions/`.

Happy coding and feel free to ask questions if anything is unclear!
