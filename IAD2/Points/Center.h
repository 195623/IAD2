#include <iostream>
#include <vector>

#include "Point.h"

class Center : public Point
{
public:
    Center(double x, double y) ;

    void reposition_center( std::vector<Point> allPoints ) ;
    std::vector<Point> return_belonging_points( std::vector<Point> allPoints ) ;


};


