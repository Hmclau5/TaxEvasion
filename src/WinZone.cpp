#include "WinZone.h"

WinZone::WinZone(Rectangle InBounds, Color InColor)

{
    bounds = InBounds; 
    color = InColor; 


}

Rectangle WinZone::GetBounds()
{
    return bounds;
}


void WinZone::DrawWinZone()
{
    DrawRectangleRec(bounds, color);

}