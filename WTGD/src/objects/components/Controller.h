#ifndef CONTROLLER_H
#define CONTROLLER_H

#ifdef DLL_EXPORT
#define CONTROLLER_API __declspec(dllexport)
#else
#define CONTROLLER_API __declspec(dllimport)
#endif 

#include "Component.h"
#include <SFML/Graphics.hpp>

namespace WTGD
{
	class CONTROLLER_API Controller : public Component
	{
		friend class MovementComponent;
	public:
		/// <summary>
		/// Controller Default Constructor
		/// </summary>
		Controller();
		~Controller() override;
		/// <summary>
		/// Returns the current axis direction 
		/// </summary>
		[[nodiscard]] sf::Vector2f get_direction_vector()const { return sf::Vector2f(x_axis, y_axis); }

	protected:
		bool fw_movement;
		bool right_movement;
		float x_axis, y_axis, current_rotation = 0.0f;

		virtual void on_update(const float delta) override;
		void on_fixed_update(const float delta_time) override;

	};
}

#endif