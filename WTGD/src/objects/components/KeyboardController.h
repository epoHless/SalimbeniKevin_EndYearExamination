#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#ifdef DLL_EXPORT
#define KEYBOARD_CONTROLLER_API __declspec(dllexport)
#else
#define KEYBOARD_CONTROLLER_API __declspec(dllimport)
#endif 

#include "Controller.h"

namespace WTGD
{
	class KEYBOARD_CONTROLLER_API KeyboardController : public Controller
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