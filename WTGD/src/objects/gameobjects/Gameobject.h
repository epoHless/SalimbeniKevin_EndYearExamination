#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#ifdef DLL_EXPORT
#define GAMEOBJECT_API __declspec(dllexport)
#else
#define GAMEOBJECT_API __declspec(dllimport)
#endif

#include <string>

namespace WTGD 
{
	class GAMEOBJECT_API GameObject
	{
	public:
		std::string name;

	};
}

#endif GAMEOBJECT_H
