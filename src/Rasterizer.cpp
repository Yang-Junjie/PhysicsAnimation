#include "Rasterizer.hpp"
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

