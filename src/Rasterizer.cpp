#include "Rasterizer.hpp"
#include "Vec2.hpp"
#include <cmath>
Rasterizer::Rasterizer(Render* render)
    : m_render(render)
{
}

void Rasterizer::DrawLine(
    int x1, int y1, int x2, int y2,
    unsigned int r,
    unsigned int g,
    unsigned int b,
    unsigned int a)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = std::fmax(std::abs(dx), std::abs(dy));

    if (steps == 0) {
        setPixel(x1, y1, r, g, b, a);
        return;
    }

    float xInc = static_cast<float>(dx) / steps;
    float yInc = static_cast<float>(dy) / steps;

    float x = static_cast<float>(x1);
    float y = static_cast<float>(y1);

    for (int i = 0; i <= steps; i++) {
        setPixel(static_cast<int>(x + 0.5f), static_cast<int>(y + 0.5f), r, g, b, a);
        x += xInc;
        y += yInc;
    }
}

void Rasterizer::DrawCircle(
    int centerX, int centerY, int radius,
    unsigned int r,
    unsigned int g,
    unsigned int b,
    unsigned int a)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y) {
        setCirclePoints(centerX, centerY, x, y, r, g, b, a);
        if (d <= 0) {
            d += 4 * x + 6;
        } else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void Rasterizer::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
    unsigned int r,
    unsigned int g,
    unsigned int b,
    unsigned int a)
{
    Vec2 v1(x1, y1);
    Vec2 v2(x2, y2);
    Vec2 v3(x3, y3);
    int the_max_x = fmax(fmax(x1, x2), x3);
    int the_max_y = fmax(fmax(y1, y2), y3);
    int the_min_x = fmin(fmin(x1, x2), x3);
    int the_min_y = fmin(fmin(y1, y2), y3);
    for (int i = the_min_x; i <= the_max_x; i++) {
        for (int j = the_min_y; j <= the_max_y; j++) {
            Vec2 P(i, j);
            if (inside(v1, v2, v3, P)) {
                setPixel(i, j, r, g, b, a);
            }
        }
    }
}
void Rasterizer::setPixel(
    int x, int y,
    unsigned int r, unsigned int g,
    unsigned int b, unsigned int a)
{
    if (x >= 0 && y >= 0 && x < m_render->getWidth() && y < m_render->getHeight()) {
        m_render->setPixel(x, y, r, g, b, a);
    }
}

void Rasterizer::setCirclePoints(
    int cx, int cy, int x, int y,
    unsigned int r, unsigned int g,
    unsigned int b, unsigned int a)
{
    setPixel(cx + x, cy + y, r, g, b, a);
    setPixel(cx - x, cy + y, r, g, b, a);
    setPixel(cx + x, cy - y, r, g, b, a);
    setPixel(cx - x, cy - y, r, g, b, a);
    setPixel(cx + y, cy + x, r, g, b, a);
    setPixel(cx - y, cy + x, r, g, b, a);
    setPixel(cx + y, cy - x, r, g, b, a);
    setPixel(cx - y, cy - x, r, g, b, a);
}
bool Rasterizer::inside(const Vec2& v1, const Vec2& v2, const Vec2& v3, const Vec2& p)
{
    double cross1 = (v1 - v2).cross(v1 - p);
    double cross2 = (v2 - v3).cross(v2 - p);
    double cross3 = (v3 - v1).cross(v3 - p);
    bool has_neg = (cross1 < 0 || cross2 < 0 || cross3 < 0);
    bool has_pos = (cross1 > 0 || cross2 > 0 || cross3 > 0);
    if (has_neg && has_pos)
        return false;
    return true;
}
