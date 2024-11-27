#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#include <vector>

using namespace std;

class Entity
{
    protected:
        Rectangle bounds;

    public:
        Entity(Rectangle boundsIn);

        enum class Type
        {
            Player,
            WinZone, 
            Enemy, 
            Ground
        };

        Type type_;

        virtual Type GetType();
        virtual void Update(vector<Entity*> entities);
        virtual void Draw();
        Rectangle GetBounds();
};

#endif