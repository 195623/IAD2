#include "../headers.h"
using namespace std ;

Painter::Painter()
{

};

extern bool bigPixels ;

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

void Painter::draw_points( vector<Point> points, vector<Center> centers, int xmar, int ymar, bool colors )
{
    //SetPixel(NULL, 50, 50, RGB(255, 255, 255));
    extern bool globalColor ;

    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    RECT rect;
    GetClientRect(myconsole, &rect);

    int rred, ggreen, bblue ;
    int n = centers.size() ;

    if( n == 1 ) n = 2 ;
    int colorStep = 255/(n-1);

    //int multi = 1 ;
    //if( n < 32 ) multi = 2 ;
    //if( n < 16 ) multi = 4 ;
    //if( n < 8  ) multi = 8 ;
    //if( n < 4  ) multi = 16 ;

    for(int i = 0; i < (int) centers.size(); i++)
    {
        rred = colorStep*i ;
        bblue = 255 - rred ;
        ggreen = 0 ;


        //rred = (int(multi*i/16)%4)*colorStep + colorStep ;
        //ggreen = (int(multi*i/4)%4) * colorStep + colorStep ;
        //bblue = ((multi*i)%4)*colorStep + colorStep ;



        if( rred > 255   || rred   < 0 ) rred = 0 ;
        if( ggreen > 255 || ggreen < 0 ) ggreen = 0 ;
        if( bblue > 255  || bblue  < 0 ) bblue = 0 ;


        vector<Point> belongingPoints = centers[i].return_belonging_points(points) ;

        for(int j = 0; j < (int) belongingPoints.size(); j++)
        {
            int xx = 10*belongingPoints[j].return_x() +xmar;
            int yy = 10*belongingPoints[j].return_y() +ymar;

            if(globalColor)
            {
                SetPixel(mydc, xx,yy, RGB(rred/3,ggreen/3,bblue/3));

                if(bigPixels)
                {
                    SetPixel(mydc, xx+1,yy, RGB(rred/3,ggreen/3,bblue/3));
                    SetPixel(mydc, xx+2,yy, RGB(rred/3,ggreen/3,bblue/3));
                    SetPixel(mydc, xx,yy+1, RGB(rred/3,ggreen/3,bblue/3));
                    SetPixel(mydc, xx+1,yy+1, RGB(rred/3,ggreen/3,bblue/3));
                    SetPixel(mydc, xx+2,yy+1, RGB(rred/3,ggreen/3,bblue/3));
                    SetPixel(mydc, xx,yy+2, RGB(rred/3,ggreen/3,bblue/3));
                    SetPixel(mydc, xx+1,yy+2, RGB(rred/3,ggreen/3,bblue/3));
                    SetPixel(mydc, xx+2,yy+2, RGB(rred/3,ggreen/3,bblue/3));
                }
            }
            else SetPixel(mydc, xx,yy, RGB(255/3,255/3,255/3));
        }

        int x = 10*centers[i].return_x() +xmar;
        int y = 10*centers[i].return_y() +ymar;

        if(globalColor)
        {
            SetPixel(mydc, x,y, RGB(rred,ggreen,bblue));

            if( bigPixels)
            {
                SetPixel(mydc, x+1,y, RGB(rred,ggreen,bblue));
                SetPixel(mydc, x+2,y, RGB(rred,ggreen,bblue));
                SetPixel(mydc, x,y+1, RGB(rred,ggreen,bblue));
                SetPixel(mydc, x+1,y+1, RGB(rred,ggreen,bblue));
                SetPixel(mydc, x+2,y+1, RGB(rred,ggreen,bblue));
                SetPixel(mydc, x,y+2, RGB(rred,ggreen,bblue));
                SetPixel(mydc, x+1,y+2, RGB(rred,ggreen,bblue));
                SetPixel(mydc, x+2,y+2, RGB(rred,ggreen,bblue));
            }
        }
        else SetPixel(mydc, x,y, RGB(255,255,255)) ;


    }

}
