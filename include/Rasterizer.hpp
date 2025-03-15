#ifndef RASTERIZER_HPP
#define RASTERIZER_HPP
#include "Render.hpp"
#include "Vec2.hpp"
#include <ctime>

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

    void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
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

    bool inside(int x1, int y1, int x2, int y2, int x3, int y3, int pointx, int pointy);

    bool inside(const Vec2& v1,const Vec2& v2,const Vec2& v3,const Vec2& p);
};
#endif
