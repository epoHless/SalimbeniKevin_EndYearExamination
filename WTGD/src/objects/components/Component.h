#ifndef COMPONENT_H
#define COMPONENT_H

#ifdef DLL_EXPORT
#define COMPONENT_API __declspec(dllexport)
#else
#define COMPONENT_API __declspec(dllimport)
#endif  

#include <string>
#include "../Object.h"
#include "../../interfaces/ITickable.h"

namespace WTGD
{
	class COMPONENT_API Component : public Object, public ITickable
	{
		friend class GameObject;
	public:
		Component(const std::string name, const bool is_active = true) : Object(name, is_active){}
		virtual ~Component() = default;

		[[nodiscard]] GameObject* get_owner()const { return owner; }

	protected:
		// Inherited via ITickable
		virtual void on_update(const float delta) override;

	private:
		GameObject* owner = nullptr;
	};
}

#endif COMPONENT_H

