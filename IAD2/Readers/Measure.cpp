#include "../headers.h"

using namespace std ;

double Measure::single_distance( Center* p_center, Point point )
{
    int px = point.return_x(),
        py = point.return_y(),
        cx = p_center->return_x(),
        cy = p_center->return_y() ;

    double distance = sqrt((px-cx)*(px-cx)+(py-cy)*(py-cy)) ;

    return distance ;

}

double Measure::total_distance( Center* p_center, vector<Point> points )
{
    double totalDistance = 0 ;

    for( vector<Point>::iterator it = points.begin() ;  it != points.end() ; it++ )
    {
        totalDistance += single_distance(p_center,*it) ;
    }

    return totalDistance ;
}
