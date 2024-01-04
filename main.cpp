#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "Board.hpp"

int main() {
	Board board;
	board.ReadFromFile(); // optional
	for (int k = 0; k<10; ++k) {
		board.Show();
		board.NextGen();
		board.WriteToFile(k);		
		std::this_thread::sleep_for(std::chrono::seconds(1));
		system("clear");
	}

	return 0;
}