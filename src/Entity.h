#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"

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

        virtual Type getType()=0;
        

};

#endif