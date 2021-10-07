#pragma once
#include "Board.h"

class Game
{
public:
	Game();
	~Game();
	static std::string move(Board board);
	static std::string boardToString(Board board);
private:

};
