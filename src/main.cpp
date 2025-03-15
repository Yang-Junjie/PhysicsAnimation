#include "Rasterizer.hpp"
#include "Render.hpp"
#include "Vec2.hpp"
#include <iostream>
#include <string>
using namespace std;

void Vec2Test()
{
    Vec2 v1;
    cout << "v1:" << v1 << endl;
    Vec2 v2(2.0, 2.0);
    cout << "v2:" << v2 << endl;

    cout << "v1+v2" << v1 + v2 << endl;
    cout << "v1-v2" << v1 - v2 << endl;
    cout << "v2*3" << v2 * 3 << endl;
    cout << "3*v2" << 3 * v2 << endl;
    cout << "v2/4" << v2 / 4.0 << endl;
    v1 += v2;
    cout << "v1+=v2\nv1=" << v1 << endl;
    v1 *= 2;
    cout << "v1*=2\nv1=" << v1 << endl;
    v1 -= v2;
    cout << "v1-=v2\nv1=" << v1 << endl;
    v1 /= 2.0;
    cout << "v1/=2.0\nv1=" << v1 << endl;
}

int main()
{
    Render render(256, 256);
    Rasterizer rasterizer(&render);
    const char* path = "test1.png";
    string open_command = "termux-open ";
    string command = open_command + string(path);
    render.createFile(path);
    rasterizer.DrawCircle(128, 128, 50, 0, 255, 0);
    rasterizer.DrawLine(10, 10, 100, 100, 255, 0, 0);    
    rasterizer.DrawTriangle(10,10,50,10,30,50,0,0,255);
    render.saveFile();

    Vec2Test();
    cout << "Hello PhysicsAnimation" << endl;
    system(command.c_str());
    return 0;
}
