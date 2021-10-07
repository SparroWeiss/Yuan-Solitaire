#pragma once
#include <string>
#include <iostream>

#define ROWS 7
#define INITIAL_STRING "2211122221112211111111110111111111122111222211122"

enum class BoardPieces { Empty, Ball, Forbidden };

class Board
{
public:
	Board() : Board(INITIAL_STRING) {}
	Board(const std::string board);
	Board(const Board& other) : Board(other.to_string()) { }
	~Board() { delete this->board_; }
	std::string to_string() const;
	int howManyLeft() const;
	bool validMove(const int src, const int dst) const;
	Board move(const int src, const int dst) const;
private:
	BoardPieces* board_;
};