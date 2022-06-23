#ifndef JOYSTICK_CONTROLLER_H
#define JOYSTICK_CONTROLLER_H

#ifdef DLL_EXPORT
#define JOYSTICK_CONTROLLER_API __declspec(dllexport)
#else
#define JOYSTICK_CONTROLLER_API __declspec(dllimport)
#endif 

#include "Controller.h"

namespace WTGD
{
	class JOYSTICK_CONTROLLER_API JoystickController : public Controller
	{
	public:
		JoystickController() = default;
	protected:
		// Inherited via Controller
		virtual void on_update(const float delta) override;
	};
}
#endif