#ifndef ITICKABLE_H
#define ITICKABLE_H

#include <pch.h>

namespace WTGD
{
	class WTGD_API ITickable
	{
	public:
		/// <summary>
		/// Check if the tick is enabled
		/// </summary>
		/// <returns>Returns true if it is enabled, false otherswise</returns>
		bool is_tick_enabled()const { return tickable; }
		/// <summary>
		/// Enables the tick
		/// </summary>
		void enable_tick() { tickable = true; }
		/// <summary>
		/// Disables the tick
		/// </summary>
		void disable_tick() { tickable = false; }

	protected:
		/// <summary>
		/// Called every frame
		/// </summary>
		/// <param name="delta"></param>
		virtual void on_update(const float delta) = 0;
		virtual void on_fixed_update(const float delta_time) = 0;


	private:
		bool tickable = true;
	};
}

#endif ITICKABLE_H