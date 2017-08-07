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
        //else if (x == 'p') m.print_board(false);
        //else if (x == 'P') m.print_board(true);
		
        //else if (x == 'g') m.given();
        //else if (x == 'c') m.clear();
        //else if (x == 's') m.step();
		
        //else if (x == '?')
        //{
        //	std::cin >> x;
		//	if (x == 's') std::cout << m.get_score() << std::endl;
		//	if (x == 'n') std::cout << m.get_lines() << std::endl;
		//}
		
		//else if (x == 'I') m.set_active('I');
		//else if (x == 'O') m.set_active('O');
		//else if (x == 'Z') m.set_active('Z');
		//else if (x == 'S') m.set_active('S');
		//else if (x == 'J') m.set_active('J');
		//else if (x == 'L') m.set_active('L');
		//else if (x == 'T') m.set_active('T');
		//else if (x == 't') m.print_active();
		
		//else if (x == ')') m.rotate();
		//else if (x == '(') m.c_rotate();
		//else if (x == '<') m.left();
		//else if (x == '>') m.right();
		//else if (x == 'v') m.down();
		//else if (x == 'V') m.hard_down();
		
		//else if (x == ';') std::cout << std::endl;
	}

}
