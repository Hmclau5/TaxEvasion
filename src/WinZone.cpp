#include "WinZone.h"

WinZone::WinZone(float xIn, float yIn)

{
    bounds = {xIn, yIn, 96, 192}; 
    


}

Rectangle WinZone::GetBounds()
{
    return bounds;
}


void WinZone::DrawWinZone()
{
    DrawRectangleRec(bounds, GREEN);

}