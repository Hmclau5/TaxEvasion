#ifndef WINZONE_H
#define WINZONE_H


#include "raylib.h"

class WinZone
{
    private:
        Rectangle bounds;
        

    public:
        WinZone(float xIn, float yIn);

        Rectangle GetBounds();

        void DrawWinZone();

};


#endif // WINZONE_H