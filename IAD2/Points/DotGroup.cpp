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

    if(!forgy) random_partition(nOfCenters);
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


void DotGroup::display_all_std_deviations()
{
    Measure measure = Measure() ;

    for( int i = 0 ; i<centers.size() ; i++ )
    {
        cout << "\nCenter " << centers[i].display_point() << ": std_deviation sum = " << measure.std_deviation(centers[i],points) ;
    }
}







void DotGroup::random_partition( int number )
{
    //vector<Center> centers ;

    //if(displayTextNotPixels) cout << "Centers created:\n\n" ;

    for( int i = 0 ; i<number ; i++ )
    {
        double x = (double) (rand()%600-300)/20 ;
        double y = (double) (rand()%600-300)/20 ;

        this->centers.push_back(Center(x,y,i)) ;

        //if(displayTextNotPixels) cout << "(" << x << "," << y << ")\n" ;
    }

    for( int i = 0 ; i<points.size();i++)
    {
            int r = rand()%number ;
            points[i].set_currentCenterID(r);
    }


    //if(displayTextNotPixels) cout << "\n----------\n" ;

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




vector<string> DotGroup::iterate(int xmar, int ymar, bool graphics)
{
    Painter painter = Painter() ;
    Measure measure = Measure();

    vector<string> outputLines ;
    string header = output_column_headers(centers.size());
    outputLines.push_back(header);

    int k = 0 ;

    //for(int j=0;j<1;j++)
    //for(int j = 0 ; !assigned_quantities_are_unchanged( centers ) ; j++)
    for(int j = 0 ; !no_point_changed() ; j++)
    {
        string line = "" ;

        int ip = 500, ic = -13 ;

        for( int i = 0 ; i< (int) points.size() ; i++ )
        {
            int display = -1 ;
            //if(i==ip) display = ic ;
            measure.set_closest_center(&points[i],centers,display);
        }

        for( int c = 0 ; c< (int) centers.size() ; c++ )
        {
            line += dts(measure.total_Distance(centers[c],points)) ;
            line += " ; " ;
        }

        line += ";;" ;

        for( int c = 0 ; c< (int) centers.size() ; c++ )
        {
            line += dts(measure.std_deviation(centers[c],points)) ;
            line += ";" ;
        }

        for( int i = 0 ; i< (int) centers.size() ; i++ )
        {
            centers[i].update_assigned_quantities(points); // is always 1 step behind; shows previous state of belongings
            centers[i].reposition_center(points) ;
        }

        line += ";;" ;

        for( int c = 0 ; c< (int) centers.size() ; c++ )
        {
            line += centers[c].display_point();
            line += " ; " ;
        }

        {
            if( getchUsed )
            {
                do
                {
                    k=getch();
                }
                while(k<1);

                k=0 ;
            }

            if(graphics) painter.draw_points(points,centers,xmar,ymar) ; // temporary unseperated into center-groups
        }




        //cout << "&&&&&" ;

        line += '\n' ;
        outputLines.push_back(line);
    }

    return outputLines ;
}



bool DotGroup::no_point_changed( )
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


bool DotGroup::assigned_quantities_are_unchanged( vector<Center> centers )
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

/*
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

   generate secret number between 1 and 10:
  //int i = rand() % 10 + 1;
}
*/

