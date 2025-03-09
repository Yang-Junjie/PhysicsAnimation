#include "Render.hpp"
#include <cstdio>

Render::Render()
{
}

Render::Render(
    const unsigned int w,
    const unsigned int h,
    bool rgba)
    : m_width(w)
    , m_height(h)
    , m_rgba_state(rgba)
{
    if (m_rgba_state)
        m_size = 4;
    m_buffer = new unsigned char[w * h * m_size]();
}
Render::~Render()
{
    delete[] m_buffer;
}
bool Render::createFile(const char* path)
{
    m_fp = fopen(path, "wb");
    if (m_fp == nullptr)
        return false;
    else
        return true;
}

void Render::setPixel(
    const unsigned int x,
    const unsigned int y,
    const unsigned int r,
    const unsigned int g,
    const unsigned int b,
    const unsigned int a)
{
    m_buffer[(y * m_width + x) * m_size + 0] = r;
    m_buffer[(y * m_width + x) * m_size + 1] = g;
    m_buffer[(y * m_width + x) * m_size + 2] = b;
    if (m_rgba_state)
        m_buffer[(y * m_width + x) * m_size + 3] = a;
}
bool Render::saveFile()
{
    svpng(m_fp, m_width, m_height, m_buffer, m_rgba_state);
    return fclose(m_fp);
}

unsigned int Render::getWidth(){return m_width;}
unsigned int Render::getHeight(){return m_height;}
