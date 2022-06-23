#include "KeyboardController.h"

void WTGD::KeyboardController::on_update(const float delta)
{
	Controller::on_update(delta);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		fw_movement = true;
		y_axis = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		fw_movement = true;
		y_axis = 1;
	}
	else
	{
		fw_movement = false;
		y_axis = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		right_movement = true;
		x_axis = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		right_movement = true;
		x_axis = -1;
	}
	else
	{
		right_movement = false;
		x_axis = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		current_rotation += 2.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		current_rotation -= 2.0f;
	}
}
