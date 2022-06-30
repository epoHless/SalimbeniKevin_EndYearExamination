#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#include <pch.h>

#include "AreaObject.h"
#include <objects/gameobjects/AreaObject.h>
#include <objects/components/Renderer.h>
#include <objects/components/Collider.h>

namespace WTGD
{
    class WTGD_API WorldObject : public AreaObject
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