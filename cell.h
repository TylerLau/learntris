#ifndef __CELL_H__
#define __CELL_H__

#include <memory>
#include <string>
#include <tuple>

// Forward Declaration of Tetrimino
class Tetramino; 
    /*public:
        auto type() -> std::string;
        auto add(auto _cell) -> int;
        auto remove(auto _cell) -> int;
        bool active;*/

class Cell {
    // Public Member Functions
    public:
        // Constructor
        Cell();
        void setCoordinates(int x, int y);
        // Function to assign a tetrimino object to the cell
        auto assign(std::shared_ptr<Tetramino>& obj)->int;
        // Function to remove a tetrimino object from the cell
        auto remove()->int;
        // Function that returns tetrimino object occupying it (if any)
        auto checkOccupied()->std::shared_ptr<Tetramino>;
        // Function that returns whether current tetrimino is active
        auto isActive()->bool;
        // Functions that return cell coordinates
        auto getX() const -> int;
        auto getY() const -> int;
        
    // Private Member Functions
    private:
        bool operator==(const Cell & b) const;
        
    // Public Member Variables
    public:
        // Letter/symbol denoting the type of piece occupying the cell
        std::string label;
        
    // Private Member Variables
    private:
        //shared_ptr to tetramino that occupies it
        std::shared_ptr<Tetramino> current_piece;
        std::tuple<int,int> coordinate;
};

#endif //__CELL_H__
