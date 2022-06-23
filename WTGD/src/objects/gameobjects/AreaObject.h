#ifndef AREA_OBJECT_H
#define AREA_OBJECT_H

#ifdef DLL_EXPORT
#define AREA_OBJECT_API __declspec(dllexport)
#else
#define AREA_OBJECT_API __declspec(dllimport)
#endif 

#include "GameObject.h"
#include "../components/Transform.h"

namespace WTGD
{
	class AREA_OBJECT_API AreaObject : public GameObject
	{
	public:
		AreaObject(const std::string name, const bool is_active);
		~AreaObject();

		Transform* transform;
	};
}

#endif