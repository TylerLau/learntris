#include "matrix.h"

//
// Public member functions
//

Matrix::Matrix() {
    // USAGE: Constructor for the matrix class
    lines = 0;
    score = 0;
    active_piece = nullptr;
    initGrid();
}

void Matrix::printGrid() {
    // USAGE: Prints out contents of cells in the grid
    for (int i = 0; i < 22; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << grid[i][j].label << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::given() {
    // USAGE: Allows an input stream of 22 characters to set table
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 10; j++) {
            std::string temp;
            std::cin >> temp;
            if (temp != ".") {
                auto temp_ptr = std::make_shared<Tetramino>(temp);
                grid[i][j].assign(temp_ptr);
            }
        }
    }
}

void Matrix::clear() {
    // USAGE: Clears the board
    initGrid();
}

int Matrix::get_score() {
    // USAGE: Prints current user score with cout
    return score;
}

int Matrix::get_lines() {
    // USAGE: Prints current liens cleared by user with cout
    return lines;
}

void Matrix::step() {
    // USAGE: Checks for filled rows and updates grid accordingly    
    int pushes[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 21; i >= 0; --i) {
        // Check if row is completely filled
        bool filled = true;
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j].checkOccupied() == nullptr) filled = false;
        }

        if (filled) {
            // Clear the cells in the row
            for (int j = 0; j < 10; ++j) grid[i][j].remove();
            // Increment # of pushes for above rows
            for (int x = i-1; x >= 0; ++x) pushes[x]++;
            lines += 1;
            score += 100;
        }
    } 
    
    // Update the grid starting from the bottom
    for (int i = 21; i >= 0; --i) {
        if (pushes[i] > 0) {
            // Push everything in current row i to row i + pushes[i] 
            int new_row = i + pushes[i];
            for (int j = 0; j < 10; ++j) {
                auto temp = grid[i][j].checkOccupied();
                grid[new_row][j].assign(temp);
                grid[i][j].remove();
            }
        }
    }
}

//
// Private member functions
//

void Matrix::initGrid() {
    // USAGE: Creates a blank grid and sets it to the matrix object
    for (int i = 0; i < 22; ++i) {
        for (int j = 0; j < 10; ++j) {
            grid[i][j] = Cell();
        }
    }
}


