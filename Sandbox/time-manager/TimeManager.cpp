#include "TimeManager.h"

TimeManager::TimeManager(){}

TimeManager::~TimeManager(){}

sf::Time TimeManager::GetCurrentTime() const
{
	return clock.getElapsedTime();
}

float TimeManager::GetElapsedTime(float currentTime, float lastTime)
{
	return currentTime - lastTime;
}
