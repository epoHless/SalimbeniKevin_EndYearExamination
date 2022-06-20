#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <LoopManager.h>

class GameManager
{
//Constructors / Destructor
public:
	/// <summary>
	/// Default Loop Manager Contructor
	/// </summary>
	GameManager(){};
	/// <summary>
	/// Default Loop Manager Destructor
	/// </summary>
	~GameManager(){};

//Public Functions
public:

	/// <summary>
	/// Main loop function
	/// </summary>
	void run(WTGD::LoopManager* manager);


//Private Functions
private:
	void initialize(WTGD::LoopManager* manager);

//Private Members
private:

	std::vector<WTGD::GameObject> gameobjects;
};

#endif