#ifndef KILLBOX_H
#define KILLBOX_H

#include "Enemy.h"

class KillBox : public Enemy
{


    public:
        KillBox(float xIn, float yIn, float widthIn, float heightIn);
        void Update(vector<Entity*>& entities);

};


#endif