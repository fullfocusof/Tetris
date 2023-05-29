#include "Tetris.h"
#include <ctime>

int main() 
{
	srand(time(NULL));
	Tetris game;
	return static_cast<int>(game.run());
}
