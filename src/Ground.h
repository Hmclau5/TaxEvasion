#ifndef GROUND_H
#define GROUND_H
#include "raylib.h"
#include "Entity.h"

class Ground : public Entity
{
    protected:
        
        Texture2D texture;
        Rectangle textureRec;
        Type type_;
        

    public:
        Ground(float xIn, float yIn, float widthIn, float heightIn);

        virtual Type getType() override;
        

        Rectangle GetBounds();

        void DrawGround();



};



#endif // Ground.h