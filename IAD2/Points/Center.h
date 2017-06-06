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

    int return_nowBelonging() ;
    int return_prevBelonging() ;

    void update_assigned_quantities( std::vector<Point> allPoints ) ;
    bool belonging_points_not_changed() ;

private:
    int ID ;

    int nowBelonging ;
    int prevBelonging ;


};


