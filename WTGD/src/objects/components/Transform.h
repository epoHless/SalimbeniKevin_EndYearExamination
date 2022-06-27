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
		/// <summary>
		/// Default Transform Constructor
		/// </summary>
		Transform();
		explicit Transform(
			sf::Vector2f position,
			float rotation,
			sf::Vector2f scale
		);
		/// <summary>
		/// Default Transform Destructor
		/// </summary>
		~Transform() override;

		//Setters
		
		/// <summary>
		/// Sets this object current position
		/// </summary>
		/// <param name="x">X position</param>
		/// <param name="y">Y position</param>
		void set_position(float x, float y)const;
		/// <summary>
		/// Sets this object current position
		/// </summary>
		/// <param name="">Vector2f position</param>
		void set_position(sf::Vector2f)const;
		/// <summary>
		/// Sets this object current rotation
		/// </summary>
		/// <param name="angle"></param>
		void set_rotation(float angle)const;
		/// <summary>
		/// Sets this object current scale
		/// </summary>
		/// <param name="x">X scale</param>
		/// <param name="y">Y scale</param>
		void set_scale(float x, float y)const;
		/// <summary>
		/// Sets this object current scale
		/// </summary>
		/// <param name="">Vector2f scale</param>
		void set_scale(sf::Vector2f)const;

		//Getters

		/// <summary>
		/// Get this object current position
		/// </summary>
		/// <returns>The current position</returns>
		sf::Vector2f get_position()const;
		/// <summary>
		/// Get this object current scale
		/// </summary>
		/// <returns>The current scale</returns>
		sf::Vector2f get_scale()const;
		/// <summary>
		/// Get this object current rotation
		/// </summary>
		/// <returns>The current rotation</returns>
		float get_rotation()const;

		/// <summary>
		/// Get this object transform
		/// </summary>
		[[nodiscard]] sf::RectangleShape* get_transform()const;		

	private:
		sf::Vector2f position;
		float rotation;
		sf::Vector2f scale;

		sf::RectangleShape* transform;

	public:
		//Operator overloads

		/// <summary>
		/// Adds B to this position
		/// </summary>
		/// <param name="b">Value to add</param>
		void operator+=(const sf::Vector2f b)
		{
			position.x += b.x;
			position.y += b.y;
		}
		/// <summary>
		/// Subtract B to this position
		/// </summary>
		/// <param name="b">Value to subtract</param>
		void operator-=(const sf::Vector2f b)
		{
			position.x -= b.x;
			position.y -= b.y;
		}

		/// <summary>
		/// Multiplies B to this position
		/// </summary>
		/// <param name="b">Value to multiply</param>
		void operator*=(const sf::Vector2f b)
		{
			position.x *= b.x;
			position.y *= b.y;
		}
		/// <summary>
		/// Divides B to this position
		/// </summary>
		/// <param name="b">Value to divide</param>
		void operator/=(const sf::Vector2f b)
		{
			position.x /= b.x;
			position.y /= b.y;
		}
		/// <summary>
		/// Adds B to this position
		/// </summary>
		/// <param name="b">Value to add</param>
		sf::Vector2f operator+(const sf::Vector2f& b)
		{
			sf::Vector2f temp = position;
			temp.x = position.x + b.x;
			temp.y = position.y + b.y;

			return temp;
		}
		/// <summary>
		/// Subtract B to this position
		/// </summary>
		/// <param name="b">Value to subtract</param>
		sf::Vector2f operator-(const sf::Vector2f& b)
		{
			sf::Vector2f temp = position;
			temp.x = position.x - b.x;
			temp.y = position.y - b.y;

			return temp;
		}
		/// <summary>
		/// Multiplies B to this position
		/// </summary>
		/// <param name="b">Value to multiply</param>
		sf::Vector2f operator*(const sf::Vector2f& b)
		{
			sf::Vector2f temp = position;
			temp.x = position.x * b.x;
			temp.y = position.y * b.y;

			return temp;
		}
		/// <summary>
		/// Divides B to this position
		/// </summary>
		/// <param name="b">Value to divide</param>
		sf::Vector2f operator/(const sf::Vector2f& b)
		{
			sf::Vector2f temp = position;
			temp.x = position.x / b.x;
			temp.y = position.y / b.y;

			return temp;
		}		
		/// <summary>
		/// Decrements the current vector
		/// </summary>
		/// <returns></returns>
		sf::Vector2f& operator--()
		{
			--position.x; --position.y;
			return position;
		}
		/// <summary>
		/// Decrements the current vector
		/// </summary>
		/// <returns></returns>
		sf::Vector2f operator--(int)
		{
			sf::Vector2f temp = position;
			operator--();
			return temp;
		}
		/// <summary>
		/// Increments the current vector
		/// </summary>
		/// <returns></returns>
		sf::Vector2f& operator++()
		{
			++position.x; ++position.y;
			return position;
		}
		/// <summary>
		/// Increments the current vector
		/// </summary>
		/// <returns></returns>
		sf::Vector2f operator++(int)
		{
			sf::Vector2f temp = position;
			operator++();
			return temp;
		}
	};
}

#endif