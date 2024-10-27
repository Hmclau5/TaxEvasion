
#include "Ground.h"

Ground::Ground(Rectangle InBounds, Color InColor)
{
    bounds = InBounds; 
    color = InColor; 
};

Rectangle Ground::GetBounds()
{
    return bounds;
};

void Ground::DrawGround()
{
    DrawRectangleRec(bounds, color);
};