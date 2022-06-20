#include "game-manager/GameManager.h"

int main()
{
	GameManager* gm = new GameManager();
	gm->run(new WTGD::LoopManager());
	return 0;
}