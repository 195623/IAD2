#include "../headers.h"
using namespace std ;

Point::Point( int x, int y )
{
    this->x = x ;
    this->y = y ;
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

int Point::return_x()
{
    return this->x ;
}

int Point::return_y()
{
    return this->y ;
}

