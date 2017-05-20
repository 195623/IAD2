#include "../headers.h"
using namespace std ;


Painter::Painter()
{

};


void Painter::draw()
{
    //SetPixel(NULL, 50, 50, RGB(255, 255, 255));
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    RECT rect;
    GetClientRect(myconsole, &rect);
    for(int i = 0; i < rect.bottom - rect.top; ++i)
        SetPixel(mydc, (rect.right - rect.left) / 2, i, RGB(255, 0, 0));
    for(int i = 0; i < rect.right - rect.left; ++i)
        SetPixel(mydc, i, (rect.bottom - rect.top) / 2, RGB(255, 0, 0));
}

void Painter::draw_points( vector<Point> points, vector<Center> centers, int margin )
{
    //SetPixel(NULL, 50, 50, RGB(255, 255, 255));
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    RECT rect;
    GetClientRect(myconsole, &rect);

    for(int i = 0; i < points.size(); i++)
    {
        int x = 10*points[i].return_x() +150+margin;
        int y = 10*points[i].return_y() +150+margin;
        SetPixel(mydc, x,y, RGB(255, 255, 255));
    }


    for(int i = 0; i < centers.size(); i++)
    {
        int x = 10*centers[i].return_x() +150+margin;
        int y = 10*centers[i].return_y() +150+margin;
        SetPixel(mydc, x,y, RGB(0, 255, 0));
    }

}
