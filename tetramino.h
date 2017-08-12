#ifndef __TETRAMINO_H__
#define __TETRAMINO_H__

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>

class Tetramino {
    // Public member functions
    public:
        Tetramino(std::string _name);
        
        auto type()->std::string; // Function that returns type of piece
        virtual auto print() -> int {};    // Function to print piece in 4x4
        
        auto add(const std::tuple<int,int> _coord) -> int;
        auto remove(const std::tuple<int,int> _coord) -> int;
                
        // Function for checking valid piece movement
        //virtual auto checkLeft() -> std::vector<std::tuple<int,int>>; 
        //virtual auto checkRight() -> std::vector<std::tuple<int,int>>;
        //virtual auto checkDown() -> std::vector<std::tuple<int,int>>; 
        //virtual auto checkCW() -> std::vector<std::tuple<int,int>>; 
        //virtual auto checkCCW() -> std::vector<std::tuple<int,int>>; 

        auto rotateCW() -> int;
        auto rotateCCW() -> int;
    // Private member functions

    // Private member functions
    private:

    // Public member variables
    public:
        bool active;
    // Private member variables
    private:

    protected:
        std::string name;   // Stores letter representation of tetramino
        std::vector<std::tuple<int,int>> cell_list;
        int orientation;
};

// I TYPE PIECE MAP (orientation 0 to 3)
// . . . .   . . 0 .   . . . .   . 3 . .
// 0 1 2 3   . . 1 .   . . . .   . 2 . .
// . . . .   . . 2 .   3 2 1 0   . 1 . .
// . . . .   . . 3 .   . . . .   . 0 . .

class I_Type: public Tetramino {
    public:
        I_Type();
        
        auto print() -> int; 

        //auto checkLeft() -> std::vector<std::tuple<int,int>>; 
        //auto checkRight() -> std::vector<std::tuple<int,int>>;
        //auto checkDown() -> std::vector<std::tuple<int,int>>; 
        //auto checkCW() -> std::vector<std::tuple<int,int>>; 
        //auto checkCCW() -> std::vector<std::tuple<int,int>>;
    private:

    public:

    private:
};

// T TYPE PIECE MAP
// . 0 .   . 1 .   . . .   . 3 .
// 1 2 3   . 2 0   3 2 1   0 2 .
// . . .   . 3 .   . 0 .   . 1 .

class T_Type: public Tetramino {
    public:
        T_Type();
         
        auto print() -> int; 
/*
        auto checkLeft() -> std::vector<std::tuple<int,int>>;
        auto checkRight() -> std::vector<std::tuple<int,int>>;
        auto checkDown() -> std::vector<std::tuple<int,int>>; 
        auto checkCW() -> std::vector<std::tuple<int,int>>; 
        auto checkCCW() -> std::vector<std::tuple<int,int>>;
*/
    private:

    public:

    private:
};

// J TYPE PIECE MAP
// 0 . .   . 1 0   . . .   . 3 .
// 1 2 3   . 2 .   3 2 1   . 2 .
// . . .   . 3 .   . . 0   0 1 .

class J_Type: public Tetramino {
    public:
        J_Type();
        
        auto print() -> int; 
/*
        auto checkLeft() -> std::vector<std::tuple<int,int>>; 
        auto checkRight() -> std::vector<std::tuple<int,int>>;
        auto checkDown() -> std::vector<std::tuple<int,int>>; 
        auto checkCW() -> std::vector<std::tuple<int,int>>; 
        auto checkCCW() -> std::vector<std::tuple<int,int>>;
*/
    private:

    public:

    private:
};

// L TYPE PIECE MAP
// . . 0   . 1 .   . . .   0 3 .
// 1 2 3   . 2 .   3 2 1   . 2 .
// . . .   . 3 0   0 . .   . 1 .

class L_Type: public Tetramino {
    public:
        L_Type();
        
        auto print() -> int; 
/*
        auto checkLeft() -> std::vector<std::tuple<int,int>>; 
        auto checkRight() -> std::vector<std::tuple<int,int>>;
        auto checkDown() -> std::vector<std::tuple<int,int>>; 
        auto checkCW() -> std::vector<std::tuple<int,int>>; 
        auto checkCCW() -> std::vector<std::tuple<int,int>>;
*/
    private:

    public:

    private:
};

// S TYPE PIECE MAP
// . 0 1   . 2 .   . . .   1 . .
// 2 3 .   . 3 0   . 3 2   0 3 .
// . . .   . . 1   1 0 .   . 2 .

class S_Type: public Tetramino {
    public:
        S_Type();
        
        auto print() -> int; 
/*
        auto checkLeft() -> std::vector<std::tuple<int,int>>; 
        auto checkRight() -> std::vector<std::tuple<int,int>>;
        auto checkDown() -> std::vector<std::tuple<int,int>>; 
        auto checkCW() -> std::vector<std::tuple<int,int>>; 
        auto checkCCW() -> std::vector<std::tuple<int,int>>;
*/
    private:

    public:

    private:
};

// Z TYPE PIECE MAP
// 0 1 .   . . 0   . . .   . 3 .
// . 2 3   . 2 1   3 2 .   1 2 .
// . . .   . 3 .   . 1 0   0 . .

class Z_Type: public Tetramino {
    public:
        Z_Type();
        
        auto print() -> int; 
/*
        auto checkLeft() -> std::vector<std::tuple<int,int>>; 
        auto checkRight() -> std::vector<std::tuple<int,int>>;
        auto checkDown() -> std::vector<std::tuple<int,int>>; 
        auto checkCW() -> std::vector<std::tuple<int,int>>; 
        auto checkCCW() -> std::vector<std::tuple<int,int>>;
*/
    private:

    public:

    private:
};

// O TYPE PIECE MAP
// 0 1   2 0   3 2   1 3 
// 2 3   3 1   1 0   0 2

class O_Type: public Tetramino {
    public:
        O_Type();
        
        auto print() -> int; 
/*
        auto checkLeft() -> std::vector<std::tuple<int,int>>; 
        auto checkRight() -> std::vector<std::tuple<int,int>>;
        auto checkDown() -> std::vector<std::tuple<int,int>>; 
        auto checkCW() -> std::vector<std::tuple<int,int>>; 
        auto checkCCW() -> std::vector<std::tuple<int,int>>;
*/
    private:

    public:

    private:
};

#endif //__TETRAMINO_H__
