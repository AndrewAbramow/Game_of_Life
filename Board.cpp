#include "Board.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Board::Board() {
	// initialize field
	std::srand(std::time(nullptr));
	for (auto& i: curr_field)  {
		for (auto& j: i) {
			if (rand() % fill == 0) j = 1;
			else j = 0;
	    }
	}
}

void Board::Show() {
	for (const auto& i: curr_field)  {
        for (const auto& j: i) {
        	if (j) std::cout<<'*';
        	else std::cout<<' ';
        }
        std::cout<<'\n';
    }
}

int Board::GetX(int x) {
	return (width + x) % width;
}

int Board::GetY(int y) {
	return (height + y) % height;
}

void Board::NextGen() {
	prev_field = curr_field;
	for (int i = 0; i<width; ++i) {
		for (int j = 0; j<height; ++j) {
			int count_neib = 0;
			count_neib += prev_field.at(GetX(i-1)).at(GetY(j-1))
					   +  prev_field.at(GetX(i-1)).at(GetY(j))
					   +  prev_field.at(GetX(i-1)).at(GetY(j+1))
					   +  prev_field.at(GetX(i)).at(GetY(j-1))
					   +  prev_field.at(GetX(i)).at(GetY(j+1))
					   +  prev_field.at(GetX(i+1)).at(GetY(j-1))
					   +  prev_field.at(GetX(i+1)).at(GetY(j))
					   +  prev_field.at(GetX(i+1)).at(GetY(j+1));

			if ((prev_field.at(i).at(j) == 0) && (count_neib == 3)) {
				curr_field.at(i).at(j) = 1;
			} else if ((count_neib <2 ) || (count_neib >3)) {
				curr_field.at(i).at(j) = 0;
			}
		}
	}
}