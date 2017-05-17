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
    centers.push_back( Center(20,20,1)) ;
    centers.push_back( Center(20,0 ,2)) ;
    centers.push_back( Center(0,20 ,3)) ;

    reader.Create_Pairs("test_data.txt",&points) ;



    for( int j = 0 ; j<50 ; j++ )
    {
        for( int i = 0 ; i<points.size() ; i++ )
        {
            measure.set_closest_center(&points[i],centers);
        }

        double allCentersDistance = 0 ;

        for( int i = 0 ; i<centers.size() ; i++ )
        {
            centers[i].reposition_center(points) ;
            //allCentersDistance += measure.total_sqDistance(centers[i],points) ;
        }

        //cout << "Total distance = " << allCentersDistance << '\n' ;
        vector<Point> cpoints = centers[1].return_belonging_points(points) ;
        cout << "\n - dist[1] = " << measure.total_sqDistance(centers[1],cpoints);

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
