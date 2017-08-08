#include "tetramino.h"

Tetramino::Tetramino(std::string _name) {
    name = _name;
}

auto Tetramino::type() -> std::string {
    return name;
}

