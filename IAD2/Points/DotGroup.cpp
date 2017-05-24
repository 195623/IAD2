#include "../headers.h"
#include <conio.h>
using namespace std ;

extern bool displayTextNotPixels ;
extern bool getchUsed ;

DotGroup::DotGroup( string fileName, int centers )
{
    srand (time(NULL));

    Reader reader = Reader() ;

    reader.Create_Points(fileName,&this->points) ;
    this->centers = randomize_centers(centers);


}


std::vector<Point> DotGroup::return_points()
{
    return this->points ;
}

std::vector<Center> DotGroup::return_centers()
{
    return this->centers ;
}


vector<Center> DotGroup::randomize_centers( int number )
{
    vector<Center> centers ;

    if(displayTextNotPixels) cout << "Centers created:\n\n" ;

    for( int i = 0 ; i<number ; i++ )
    {
        double x = (double) (rand()%30-15) ;

        double y = (double) (rand()%30-15) ;


        centers.push_back(Center(x,y,i)) ;

        if(displayTextNotPixels) cout << "(" << x << "," << y << ")\n" ;
    }

    if(displayTextNotPixels) cout << "\n----------\n" ;

    return centers ;

  /* generate secret number between 1 and 10: */
  //int i = rand() % 10 + 1;
}





vector<string> DotGroup::iterate()
{
    Painter painter = Painter() ;
    Measure measure = Measure();
    vector<string> outputLines ;
    string header = "" ;



    for( int c = 0 ; c< (int) centers.size() ; c++ )
    {
        header += "C["+dts(c+1) ;
        header += "];" ;
    }
    header += '\n' ;

    outputLines.push_back(header);

    int k = 0 ;

    for(int j = 0 ; !belongings_quantities_are_unchanged(centers) ; j++)
    //for(int j = 0 ; !no_point_changed(points) ; j++)
    {
        for( int i = 0 ; i< (int) points.size() ; i++ )
        {
            measure.set_closest_center(&points[i],centers);
        }

        //double allCentersDistance = 0 ;

        for( int i = 0 ; i< (int) centers.size() ; i++ )
        {
            centers[i].update_numbersOfBelongings(points); // is always 1 step behind; shows previous state of belongings
            centers[i].reposition_center(points) ;
            //allCentersDistance += measure.total_sqDistance(centers[i],points) ;
        }

        //cout << "Total distance = " << allCentersDistance << '\n' ;

        //vector<Point> cpoints = centers[1].return_belonging_points(points) ;
        //cout << "\n - dist[1] = " << measure.total_sqDistance(centers[1],cpoints);
        //cout << "\n\n" ;

        string countLine = "" ;

        string line = "" ;
        for( int c = 0 ; c< (int) centers.size() ; c++ )
        {
            line += dts(measure.total_sqDistance(centers[c],centers[c].return_belonging_points(points))) ;
            line += " ; " ;

            vector<Point> belongingPoints = centers[c].return_belonging_points(points) ;
            countLine += dts((double) belongingPoints.size() ) + "   " ;

            //painter.draw_points(belongingPoints,cent)
        }

        line += ";;" ;

        for( int c = 0 ; c< (int) centers.size() ; c++ )
        {
            line += centers[c].display_point();
            line += " ; " ;
        }

        if( displayTextNotPixels ) cout << countLine << '\n' ;
        else
        {
            painter.draw_points(points,centers,100) ; // temporary unseperated into center-groups


            if( getchUsed )
            {
                do
                {
                    k=getch();
                }
                while(k<1);

                k=0 ;
            }


        }




        //cout << "&&&&&" ;

        line += '\n' ;
        outputLines.push_back(line);
    }

    return outputLines ;
}



bool DotGroup::no_point_changed( vector<Point> points )
{
    int n = points.size() ;
    int notChanged = 0 ;

    for( int i = 0 ; i<n ; i++ )
    {
        notChanged += points[i].did_not_change();
    }

    if( notChanged == n ) return true ;

    return false ;
}


bool DotGroup::belongings_quantities_are_unchanged( vector<Center> centers )
{
    int n = centers.size() ;
    int notChanged = 0 ;

    for( int i = 0 ; i<n ; i++ )
    {
        notChanged += centers[i].belonging_points_not_changed();
    }

    if( notChanged == n ) return true ;

    return false ;
}

void DotGroup::display_centers()
{
    for( int i = 0 ; i< (int) centers.size() ; i++ )
    {
        cout << " - " << centers[i].display_point() ;
    }
}



double DotGroup::variance( Center center )
{
    Measure measure = Measure() ;

    double sum = 0, avg=0, var = 0 ;

    vector<Point> assignedPoints = center.return_belonging_points(points);

    double n = assignedPoints.size();

    for( int i = 0 ; i<n ; i++ )
    {
        sum += measure.single_sqDistance(center,assignedPoints[i]);
    }

    avg = sum/n ;

    for( int i = 0 ; i<n ; i++ )
    {
        double thisDistance = measure.single_sqDistance(center,assignedPoints[i]) ;

        var += (avg-thisDistance)*(avg-thisDistance) ;
    }

    var = var/n ;

    return var ;
}
