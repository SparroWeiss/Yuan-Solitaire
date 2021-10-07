#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

std::string Game::move(Board board)
{
	if (board.howManyLeft() == 1)
		return std::string();
	for (int i = 0; i < ROWS * ROWS; i++)
	{
		if (board[i] != BoardPieces::Ball)
			continue;

	}
	return std::string();
}

std::string Game::boardToString(Board board)
{
	std::string s = "";
	std::string board_string = board.to_string();
	for (int i = 0; i < ROWS * ROWS; i++)
	{
		if (i % ROWS == 0)
			s += "\n";
		switch (board_string[i])
		{
		case '0':
			s += "X ";
			break;
		case '1':
			s += "O ";
			break;
		case '2':
			s += "  ";
		default:
			break;
		}
	}
	return s;
}
