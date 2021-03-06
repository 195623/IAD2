#include "headers.h"
using namespace std ;

bool displayTextNotPixels = false ;
bool getchUsed = false ;

bool globalColor = true ;
bool bigPixels = false ;






int main()
{
    srand (time(NULL));

    int numberOfCenters = 1 ;
    bool forgy = false ;

    cout << "How many centers? " ;
    cin >> numberOfCenters ;
    cout << "Forgy? (1/0) " ;
    cin >> forgy ;
    cout << "Colors? (1/0) " ;
    cin >> globalColor ;

    system("CLS");

    int numberOfTrails = 5 ;


    // single read of .txt file
    // option to randomize centers OUTSIDE the constructor,
    // and to reset the previous-center-assigned for each point

    //for(int i = 0 ; i<numberOfTrails ; i++ )
    if( numberOfCenters >=1 )
    {

        DotGroup dotGroup = DotGroup("test_data.txt",forgy, numberOfCenters) ;
        //DotGroup dotGroup = DotGroup("",numberOfCenters,20) ;
        Reader reader = Reader();

        //dotGroup.display_centers();

        vector<string> csvOutput = dotGroup.iterate(300,250,true);

        reader.write_thing_into_csv("test.csv",csvOutput);
        cout << "\n\n                " << csvOutput.size() << " iterations done.\n" ;

        dotGroup.display_sum_of_distances();

        //dotGroup.display_centers();
        //dotGroup.display_sum_of_distances();
        //dotGroup.display_all_distances()
        //dotGroup.display_all_std_deviations() ;
    }

    cout << "\n\n\n\nFinished." ;

cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" ;
    cin.get();

    return 0 ;
}

// ----------------------------------------------------------------


