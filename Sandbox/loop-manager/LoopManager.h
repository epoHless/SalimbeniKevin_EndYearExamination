#ifndef LOOP_MANAGER_H
#define LOOP_MANAGER_H

#include "../time-manager/TimeManager.h"
#include <SFML/Graphics.hpp>

class LoopManager
{
//Constructors / Destructor
public:
	/// <summary>
	/// Default Loop Manager Contructor
	/// </summary>
	LoopManager() : gameWindow(nullptr){};
	/// <summary>
	/// Default Loop Manager Destructor
	/// </summary>
	~LoopManager();

//Public Functions
public:

	/// <summary>
	/// Creates the game window
	/// </summary>
	void createWindow(const float width, const float height, const char* title);

	/// <summary>
	/// Change the amount of max FPS for the game window (standard is 60 FPS)
	/// </summary>
	/// <param name="newLimit">The new FPS limit</param>
	void setMaxFPS(unsigned newLimit);

	/// <summary>
	/// Returns the current frame's FPS
	/// </summary>
	/// <returns></returns>
	unsigned getFPS()const;

	/// <summary>
	/// Toggle the FPS limit ON or OFF depending on the current setting
	/// </summary>
	void fpsLimitToggler();

	/// <summary>
	/// Main loop function
	/// </summary>
	void run();


//Private Functions
private:
	void initialize();
	void draw();
	void update();
	void pollEvents();
	void updateGameTime();

//Private Members
private:
	sf::RenderWindow* gameWindow;

	unsigned maxFPS = 60;
	bool isFpsLimited = true;

	TimeManager timeManager;
	float elapsedTime;
	float lag;
	sf::Time lastTime, currentTime;
};

#endif