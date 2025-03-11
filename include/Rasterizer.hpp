#ifndef RASTERIZER_HPP
#define RASTERIZER_HPP
#include "Render.hpp"

class Rasterizer {
public:
    Rasterizer(Render* render);

    void DrawLine(int x1, int y1, int x2, int y2,
        unsigned int r,
        unsigned int g,
        unsigned int b,
        unsigned int a = 255);

    void DrawCircle(int centerX, int centerY, int radius,
        unsigned int r,
        unsigned int g,
        unsigned int b,
        unsigned int a = 255);

private:
    Render* m_render;

    void setPixel(int x, int y,
            unsigned int r,
            unsigned int g,
            unsigned int b,
            unsigned int a);
    void setCirclePoints(int cx, int cy, int x, int y,
        unsigned int r,
        unsigned int g,
        unsigned int b,
        unsigned int a);
};
#endif
