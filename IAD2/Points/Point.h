#include <iostream>


class Center ;

class Point
{
public:
    Point(double x, double y) ;

    double return_x() ;
    double return_y() ;

    void set_currentCenterID( int newCenterID ) ;
    int return_currentCenterID();

    std::string display_point();

protected:
    double x ;
    double y ;

private:
    int currentCenterID ;
    int previousCenterID ;

};

