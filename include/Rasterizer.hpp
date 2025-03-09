#ifndef RASTERIZER_HPP
#define RASTERIZER_HPP
#include "Render.hpp"
class Rasterizer{
private:
    Render* m_render;
public:
    Rasterizer(Render* render);
    void DrawLine(int x1,int y1,int x2,int y2,
            const unsigned int r,
            const unsigned int g,
            const unsigned int b,
            const unsigned int a=0
            );
};

#endif
