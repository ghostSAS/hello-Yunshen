#include "nQueens_solver.hpp"
#include "draw_board.hpp"

int NN = 4;

int main() 
{
	std::cout << "Enter the size of chess board (n*n): ";
	std::cin >> NN;

	std::vector<int> state = std::vector<int>(NN);
	std::vector<std::vector<int>> board = std::vector<std::vector<int>>(NN, std::vector<int>(NN));

	// Getting a starting point by  randomly configuring the board 
	configureRandomly(board, state); 

	// Do hill climbing on the board obtained 
	hillClimbing(board, state); 

    printBoard(board);
	std::cout << "hi" << std::endl;

	// drawBoard(board, state);
	// bool p_open = true;
	// ShowExampleAppLayout(&p_open);
	drawBoard();

	return 0; 
} 