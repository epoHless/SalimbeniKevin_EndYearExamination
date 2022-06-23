#include "AreaObject.h"

WTGD::AreaObject::AreaObject() : GameObject("Area Object")
{
	transform = new Transform();
	transform->set_scale(50, 50);
	
	add_component(transform);
}

WTGD::AreaObject::~AreaObject()
{
	delete transform;
}
