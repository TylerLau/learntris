#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <memory>
#include <iostream>
#include <cstring>
#include <cassert>
#include <string>
#include <cstring>
#include <algorithm>
#include <tuple>
#include "cell.h"
#include "tetramino.h"

class Matrix {
    // Public member functions
    public:
        Matrix();    
        
        // Display Functions
        void printGrid(bool mode);
        void printActive();

        // Grid Manipulating Functions
        void given();
        void clear();
        void step();

        // User Functions
        int get_score();
        int get_lines();
        
        // Piece Manipulating Functions
        auto setActive(char type) -> std::shared_ptr<Tetramino>; 
        void rotateCW();
        void rotateCCW();
        void moveLeft();
        void moveRight();
        void moveDown();
        void moveHardDown();

    // Private member functions
    private:
        void initGrid();
        void initPiece(char type);
        void updateBackup();
        bool checkSpaceEmpty(const std::vector<std::tuple<int,int>> & cell_list);
        bool checkTopEmpty();
        int move(const std::vector<std::tuple<int,int>> & cell_list);
        

    // Public member variables
    public:

    // Private member variables
    private:
        int lines;      // # of lines cleared
        int score;      // User score
        bool game_over; 
        // Pointer to the current active piece
        std::shared_ptr<Tetramino> active_piece;

        // 22x10 array of pointers to pieces
        Cell grid[22][10];
        Cell backup_grid[22][10];
};   

#endif  // __MATRIX_H__
