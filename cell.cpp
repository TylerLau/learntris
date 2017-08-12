#include "cell.h"
#include "tetramino.h"

Cell::Cell() {
    label = ".";
    current_piece = nullptr;
}

void Cell::setCoordinates(int x, int y) {
    coordinate = std::make_tuple(x,y);
}

auto Cell::assign(std::shared_ptr<Tetramino>& obj) -> int {
    // Return: 0 if successful, 1 if nto successful
    if (current_piece != nullptr) return 1; // Error, cell is occupied
    else {
        this->label = obj -> type();
        this->current_piece = obj;
        current_piece -> add(this);
        return 0;
    }
}

auto Cell::remove() -> int {
    // Return: 0 if successful, 1 if not successful
    if (current_piece != nullptr) {
        label = ".";
        current_piece -> remove(this);
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

auto Cell::isActive() -> bool {
    // Return: Whether or not tetrimino held by cell is marked as active
    bool temp = false;
    if (current_piece != nullptr) temp = (*current_piece).active;
    return temp;
}

auto Cell::getX() const -> int{
    // Return: X coordinate
    return std::get<0>(coordinate);
}

auto Cell::getY() const -> int{
    // Return: Y coordinate
    return std::get<1>(coordinate);
}

bool Cell::operator==(const Cell & b) const {
    // USAGE: == operator overload (NOT USED)
    if (this -> getX() == b.getX() && this -> getY() == b.getY()) return true;
    else return false;
}

