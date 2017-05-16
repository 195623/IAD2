#include <iostream>
#include <vector>
#include "Point.h"

class Center : public Point
{
public:
    Center(double x, double y, int ID ) ;
    int return_ID() ;

    void reposition_center( std::vector<Point> allPoints ) ;
    std::vector<Point> return_belonging_points( std::vector<Point> allPoints ) ;

private:
    int ID ;


};


