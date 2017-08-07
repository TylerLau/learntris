#include <vector>

class Matrix {
	public:
		Matrix();
				
		char get(int x, int y);
		void print_board(bool active);
		void given();
		void clear();
		int get_score();
		int get_lines();
		void step();
		
		void set_active(char type);
		void print_active();
		
		void rotate();
		void c_rotate();
		bool left();
		bool right();
		bool down();
		void hard_down();
		
	private:
		int score;
		int lines;
		char board[22][10];
		char active;
		std::vector< std::vector<char> > active_block;
		int position_x;
		int position_y;
		
		void init_board();
		void add(int x, int y, char n);
		
		bool shove_left();
		bool shove_right();
		bool shove_down();
		bool check_left();
		bool check_right();
		bool check_down();
		void place_active();
};