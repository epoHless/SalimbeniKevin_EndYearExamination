#ifndef JOYSTICK_CONTROLLER_H
#define JOYSTICK_CONTROLLER_H

#include <pch.h>
#include <objects/components/Controller.h>

namespace WTGD
{
	class WTGD_API JoystickController : public Controller
	{
	public:
		/// <summary>
		/// Default Joystick Constructor
		/// </summary>
		JoystickController() = default;
	protected:
		// Inherited via Controller
		virtual void on_update(const float delta) override;
	};
}
#endif