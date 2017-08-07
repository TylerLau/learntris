//#ifndef __MATRIX_H__
//#define __MATRIX_H__

#include <iostream>
#include <vector>
#include <memory>
#include "Tetramino.h"

class Matrix {
    // Public member functions
    public:
        Matrix();    
        
    // Private member functions
    private:


    // Public member variables
    public:

    // Private member variables
    private:
        int lines;      // # of lines cleared
        int score;      // User score
        // Pointer to the currently active piece
        // 22x10 Vector table of pointers to pieces
        std::unique_ptr<Tetramino> active_piece;
        // std::vector<std::vector<std::unique_ptr<Tetramino>>> grid
};   

//#endif
