#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <memory>
#include <iostream>
#include "cell.h"
#include "tetramino.h"

class Matrix {
    // Public member functions
    public:
        Matrix();    
        void printGrid();
    // Private member functions
    private:
        void initGrid();

    // Public member variables
    public:

    // Private member variables
    private:
        int lines;      // # of lines cleared
        int score;      // User score
        
        // Pointer to the current active piece
        std::shared_ptr<Tetramino> active_piece;

        // 22x10 array of pointers to pieces
        Cell grid[22][10];
};   

#endif  // __MATRIX_H__
