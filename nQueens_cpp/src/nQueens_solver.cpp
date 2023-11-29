#include "nQueens_solver.hpp"

// A utility function that configures
// the 2D array "board" and
// array "state" randomly to provide
// a starting point for the algorithm.
void configureRandomly(std::vector<std::vector<int>>& board, std::vector<int>& state){ 

	// Seed for the random function 
	srand(time(0)); 

	// Iterating through the 
	// column indices 
	for (int i = 0; i < NN; i++) { 

		// Getting a random row index 
		state[i] = rand() % NN; 

		// Placing a queen on the 
		// obtained place in 
		// chessboard. 
		board[state[i]][i] = 1; 
	} 
} 

// A utility function that prints 
// the 2D array "board". 
void printBoard(const std::vector<std::vector<int>>& board) 
{ 

	for (int i = 0; i < NN; i++) { 
		std::cout << " "; 
		for (int j = 0; j < NN; j++) { 

			std::cout << (board[i][j] == 1 ? "Q" : ".") << " "; 
		} 
		std::cout << "\n"; 
	} 
} 

// A utility function that prints 
// the array "state". 
void printState(const std::vector<int>& state) 
{ 

	for (int i = 0; i < NN; i++) { 
		std::cout << " " << state[i] << " "; 
	} 
	std::cout << std::endl; 
} 

// A utility function that compares 
// two arrays, state1 and state2 and 
// returns true if equal 
// and false otherwise. 
bool compareStates(const std::vector<int>& state1, const std::vector<int>& state2) 
{ 

	for (int i = 0; i < NN; i++) { 
		if (state1[i] != state2[i]) { 
			return false; 
		} 
	} 
	return true; 
} 

// A utility function that fills 
// the 2D array "board" with 
// values "value" 
void fill(std::vector<std::vector<int>>& board, int value) 
{ 
	for (int i = 0; i < NN; i++) { 
		for (int j = 0; j < NN; j++) { 
			board[i][j] = value; 
		} 
	} 
} 

// This function calculates the 
// objective value of the 
// state(queens attacking each other) 
// using the board by the 
// following logic. 
int calculateObjective(std::vector<std::vector<int>>& board, std::vector<int>& state) 
{ 

	// For each queen in a column, we check 
	// for other queens falling in the line 
	// of our current queen and if found, 
	// any, then we increment the variable 
	// attacking count. 

	// Number of queens attacking each other, 
	// initially zero. 
	int attacking = 0; 

	// Variables to index a particular 
	// row and column on board. 
	int row, col; 

	for (int i = 0; i < NN; i++) { 

		// At each column 'i', the queen is 
		// placed at row 'state[i]', by the 
		// definition of our state. 

		// To the left of same row 
		// (row remains constant 
		// and col decreases) 
		row = state[i], col = i - 1; 
		while (col >= 0 
			&& board[row][col] != 1) { 
			col--; 
		} 
		if (col >= 0 
			&& board[row][col] == 1) { 
			attacking++; 
		} 

		// To the right of same row 
		// (row remains constant 
		// and col increases) 
		row = state[i], col = i + 1; 
		while (col < NN 
			&& board[row][col] != 1) { 
			col++; 
		} 
		if (col < NN 
			&& board[row][col] == 1) { 
			attacking++; 
		} 

		// Diagonally to the left up 
		// (row and col simultaneously 
		// decrease) 
		row = state[i] - 1, col = i - 1; 
		while (col >= 0 && row >= 0 
			&& board[row][col] != 1) { 
			col--; 
			row--; 
		} 
		if (col >= 0 && row >= 0 
			&& board[row][col] == 1) { 
			attacking++; 
		} 

		// Diagonally to the right down 
		// (row and col simultaneously 
		// increase) 
		row = state[i] + 1, col = i + 1; 
		while (col < NN && row < NN 
			&& board[row][col] != 1) { 
			col++; 
			row++; 
		} 
		if (col < NN && row < NN 
			&& board[row][col] == 1) { 
			attacking++; 
		} 

		// Diagonally to the left down 
		// (col decreases and row 
		// increases) 
		row = state[i] + 1, col = i - 1; 
		while (col >= 0 && row < NN 
			&& board[row][col] != 1) { 
			col--; 
			row++; 
		} 
		if (col >= 0 && row < NN 
			&& board[row][col] == 1) { 
			attacking++; 
		} 

		// Diagonally to the right up 
		// (col increases and row 
		// decreases) 
		row = state[i] - 1, col = i + 1; 
		while (col < NN && row >= 0 
			&& board[row][col] != 1) { 
			col++; 
			row--; 
		} 
		if (col < NN && row >= 0 
			&& board[row][col] == 1) { 
			attacking++; 
		} 
	} 

	// Return pairs. 
	return (int)(attacking / 2); 
} 

