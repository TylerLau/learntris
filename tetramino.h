#ifndef __TETRAMINO_H__
#define __TETRAMINO_H__

#include <string>

class Tetramino {
    // Public member functions
    public:
        Tetramino(std::string _name);
        
        auto type()->std::string; // Function that returns type of piece
    // Private member functions
    private:

    // Public member variables
    public:

    // Private member variables
    private:
        std::string name;   // Stores the type of tetramino
};

#endif //__TETRAMINO_H__
