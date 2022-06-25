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
		/// <summary>
		/// Default Collider Constructor
		/// </summary>
		/// <param name="body">GameObjets' transform</param>
		/// <param name="enabled">Should be enabled from start</param>
		Collider(sf::RectangleShape* transform, bool enabled = true);

		void Move(float dx, float dy) { body->move(dx, dy); }
		/// <summary>
		/// Returns true if this collider is colliding with another collider
		/// </summary>
		/// <param name="others">other octive colliders</param>
		/// <param name="push">push force</param>
		/// <returns>Overlap condition</returns>
		bool check_collision(std::vector<Collider*> others, float push);
		/// <summary>
		/// Get the collider position
		/// </summary>
		/// <returns>collider position</returns>
		sf::Vector2f get_position() { return body->getPosition(); }
		/// <summary>
		/// Get the collider's half size
		/// </summary>
		/// <returns>collider's half size</returns>
		sf::Vector2f get_half_size() { return body->getSize() / 2.0f; }

		/// <summary>
		/// Enables the collision
		/// </summary>
		void enable_collision() { collision_enabled = true; }
		/// <summary>
		/// Disables the collision
		/// </summary>
		void disable_collision() { collision_enabled = false; }
		/// <summary>
		/// Checks if the collider is enabled
		/// </summary>
		[[nodiscard]] bool is_enabled()const { return collision_enabled; }
		/// <summary>
		/// Returns the collider
		/// </summary>
		[[nodiscard]] sf::RectangleShape* get_body()const { return body; }

	protected:
		virtual void on_update(const float delta) override;

	private:
		sf::RectangleShape* body;
		bool collision_enabled;
	};
}
#endif