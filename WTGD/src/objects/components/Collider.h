#ifndef COLLIDER_H
#define COLLIDER_H

#ifdef DLL_EXPORT
#define COLLIDER_API __declspec(dllexport)
#else
#define COLLIDER_API __declspec(dllimport)
#endif 

#include <SFML/Graphics.hpp>
#include "Component.h"
#include <vector>

namespace WTGD
{
	class COLLIDER_API Collider : public Component
	{
	public:
		Collider(sf::RectangleShape* body, bool enabled = true);

		void Move(float dx, float dy) { body->move(dx, dy); }

		bool check_collision(std::vector<Collider*> others, float push);
		sf::Vector2f get_position() { return body->getPosition(); }
		sf::Vector2f get_half_size() { return body->getSize() / 2.0f; }

		void enable_collision() { collision_enabled = true; }
		void disable_collision() { collision_enabled = false; }

		[[nodiscard]] bool is_enabled()const { return collision_enabled; }

	protected:
		virtual void on_update(const float delta) override;

	private:
		sf::RectangleShape* body;
		bool collision_enabled;
	};
}
#endif