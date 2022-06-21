#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#ifdef DLL_EXPORT
#define GAMEOBJECT_API __declspec(dllexport)
#else
#define GAMEOBJECT_API __declspec(dllimport)
#endif

#include <string>
#include <vector>

#include "../Object.h"
#include "../../interfaces/ITickable.h"
#include "../components/Component.h"

class Component;

namespace WTGD 
{
	class GAMEOBJECT_API GameObject : public Object, public ITickable
	{
		friend class LoopManager;
	public:
		GameObject(const std::string name, const bool active = true);
		GameObject(const std::string name, const std::vector<Component*> components,const bool active = true);
		~GameObject() = default;

		void add_component(Component* component);
		void remove_component(Component* component);

		template<class T, class = Component> T* get_component()const
		{
			if (components.size() == 0) return nullptr;

			for (Component* comp : components)
			{
				const auto val = dynamic_cast<T*>(comp);
				if (!val) continue;

				return val;
			}
			return nullptr;
		}

		template<class T, class = Component> std::vector<T*> get_components()const
		{
			std::vector<T*> output;

			if (components.size() == 0) return nullptr;

			for each (Component * comp in this->components)
			{
				const auto val = dynamic_cast<T*>(comp);
				if (!val) continue;

				output.push_back(val);
			}
			return output;
		}

	protected:
		// Inherited via ITickable
		virtual void on_update(const float delta) override;

	private:
		std::vector<Component*> components;

	};
}

#endif GAMEOBJECT_H