// A utility function that 
// generates a board configuration 
// given the state. 
void generateBoard(std::vector<std::vector<int>>& board, std::vector<int>& state) 
{ 

	fill(board, 0); 
	for (int i = 0; i < NN; i++) { 
		board[state[i]][i] = 1; 
	} 
} 

// A utility function that copies 
// contents of state2 to state1. 
void copyState(std::vector<int>& state1, const std::vector<int>& state2) 
{ 

	for (int i = 0; i < NN; i++) { 
		state1[i] = state2[i]; 
	} 
} 

// This function gets the neighbour 
// of the current state having 
// the least objective value 
// amongst all neighbours as 
// well as the current state. 
void getNeighbour(std::vector<std::vector<int>>& board, std::vector<int>& state) 
{ 
	// Declaring and initializing the 
	// optimal board and state with 
	// the current board and the state 
	// as the starting point. 

	// int opBoard[NN][NN]; 
	// int opState[NN]; 

	std::vector<int> opState(NN);
	std::vector<std::vector<int>> opBoard(NN, std::vector<int>(NN));

	copyState(opState, state); 
	generateBoard(opBoard, opState); 

	// Initializing the optimal 
	// objective value 

	int opObjective = calculateObjective(opBoard, opState); 

	// Declaring and initializing 
	// the temporary board and 
	// state for the purpose 
	// of computation. 

	// int NeighbourBoard[NN][NN]; 
	// int NeighbourState[NN]; 
	std::vector<int> NeighbourState(NN);
	std::vector<std::vector<int>> NeighbourBoard(NN, std::vector<int>(NN));


	copyState(NeighbourState, state); 
	generateBoard(NeighbourBoard, NeighbourState); 

	// Iterating through all 
	// possible neighbours 
	// of the board. 

	for (int i = 0; i < NN; i++) { 
		for (int j = 0; j < NN; j++) { 

			// Condition for skipping the 
			// current state 

			if (j != state[i]) { 

				// Initializing temporary 
				// neighbour with the 
				// current neighbour. 

				NeighbourState[i] = j; 
				NeighbourBoard[NeighbourState[i]][i] 
					= 1; 
				NeighbourBoard[state[i]][i] 
					= 0; 

				// Calculating the objective 
				// value of the neighbour. 

				int temp = calculateObjective( 
						NeighbourBoard, 
						NeighbourState); 

				// Comparing temporary and optimal 
				// neighbour objectives and if 
				// temporary is less than optimal 
				// then updating accordingly. 

				if (temp <= opObjective) { 
					opObjective = temp; 
					copyState(opState, 
							NeighbourState); 
					generateBoard(opBoard, 
								opState); 
				} 

				// Going back to the original 
				// configuration for the next 
				// iteration. 

				NeighbourBoard[NeighbourState[i]][i] 
					= 0; 
				NeighbourState[i] = state[i]; 
				NeighbourBoard[state[i]][i] = 1; 
			} 
		} 
	} 

	// Copying the optimal board and 
	// state thus found to the current 
	// board and, state since c++ doesn't 
	// allow returning multiple values. 

	copyState(state, opState); 
	fill(board, 0); 
	generateBoard(board, state); 
} 

void hillClimbing(std::vector<std::vector<int>>& board, std::vector<int>& state) 
{ 

	// Declaring and initializing the 
	// neighbour board and state with 
	// the current board and the state 
	// as the starting point. 

	// int neighbourBoard[NN][NN] = {}; 
	// int neighbourState[NN]; 

	std::vector<int> neighbourState(NN);
	std::vector<std::vector<int>> neighbourBoard(NN, std::vector<int>(NN));
	

	copyState(neighbourState, state); 
	generateBoard(neighbourBoard, 
				neighbourState); 

	do { 

		// Copying the neighbour board and 
		// state to the current board and 
		// state, since a neighbour 
		// becomes current after the jump. 

		copyState(state, neighbourState); 
		generateBoard(board, state); 

		// Getting the optimal neighbour 

		getNeighbour(neighbourBoard, 
					neighbourState); 

		if (compareStates(state, 
						neighbourState)) { 

			// If neighbour and current are 
			// equal then no optimal neighbour 
			// exists and therefore output the 
			// result and break the loop. 

			std::cout << "Found Solution" << std::endl;
			break;
		} 
		else if (calculateObjective(board, 
									state) 
				== calculateObjective( 
						neighbourBoard, 
						neighbourState)) { 

			// If neighbour and current are 
			// not equal but their objectives 
			// are equal then we are either 
			// approaching a shoulder or a 
			// local optimum, in any case, 
			// jump to a random neighbour 
			// to escape it. 

			// Random neighbour 
			neighbourState[rand() % NN] 
				= rand() % NN; 
			generateBoard(neighbourBoard, 
						neighbourState); 
		} 

	} while (true); 
} 


