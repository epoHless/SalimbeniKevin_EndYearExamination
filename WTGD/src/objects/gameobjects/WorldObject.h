#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#ifdef DLL_EXPORT
#define WORLD_OBJECT_API __declspec(dllexport)
#else
#define WORLD_OBJECT_API __declspec(dllimport)
#endif 

#include "AreaObject.h"
#include "../components/Renderer.h"
#include "../components/Collider.h"

namespace WTGD
{
    class WORLD_OBJECT_API WorldObject : public AreaObject
    {
    public:
        /// <summary>
        /// WorldObject Default Constructor
        /// </summary>
        /// <param name="name"></param>
        /// <param name="is_active"></param>
        WorldObject(const std::string name, const bool is_active);
        ~WorldObject();

        Renderer* renderer;
        Collider* collider;

    };
}

#endif