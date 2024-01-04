#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "game.hpp"

int main() {
	Board board;
	FillRand(board);
	ShowBoard(board);

	for (int k = 0; k<10; ++k) {
		ShowBoard(board);
		Step(board);		
		std::this_thread::sleep_for(std::chrono::seconds(1));
		system("clear");

	}

	return 0;
}