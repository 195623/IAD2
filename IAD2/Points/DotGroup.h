class Point ;
class Center ;

std::string dts( double db ) ;

class DotGroup
{
public:
    DotGroup( std::string fileName, int nOfCenters = 2, int nOfPoints = 4 );
    std::vector<Point> return_points() ;
    std::vector<Center> return_centers() ;

    void display_centers() ;
    void display_sum_of_distances() ;
    void display_all_distances() ;
    void display_all_variances() ;


    std::vector<Center> randomize_centers( int number ) ;
    std::vector<Point>  randomize_points ( int number ) ;
    std::vector<std::string> iterate() ;
    bool no_point_changed( std::vector<Point> points ) ;
    bool belongings_quantities_are_unchanged( std::vector<Center> centers ) ;



private:
    std::vector<Point> points ;
    std::vector<Center> centers ;

};
