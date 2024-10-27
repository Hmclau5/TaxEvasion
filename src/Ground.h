#ifndef GROUND_H
#define GROUND_H
#include <raylib.h>

class Ground
{
    private:
        Rectangle bounds;
        Color color; 

    public:
    Ground(Rectangle inBounds, Color InColor);

    Rectangle GetBounds();

    void DrawGround();



};

#endif // Ground.h