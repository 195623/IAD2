#include "../headers.h"
using namespace std ;

Point::Point( double x, double y )
{
    this->x = x ;
    this->y = y ;
}

void Point::display_point()
{
    cout << "(" << x << "," << y << ")\n" ;
}

void Point::set_center(Center* center)
{
    this->previousCenter = this->currentCenter ;

    this->currentCenter = center ;
}

Center* Point::return_currentCenter()
{
    return this->currentCenter ;
}

double Point::return_x()
{
    return this->x ;
}

double Point::return_y()
{
    return this->y ;
}

