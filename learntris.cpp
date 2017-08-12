#include <iostream>
#include <string>
#include "matrix.h"

int main() {
	
	Matrix m;

	char x;
	while(true)
    {
		std::cin >> x;
		if (x == 'q') break;
        else if (x == 'p') m.printGrid(false);
        else if (x == 'P') m.printGrid(true);
		
        else if (x == 'g') m.given();
        else if (x == 'c') m.clear();
        else if (x == 's') m.step();

        else if (x == '?') {
        	std::cin >> x;
		    if (x == 's') std::cout << m.get_score() << std::endl;
			if (x == 'n') std::cout << m.get_lines() << std::endl;
		}
		
		else if (x == 'I') m.setActive('I');
		else if (x == 'O') m.setActive('O');
		else if (x == 'Z') m.setActive('Z');
		else if (x == 'S') m.setActive('S');
		else if (x == 'J') m.setActive('J');
		else if (x == 'L') m.setActive('L');
		else if (x == 'T') m.setActive('T');
        else if (x == 't') m.printActive();
		
		else if (x == ')') m.rotateCW();
		else if (x == '(') m.rotateCCW();
		else if (x == '<') m.moveLeft();
		else if (x == '>') m.moveRight();
		else if (x == 'v') m.moveDown();
		//else if (x == 'V') m.hard_down();
		
		else if (x == ';') std::cout << std::endl;
	}

}
