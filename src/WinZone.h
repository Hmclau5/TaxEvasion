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

        Rectangle GetBounds();

        virtual Type getType() override;

        void DrawWinZone();

};


#endif // WINZONE_H