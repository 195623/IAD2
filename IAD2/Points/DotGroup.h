class Point ;
class Center ;

std::string dts( double db ) ;

class DotGroup
{
public:
    DotGroup( std::string fileName, int centers = 2 );
    std::vector<Point> return_points() ;
    std::vector<Center> return_centers() ;

    void display_centers() ;


    std::vector<Center> randomize_centers( int number ) ;
    std::vector<std::string> iterate() ;
    bool no_point_changed( std::vector<Point> points ) ;
    bool belongings_quantities_are_unchanged( std::vector<Center> centers ) ;

    double variance( Center center ) ;

private:
    std::vector<Point> points ;
    std::vector<Center> centers ;

};
