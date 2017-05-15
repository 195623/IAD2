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

    double single_distance( Center* p_center, Point point ) ;
    double total_distance( Center* p_center, std::vector<Point> points ) ;
};
