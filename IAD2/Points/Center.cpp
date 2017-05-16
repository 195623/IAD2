#include "../headers.h"
using namespace std ;

Center::Center( double x, double y ):Point(x,y)
{
}

void Center::reposition_center( vector<Point> allPoints )
{
    vector<Point> belongingPoints = return_belonging_points(allPoints) ;

    double xs = 0, ys = 0 ;

    double n = belongingPoints.size();

    for( vector<Point>::iterator it = belongingPoints.begin() ; it != belongingPoints.end() ; it++ )
    {
        xs += (*it).return_x();
        ys += (*it).return_y();
    }

    this->x = xs/n ;
    this->y = ys/n ;

    cout << "Center::reposition_center() --> " ;
    display_point();
}


vector<Point> Center::return_belonging_points( vector<Point> allPoints )
{
    vector<Point> belongingPoints ;

    for( vector<Point>::iterator it = allPoints.begin() ; it != allPoints.end() ; it++ )
    {
        if( (*it).return_currentCenter() == this ) belongingPoints.push_back(*it) ;
    }

    return belongingPoints ;
}
