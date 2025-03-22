//
// Created by Keshav Bhandari on 2/8/24.
//
#include <iostream>
#include <string>
#include <filesystem>
using namespace std;

void deallocateBoard(int** BOARD, const int& rows) {
    // TODO: Implement memory deallocation for the 2D board

    /**
     * - Check if BOARD is nullptr.
     * - Iterate through each row and deallocate using delete[].
     * - Deallocate the array of row pointers using delete[].
     * - Set BOARD to nullptr to avoid dangling pointers.
     */
    if (BOARD != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] BOARD[i];
        }
        delete[] BOARD;
        BOARD = nullptr;
    }
}

void createFolder(const std::string& folderPath) {
    if (!filesystem::exists(folderPath)) {
        if (filesystem::create_directory(folderPath)) {
            std::cout << "Folder created successfully: " << folderPath << std::endl;
        } else {
            std::cerr << "Failed to create folder: " << folderPath << std::endl;
        }
    } else {
        std::cout << "Folder already exists: " << folderPath << std::endl;
    }
}

void initDataFolder(){
    createFolder("data/");
    createFolder("data/puzzles/");
    createFolder("data/solutions/");
}

string getFileName(const int& index, const string& destination, const string& prefix){
    string index_str = to_string(index);
    string index_fill = string(4 - index_str.length(), '0');
    string filename = destination + index_fill + index_str + prefix + ".txt";
    return filename;
}