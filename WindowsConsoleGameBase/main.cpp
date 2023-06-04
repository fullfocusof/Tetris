#include "Tetris.h"
#include <ctime>

int main() 
{
	srand(static_cast<unsigned int>(time(NULL)));
	Tetris game;
	return static_cast<int>(game.run());
}
