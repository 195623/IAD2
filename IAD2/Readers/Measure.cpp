#include "../headers.h"

using namespace std ;

Measure::Measure()
{

}

double Measure::single_sqDistance( Center center, Point point )
{
    double px = point.return_x(),
        py = point.return_y(),
        cx = center.return_x(),
        cy = center.return_y() ;

    double distance = ((px-cx)*(px-cx)+(py-cy)*(py-cy)) ;

    return distance ;

}

double Measure::total_sqDistance( Center center, vector<Point> points )
{
    double totalDistance = 0 ;

    if(points.size() == 0 ) return -1 ;

    for( vector<Point>::iterator it = points.begin() ;  it != points.end() ; it++ )
    {
        totalDistance += single_sqDistance(center,*it) ;
    }

    return totalDistance/10000 ;
}

void Measure::set_closest_center( Point* p_point, vector<Center> centers )
{
    double sqDistance ;

    if(centers.size()>0)
    {
        sqDistance = single_sqDistance(centers[0],*p_point) ;
        p_point->set_currentCenterID(centers[0].return_ID()) ;
    }
    else
    {
        cout << "[ set_closest_center(): vector<Center> is empty ]\n" ;
        return ;
    }

    for( vector<Center>::iterator it = centers.begin() ;  it != centers.end() ; it++ )
    {
        double newSqDistance = single_sqDistance(*it,*p_point) ;
        int newID = (*it).return_ID();

        if( newSqDistance < sqDistance )
        {
            sqDistance = newSqDistance ;

            p_point->set_currentCenterID(newID) ;
            //cout << "New ID = " << newID << '\n' ;
        }
    }
}



