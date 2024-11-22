
#include "Ground.h"

Ground::Ground(float xIn, float yIn)
{
    bounds = {(float)xIn, (float)yIn, 96, 96};

    
    
};


Rectangle Ground::GetBounds()
{
    return bounds;
};

void Ground::DrawGround()
{
    DrawTextureRec(texture, textureRec , {bounds.x, bounds.y}, WHITE);
};