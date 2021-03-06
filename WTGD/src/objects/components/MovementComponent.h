#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#ifdef DLL_EXPORT
#define MOVEMENT_COMPONENT_API __declspec(dllexport)
#else
#define MOVEMENT_COMPONENT_API __declspec(dllimport)
#endif 

#include "Component.h"
#include "Controller.h"
#include "Transform.h"

namespace WTGD
{
	class MOVEMENT_COMPONENT_API MovementComponent : public Component
	{
	public:
		/// <summary>
		/// Default Movement Controller
		/// </summary>
		MovementComponent();
		~MovementComponent() override;

		/// <summary>
		/// Checks if the controller is moving
		/// </summary>
		[[nodiscard]] bool is_moving()const 
		{ 
			return(controller->fw_movement || controller->right_movement); 
		}

		/// <summary>
		/// Set the speed of the object
		/// </summary>
		/// <param name="new_speed">New speed to set</param>
		void set_speed(const float new_speed) { movement_speed = new_speed; }
		/// <summary>
		/// Returns the component's velocity
		/// </summary>
		[[nodiscard]] sf::Vector2f get_velocity()const;
		/// <summary>
		/// Returns the component's direction
		/// </summary>
		[[nodiscard]] sf::Vector2f get_direction()const;

		Controller* controller;
		Transform* transform;

		float movement_speed = 100.0f;
		float rotation_speed = 5.0f;

		void on_update(const float delta) override;
	};
}

#endif