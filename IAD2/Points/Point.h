#include <iostream>

class Center ;

class Point
{
public:
    Point(int x, int y) ;

    int return_x() ;
    int return_y() ;

    void set_center(Center* center) ;
    Center* return_currentCenter();

protected:
    int x ;
    int y ;

private:
    Center* currentCenter ;
    Center* previousCenter ;

};

