#include "headers.h"
using namespace std ;

bool displayTextNotPixels = false ;

int main()
{
    srand (time(NULL));

    int numberOfCenters = 1 ;

    cout << "How many centers? " ;
    cin >> numberOfCenters ;
    system("CLS");

    if( numberOfCenters >=1 )
    {
        DotGroup dotGroup = DotGroup("test_data.txt",numberOfCenters) ;
        Reader reader = Reader();

        vector<string> csvOutput = dotGroup.iterate();
        reader.write_thing_into_csv("test.csv",csvOutput);
    }

    cout << "finished" ;
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




