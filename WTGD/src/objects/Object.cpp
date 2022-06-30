#include <pch.h>
#include <objects/Object.h>

WTGD::Object::Object(const std::string name, bool is_active)
{
	this->name = name;
	this->is_active = is_active;
}
