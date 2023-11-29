// #ifndef NQUEENS_SOLVER_HPP
// #define NQUEENS_SOLVER_HPP

#pragma once

#include <iostream> 
#include <math.h>
#include <vector>

// #define vector std::vector
// #define NN 8

extern int NN;

// using namespace std;
// int state[NN] = {}; 
// int board[NN][NN] = {}; 



void configureRandomly(std::vector<std::vector<int>>& board, std::vector<int>& state);

void printBoard(const std::vector<std::vector<int>>& board) ;

void printState(const std::vector<int>& state);

bool compareStates(const std::vector<int>& state1, const std::vector<int>& state2);

void fill(std::vector<std::vector<int>>& board, int value);

int calculateObjective(std::vector<std::vector<int>>& board, std::vector<int>& state);

void generateBoard(std::vector<std::vector<int>>& board, std::vector<int>& state);

void copyState(std::vector<int>& state1, const std::vector<int>& state2);

void getNeighbour(std::vector<std::vector<int>>& board, std::vector<int>& state);

void hillClimbing(std::vector<std::vector<int>>& board, std::vector<int>& state);

// #endif