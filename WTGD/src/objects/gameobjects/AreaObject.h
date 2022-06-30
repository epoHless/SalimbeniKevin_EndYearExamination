#ifndef AREA_OBJECT_H
#define AREA_OBJECT_H

#include <pch.h>
#include <objects/gameobjects/Gameobject.h>
#include <objects/components/Transform.h>

namespace WTGD
{
	class WTGD_API AreaObject : public GameObject
	{
	public:
		/// <summary>
		/// AreaObject Default Constructor
		/// </summary>
		/// <param name="name"></param>
		/// <param name="is_active"></param>
		AreaObject(const std::string name, const bool is_active);
		/// <summary>
		/// AreaObject Default Destructor
		/// </summary>
		~AreaObject();

		Transform* transform;
	};
}

#endif