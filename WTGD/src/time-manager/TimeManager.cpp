#include "TimeManager.h"

WTGD::TimeManager::TimeManager() {}

WTGD::TimeManager::~TimeManager() {}

sf::Time WTGD::TimeManager::GetCurrentTime() const
{
	return clock.getElapsedTime();
}

float WTGD::TimeManager::GetElapsedTime(float currentTime, float lastTime)
{
	return currentTime - lastTime;
}