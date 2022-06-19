#ifndef LOOP_MANAGER_H
#define LOOP_MANAGER_H

#include "../time-manager/TimeManager.h"
#include <SFML/Graphics.hpp>

class LoopManager
{
public:
	/// <summary>
	/// Default Loop Manager Contructor
	/// </summary>
	LoopManager();	
	/// <summary>
	/// Default Loop Manager Destructor
	/// </summary>
	~LoopManager();

private:
	void initialize();
	void draw();
	void update();
	void pollEvents();

private:
	TimeManager timeManager;
	sf::RenderWindow gameWindow;
	sf::Time lastTime, currentTime;
};

#endif