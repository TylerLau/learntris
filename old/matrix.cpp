#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "matrix.h"

Matrix::Matrix()
{
	lines = 0;
	score = 0;
	init_board();
}

void Matrix::add(int x, int y, char n)
{
	board[x][y] = n;
}

char Matrix::get(int x, int y)
{
	return board[x][y];
}

void Matrix::print_board(bool active) 
{
	if (!active)
	{
		for (int i = 0; i < 22; ++i) 
		{
			for (int j = 0; j < 10; ++j) 
			{
				std::cout << board[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < 22; ++i) 
		{
			for (int j = 0; j < 10; ++j) 
			{
				if (i >= position_y && i < (position_y + active_block.size()) && j >= position_x && j < (position_x + active_block.size()) )
				{
					char y = active_block[i - position_y][j - position_x];
					putchar(toupper(y));
					std::cout << " ";
				}
				else std::cout << board[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}

void Matrix::init_board()
{
	for (int i = 0; i < 22; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			board[i][j] = '.';
		}
	}
}

void Matrix::given()
{
	char s;
	for (int i = 0; i < 22; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			std::cin >> s;
			board[i][j] = s;
		}
	}
}

void Matrix::clear()
{
	this->init_board();
}

int Matrix::get_score()
{
	return score;
}

int Matrix::get_lines()
{
	return lines;
}

void Matrix::step()
{
	bool check;
	for (int i = 0; i < 22; ++i)
	{
		check = true;
		for (int j = 0; j < 10; ++j)
		{
			if (board[i][j] == '.')
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			for (int j = 0; j < 10; ++j)
			{
				board[i][j] = '.';
			}
			score += 100;
			lines += 1;
		}
	}
}

void Matrix::set_active(char type)
{
	std::vector< std::vector<char> > active_temp;
	if (type == 'I')
	{
		std::vector<char> rowx;
		rowx.push_back('.');
		rowx.push_back('.');
		rowx.push_back('.');
		rowx.push_back('.');
		
		std::vector<char> row1;
		row1.push_back('c');
		row1.push_back('c');
		row1.push_back('c');
		row1.push_back('c');
		
		active_temp.push_back(rowx);
		active_temp.push_back(row1);
		active_temp.push_back(rowx);
		active_temp.push_back(rowx);
	}
	else if (type == 'O')
	{
		std::vector<char> row;
		row.push_back('y');
		row.push_back('y');
		
		active_temp.push_back(row);
		active_temp.push_back(row);
	}
	else if (type == 'Z')
	{
		std::vector<char> row1;
		row1.push_back('r');
		row1.push_back('r');
		row1.push_back('.');
		
		std::vector<char> row2;
		row2.push_back('.');
		row2.push_back('r');
		row2.push_back('r');
		
		std::vector<char> row3;
		row3.push_back('.');
		row3.push_back('.');
		row3.push_back('.');
		
		active_temp.push_back(row1);
		active_temp.push_back(row2);
		active_temp.push_back(row3);
	}
	else if (type == 'S')
	{
		std::vector<char> row1;
		row1.push_back('.');
		row1.push_back('g');
		row1.push_back('g');
		
		std::vector<char> row2;
		row2.push_back('g');
		row2.push_back('g');
		row2.push_back('.');
		
		std::vector<char> row3;
		row3.push_back('.');
		row3.push_back('.');
		row3.push_back('.');
		
		active_temp.push_back(row1);
		active_temp.push_back(row2);
		active_temp.push_back(row3);
	}
	else if (type == 'J')
	{
		std::vector<char> row1;
		row1.push_back('b');
		row1.push_back('.');
		row1.push_back('.');
		
		std::vector<char> row2;
		row2.push_back('b');
		row2.push_back('b');
		row2.push_back('b');
		
		std::vector<char> row3;
		row3.push_back('.');
		row3.push_back('.');
		row3.push_back('.');
		
		active_temp.push_back(row1);
		active_temp.push_back(row2);
		active_temp.push_back(row3);
	}
	else if (type == 'L')
	{
		std::vector<char> row1;
		row1.push_back('.');
		row1.push_back('.');
		row1.push_back('o');
		
		std::vector<char> row2;
		row2.push_back('o');
		row2.push_back('o');
		row2.push_back('o');
		
		std::vector<char> row3;
		row3.push_back('.');
		row3.push_back('.');
		row3.push_back('.');
		
		active_temp.push_back(row1);
		active_temp.push_back(row2);
		active_temp.push_back(row3);
	}
	else if (type == 'T')
	{
		std::vector<char> row1;
		row1.push_back('.');
		row1.push_back('m');
		row1.push_back('.');
		
		std::vector<char> row2;
		row2.push_back('m');
		row2.push_back('m');
		row2.push_back('m');
		
		std::vector<char> row3;
		row3.push_back('.');
		row3.push_back('.');
		row3.push_back('.');
		
		active_temp.push_back(row1);
		active_temp.push_back(row2);
		active_temp.push_back(row3);
	}
	
	active = type;
	active_block = active_temp;
	position_x = 5 - active_block.size() + active_block.size()/2;
	position_y = 0;
}

void Matrix::print_active()
{
	for (int i = 0; i < active_block.size(); ++i)
	{
		for (int j = 0; j < active_block.size(); ++j)
		{
			std::cout << active_block[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
		
void Matrix::rotate()
{
	std::vector< std::vector<char> > active_temp;
	for (int i = 0; i < active_block.size(); ++i) 
	{
		std::vector<char> row;
		for (int j = active_block.size() - 1; j >= 0; --j)
		{
			row.push_back(active_block[j][i]);
		}
		active_temp.push_back(row);
	}
	active_block = active_temp;
}

void Matrix::c_rotate()
{
	std::vector< std::vector<char> > active_temp;
	for (int i = active_block.size() - 1; i >= 0; --i) 
	{
		std::vector<char> row;
		for (int j = 0; j < active_block.size(); ++j)
		{
			row.push_back(active_block[j][i]);
		}
		active_temp.push_back(row);
	}
	active_block = active_temp;
}	

bool Matrix::left()
{
	if (position_x > 0 && this->check_left()) 
	{
		position_x -= 1;
		return true;
	}
	else if (this->shove_left()) return true;
	else return false;
}

bool Matrix::right() 
{
	if (position_x + active_block.size() < 10 && this->check_right()) 
	{
		position_x += 1;
		return true;
	}
	else if (this->shove_right()) return true;
	else return false;
}

bool Matrix::down()
{
	if (position_y + active_block.size() < 22 && this->check_down()) 
	{
		position_y += 1;
		return true;
	}
	else if (this->shove_down()) return true;
	else return false;
}

bool Matrix::shove_left()
{
	bool check = true;
	for (int i = 0; i < active_block.size(); ++i)
		if (active_block[i][0] != '.') check = false;
	
	if (check)
	{
		for (int i = 0; i < active_block.size(); ++i)
		{
			for (int j = 0; j < active_block.size()-1; ++j)
			{
				active_block[i][j] = active_block[i][j+1];
			}
			active_block[i][active_block.size()-1] = '.';
		}
		return true;
	}
	else return false;
}

bool Matrix::shove_right()
{
	bool check = true;
	for (int i = 0; i < active_block.size(); ++i)
		if (active_block[i][active_block.size()-1] != '.') check = false;
	
	if (check)
	{
		for (int i = 0; i < active_block.size(); ++i)
		{
			for (int j = active_block.size()-1; j > 0; --j)
			{
				active_block[i][j] = active_block[i][j-1];
			}
			active_block[i][0] = '.';
		}
		return true;
	}
	else return false;
}

bool Matrix::shove_down()
{
	bool check = true;
	for (int j = 0; j < active_block.size(); ++j)
		if (active_block[active_block.size()-1][j] != '.') check = false;
	
	if (check)
	{
		for (int i = active_block.size() - 1; i >= 0; --i)
		{
			for (int j = 0; j < active_block.size(); ++j)
			{
				if (i == 0) active_block[i][j] = '.';
				else active_block[i][j] = active_block[i-1][j];
			}
		}
		return true;
	}
	else return false;
}

void Matrix::hard_down()
{
	while (this->down());
	this->place_active();
	std::cout << position_y << std::endl;
}

void Matrix::place_active()
{
	for (int i = 0; i < active_block.size(); ++i)
	{
		for (int j = 0; j < active_block.size(); ++j)
		{
			board[i+position_y][j+position_x] = tolower(active_block[i][j]);
		}
	}
	std::vector< std::vector<char> > blank;
	active_block = blank;
}

bool Matrix::check_left()
{
	for (int i = 0; i < active_block.size(); ++i)
	{
		if (active_block[i][0] != '.')
		{
			if (board[i+position_y][position_x-1] != '.') return false;
		}
	}
	return true;
}

bool Matrix::check_right()
{
	for (int i = 0; i < active_block.size(); ++i)
	{
		if (active_block[i][active_block.size()-1] != '.')
		{
			if (board[i+position_y][position_x+active_block.size()+1] != '.') return false;
		}
	}
	return true;
}

bool Matrix::check_down()
{
	if (position_y+active_block.size() == 21) return true;
	for (int j = 0; j < active_block.size(); ++j)
	{
		if (active_block[active_block.size()-1][j] != '.')
		{
			if (board[position_y+active_block.size()+1][j+position_x] != '.') return false;
		}
	}
	return true;
}
		