#include "Render.hpp"
#include <iostream>
#include <string>
#include "Rasterizer.hpp"
using namespace std;

int main()
{
    Render render(256, 256);
    Rasterizer rasterizer(&render);
    const char* path = "test1.png";
    string open_command = "termux-open ";
    string command = open_command + string(path);
    render.createFile(path);
    rasterizer.DrawLine(10,10,100,100,255,0,0);
    render.saveFile();
    cout << "Hello PhysicsAnimation" << endl;
    system(command.c_str());
    return 0;
}
