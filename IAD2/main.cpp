#include "headers.h"
using namespace std ;

int main()
{
    srand (time(NULL));

    DotGroup dotGroup = DotGroup("test_data.txt",3) ;
    Reader reader = Reader();

    vector<string> csvOutput = dotGroup.iterate();
    reader.write_thing_into_csv("test.csv",csvOutput);

    cin.get();

    return 0 ;
}

// ----------------------------------------------------------------




// ----------------------------------------------------------------



void show_points( vector<Point> points)
{
    for( int i = 0 ; i< (int) points.size() ; i++ )
    {
        int x = points[i].return_x() ;
        int y = points[i].return_y() ;

        cout << "(" << x << "," << y << ")\n" ;
    }
}




