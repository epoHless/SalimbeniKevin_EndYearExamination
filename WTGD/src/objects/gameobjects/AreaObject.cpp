#include "AreaObject.h"

WTGD::AreaObject::AreaObject(const std::string name, const bool is_active) : GameObject(name, is_active)
{
	this->name = name;
	this->is_active = is_active;

	transform = new Transform();
	transform->set_scale(50, 50);
	transform->get_transform()->setFillColor(sf::Color::White);

	add_component(transform);
}

WTGD::AreaObject::~AreaObject()
{
	delete transform;
}
