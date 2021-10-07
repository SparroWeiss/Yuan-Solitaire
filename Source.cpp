#include <iostream>
#include "Board.h"
#include "Game.h"

int main()
{
	Board b = Board();
	Game g = Game();
	std::cout << g.boardToString(b);
	return 0;
}