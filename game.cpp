#include "game.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

void FillRand(Board board){
	std::srand(std::time(nullptr));

	for (int i = 0; i<width; ++i) {
		for (int j = 0; j<height; ++j) {
			if (rand() % 10 == 0) {
				board[i][j] = 1;
			} else {
				board[i][j] = 0;
			}
		}
	}
}

void ShowBoard(const Board board) {	
	for (int i = 0; i<width; ++i) {
		for (int j = 0; j<height; ++j) {
			if (board[i][j]) {
				std::cout<<'*';
			} else {
				std::cout<<' ';
			}
		}
		std::cout<<'\n';
	}
}

void Copy(Board src, Board dst) {
	for (int i = 0; i<width; ++i) {
		for (int j = 0; j<height; ++j) {
			dst[i][j] = src[i][j];
		}
	}
}

int GetX(int x) {
	return (width + x) % width;
}

int GetY(int y) {
	return (height + y) % height;
}

void Step(Board board) {
Board prev;
Copy(board, prev);
	for (int i = 0; i<width; ++i) {
		for (int j = 0; j<height; ++j) {
			int count_neib = 0;
			count_neib += prev[GetX(i-1)][GetY(j-1)];
			count_neib += prev[GetX(i-1)][GetY(j)];
			count_neib += prev[GetX(i-1)][GetY(j+1)];
			count_neib += prev[GetX(i)][GetY(j-1)];
			count_neib += prev[GetX(i)][GetY(j+1)];
			count_neib += prev[GetX(i+1)][GetY(j-1)];
			count_neib += prev[GetX(i+1)][GetY(j)];
			count_neib += prev[GetX(i+1)][GetY(j+1)];

			if ((prev[i][j] == 0) && (count_neib == 3)) {
				board[i][j] = 1;
			} else if ((count_neib <2 ) || (count_neib >3)) {
				board[i][j] = 0;
			}
		}
	}
}