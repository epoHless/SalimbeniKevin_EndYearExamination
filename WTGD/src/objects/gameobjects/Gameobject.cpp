#include "Gameobject.h"

WTGD::GameObject::GameObject(const std::string name, const bool is_active) : Object(name, is_active)
{
	this->name = name;
	this->is_active = is_active;
}

WTGD::GameObject::GameObject(const std::string name, const std::vector<Component*> components, const bool is_active) : Object(name, is_active)
{
	this->name = name;
	this->components = components;
	this->is_active = is_active;
}

void WTGD::GameObject::add_component(Component* component)
{
	component->owner = this;
	components.push_back(component);
}

void WTGD::GameObject::remove_component(Component* component)
{
	components.erase(std::remove(components.begin(), components.end(), component), components.end());
}

void WTGD::GameObject::on_update(const float delta_time)
{
	for (auto item : components)
	{
		if (item->is_active && item->is_tick_enabled()) { item->on_update(delta_time); }
	}
}