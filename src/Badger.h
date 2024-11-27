#ifndef BADGER_H
#define BADGER_H

#include "Enemy.h"


class Badger : public Enemy
{

    protected:
        float moveSpeed;
        bool grounded;

    public:
        Badger(float xIn, float yIn);


        void Collide(Ground ground) override;
        void MoveAndSlide() override ;

        


};


#endif