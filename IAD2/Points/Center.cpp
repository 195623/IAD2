#include "../headers.h"
using namespace std ;

string dts( double db ) ;

Center::Center( double x, double y, int ID ):Point(x,y)
{
    this->ID = ID ;
}

int Center::return_ID()
{
    return this->ID ;
}

int Center::return_nowBelonging()
{
    return this->nowBelonging ;
}

int Center::return_prevBelonging()
{
    return this->prevBelonging ;
}

void Center::update_numbersOfBelongings( vector<Point> allPoints )
{
    vector<Point> belongingPoints = this->return_belonging_points(allPoints) ;

    this->prevBelonging = nowBelonging ;
    this->nowBelonging = belongingPoints.size();
}

bool Center::belonging_points_not_changed()
{
    return (prevBelonging==nowBelonging) ;
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

    //cout << "\n[" << dts(xs) << "," << dts(ys) << "]\n" ;
    //cout << "\n[" << dts(n) << "]\n" ;

    //cout << "/" << xs << "," << ys << "\\\n" ;

    if(n>0)
    {
        this->x = xs/n ;
        this->y = ys/n ;
        //cout << display_point();
    }

    //update_belonging( allPoints ) ;

}


vector<Point> Center::return_belonging_points( vector<Point> allPoints )
{
    vector<Point> belongingPoints ;

    for( vector<Point>::iterator it = allPoints.begin() ; it != allPoints.end() ; it++ )
    {
        if( (*it).return_currentCenterID() == this->ID ) belongingPoints.push_back(*it) ;
        //cout << "*" ;
    }

    //cout << "\nC[" << this->ID << "]: " << belongingPoints.size() << " -- " ;

    return belongingPoints ;
}
