#include "../headers.h"

using namespace std ;

Measure::Measure()
{

}

double Measure::single_Distance( Center center, Point point )
{
    double px = point.return_x(),
        py = point.return_y(),
        cx = center.return_x(),
        cy = center.return_y() ;

    double distance = sqrt((px-cx)*(px-cx)+(py-cy)*(py-cy)) ;

    return distance ;

}

double Measure::total_Distance( Center center, vector<Point> points, bool forAllPoints  )
{
    double totalDistance = 0 ;

    vector<Point> assignedPoints ;
    if(!forAllPoints) assignedPoints = center.return_belonging_points(points) ;
    else assignedPoints = points ;

    if(assignedPoints.size() == 0 ) return -1 ;

    for( vector<Point>::iterator it = assignedPoints.begin() ;  it != assignedPoints.end() ; it++ )
    {
        totalDistance += single_Distance(center,*it) ;
    }

    return totalDistance/10000 ;
}

double Measure::all_totalDistances( vector<Center> centers, vector<Point> points )
{
    double totalDistance = 0 ;

    for( int i = 0 ; i < (int) centers.size() ; i++ )
    {
        double thisDistance = total_Distance(centers[i],points) ;
        if( thisDistance>=0 ) totalDistance += thisDistance ;
    }

    return totalDistance ;
}

void Measure::set_closest_center( Point* p_point, vector<Center> centers )
{
    double Distance ;

    if(centers.size()>0)
    {
        Distance = single_Distance(centers[0],*p_point) ;
        p_point->set_currentCenterID(centers[0].return_ID()) ;
    }
    else
    {
        cout << "[ set_closest_center(): vector<Center> is empty ]\n" ;
        return ;
    }

    for( vector<Center>::iterator it = centers.begin() ;  it != centers.end() ; it++ )
    {
        double newDistance = single_Distance(*it,*p_point) ;
        int newID = (*it).return_ID();

        if( newDistance < Distance )
        {
            Distance = newDistance ;

            p_point->set_currentCenterID(newID) ;
            //cout << "New ID = " << newID << '\n' ;
        }
    }
}


double Measure::variance( Center center, vector<Point> points, bool forAllPoints )
{
    //Measure measure = Measure() ;

    double sum = 0, avg=0, var = 0 ;

    vector<Point> assignedPoints ;

        if(!forAllPoints) assignedPoints = center.return_belonging_points(points);
        else assignedPoints = points ;

    double n = assignedPoints.size();

    for( int i = 0 ; i<n ; i++ )
    {
        sum += single_Distance(center,assignedPoints[i]);
    }

    avg = sum/n ;

    for( int i = 0 ; i<n ; i++ )
    {
        double thisDistance = single_Distance(center,assignedPoints[i]) ;

        var += (avg-thisDistance)*(avg-thisDistance) ;
    }

    var = var/n ;

    return var ;
}
