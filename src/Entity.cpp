#include "Entity.h"

Entity::Entity(Rectangle boundsIn)
{
    bounds = boundsIn;
};

Rectangle Entity::GetBounds()
{
    return bounds;
}

Entity::Type Entity::GetType()
{
    return type_;
}

void Entity::Update(vector<Entity*>){};
void Entity::Draw(){};