#include <iostream>
#include <vector>
#include "headers.h"
using namespace std ;

int main()
{
    Reader reader = Reader() ;
    Measure measure = Measure();

    vector<Point> points ;

    vector<Center*> centers ;
    centers.push_back( new Center(20,11)) ;
    centers.push_back( new Center(-5,17)) ;
    centers.push_back( new Center(1,-10)) ;

    reader.Create_Pairs("test_data.txt",&points) ;

    for( int i = 0 ; i<points.size() ; i++ )
    {
        measure.set_closest_center(&points[i],centers);
    }

    for( int i = 0 ; i<centers.size() ; i++ )
    {
        centers[i]->reposition_center(points) ;
    }

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
