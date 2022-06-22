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

	void set_events(sf::Event evt);


//Private Functions
private:
	void initialize();

//Private Members
private:

	std::vector<WTGD::GameObject*> gameobjects;

	WTGD::LoopManager* _manager = nullptr;
	sf::Event evt;
};

#endif