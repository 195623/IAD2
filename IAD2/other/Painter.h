#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <wincon.h>

#include <vector>
class Point ;
class Center ;

class Painter
{
public:
    Painter() ;

    void draw() ;
    void draw_points( std::vector<Point> points, std::vector<Center> centers = std::vector<Center>(), int margin = 0 ) ;
};
