#include "Component.h"

void WTGD::Component::on_update(const float delta)
{
	/*
		Call Component Update Here!
	*/

	printf("Component : %s is running! | ", this->get_name().c_str());
}
