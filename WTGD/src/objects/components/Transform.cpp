#include "Transform.h"

WTGD::Transform::Transform() : Component("Transform")
{
    disable(); //disable loop call

    

    position = sf::Vector2f(640, 320);
    scale = sf::Vector2f(1, 1);
    rotation = 0;

    transform = new sf::RectangleShape(scale);
    transform->setOrigin(position / 2.0f);
}

WTGD::Transform::Transform(sf::Vector2f position, float rotation, sf::Vector2f scale) : Component("Transform")
{
    disable();

    this->position = position;
    this->rotation = rotation;
    this->scale = scale;

    transform = new sf::RectangleShape(scale);
}

WTGD::Transform::~Transform()
{
    delete transform;
}

void WTGD::Transform::set_position(float x, float y) const
{
    transform->setPosition(x, y);
}

void WTGD::Transform::set_position(sf::Vector2f newPos) const
{
    transform->setPosition(newPos);
}

void WTGD::Transform::set_rotation(float angle) const
{
    
    transform->setRotation(angle);
}

void WTGD::Transform::set_scale(float x, float y) const
{
    transform->setScale(x, y);
}

void WTGD::Transform::set_scale(sf::Vector2f newScale) const
{
    transform->setScale(newScale);
}

sf::Vector2f WTGD::Transform::get_position() const
{
    return position;
}

sf::Vector2f WTGD::Transform::get_scale() const
{
    return scale;
}

float WTGD::Transform::get_rotation() const
{
    return rotation;
}

sf::RectangleShape* WTGD::Transform::get_transform() const
{
    return transform;
}
