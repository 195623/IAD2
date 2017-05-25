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

void Painter::draw_points( vector<Point> points, vector<Center> centers, int margin, int red, int green, int blue )
{
    //SetPixel(NULL, 50, 50, RGB(255, 255, 255));
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    RECT rect;
    GetClientRect(myconsole, &rect);




    for(int i = 0; i < (int) centers.size(); i++)
    {
        int colorStep = 255/(centers.size()-1);

        vector<Point> belongingPoints = centers[i].return_belonging_points(points) ;

        for(int j = 0; j < (int) belongingPoints.size(); j++)
        {
            int xx = 10*belongingPoints[j].return_x() +500+margin;
            int yy = 10*belongingPoints[j].return_y() +300+margin;
            SetPixel(mydc, xx,yy, RGB(255/3-colorStep*i/3, colorStep*i/3, 0));
        }

        int x = 10*centers[i].return_x() +500+margin;
        int y = 10*centers[i].return_y() +300+margin;
        SetPixel(mydc, x,y, RGB(255-colorStep*i, colorStep*i, 0));


    }

}
