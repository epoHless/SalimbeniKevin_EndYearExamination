#ifndef COMPONENT_H
#define COMPONENT_H

#include <pch.h>
#include <objects/Object.h>
#include <objects/gameobjects/Gameobject.h>
#include <interfaces/ITickable.h>

namespace WTGD
{
	class WTGD_API Component : public Object, public ITickable
	{
		friend class GameObject;
	public:
		/// <summary>
		/// Component Default Constructor
		/// </summary>
		/// <param name="name">Component's name</param>
		/// <param name="is_active">Should be active</param>
		Component(const std::string name, const bool is_active = true) : Object(name, is_active){}
		virtual ~Component() = default;

		/// <summary>
		/// Returns the owning GameObject
		/// </summary>
		[[nodiscard]] GameObject* get_owner()const { return owner; }

	protected:
		// Inherited via ITickable
		virtual void on_update(const float delta) override;
		virtual void on_fixed_update(const float delta_time) override;


	private:
		GameObject* owner = nullptr;
	};
}

#endif COMPONENT_H

