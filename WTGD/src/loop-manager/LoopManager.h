#ifndef LOOP_MANAGER_H
#define LOOP_MANAGER_H

#include <pch.h>
#include <time-manager/TimeManager.h>
#include <objects/gameobjects/Gameobject.h>
#include <objects/components/KeyboardController.h>
#include <objects/components/JoystickController.h>
#include <objects/components/Collider.h>
#include <objects/gameobjects/Character.h>


namespace WTGD
{
	class WTGD_API LoopManager
	{
	//Constructors / Destructor
	public:
		/// <summary>
		/// Default Loop Manager Contructor
		/// </summary>
		LoopManager() : gameWindow(nullptr) {};
		/// <summary>
		/// Default Loop Manager Destructor
		/// </summary>
		~LoopManager();

	//Public Functions
	public:

		/// <summary>
		/// Creates the game window
		/// </summary>
		void create_window(const float width, const float height, const char* title);

		/// <summary>
		/// Change the amount of max FPS for the game window (standard is 60 FPS)
		/// </summary>
		/// <param name="newLimit">The new FPS limit</param>
		void set_max_fps(unsigned newLimit);

		/// <summary>
		/// Returns the current frame's FPS
		/// </summary>
		/// <returns></returns>
		unsigned get_fps()const;

		/// <summary>
		/// Toggle the FPS limit ON or OFF depending on the current setting
		/// </summary>
		void fps_limit_toggler();

		/// <summary>
		/// Draws the registered GameObjects on the screen
		/// </summary>
		void draw(const std::vector<GameObject*>& gameobjects) const;
		/// <summary>
		/// Updates the registered GameObjects on the screen
		/// </summary>
		/// <param name="gameobjects"></param>
		void update(const std::vector<GameObject*>& gameobjects) const;
		/// <summary>
		/// Updates the registeres GameObjects on the screen with a fixed update
		/// </summary>
		/// <param name="gameobjects"></param>
		void fixed_update(const std::vector<GameObject*>& gameobjects) const;
		/// <summary>
		/// Call this function to run the main loop
		/// </summary>
		/// <param name="gameobjects"></param>
		void run(const std::vector<GameObject*>& gameobjects);
		/// <summary>
		/// Reacts to events
		/// </summary>
		void pollEvents(/*std::function<void(sf::Event)>, sf::Event evt*/) const;
		/// <summary>
		/// Updates the game time
		/// </summary>
		void updateGameTime();
		/// <summary>
		/// Adds the GameObjects colliders to the activeColliders vector
		/// </summary>
		/// <param name="gameobjects">GameObjects' colliders to add</param>
		void add_colliders(std::vector<GameObject*> gameobjects);

		/// <summary>
		/// Set the desired event to check during runtime
		/// </summary>
		/// <param name="func">Function to point</param>
		/// <param name="evt">sf::Event to pass</param>
		void set_input_func(std::function<void(sf::Event)> func, sf::Event evt) { input_func = func; input_event = evt; }
		/// <summary>
		/// Empty function used when the custom input function is unused
		/// </summary>
		void base_input_func() {}

		/// <summary>
		/// Set the target frames for the fixed update
		/// </summary>
		/// <param name="new_ms"></param>
		void set_ms_for_fixed_update(float new_ms) { msForFixedUpdate = new_ms; }

	//Private Members
	public:
		sf::RenderWindow* gameWindow;

		unsigned maxFPS = 60;
		bool isFpsLimited = true;

		WTGD::TimeManager timeManager;
		float elapsedTime = 0.0f;
		sf::Time lastTime, currentTime;

		float lag = 0.0f;
		bool fixedUpdateEnabled = true;
		float msForFixedUpdate = 0.016f;

		std::function<void(sf::Event)> input_func = nullptr;
		sf::Event input_event{};

		std::vector<Collider*> activeColliders;
	};
}

#endif LOOP_MANAGER_H

