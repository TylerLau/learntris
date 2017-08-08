#include "matrix.h"

//
// Public member functions
//

Matrix::Matrix() {
    // USAGE: Constructor for the matrix class
    lines = 0;
    score = 0;
    active_piece = nullptr;
}

void Matrix::printGrid() {
    for (int i = 0; i < 22; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << grid[i][j].label << " ";
        }
        std::cout << std::endl;
    }
    //std::cout << grid[0][0].label << std::endl;
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


