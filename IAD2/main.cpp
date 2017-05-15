#include <iostream>
#include <vector>
#include "headers.h"
using namespace std ;

int main()
{
    Reader reader = Reader() ;

    vector<Point> points ;

    reader.Create_Pairs("test_data.txt",&points) ;

    cin.get();

    return 0 ;
}

void show_points( vector<Point> points)
{
    for( int i = 0 ; i<points.size() ; i++ )
    {
        int x = points[i].return_x() ;
        int y = points[i].return_y() ;

        cout << "(" << x << "," << y << ")\n" ;
    }
}
