#include <iostream>
#include <vector>

#include "Point.h"

class Center : public Point
{
public:
    Center(int x, int y) ;

    void reposition_center( std::vector<Point> allPoints ) ;
    std::vector<Point> return_belonging_points( std::vector<Point> allPoints ) ;
};


