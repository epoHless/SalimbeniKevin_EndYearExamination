#include "JoystickController.h"

void WTGD::JoystickController::on_update(const float delta)
{
	Controller::on_update(delta);

	if (sf::Joystick::isConnected(0))
	{
		
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) > 50.0f)
		{
			fw_movement = true;
			y_axis = 1;
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) < -50.0f)
		{
			fw_movement = true;
			y_axis = -1;
		}
		else
		{
			fw_movement = false;
			y_axis = 0;
		}

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) > 50.0f)
		{
			right_movement = true;
			x_axis = 1;
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) < -50.0f)
		{
			right_movement = true;
			x_axis = -1;
		}
		else
		{
			right_movement = false;
			x_axis = 0;
		}

		

		sf::Joystick::update();

		printf("X: %f, Y %f", sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX), sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY));
	}
}
