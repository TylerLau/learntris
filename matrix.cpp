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

void Matrix::printGrid(bool mode) {
    // USAGE: Prints out contents of cells in the grid
    if (mode) {
        for (int i = 0; i < 22; ++i) {
            for (int j = 0; j < 10; ++j) {
                auto temp = grid[i][j].label;
                if (grid[i][j].isActive()) temp[0] = std::toupper(temp[0]);
                std::cout << temp << " ";
            }   
            std::cout << std::endl;
         }
    }
    else {
        for (int i = 0; i < 22; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::cout << backup_grid[i][j].label << " ";
            }   
            std::cout << std::endl;
         }
    }
}

void Matrix::printActive() {
    // USAGE: Prints out the current active piece
    active_piece -> print();
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
    updateBackup();
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
    //int pushes[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 22; ++i) {
        // Check if row is completely filled
        bool filled = true;
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j].checkOccupied() == nullptr) filled = false;
        }

        if (filled) {
            // Clear the cells in the row
            for (int j = 0; j < 10; ++j) grid[i][j].remove();
            // Increment # of pushes for above rows
            //for (int x = i-1; x >= 0; ++x) pushes[x]++;
            lines += 1;
            score += 100;
        }
    } 

    updateBackup();

    /* 
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
    }*/
}

auto Matrix::setActive(char type) -> std::shared_ptr<Tetramino> {
    if (active_piece != nullptr) active_piece->active = false;
    switch(type) {
        case 'I':
            active_piece = std::make_shared<I_Type>();
            initPiece(type);
            return active_piece;
            break;
        case 'O':
            active_piece = std::make_shared<O_Type>();
            initPiece(type);
            return active_piece;
            break;
        case 'Z':
            active_piece = std::make_shared<Z_Type>();
            initPiece(type);
            return active_piece;
            break;
        case 'S':
            active_piece = std::make_shared<S_Type>();
            initPiece(type);
            return active_piece;
            break;
        case 'J':
            active_piece = std::make_shared<J_Type>();
            initPiece(type);
            return active_piece;
            break;
        case 'L':
            active_piece = std::make_shared<L_Type>();
            initPiece(type);
            return active_piece;
            break;
        case 'T':
            active_piece = std::make_shared<T_Type>();
            initPiece(type);
            return active_piece;
            break;
        default:
            return nullptr;
            break;
    }
}   

void Matrix::rotateCW() {
    //Check if movement is valid first
    //auto spaces = active_piece -> checkCW();
    //If any of the spaces don't return nullptr for cell->checkOccupied don't rotate
    
    active_piece -> rotateCW();
}

void Matrix::rotateCCW() {
    //Check if movement is valid first
    //auto spaces = active_piece -> checkCCW();
    //If any of the spaces don't return nullptr for cell->checkOccupied don't rotate
    
    active_piece -> rotateCCW();
}

void Matrix::moveLeft() {
    // USAGE: Check if current active piece can move to left and if it can, move there
    auto cell_list = active_piece -> checkLeft();
    if (checkSpaceEmpty(cell_list)) {
        move(cell_list);
    }
}

void Matrix::moveRight() {
    // USAGE: Check if current active piece can move to right and if it can, move there
    auto cell_list = active_piece -> checkRight();
    if (checkSpaceEmpty(cell_list)) {
        move(cell_list);
    }
}

void Matrix::moveDown() {
    // USAGE: Check if current active piece can move to right and if it can, move there
    auto cell_list = active_piece -> checkDown();
    if (checkSpaceEmpty(cell_list)) {
        move(cell_list);
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
            grid[i][j].setCoordinates(i,j);
        }
    }
    updateBackup();
}

void Matrix::initPiece(char type) {
    //USAGE: Places a newly made active piece on the grid
    switch(type) {
        case 'I':
            assert(grid[1][3].assign(active_piece) != 1);
            assert(grid[1][4].assign(active_piece) != 1);
            assert(grid[1][5].assign(active_piece) != 1);
            assert(grid[1][6].assign(active_piece) != 1);
            break;
        case 'O':
            assert(grid[0][4].assign(active_piece) != 1);
            assert(grid[0][5].assign(active_piece) != 1);
            assert(grid[1][4].assign(active_piece) != 1);
            assert(grid[1][5].assign(active_piece) != 1);
            break;
        case 'S':
            assert(grid[0][4].assign(active_piece) != 1);
            assert(grid[0][5].assign(active_piece) != 1);
            assert(grid[1][3].assign(active_piece) != 1);
            assert(grid[1][4].assign(active_piece) != 1);
            break; 
        case 'Z':
            assert(grid[0][3].assign(active_piece) != 1);
            assert(grid[0][4].assign(active_piece) != 1);
            assert(grid[1][4].assign(active_piece) != 1);
            assert(grid[1][5].assign(active_piece) != 1);
            break;
        case 'J':
            assert(grid[0][3].assign(active_piece) != 1);
            assert(grid[1][3].assign(active_piece) != 1);
            assert(grid[1][4].assign(active_piece) != 1);
            assert(grid[1][5].assign(active_piece) != 1);
            break;
        case 'L':
            assert(grid[0][5].assign(active_piece) != 1);
            assert(grid[1][3].assign(active_piece) != 1);
            assert(grid[1][4].assign(active_piece) != 1);
            assert(grid[1][5].assign(active_piece) != 1);
            break;
        case 'T':
            assert(grid[0][4].assign(active_piece) != 1);
            assert(grid[1][3].assign(active_piece) != 1);
            assert(grid[1][4].assign(active_piece) != 1);
            assert(grid[1][5].assign(active_piece) != 1);
            break;
        default:
            break;
    }
}

void Matrix::updateBackup() {
    // USAGE: Updates backup_grid after every init, step, and given function call
    for (int i = 0; i < 22; ++i) {
        for (int j = 0; j < 10; ++j) {
            backup_grid[i][j] = grid[i][j];
        }
    }
}

bool Matrix::checkSpaceEmpty(const std::vector<std::tuple<int,int>> & cell_list) {
    // USAGE: Helper function for checking if cells in a list are occupied
    for (auto itr = cell_list.begin(); itr != cell_list.end(); ++itr) {
        int x = std::get<0>(*itr);
        int y = std::get<1>(*itr);
        
        // Check for boundary collision
        if (x < 0 || x > 21 || y < 0 || y > 9) return false;

        // Check if there is a piece already there
        if (grid[x][y].checkOccupied() != nullptr && !grid[x][y].isActive()) 
            return false;
    }
    return true;
}

int Matrix::move(const std::vector<std::tuple<int,int>> & cell_list) {
    // USAGE: Accepts a tuple vector of new coordinates after a move   
    auto old_cells = active_piece -> getCells();
    for (auto itr = old_cells.begin(); itr != old_cells.end(); ++itr) {
        (*itr) -> remove();
    }
    for (auto itr = cell_list.begin(); itr != cell_list.end(); ++itr) {
        int x = std::get<0>(*itr);
        int y = std::get<1>(*itr);
        
        grid[x][y].assign(active_piece);
    }
    return 0;
}
