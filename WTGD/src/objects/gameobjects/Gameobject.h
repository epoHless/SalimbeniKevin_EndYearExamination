#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <pch.h>
#include <objects/Object.h>
#include <interfaces/ITickable.h>
#include <objects/components/Component.h>

class Component;

namespace WTGD 
{
	class WTGD_API GameObject : public Object, public ITickable
	{
		friend class LoopManager;
	public:
		/// <summary>
		/// Default GameObject Contructor
		/// </summary>
		/// <param name="name">This object name</param>
		/// <param name="active">Should be enabled</param>
		GameObject(const std::string name, const bool active = true);
		/// <summary>
		/// Additional Contructor, components enabled
		/// </summary>
		/// <param name="name">This object name</param>
		/// <param name="components">The components to add</param>
		/// <param name="active">Should be enabled</param>
		GameObject(const std::string name, const std::vector<Component*> components,const bool active = true);
		~GameObject() = default;

		/// <summary>
		/// Add a component to this object
		/// </summary>
		/// <param name="component">The component to add</param>
		void add_component(Component* component);

		/// <summary>
		/// DEPRECATED | Remove a component from this object
		/// </summary>
		/// <param name="component">The component to remove</param>
		void remove_component_depr(Component* component);

		/// <summary>
		/// Remove a component from this object
		/// </summary>
		/// <typeparam name="T">Component Class</typeparam>
		/// <typeparam name=""></typeparam>
		template<class T, class = Component>
		void remove_component()
		{
			if (components.size() == 0) return;

			for (Component* comp : components)
			{
				const auto val = dynamic_cast<T*>(comp);

				if(!val)
				{
					printf("no component found!");
					continue;
				}
				else
				{
					components.erase(std::remove(components.begin(), components.end(), val), components.end());
				}
			}
		}

		/// <summary>
		/// Get a component by class
		/// </summary>
		/// <typeparam name="T">Component class</typeparam>
		/// <typeparam name=""></typeparam>
		/// <returns></returns>
		template<class T, class = Component> 
		T* get_component()const
		{
			if (components.size() == 0) return nullptr;

			for (Component* comp : components)
			{
				T* val = nullptr;
				val = reinterpret_cast<T*>(comp);
				if (!val) continue;

				return val;
			}
			return nullptr;
		}

		/// <summary>
		/// Get all the components of a given class in this object
		/// </summary>
		/// <typeparam name="T">Component class</typeparam>
		/// <typeparam name=""></typeparam>
		/// <returns></returns>
		template<class T, class = Component>
		std::vector<T*> get_components()const
		{
			std::vector<T*> output;

			if (components.size() == 0) return output;

			for (Component * comp : this->components)
			{
				const auto val = dynamic_cast<T*>(comp);
				if (!val) continue;

				output.push_back(val);
			}

			return output;
		}

		void set_tag(std::string new_tag) { tag = new_tag; }
		[[nodiscard]] std::string get_tag()const { return tag; }

	protected:
		// Inherited via ITickable
		virtual void on_update(const float delta) override;
		virtual void on_fixed_update(const float delta_time) override;

		std::string tag;

	private:
		std::vector<Component*> components;

	};
}

#endif GAMEOBJECT_H
