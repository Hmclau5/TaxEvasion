#include "Badger.h"

const float GRAVITY = 1.2;

Badger::Badger(float xIn, float yIn)
    : Enemy(xIn , yIn)
{
    bounds = {xIn,yIn,256,128};
    
    texture = LoadTexture("C:/Users/Haden/Desktop/NewTaxEvasion/assets/badger.png");

    xVel = 5;
    yVel = 0;

    textureRec = {0,0,256,128};

    grounded = false;
}

void Badger::Collide(Ground ground)
{  
    if(CheckCollisionRecs(bounds, ground.GetBounds()) && !grounded)
    {
        Rectangle collision = GetCollisionRec(bounds, ground.GetBounds());
        if(collision.width > collision.height && (collision.y > bounds.y))
        {
            bounds.y = ground.GetBounds().y - bounds.height;
            yVel = 0;
            grounded = true;
        }
        if(collision.width > collision.height && (collision.y <= bounds.y))
        {
            bounds.y = ground.GetBounds().y + ground.GetBounds().height;
            yVel = 0;
        }
        if(collision.height > collision.width && (collision.x <= bounds.x))
        {
            bounds.x = ground.GetBounds().x + ground.GetBounds().width;
            xVel = 0;
        }
        if(collision.height > collision.width && (collision.x > bounds.x))
        {
            bounds.x = ground.GetBounds().x - bounds.width;
            xVel = 0;
        }

        if(bounds.x+bounds.width > ground.GetBounds().x+ground.GetBounds().width||bounds.x < ground.GetBounds().x)
            xVel = - xVel;
    }

}

void Badger::MoveAndSlide()
{

    
        bounds.x += xVel;
        bounds.y += yVel;

        yVel += GRAVITY;
      

        grounded = false;

}

void Badger::Update(vector<Entity*> entities)
{
    MoveAndSlide();
    for (Entity* i : entities)
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

                    if(bounds.x+bounds.width > ground->GetBounds().x+ground->GetBounds().width||bounds.x < ground->GetBounds().x)
                        xVel = - xVel;
                }
            }
        }
    }
}
