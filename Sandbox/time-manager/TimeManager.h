#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include "SFML/System.hpp"

class TimeManager
{
public:

	/// <summary>
	/// Default Time Manager Constructor
	/// </summary>
	TimeManager();
	/// <summary>
	/// Default Time Manager Destructor
	/// </summary>
	virtual ~TimeManager();

	/// <summary>
	/// Returns the time passed from the beginning of the frame
	/// </summary>
	/// <returns>Time Passed</returns>
	sf::Time GetCurrentTime()const;

	/// <summary>
	/// Returns the time passed from the last frame to the new one
	/// </summary>
	/// <param name="currentTime">Current frame time</param>
	/// <param name="lastTime">Last frame time</param>
	/// <returns></returns>
	static float GetElapsedTime(float currentTime, float lastTime);

private:
	sf::Clock clock;
};

#endif 