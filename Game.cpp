#include "Game.h"

/// <summary>
/// This function moves the balls around the board untill it finds the right path.
/// </summary>
/// <param name="board">The current board of the game</param>
/// <returns>A long string that shows the path to having only one ball on the board.</returns>
std::string Game::move(Board board)
{
	if (board.howManyLeft() == 1)
		return boardToString(board); // Only one ball left on the board.
	for (int src = 0; src < ROWS * ROWS; src++)
	{
		for (int dst = 0; dst < ROWS * ROWS; dst++)
		{
			if (!board.validMove(src, dst))
				continue; // Invalid move.
			std::string result = move(board.move(src, dst));
			if (result != "") // If the move is part of the right path.
				return boardToString(board) + result;
		}
	}
	return std::string(); // Dead end.
}

/// <summary>
/// This function convert a board instance to a readable string. 
/// </summary>
/// <param name="board">The current board of the game</param>
/// <returns>The board in ascii art.</returns>
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
		case '0': // Empty.
			s += "X ";
			break;
		case '1': // Ball.
			s += "O ";
			break;
		case '2': // Forbidden.
			s += "  ";
		default:
			break;
		}
	}
	return s + "\n\n";
}
