#include "Collider.h"

WTGD::Collider::Collider(sf::RectangleShape* body, bool enabled) : Component("Collider")
{
	collision_enabled = enabled;

	this->body = body;
	body->setSize(body->getSize());
	body->setOrigin(body->getSize() / 2.0f);
	body->setPosition(body->getPosition());
	body->setScale(body->getScale());
	enable_tick();
}

bool WTGD::Collider::check_collision(std::vector<Collider*> others, float push)
{
	for (Collider* other : others)
	{
		sf::Vector2f otherPosition = other->get_position();
		sf::Vector2f otherHalfSize = other->get_half_size();
		sf::Vector2f thisPosition = get_position();
		sf::Vector2f thisHalfSize = get_half_size();

		float deltaX = otherPosition.x - thisPosition.x;
		float deltaY = otherPosition.y - thisPosition.y;

		float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
		float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

		if (intersectX < 0.0f && intersectY < 0.0f)
		{
			push = std::min(std::max(push, 0.0f), 1.0f);

			if (intersectX > intersectY)
			{
				if (deltaX > 0.0f)
				{
					Move(intersectX * (1.0f - push), 0.0f);
					other->Move(-intersectX * push, 0.0f);
				}
				else
				{
					Move(-intersectX * (1.0f - push), 0.0f);
					other->Move(intersectX * push, 0.0f);
				}
			}
			else
			{
				if (deltaY > 0.0f)
				{
					Move(0.0f, intersectY * (1.0f - push));
					other->Move(0.0f, -intersectY * push);
				}
				else
				{
					Move(0.0f, -intersectY * (1.0f - push));
					other->Move(0.0f, intersectY * push);
				}
			}

			return true;
		}
	}
}

void WTGD::Collider::on_update(const float delta)
{
}
