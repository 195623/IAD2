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

    double single_Distance( Center center, Point point ) ;
    double  total_Distance( Center center, std::vector<Point> points, bool forAllPoints=false ) ;
    double  all_totalDistances( std::vector<Center> centers, std::vector<Point> points ) ;
    double variance( Center center, std::vector<Point> points, bool forAllPoints=false );

    void set_closest_center( Point* p_point, std::vector<Center> centers ) ;
};
