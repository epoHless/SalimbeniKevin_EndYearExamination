#ifndef CHARACTER_H
#define CHARACTER_H

#ifdef DLL_EXPORT
#define CHARACTER_API __declspec(dllexport)
#else
#define CHARACTER_API __declspec(dllimport)
#endif 

#include "WorldObject.h"

namespace WTGD
{
	class CHARACTER_API Character : public WorldObject
	{
	
	};
}

#endif