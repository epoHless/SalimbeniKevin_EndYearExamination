#include <pch.h>
#include <time-manager/TimeManager.h>

WTGD::TimeManager::TimeManager() {}

WTGD::TimeManager::~TimeManager() {}

sf::Time WTGD::TimeManager::get_current_time() const
{
	return clock.getElapsedTime();
}

float WTGD::TimeManager::get_elapsed_time(float currentTime, float lastTime)
{
	return currentTime - lastTime;
}