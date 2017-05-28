#include "../headers.h"
#include <conio.h>
using namespace std ;

extern bool displayTextNotPixels ;
extern bool getchUsed ;

DotGroup::DotGroup( string fileName, bool forgy, int nOfCenters, int nOfPoints )
{
    srand (time(NULL));

    Reader reader = Reader() ;

    if(fileName!="") reader.Create_Points(fileName,&this->points) ;
    else randomize_points(nOfPoints) ;

    if(!forgy) randomize_centers(nOfCenters);
    else forgy_centers(nOfCenters) ;


}


std::vector<Point> DotGroup::return_points()
{
    return this->points ;
}

std::vector<Center> DotGroup::return_centers()
{
    return this->centers ;
}


void DotGroup::display_sum_of_distances()
{
    Measure measure = Measure() ;
    cout << "\nSum of distances: " << measure.all_totalDistances(centers,points) << '\n' ;
}



void DotGroup::display_all_distances()
{
    Measure measure = Measure() ;

    for( int i = 0 ; i<centers.size() ; i++ )
    {
        cout << "\nCenter " << centers[i].display_point() << ": distance sum = " << measure.total_Distance(centers[i],points) ;
    }
}


void DotGroup::display_all_variances()
{
    Measure measure = Measure() ;

    for( int i = 0 ; i<centers.size() ; i++ )
    {
        cout << "\nCenter " << centers[i].display_point() << ": variance sum = " << measure.variance(centers[i],points) ;
    }
}



void DotGroup::randomize_centers( int number )
{
    //vector<Center> centers ;

    if(displayTextNotPixels) cout << "Centers created:\n\n" ;

    for( int i = 0 ; i<number ; i++ )
    {
        double x = (double) (rand()%600-300)/20 ;

        double y = (double) (rand()%600-300)/20 ;


        this->centers.push_back(Center(x,y,i)) ;

        if(displayTextNotPixels) cout << "(" << x << "," << y << ")\n" ;
    }

    if(displayTextNotPixels) cout << "\n----------\n" ;

    //return centers ;

  /* generate secret number between 1 and 10: */
  //int i = rand() % 10 + 1;
}


void DotGroup::randomize_points( int number )
{
    //vector<Point> points ;

    //if(displayTextNotPixels) cout << "Centers created:\n\n" ;

    for( int i = 0 ; i<number ; i++ )
    {
        double x = (double) (rand()%600-300)/20 ;

        double y = (double) (rand()%600-300)/20 ;


        this->points.push_back(Point(x,y)) ;

        //if(displayTextNotPixels) cout << "(" << x << "," << y << ")\n" ;
    }

    //if(displayTextNotPixels) cout << "\n----------\n" ;

    //return points ;

  /* generate secret number between 1 and 10: */
  //int i = rand() % 10 + 1;
}

void DotGroup::forgy_centers( int numberOfCenters )
{
    int n = points.size() ;

    for( int i = 0 ; i<numberOfCenters ; i++ )
    {
        int k = rand()%n ;

        double x = points[k].return_x() ;
        double y = points[k].return_y() ;

        this->centers.push_back(Center(x,y,i)) ;
    }
}




vector<string> DotGroup::iterate(int xmar, int ymar)
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

    header += ";;" ;

    for( int c = 0 ; c< (int) centers.size() ; c++ )
    {
        header += "C["+dts(c+1) ;
        header += "];" ;
    }

    header += ";;" ;

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
            //allCentersDistance += measure.total_Distance(centers[i],points) ;
        }

        //cout << "Total distance = " << allCentersDistance << '\n' ;

        //vector<Point> cpoints = centers[1].return_belonging_points(points) ;
        //cout << "\n - dist[1] = " << measure.total_Distance(centers[1],cpoints);
        //cout << "\n\n" ;

        string countLine = "" ;

        string line = "" ;
        for( int c = 0 ; c< (int) centers.size() ; c++ )
        {
            line += dts(measure.total_Distance(centers[c],points)) ;
            line += " ; " ;

            vector<Point> belongingPoints = centers[c].return_belonging_points(points) ;
            //countLine += dts((double) belongingPoints.size() ) + "   " ;

            //painter.draw_points(belongingPoints,cent)
        }

        line += ";;" ;

        for( int c = 0 ; c< (int) centers.size() ; c++ )
        {
            line += dts(measure.variance(centers[c],points)) ;
            line += ";" ;
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
            painter.draw_points(points,centers,xmar,ymar) ; // temporary unseperated into center-groups


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




