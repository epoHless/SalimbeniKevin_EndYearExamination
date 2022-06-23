#ifndef TRANSFORM_H
#define TRANSFORM_H

#ifdef DLL_EXPORT
#define TRANSFORM_API __declspec(dllexport)
#else
#define TRANSFORM_API __declspec(dllimport)
#endif  

#include "Component.h"
#include <SFML/Graphics.hpp>

namespace WTGD
{
	class TRANSFORM_API Transform : public Component
	{
	public:
		Transform();
		explicit Transform(
			sf::Vector2f position,
			float rotation,
			sf::Vector2f scale
		);
		~Transform() override;

		//Setters
		void set_position(float x, float y)const;
		void set_position(sf::Vector2f)const;

		void set_rotation(float angle)const;

		void set_scale(float x, float y)const;
		void set_scale(sf::Vector2f)const;

		//Getters
		sf::Vector2f get_position()const;
		sf::Vector2f get_scale()const;
		float get_rotation()const;

		[[nodiscard]] sf::RectangleShape* get_transform()const;		

	private:
		sf::Vector2f position;
		float rotation;
		sf::Vector2f scale;

		sf::RectangleShape* transform;

	public:
		//Operator overloads
		void operator+=(const sf::Vector2f b)
		{
			position.x += b.x;
			position.y += b.y;
		}

		void operator-=(const sf::Vector2f b)
		{
			position.x -= b.x;
			position.y -= b.y;
		}

		void operator*=(const sf::Vector2f b)
		{
			position.x *= b.x;
			position.y *= b.y;
		}

		void operator/=(const sf::Vector2f b)
		{
			position.x /= b.x;
			position.y /= b.y;
		}

		sf::Vector2f operator+(const sf::Vector2f& b)
		{
			sf::Vector2f temp = position;
			temp.x = position.x + b.x;
			temp.y = position.y + b.y;

			return temp;
		}

		sf::Vector2f operator-(const sf::Vector2f& b)
		{
			sf::Vector2f temp = position;
			temp.x = position.x - b.x;
			temp.y = position.y - b.y;

			return temp;
		}

		sf::Vector2f operator*(const sf::Vector2f& b)
		{
			sf::Vector2f temp = position;
			temp.x = position.x * b.x;
			temp.y = position.y * b.y;

			return temp;
		}

		sf::Vector2f operator/(const sf::Vector2f& b)
		{
			sf::Vector2f temp = position;
			temp.x = position.x / b.x;
			temp.y = position.y / b.y;

			return temp;
		}

		sf::Vector2f& operator--()
		{
			--position.x; --position.y;
			return position;
		}

		sf::Vector2f operator--(int)
		{
			sf::Vector2f temp = position;
			operator--();
			return temp;
		}

		sf::Vector2f& operator++()
		{
			++position.x; ++position.y;
			return position;
		}

		sf::Vector2f operator++(int)
		{
			sf::Vector2f temp = position;
			operator++();
			return temp;
		}
	};
}

#endif