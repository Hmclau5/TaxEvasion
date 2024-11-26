#include "KillBox.h"

KillBox::KillBox(float xIn, float yIn, float widthIn, float heightIn)
    : Enemy(xIn, yIn)
{
    bounds = {xIn,yIn,widthIn, heightIn};
}

