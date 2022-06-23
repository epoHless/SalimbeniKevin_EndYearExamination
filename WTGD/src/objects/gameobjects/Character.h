#ifndef CHARACTER_H
#define CHARACTER_H

#ifdef DLL_EXPORT
#define CHARACTER_API __declspec(dllexport)
#else
#define CHARACTER_API __declspec(dllimport)
#endif 

#include "WorldObject.h"
#include "../components/Controller.h"
#include "../components/KeyboardController.h"
#include "../components/MovementComponent.h"

namespace WTGD
{
	class CHARACTER_API Character : public WorldObject
	{
		friend class LoopManager;
	public:
		Character(Controller* input, const std::string name, const bool is_active = true);
		//Character(const std::string name, const bool is_active = true);
		~Character();

	protected:
		void on_update(const float delta) override;

	public:

		void set_controller(Controller* input) 
		{ 
			controller = input;
			add_component(controller);
		}

		Controller* controller;
		MovementComponent* movementComponent;
	};
}

#endif