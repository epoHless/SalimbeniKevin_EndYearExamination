#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#ifdef DLL_EXPORT
#define TIME_MANAGER_API __declspec(dllexport)
#else
#define TIME_MANAGER_API __declspec(dllimport)
#endif

#include <SFML/System.hpp>

namespace WTGD
{
	class TIME_MANAGER_API TimeManager
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
}

#endif TIME_MANAGER_H