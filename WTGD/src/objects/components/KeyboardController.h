#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include <pch.h>
#include <objects/components/Controller.h>

namespace WTGD
{
	class WTGD_API KeyboardController : public Controller
	{
	public:
		/// <summary>
		/// Defualt Keyboard Controller
		/// </summary>
		KeyboardController();
	protected:
		// Inherited via Controller
		virtual void on_update(const float delta) override;
	};
}
#endif