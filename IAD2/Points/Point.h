#include <iostream>

class Center ;

class Point
{
public:
    Point(double x, double y) ;

    double return_x() ;
    double return_y() ;

    void set_center(Center* center) ;
    Center* return_currentCenter();

    void display_point();

protected:
    double x ;
    double y ;

private:
    Center* currentCenter ;
    Center* previousCenter ;

};

