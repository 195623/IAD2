class Point ;
class Center ;

std::string dts( double db ) ;

class DotGroup
{
public:
    DotGroup( std::string fileName, bool forgy, int nOfCenters = 2, int nOfPoints = 4 );
    std::vector<Point> return_points() ;
    std::vector<Center> return_centers() ;

    void display_centers() ;
    void display_sum_of_distances() ;
    void display_all_distances() ;
    void display_all_std_deviations() ;


    void randomize_points ( int number ) ;

    void forgy_centers(int numberOfCenters) ;
    void random_partition( int number ) ;

    std::vector<std::string> iterate(int xmar, int ymar, bool graphics = true) ;
    bool no_point_changed( ) ;
    bool assigned_quantities_are_unchanged( std::vector<Center> centers ) ;


    //void randomize_centers( int number ) ;
private:
    std::vector<Point> points ;
    std::vector<Center> centers ;

};
