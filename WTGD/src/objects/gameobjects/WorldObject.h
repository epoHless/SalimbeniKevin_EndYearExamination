#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#ifdef DLL_EXPORT
#define WORLD_OBJECT_API __declspec(dllexport)
#else
#define WORLD_OBJECT_API __declspec(dllimport)
#endif 

#include "AreaObject.h"
#include "../components/Renderer.h"

namespace WTGD
{
    class WorldObject : public AreaObject
    {
    public:
        WorldObject();
        ~WorldObject();

        Renderer* renderer;
    };
}

#endif