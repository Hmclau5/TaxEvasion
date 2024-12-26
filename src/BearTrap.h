#ifndef BEARTRAP_H
#define BEARTRAP_H

#include "Enemy.h"

class BearTrap : public  Enemy
{
    protected:
        int timer; 
        bool grounded;
        

    public:
        BearTrap(float xIn, float yIn);

        //void Collide(Ground ground) override;
        void Update(vector<Entity*>& entities) override;
        void Draw() override;

} ;


#endif