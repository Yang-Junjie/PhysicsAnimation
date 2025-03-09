#include "Rasterizer.hpp"
#include <cmath>
Rasterizer::Rasterizer(Render* render)
    : m_render(render)
{
}

void Rasterizer::DrawLine(int x1, int y1, int x2, int y2,
    const unsigned int r,
    const unsigned int g,
    const unsigned int b,
    const unsigned int a)
{
    int dx = x2 - x1, dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float delta_x = static_cast<float>(dx) / steps;
    float delta_y = static_cast<float>(dy) / steps;

    for (int k = 0; k <= steps; ++k) { 
        int x = x1 + static_cast<int>(delta_x * k);
        int y = y1 + static_cast<int>(delta_y * k);

        if (x >= 0 && x < m_render->getWidth() && y >= 0 && y < m_render->getHeight()) {
            m_render->setPixel(x, y, r, g, b, a);
        }
    }
}

