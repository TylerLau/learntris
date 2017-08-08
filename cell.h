#ifndef __CELL_H__
#define __CELL_H__

#include <memory>
#include <string>
#include "tetramino.h"

class Cell {
    // Public Member Functions
    public:
        // Constructor
        Cell();
        // Function to assign a tetrimino object to the cell
        auto assign(std::shared_ptr<Tetramino>& obj)->int;
        // Function to remove a tetrimino object from the cell
        auto remove()->int;
        // Function that returns tetrimino object occupying it (if any)
        auto checkOccupied()->std::shared_ptr<Tetramino>;
    
    // Private Member Functions
    private:

    // Public Member Variables
    public:
        // Letter/symbol denoting the type of piece occupying the cell
        std::string label;
        
    // Private Member Variables
    private:
        //shared_ptr to tetramino that occupies it
        std::shared_ptr<Tetramino> current_piece;
};

#endif //__CELL_H__
