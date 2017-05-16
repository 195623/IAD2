#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "headers.h"
using namespace std ;

int main()
{
    Reader reader = Reader() ;
    Measure measure = Measure();

    vector<Point> points ;

    vector<Center> centers ;
    centers.push_back( Center(1,11,1)) ;
    centers.push_back( Center(-5,17,2)) ;
    centers.push_back( Center(1,-10,3)) ;

    reader.Create_Pairs("test_data.txt",&points) ;



    for( int j = 0 ; j<20 ; j++ )
    {
        for( int i = 0 ; i<points.size() ; i++ )
        {
            measure.set_closest_center(&points[i],centers);
        }

        for( int i = 0 ; i<centers.size() ; i++ )
        {
            centers[i].reposition_center(points) ;
        }

        cout << "\n\n" ;
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



string dts( double db )
{
    ostringstream strs;
    strs << db;
    string str = strs.str();

    return str ;
}
