#include "loop-manager/LoopManager.h"

int main()
{
	LoopManager* lm = new LoopManager();
	lm->createWindow(1280, 720, "WTGD Game");
	lm->run();

	return 0;
}