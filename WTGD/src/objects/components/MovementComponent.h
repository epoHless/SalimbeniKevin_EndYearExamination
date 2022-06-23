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
		MovementComponent();
		~MovementComponent() override;

		[[nodiscard]] bool is_moving()const 
		{ 
			return(controller->fw_movement || controller->right_movement); 
		}

		void set_speed(const float new_speed) { speed = new_speed; }

		[[nodiscard]] sf::Vector2f get_velocity()const;
		[[nodiscard]] sf::Vector2f get_direction()const;

		Controller* controller;
		Transform* transform;

		float speed = 10;

		void on_update(const float delta) override;
	};
}

#endif