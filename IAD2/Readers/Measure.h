#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>

class Point ;
class Center ;

class Measure
{
public:
    Measure() ;

    double single_sqDistance( Center center, Point point ) ;
    double  total_sqDistance( Center center, std::vector<Point> points ) ;

    void set_closest_center( Point* p_point, std::vector<Center> centers ) ;
};
