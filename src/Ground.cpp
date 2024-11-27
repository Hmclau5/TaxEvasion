
#include "Ground.h"

Ground::Ground(float xIn, float yIn, float widthIn, float heightIn)
    : Entity({(float)xIn, (float)yIn, (float)widthIn , (float)heightIn}), type_(Entity::Type::Ground)
{
   

    
    
};


Rectangle Ground::GetBounds()
{
    return bounds;
};

Entity::Type Ground::getType()
{
    return type_;
}

void Ground::DrawGround()
{
    DrawTextureRec(texture, textureRec , {bounds.x, bounds.y}, WHITE);
};