#include "WinZone.h"

WinZone::WinZone(float xIn, float yIn)
    : Entity({xIn, yIn, 96, 192}), type_(Entity::Type::WinZone)

{

    


}

Rectangle WinZone::GetBounds()
{
    return bounds;
}

Entity::Type WinZone::getType()
{
    return type_;
}


void WinZone::DrawWinZone()
{
    DrawRectangleRec(bounds, GREEN);

}