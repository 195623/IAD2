#include "../headers.h"
using namespace std ;

Point::Point( int x, int y )
{
    this->x = x ;
    this->y = y ;
}

int Point::return_x()
{
    return this->x ;
}

int Point::return_y()
{
    return this->y ;
}

