#include "tetramino.h"
#include "cell.h"

Tetramino::Tetramino(std::string _name) {
    name = _name;
    active = false;
}

auto Tetramino::type() -> std::string {
    return name;
}

auto Tetramino::add(Cell * _cell) -> int {
    for (auto itr = cells.begin(); itr != cells.end(); ++itr) {
        if (*itr == _cell) return 1;
    }
    cells.push_back(_cell);
    return 0;
}

auto Tetramino::remove(Cell * _cell) -> int {
    for (auto itr = cells.begin(); itr != cells.end(); ++itr) {
       if (*itr == _cell) {
            cells.erase(itr);
            return 0;
       }
    }
    return 1; 
}

auto Tetramino::getCells() -> std::vector<Cell*> {
    return cells;
}

auto Tetramino::rotateCW() -> int {
    orientation++;
    if (orientation > 3) orientation = 0;
    return orientation;
}

auto Tetramino::rotateCCW() -> int {
    orientation--;
    if (orientation < 0) orientation = 3;
    return orientation;
}

auto Tetramino::checkLeft() -> std::vector<std::tuple<int,int>> {
    auto c0 = std::make_tuple(cells[0]->getX(), cells[0]->getY() - 1);
    auto c1 = std::make_tuple(cells[1]->getX(), cells[1]->getY() - 1);
    auto c2 = std::make_tuple(cells[2]->getX(), cells[2]->getY() - 1);
    auto c3 = std::make_tuple(cells[3]->getX(), cells[3]->getY() - 1);
    auto cell_list = {c0, c1, c2, c3};
    return cell_list;
}

auto Tetramino::checkRight() -> std::vector<std::tuple<int,int>> {
    auto c0 = std::make_tuple(cells[0]->getX(), cells[0]->getY() + 1);
    auto c1 = std::make_tuple(cells[1]->getX(), cells[1]->getY() + 1);
    auto c2 = std::make_tuple(cells[2]->getX(), cells[2]->getY() + 1);
    auto c3 = std::make_tuple(cells[3]->getX(), cells[3]->getY() + 1);
    auto cell_list = {c0, c1, c2, c3};
    return cell_list;
}

auto Tetramino::checkDown() -> std::vector<std::tuple<int,int>> {
    auto c0 = std::make_tuple(cells[0]->getX() + 1, cells[0]->getY());
    auto c1 = std::make_tuple(cells[1]->getX() + 1, cells[1]->getY());
    auto c2 = std::make_tuple(cells[2]->getX() + 1, cells[2]->getY());
    auto c3 = std::make_tuple(cells[3]->getX() + 1, cells[3]->getY());
    auto cell_list = {c0, c1, c2, c3};
    return cell_list;
}

//------------------------------------------------------------------
//----------------------------- I TYPE -----------------------------
//------------------------------------------------------------------

I_Type::I_Type(): Tetramino("c") {
    orientation = 0;
    active = true;
}

auto I_Type::print() -> int {
    switch(orientation) {
        case 0:
            std::cout << ". . . .\nc c c c\n. . . .\n. . . .\n";
            break;
        case 1:
            std::cout << ". . c .\n. . c .\n. . c .\n. . c .\n";
            break;
        case 2:
            std::cout << ". . . .\n. . . .\nc c c c\n. . . .\n";
            break;
        case 3:
            std::cout << ". c . .\n. c . .\n. c . .\n. c . .\n";
            break;
        default:
            return 1;
            break;
    }
    return 0;
}



//------------------------------------------------------------------
//----------------------------- O TYPE -----------------------------
//------------------------------------------------------------------

O_Type::O_Type(): Tetramino("y") {
    orientation = 0;
    active = true;
}

auto O_Type::print() -> int {
    std::cout << "y y\ny y\n";
    return 0;
}

//------------------------------------------------------------------
//----------------------------- Z TYPE -----------------------------
//------------------------------------------------------------------

Z_Type::Z_Type(): Tetramino("r") {
    orientation = 0;
    active = true;
}

auto Z_Type::print() -> int {
    switch(orientation) {
        case 0:
            std::cout << "r r .\n. r r\n. . .\n";
            break;
        case 1:
            std::cout << ". . r\n. r r\n. r .\n";
            break;
        case 2:
            std::cout << ". . .\nr r .\n. r r\n";
            break;
        case 3:
            std::cout << ". r .\nr r .\nr . .\n";
            break;
        default:
            return 1;
            break;
    }
    return 0;
}

//------------------------------------------------------------------
//----------------------------- S TYPE -----------------------------
//------------------------------------------------------------------

S_Type::S_Type(): Tetramino("g") {
    orientation = 0;
    active = true;
}

auto S_Type::print() -> int {
    switch(orientation) {
        case 0:
            std::cout << ". g g\ng g .\n. . .\n";
            break;
        case 1:
            std::cout << ". g .\n. g g\n. . g\n";
            break;
        case 2:
            std::cout << ". . .\n. g g\ng g .\n";
            break;
        case 3:
            std::cout << "g . .\ng g .\n. g .\n";
            break;
        default:
            return 1;
            break;
    }
    return 0;
}

//------------------------------------------------------------------
//----------------------------- J TYPE -----------------------------
//------------------------------------------------------------------

J_Type::J_Type(): Tetramino("b") {
    orientation = 0;
    active = true;
}

auto J_Type::print() -> int {
    switch(orientation) {
        case 0:
            std::cout << "b . .\nb b b\n. . .\n";
            break;
        case 1:
            std::cout << ". b b\n. b .\n. b .\n";
            break;
        case 2:
            std::cout << ". . .\nb b b\n. . b\n";
            break;
        case 3:
            std::cout << ". b .\n. b .\nb b .\n";
            break;
        default:
            return 1;
            break;
    }
    return 0;
}

//------------------------------------------------------------------
//----------------------------- L TYPE -----------------------------
//------------------------------------------------------------------

L_Type::L_Type(): Tetramino("o") {
    orientation = 0;
    active = true;
}

auto L_Type::print() -> int {
    switch(orientation) {
        case 0:
            std::cout << ". . o\no o o\n. . .\n";
            break;
        case 1:
            std::cout << ". o .\n. o .\n. o o\n";
            break;
        case 2:
            std::cout << ". . .\no o o\no . .\n";
            break;
        case 3:
            std::cout << "o o .\n. o .\n. o .\n";
            break;
        default:
            return 1;
            break;
    }
    return 0;
}

//------------------------------------------------------------------
//----------------------------- T TYPE -----------------------------
//------------------------------------------------------------------

T_Type::T_Type(): Tetramino("m") {
    orientation = 0;
    active = true;
}

auto T_Type::print() -> int {
    switch(orientation) {
        case 0:
            std::cout << ". m .\nm m m\n. . .\n";
            break;
        case 1:
            std::cout << ". m .\n. m m\n. m .\n";
            break;
        case 2:
            std::cout << ". . .\nm m m\n. m .\n";
            break;
        case 3:
            std::cout << ". m .\nm m .\n. m .\n";
            break;
        default:
            return 1;
            break;
    }
    return 0;
}
