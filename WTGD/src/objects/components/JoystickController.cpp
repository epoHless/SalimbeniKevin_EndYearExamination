#include "JoystickController.h"

void WTGD::JoystickController::on_update(const float delta)
{
	Controller::on_update(delta);

	if (sf::Joystick::isButtonPressed(0, 0))
	{
		fw_movement = true;
		y_axis = -1;
	}
	else if (sf::Joystick::isButtonPressed(0, 3))
	{
		fw_movement = true;
		y_axis = 1;
	}
	else
	{
		fw_movement = false;
		y_axis = 0;
	}

	if (sf::Joystick::isButtonPressed(0, 1))
	{
		right_movement = true;
		x_axis = 1;
	}
	else if (sf::Joystick::isButtonPressed(0, 2))
	{
		right_movement = true;
		x_axis = -1;
	}
	else
	{
		right_movement = false;
		x_axis = 0;
	}
}
