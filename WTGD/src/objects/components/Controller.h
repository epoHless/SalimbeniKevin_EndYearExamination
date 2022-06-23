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
	public:
		Controller();
		~Controller() override;

	protected:
		bool fw_movement;
		bool right_movement;
		float x_axis, y_axis;

		void on_update(const float delta) override = 0;
	};
}

#endif