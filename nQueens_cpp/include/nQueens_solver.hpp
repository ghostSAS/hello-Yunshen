#ifndef NQUEENS_SOLVER_HPP
#define NQUEENS_SOLVER_HPP

#include <iostream> 
#include <math.h>

#define NN 8

// using namespace std;


void configureRandomly(int board[][NN], int* state);

void printBoard(int board[][NN]);

void printState(int *state);

bool compareStates(int *state1, int *state2);

void fill(int board[][NN], int value);

int calculateObjective(int board[][NN], int *state);

void generateBoard(int board[][NN], int *state);

void copyState(int *state1, int *state2);

void getNeighbour(int board[][NN], int *state);

void hillClimbing(int board[][NN], int *state);

#endif