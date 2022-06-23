#include "MovementComponent.h"

WTGD::MovementComponent::MovementComponent() : Component("Movement Component")
{
}

WTGD::MovementComponent::~MovementComponent()
{
	delete controller;
	delete transform;
}

sf::Vector2f WTGD::MovementComponent::get_velocity() const
{
	sf::Vector2f direction = controller->get_direction_vector();
	return sf::Vector2f(direction.x * speed, direction.y * speed);
}

sf::Vector2f WTGD::MovementComponent::get_direction() const
{
	const sf::Vector2f velocity = get_velocity();
	const float length = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

	if (length == 0.0f) return { 0,0 };

	return { velocity.x / length, velocity.y / length };
}

void WTGD::MovementComponent::on_update(const float delta)
{
	if (!is_moving()) return;

	auto nextPosition = transform->get_transform()->getPosition() + sf::Vector2f(get_velocity().x * speed * delta, get_velocity().y * speed * delta);

	transform->set_position(nextPosition.x, nextPosition.y);
}
