#include <pch.h>
#include "LoopManager.h"

namespace WTGD
{
	LoopManager::~LoopManager()
	{
		delete gameWindow;
		delete this;
	}

	void LoopManager::create_window(const float width, const float height, const char* title)
	{
		set_input_func([this](sf::Event) { this->base_input_func(); }, input_event);
		gameWindow = new sf::RenderWindow(sf::VideoMode(width, height), title);
	}

	void LoopManager::set_max_fps(unsigned newLimit)
	{
		maxFPS = newLimit;
	}

	unsigned LoopManager::get_fps() const
	{
		return 1 / elapsedTime;
	}

	void LoopManager::fps_limit_toggler()
	{
		isFpsLimited = !isFpsLimited;
	}

	void LoopManager::draw(const std::vector<GameObject*>& gameobjects) const
	{
		gameWindow->clear();

		/* To be filled with

			for all the entities in game
				get entity renderer
				draw the renderer
		*/

		for (const auto go : gameobjects)
		{
			for (const auto renders = go->get_components<Transform>(); const auto rend : renders)
			{
				gameWindow->draw(*rend->get_transform());
			}
		}

		gameWindow->display();
	}

	void LoopManager::update(const std::vector<GameObject*>& gameobjects) const
	{
		/* To be filled with

			for all the gameobjects in the game
				if is active and enabled
					update it

		*/

		for (GameObject* go : gameobjects)
		{
			if (go->is_tick_enabled() && go->is_active) go->on_update(elapsedTime);
		}
	}

	void LoopManager::fixed_update(const std::vector<GameObject*>& gameobjects) const
	{
		for (GameObject* go : gameobjects)
		{
			if (go->is_tick_enabled() && go->is_active) go->on_fixed_update(elapsedTime);

			if (auto* collider = go->get_component<Collider>())
			{
				collider->check_collision(activeColliders);
			}
		}
	}

	void LoopManager::run(const std::vector<GameObject*>& gameobjects)
	{
		lastTime = timeManager.get_current_time();
		while (gameWindow->isOpen())
		{
			updateGameTime();
			printf("FPS %i\n", get_fps());

			pollEvents();

			if (fixedUpdateEnabled)
			{
				while (lag >= msForFixedUpdate)
				{
					fixed_update(gameobjects);
					lag -= msForFixedUpdate;
				}
			}

			update(gameobjects);
			draw(gameobjects);

			if (isFpsLimited)
			{
				sf::sleep(sf::seconds(1.0f / maxFPS));
			}
		}
	}

	void LoopManager::pollEvents() const
	{
		sf::Event evt = input_event;
		while (gameWindow->pollEvent(evt))
		{
			input_func(evt);

			if (evt.type == sf::Event::EventType::Closed)
			{
				gameWindow->close();
			}
		}
	}

	void LoopManager::updateGameTime()
	{
		currentTime = timeManager.get_current_time();
		elapsedTime = TimeManager::get_elapsed_time(currentTime.asSeconds(), lastTime.asSeconds());
		lastTime = currentTime;
		lag += elapsedTime;
	}

	void LoopManager::add_colliders(std::vector<GameObject*> gameobjects)
	{
		for (GameObject* go : gameobjects)
		{
			Collider* collider = go->get_component<Collider>();
			if (collider)
			{
				if (collider->is_enabled())
				{
					activeColliders.push_back(collider);
				}
			}
		}
	}
}
