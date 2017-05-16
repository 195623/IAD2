#include "../headers.h"

using namespace std ;



string dts( double db ) ;

// ----------------

Point::Point( double x, double y )
{
    this->x = x ;
    this->y = y ;
}

string Point::display_point()
{
    string strX = dts(x) ;
    string strY = dts(y) ;

    return "(" + strX + "," + strY + ")  " ;
}

void Point::set_currentCenterID( int newCenterID )
{
    this->previousCenterID = this->currentCenterID ;

    this->currentCenterID = newCenterID ;

    //if( this->previousCenterID != this->currentCenterID ) cout << "*" ;
}

int Point::return_currentCenterID()
{
    return this->currentCenterID ;
}

double Point::return_x()
{
    return this->x ;
}

double Point::return_y()
{
    return this->y ;
}

