#include "game-manager/GameManager.h"

int main()
{
	GameManager* gm = new GameManager(new WTGD::LoopManager());
	gm->run();
	return 0;
}