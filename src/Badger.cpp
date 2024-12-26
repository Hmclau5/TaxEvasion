#include "Badger.h"
#include <iostream>
using namespace std;

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





void Badger::Update(vector<Entity*>& entities) {
    MoveAndSlide();
    
    for (size_t i = 0; i < entities.size(); i++) {
        Entity* entity = entities[i];
        
        if (entity == this) continue; // Skip self

        if (entity->GetType() == Entity::Type::Ground) {
            Ground* ground = dynamic_cast<Ground*>(entity);
            if (ground && CheckCollisionRecs(bounds, ground->GetBounds()) && !grounded) {
                Rectangle collision = GetCollisionRec(bounds, ground->GetBounds());
                if (collision.width > collision.height && collision.y > bounds.y) {
                    bounds.y = ground->GetBounds().y - bounds.height;
                    yVel = 0;
                    grounded = true;
                } else if (collision.width > collision.height && collision.y <= bounds.y) {
                    bounds.y = ground->GetBounds().y + ground->GetBounds().height;
                    yVel = 0;
                } else if (collision.height > collision.width) {
                    if (collision.x <= bounds.x) {
                        bounds.x = ground->GetBounds().x + ground->GetBounds().width;
                    } else {
                        bounds.x = ground->GetBounds().x - bounds.width;
                    }
                    xVel = 0;
                }

                if (bounds.x + bounds.width > ground->GetBounds().x + ground->GetBounds().width || bounds.x < ground->GetBounds().x) {
                    xVel = -xVel;
                }
            }
        }
        
        if (entity->GetType() == Entity::Type::Enemy) {

           Enemy* enemy = dynamic_cast<Enemy*>(entity);
            if (enemy && CheckCollisionRecs(bounds, enemy->GetBounds())) {
                for( long long unsigned int i = 0; i < entities.size(); i++)
                {
                    if(bounds.x == entities[i]->GetBounds().x && bounds.y == entities[i]->GetBounds().y)
                    {
                        entities.erase(entities.begin() + i);  // Erase from vector
                    }
                }
                delete this;
                return;
            
            }

        }
    }
}

