#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <pch.h>

namespace WTGD
{
	class WTGD_API TimeManager
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
		[[nodiscard]] sf::Time get_current_time()const;

		/// <summary>
		/// Returns the time passed from the last frame to the new one
		/// </summary>
		/// <param name="currentTime">Current frame time</param>
		/// <param name="lastTime">Last frame time</param>
		/// <returns></returns>
		static float get_elapsed_time(float currentTime, float lastTime);

	private:
		sf::Clock clock;
	};
}

#endif TIME_MANAGER_H