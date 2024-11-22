#ifndef GROUND_H
#define GROUND_H
#include <raylib.h>

class Ground
{
    protected:
        Rectangle bounds;
        Texture2D texture;
        Rectangle textureRec;
        

    public:
    Ground(float xIn, float yIn);

    Rectangle GetBounds();

    void DrawGround();



};



#endif // Ground.h