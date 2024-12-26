#include "Wolf.h"
#include "Player.h"
#include "math.h"

const float GRAVITY = 1.2;

Wolf::Wolf(float xIn, float yIn)
    : Enemy(xIn, yIn)
{
    bounds = {xIn-32, yIn, 384-32, 192};
    texture = LoadTexture("C:/Users/Haden/Desktop/NewTaxEvasion/assets/wolf.png");
    xVel = 10;
    yVel = 0;
    textureRec = {0,0,384,192};
     


}



void Wolf::MoveAndSlide()
{

        yVel += GRAVITY;

        if(target.x+target.width/2 -200 > bounds.x+bounds.width/2)
            xVel = abs(xVel);
        else if(+target.x+target.width/2 +200 < bounds.x+bounds.width/2)
            xVel = -abs(xVel);


  
        
        bounds.x += xVel;
        bounds.y += yVel;

        grounded = false;

}



void Wolf::Update(vector<Entity*>& entities)
{

    MoveAndSlide();

    for(Entity* i : entities)
    {
        if(i->GetType() == Entity::Type::Ground)
        {
            Ground* ground = dynamic_cast<Ground*>(i);
            if (ground != nullptr) 
            {
                if(CheckCollisionRecs(bounds, ground->GetBounds()) && !grounded)
                {
                    Rectangle collision = GetCollisionRec(bounds, ground->GetBounds());
                    if(collision.width > collision.height && (collision.y > bounds.y))
                    {
                        bounds.y = ground->GetBounds().y - bounds.height;
                        yVel = 0;
                        grounded = true;
                    }
                    if(collision.width > collision.height && (collision.y <= bounds.y))
                    {
                        bounds.y = ground->GetBounds().y + ground->GetBounds().height;
                        yVel = 0;
                    }
                    if(collision.height > collision.width && (collision.x <= bounds.x))
                    {
                        bounds.x = ground->GetBounds().x + ground->GetBounds().width;
                        xVel = 0;
                    }
                    if(collision.height > collision.width && (collision.x > bounds.x))
                    {
                        bounds.x = ground->GetBounds().x - bounds.width;
                        xVel = 0;
                    }

                    if(bounds.x+bounds.width > ground->GetBounds().x+ground->GetBounds().width)
                        bounds.x = ground->GetBounds().x + ground->GetBounds().width - bounds.width;
                    if(bounds.x < ground->GetBounds().x)
                        bounds.x = ground->GetBounds().x;
                } 
            }    
        }

        if(i->GetType() == Entity::Type::Player)
        {
            Player* player = dynamic_cast<Player*>(i);
            if (player != nullptr)
            {
                target = player->GetBounds();
            }
        }



    }
}