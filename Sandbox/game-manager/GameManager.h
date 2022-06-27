#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <LoopManager.h>
#include "../utilities/Utility.h"

class GameManager
{
//Constructors / Destructor
public:
	/// <summary>
	/// Default Loop Manager Contructor
	/// </summary>
	GameManager(WTGD::LoopManager* manager) : _manager(manager) {};
	/// <summary>
	/// Default Loop Manager Destructor
	/// </summary>
	~GameManager(){};

//Public Functions
public:

	/// <summary>
	/// Main loop function
	/// </summary>
	void run();

//Private Functions
private:
	/// <summary>
	/// Initialize GameObjects
	/// </summary>
	void initialize();

//Private Members
private:

	std::vector<WTGD::GameObject*> gameobjects;

	WTGD::LoopManager* _manager = nullptr;
};

#endif