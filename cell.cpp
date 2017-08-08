#include "cell.h"

Cell::Cell() {
    label = ".";
    current_piece = nullptr;
}

auto Cell::assign(std::shared_ptr<Tetramino>& obj) -> int {
    // Return: 0 if successful, 1 if nto successful
    if (current_piece != nullptr) return 1; // Error, cell is occupied
    else {
        label = obj->type();
        current_piece = obj;
        return 0;
    }
}

auto Cell::remove() -> int {
    // Return: 0 if successful, 1 if not successful
    if (current_piece != nullptr) {
        label = ".";
        current_piece = nullptr;
        return 0;
    }
    else return 1;  // Error, no piece assigned to cell
}

auto Cell::checkOccupied() -> std::shared_ptr<Tetramino> {
    // Return: attached piece or nullptr (if nothing attached)
    if (current_piece != nullptr) return current_piece; 
    else return nullptr;
}


