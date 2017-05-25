#include "headers.h"
using namespace std ;

bool displayTextNotPixels = false ;
bool getchUsed = false ;






int main()
{
    srand (time(NULL));

    int numberOfCenters = 1 ;

    cout << "How many centers? " ;
    cin >> numberOfCenters ;
    system("CLS");

    if( numberOfCenters >=1 )
    {
        //DotGroup dotGroup = DotGroup("test_data.txt",numberOfCenters) ;
        DotGroup dotGroup = DotGroup("",numberOfCenters,10000) ;
        Reader reader = Reader();

        dotGroup.display_centers();
        vector<string> csvOutput = dotGroup.iterate();
        reader.write_thing_into_csv("test.csv",csvOutput);
        cout << '\n' ;
        cout << csvOutput.size() << " iterations done.\n\n" ;

        dotGroup.display_centers();
        dotGroup.display_sum_of_distances();
        dotGroup.display_all_distances() ;
        cout << '\n' ;
        dotGroup.display_all_variances() ;
    }

    cout << "\nFinished." ;

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" ;
    cin.get();

    return 0 ;
}

// ----------------------------------------------------------------


