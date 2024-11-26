
#include "Ground.h"

Ground::Ground(float xIn, float yIn, float widthIn, float heightIn)
{
    bounds = {(float)xIn, (float)yIn, (float)widthIn , (float)heightIn};

    
    
};


Rectangle Ground::GetBounds()
{
    return bounds;
};

void Ground::DrawGround()
{
    DrawTextureRec(texture, textureRec , {bounds.x, bounds.y}, WHITE);
};