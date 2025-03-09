#ifndef RENDER_HPP
#define RENDER_HPP
#define OPEN_ARGB true
#define CLOSE_ARGB false
#include "svpng.h"
class Render{
private:
    unsigned int m_width,m_height;
    unsigned char* m_buffer;
    FILE* m_fp;
    bool m_rgba_state = CLOSE_ARGB;
    unsigned int m_size = 3;
public:
    Render();
    Render(const unsigned int w,const unsigned int h,
            bool rgba = CLOSE_ARGB);
    ~Render();
    unsigned int getWidth();
    unsigned int getHeight();
    void setPixel(const unsigned int x,
                  const unsigned int y,
                  const unsigned int r,
                  const unsigned int g,
                  const unsigned int b,
                  const unsigned int a=0);
    bool createFile(const char* path);
    bool saveFile();
};
#endif
