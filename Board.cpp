#include "Board.h"


Board::Board() : Board(INITIAL_STRING) {}

Board::Board(const std::string board)
{
	this->board_ = new BoardPieces[ROWS * ROWS];
	for (int i = 0; i < ROWS * ROWS; i++)
	{
		this->board_[i] = static_cast<BoardPieces>(std::stoi(std::string(1, board[i])));
	}

}

Board::Board(const Board& other) : Board(other.to_string()) { }

Board::~Board()
{
	delete this->board_;
}

std::string Board::to_string() const
{
	std::string s = "";
	for (int i = 0; i < ROWS * ROWS; i++)
	{
		s += std::to_string(static_cast<int>(this->board_[i]));
	}
	return s;
}

int Board::howManyLeft() const
{
	int count = 0;
	for (int i = 0; i < ROWS * ROWS; i++)
	{
		if (board_[i] == BoardPieces::Ball)
		{
			count++;
		}
	}
	return count;
}

BoardPieces& Board::operator[](std::size_t idx) const
{
	return this->board_[idx];
}

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

Board Board::move(const int src, const int dst) const
{
	return Board();
}
