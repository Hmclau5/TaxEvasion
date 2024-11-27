#ifndef WOLF_H
#define WOLF_H

#include "Enemy.h"

class Wolf : public Enemy
{

    protected:

        float friction, moveSpeed;
        bool grounded, onEdgeR, onEdgeL;
        Rectangle target;
    
    public:
        Wolf(float xIn, float yIn);

        void Collide(Ground ground) override;
        void MoveAndSlide() override;
        void PlayerDetect(Rectangle player) override;



};



#endif