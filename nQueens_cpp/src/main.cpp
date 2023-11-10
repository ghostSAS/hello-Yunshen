#include "nQueens_solver.hpp"
#include "draw_board.hpp"

// Driver code 
int main() 
{ 
	int state[NN] = {}; 
	int board[NN][NN] = {}; 

	// Getting a starting point by 
	// randomly configuring the board 
	configureRandomly(board, state); 

	// Do hill climbing on the 
	// board obtained 
	hillClimbing(board, state); 

    printBoard(board);
	std::cout << "hi" << std::endl;

	// drawBoard(board, state);
	// bool p_open = true;
	// ShowExampleAppLayout(&p_open);
	showWenbo();

	return 0; 
} 