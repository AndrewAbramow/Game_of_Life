#pragma once

#include <array>

class Board {
public:
	Board();
	//~Board();
	void Show();
	int GetX(int x);
	int GetY(int y);
	void NextGen();
private:
	static const int width = 20;
	static const int height = 20;
	static const int fill = 10;
	std::array<std::array<int, height>, width> curr_field;
	std::array<std::array<int, height>, width> prev_field;
};