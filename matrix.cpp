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
    if (game_over) std::cout << "Game Over\n";
}

void Matrix::printActive() {
    // USAGE: Prints out the current active piece
    active_piece -> print();
}

void Matrix::given() {
    // USAGE: Allows an input stream of 22 characters to set table
    initGrid();
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
    int pushes[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
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
            for (int x = i-1; x >= 0; --x) pushes[x]++;
            lines += 1;
            score += 100;
        }
    }   
     
    // Update the grid starting from the bottom
    for (int i = 21; i >= 0; --i) {
        if (pushes[i] > 0) {
            // Push everything in current row i to row i + pushes[i] 
            int new_row = i + pushes[i];
            assert (new_row < 22);

            for (int j = 0; j < 10; ++j) {
                auto temp = grid[i][j].checkOccupied();
                if (temp != nullptr) {
                    grid[new_row][j].assign(temp);
                    grid[i][j].remove();
                }
            }
        }
    }

    updateBackup();
    if (!checkTopEmpty()) game_over = true;
}

auto Matrix::setActive(char type) -> std::shared_ptr<Tetramino> {
    if (game_over) return nullptr;
    if (active_piece != nullptr) {
        active_piece->active = false;
        active_piece = nullptr;
    }
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
    // USAGE: Checks if rotation is allowed and do it if it is 
    if (game_over || active_piece == nullptr) return;
    auto cell_list = active_piece -> checkCW();
    if (checkSpaceEmpty(cell_list)) {
        move(cell_list);
        active_piece -> rotateCW();
    }
}

void Matrix::rotateCCW() {
    // USAGE: Checks if rotation is allowed and does it if it is
    if (game_over || active_piece == nullptr) return;
    auto cell_list = active_piece -> checkCCW();
    if (checkSpaceEmpty(cell_list)) {
        move(cell_list);
        active_piece -> rotateCCW();
    }
}

void Matrix::moveLeft() {
    // USAGE: Check if current active piece can move to left and if it can, move there
    if (game_over || active_piece == nullptr) return;
    auto cell_list = active_piece -> checkLeft();
    if (checkSpaceEmpty(cell_list)) {
        move(cell_list);
    }
}

void Matrix::moveRight() {
    // USAGE: Check if current active piece can move to right and if it can, move there
    if (game_over || active_piece == nullptr) return;
    auto cell_list = active_piece -> checkRight();
    if (checkSpaceEmpty(cell_list)) {
        move(cell_list);
    }
}

void Matrix::moveDown() {
    // USAGE: Check if current active piece can move to right and if it can, move there
    if (game_over || active_piece == nullptr) return;
    auto cell_list = active_piece -> checkDown();
    if (checkSpaceEmpty(cell_list)) {
        move(cell_list);
    }
    else {
        active_piece -> active = false;
        active_piece = nullptr;
        step();
    }
}

void Matrix::moveHardDown() {
    // USAGE: Moves active piece down until it hits a boundary or another piece
    if (game_over || active_piece == nullptr) return;
    auto cell_list = active_piece -> checkDown();
    while (checkSpaceEmpty(cell_list)) {
        move(cell_list);
        cell_list = active_piece -> checkDown();
    }
    active_piece -> active = false;
    active_piece = nullptr;
    step();
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
    active_piece = nullptr;
    game_over = false;
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

bool Matrix::checkTopEmpty() {
    // USAGE: Helper function to check top rows before setting new active piece
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j].checkOccupied() != nullptr) return false;
        }
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
