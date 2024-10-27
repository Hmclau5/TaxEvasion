#ifndef WINZONE_H
#define WINZONE_H


#include "raylib.h"

class WinZone
{
    private:
        Rectangle bounds;
        Color color; 

    public:
        WinZone(Rectangle InBounds, Color InColor);

        Rectangle GetBounds();

        void DrawWinZone();

        



};


#endif // WINZONE_H