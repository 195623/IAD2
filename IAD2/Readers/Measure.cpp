#include "../headers.h"

using namespace std ;

double Measure::single_distance( Center center, Point point )
{
    int px = point.return_x(),
        py = point.return_y(),
        cx = center.return_x(),
        cy = center.return_y() ;

    double distance = sqrt((px-cx)*(px-cx)+(py-cy)*(py-cy)) ;

    return distance ;

}

double Measure::total_distance( Center center, vector<Point> points )
{
    double totalDistance = 0 ;

    for( vector<Point>::iterator it = points.begin() ;  it != points.end() ; it++ )
    {
        totalDistance += single_distance(center,*it) ;
    }

    return totalDistance ;
}

void Measure::set_closest_center( Point* p_point, vector<Center*> centers )
{
    double distance ;

    if(centers.size()>0) distance = single_distance(*centers[0],*p_point) ;
    else
    {
        cout << "[ set_closest_center(): vector<Center*> is empty ]\n" ;
        return ;
    }

    for( vector<Center*>::iterator it = centers.begin() ;  it != centers.end() ; it++ )
    {
        double newDistance = single_distance(**it,*p_point) ;
        if( newDistance < distance )
        {
            distance = newDistance ;
            p_point->set_center(*it) ;
        }
    }
}



