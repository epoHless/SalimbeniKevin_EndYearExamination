#include "WorldObject.h"

WTGD::WorldObject::WorldObject() : AreaObject()
{
	renderer = new Renderer();
	add_component(renderer);
}

WTGD::WorldObject::~WorldObject()
{
	delete transform;
	delete renderer;
}
