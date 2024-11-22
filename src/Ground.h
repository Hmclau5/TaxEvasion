#ifndef GROUND_H
#define GROUND_H
#include <raylib.h>

class Ground
{
    private:
        Rectangle bounds;
        Texture2D texture;
        Rectangle textureRec;
        

    public:
    Ground(float xIn, float yIn);

    Rectangle GetBounds();

    void DrawGround();



};

class Surface : public Ground
{
    public:
    Surface (int xIn, int yIn);
};

#endif // Ground.h