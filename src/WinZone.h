#ifndef WINZONE_H
#define WINZONE_H


#include "raylib.h"
#include "Entity.h"

class WinZone : public Entity
{
    
    protected:
        Type type_;

    public:
        WinZone(float xIn, float yIn);

        virtual Type GetType() override;

        virtual void Draw()override;

        Rectangle GetBounds();

};


#endif // WINZONE_H