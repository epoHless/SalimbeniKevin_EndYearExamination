#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include "SFML/System.hpp"

class TimeManager
{
public:

	TimeManager();
	virtual ~TimeManager();

	sf::Time GetCurrentTime()const;

	static float GetElapsedTime(float currentTime, float lastTime);

private:
	sf::Clock clock;
};

#endif 