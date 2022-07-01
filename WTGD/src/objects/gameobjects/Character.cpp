#include <pch.h>
#include <objects/gameobjects/Character.h>

WTGD::Character::Character(Controller* input, const std::string name, const bool is_active) : WorldObject(name, is_active)
{
	this->name = name;
	this->is_active = is_active;	

	controller = input;
	add_component(controller);

	movementComponent = new MovementComponent();
	movementComponent->controller = controller;
	movementComponent->transform = transform;
	add_component(movementComponent);
}

WTGD::Character::~Character()
{
	delete controller;
	delete movementComponent;
	delete renderer;
	delete transform;
}

void WTGD::Character::on_update(const float delta)
{
	WorldObject::on_update(delta);
}

void WTGD::Character::on_fixed_update(const float delta_time)
{
	WTGD::WorldObject::on_fixed_update(delta_time);
}
