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
		/// <summary>
		/// Default Character Constructor
		/// </summary>
		/// <param name="input">Input method (i.e. KeyboardController or JoystickController)</param>
		/// <param name="name">This object name</param>
		/// <param name="is_active">Should be enabled</param>
		Character(Controller* input, const std::string name, const bool is_active = true);
		~Character();

	protected:
		void on_update(const float delta) override;
		void on_fixed_update(const float delta_time) override;

	public:
		/// <summary>
		/// Set the input method runtime
		/// </summary>
		/// <param name="input">the new input method</param>
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