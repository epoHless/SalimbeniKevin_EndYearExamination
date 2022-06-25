#include "WorldObject.h"


WTGD::WorldObject::WorldObject(const std::string name, const bool is_active) : AreaObject(name, is_active)
{
	this->name = name;
	this->is_active = is_active;

	collider = new Collider(transform->get_transform());
	add_component(collider);

	renderer = new Renderer();
	add_component(renderer);
}

WTGD::WorldObject::~WorldObject()
{
	delete transform;
	delete renderer;
}
