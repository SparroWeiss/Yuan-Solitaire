#include "Board.h"

/// <summary>
/// This Constructor turn a string to a board instance.
/// </summary>
/// <param name="board">The string of the board, made of 0,1,2</param>
Board::Board(const std::string board)
{
	this->board_ = new BoardPieces[ROWS * ROWS];
	for (int i = 0; i < ROWS * ROWS; i++)
	{
		this->board_[i] = static_cast<BoardPieces>(std::stoi(std::string(1, board[i]))); 
		// Turn each char to BoardPiece instance.
	}
}

/// <summary>
/// This function turns the board instance into a string of 0,1,2.
/// </summary>
/// <returns>The board instance as a string.</returns>
std::string Board::to_string() const
{
	std::string s = "";
	for (int i = 0; i < ROWS * ROWS; i++)
	{
		s += std::to_string(static_cast<int>(this->board_[i]));
	}
	return s;
}

/// <summary>
/// This function counts how many balls are left on the board.
/// </summary>
/// <returns>How many balls are left.</returns>
int Board::howManyLeft() const
{
	int count = 0;
	for (int i = 0; i < ROWS * ROWS; i++)
	{
		if (this->board_[i] == BoardPieces::Ball)
		{
			count++;
		}
	}
	return count;
}

/// <summary>
/// This function checks that the move of the ball is valid.
/// </summary>
/// <param name="src">The index of the source</param>
/// <param name="dst">The index of the destination</param>
/// <returns>true - the move is valid. false - the move is invalid.</returns>
bool Board::validMove(const int src, const int dst) const
{
	// If the move is out of the boundaries of the board. 
	if (src >= ROWS * ROWS || src < 0 ||
		dst >= ROWS * ROWS || dst < 0)
		return false;
	// If the move is from an invalid piece, or to an invalid piece. 
	if (this->board_[src] != BoardPieces::Ball || this->board_[dst] != BoardPieces::Empty)
		return false;
	// If the move has an invalid distance.
	if (std::abs(src - dst) != ROWS * 2 && std::abs(src - dst) != 2)
		return false;
	// If the piece between the pieces is not a ball.
	if (this->board_[(src + dst) / 2] != BoardPieces::Ball)
		return false;
	// If the move is valid.
	return true;
}

/// <summary>
/// This function creates a new board instance, moves the pieces on the new board, and returns it.
/// </summary>
/// <param name="src">The index of the source</param>
/// <param name="dst">The index of the destination</param>
/// <returns>A new board instance, after the the pieces were moved.</returns>
Board Board::move(const int src, const int dst) const
{
	Board new_board = Board(*this);
	new_board.board_[src] = BoardPieces::Empty; // Source piece is empty.
	new_board.board_[(src + dst) / 2] = BoardPieces::Empty; // Middle piece is empty.
	new_board.board_[dst] = BoardPieces::Ball; // Destination piece is taken.
	return new_board; // Returning the board after the move.
}
