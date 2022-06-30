#include "GameManager.h"
#include <iostream>

void GameManager::run()
{
	initialize();

	_manager->run(gameobjects);
}

void GameManager::initialize()
{	

	WTGD::Character* player = new WTGD::Character(new WTGD::KeyboardController(), "Player");
	//player->renderer->set_texture("res\\pacman.png");
	player->transform->set_scale(100, 100);
	player->transform->set_position(640, 360);
	player->set_tag("Player");
	gameobjects.push_back(player);


	WTGD::WorldObject* square = new WTGD::WorldObject("Cube 1", true);
	square->transform->set_scale(100, 100);
	square->transform->set_position(500, 100);
	square->set_tag("Enviroment");


	WTGD::WorldObject* square1 = new WTGD::WorldObject("Cube 2", true);
	square1->transform->set_scale(100, 100);
	square1->transform->set_position(100, 100);
	square1->set_tag("Enviroment");

	gameobjects.push_back(square);
	gameobjects.push_back(square1);

	auto vals = WTGD::Utility::get_gameobjects_by_tag(gameobjects, "Player");

	for (WTGD::GameObject* obj : vals)
	{
		printf("Found object of class named %s", obj->get_name().c_str());
	}

	_manager->add_colliders(gameobjects);

	_manager->create_window(1280, 720, "Title");
}

