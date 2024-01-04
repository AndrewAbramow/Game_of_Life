#pragma once

// sim field
const int width = 20;
const int height = 40;

using Board = int[width][height];

void FillRand(Board board);

void ShowBoard(const Board board);

void Copy(Board src, Board dst);

int GetX(int x);

int GetY(int y);

void Step(Board board);