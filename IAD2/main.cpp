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

        cout << csvOutput.size() << " iterations done.\n\n" ;
        dotGroup.display_centers();
    }

    cout << "\nFinished." ;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" ;
    cin.get();

    return 0 ;
}

// ----------------------------------------------------------------


