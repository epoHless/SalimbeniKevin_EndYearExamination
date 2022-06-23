#include "KeyboardController.h"

void WTGD::KeyboardController::on_update(const float delta)
{
	Component::on_update(delta);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		fw_movement = true;
		y_axis = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		fw_movement = true;
		y_axis = 1;
	}
	else
	{
		fw_movement = false;
		y_axis = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		right_movement = true;
		x_axis = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
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
