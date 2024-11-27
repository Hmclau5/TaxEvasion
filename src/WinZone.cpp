#include "WinZone.h"

WinZone::WinZone(float xIn, float yIn)
    : Entity({xIn, yIn, 96, 192}), type_(Entity::Type::WinZone)

{

    


}

Rectangle WinZone::GetBounds()
{
    return bounds;
}

Entity::Type WinZone::GetType()
{
    return type_;
}


void WinZone::Draw()
{
    DrawRectangleRec(bounds, GREEN);

};