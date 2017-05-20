#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "headers.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */








using namespace std ;

vector<string> iterate( Measure measure, vector<Point> points, vector<Center> centers ) ;
string dts( double db ) ;
bool no_point_changed( vector<Point> points ) ;
vector<Center> randomize_centers( int number ) ;
void draw() ;
void draw_points( vector<Point> points, vector<Center> centers = vector<Center>(), int margin = 0 ) ;

int main()
{



    srand (time(NULL));

    Reader reader = Reader() ;
    Measure measure = Measure();

    //reader.write_to_csv("test.csv");

    vector<Point> points ;
    reader.Create_Pairs("test_data.txt",&points) ;
    vector<Center> centers = randomize_centers(10);

    Painter painter ;

    painter.draw_points(points,centers,100);

    cin.get();
    return 0 ;



    vector<string> csvLines = iterate(measure,points,centers) ;

    //for(int i = 0 ; i<csvLines.size() ; i++ ) cout << csvLines[i] << '\n' ;

    reader.write_thing_into_csv("test.csv",csvLines);



    cin.get();

    return 0 ;
}

// ----------------------------------------------------------------

vector<Center> randomize_centers( int number )
{
    vector<Center> centers ;

    cout << "Centers created:\n\n" ;

    for( int i = 0 ; i<number ; i++ )
    {
        double x = (double) (rand()%2000 - 1000) ;
        x = x/100 ;

        double y = (double) (rand()%2000 - 1000) ;
        y = y/100 ;


        centers.push_back(Center(x,y,i)) ;

        cout << "(" << x << "," << y << ")\n" ;
    }

    cout << "\n----------\n" ;

    return centers ;

  /* generate secret number between 1 and 10: */
  //int i = rand() % 10 + 1;
}

vector<string> iterate( Measure measure, vector<Point> points, vector<Center> centers )
{
    vector<string> outputLines ;
    string header = "" ;

    for( int c = 0 ; c<centers.size() ; c++ )
    {
        header += "C["+dts(c+1) ;
        header += "];" ;
    }
    header += '\n' ;

    outputLines.push_back(header);

    for(int j = 0 ; ; j++)
    {
        for( int i = 0 ; i<points.size() ; i++ )
        {
            measure.set_closest_center(&points[i],centers);
        }

        //double allCentersDistance = 0 ;

        for( int i = 0 ; i<centers.size() ; i++ )
        {
            centers[i].reposition_center(points) ;
            //allCentersDistance += measure.total_sqDistance(centers[i],points) ;
        }

        //cout << "Total distance = " << allCentersDistance << '\n' ;

        //vector<Point> cpoints = centers[1].return_belonging_points(points) ;
        //cout << "\n - dist[1] = " << measure.total_sqDistance(centers[1],cpoints);
        //cout << "\n\n" ;

        string countLine = "" ;

        string line = "" ;
        for( int c = 0 ; c<centers.size() ; c++ )
        {
            line += dts(measure.total_sqDistance(centers[c],centers[c].return_belonging_points(points))) ;
            line += " ; " ;

            countLine += dts((double) centers[c].return_belonging_points(points).size()) + "   " ;
        }

        line += ";;" ;

        for( int c = 0 ; c<centers.size() ; c++ )
        {
            line += centers[c].display_point();
            line += " ; " ;
        }

        cout << countLine << '\n' ;

        line += '\n' ;
        outputLines.push_back(line);

        if( j%10==0 && no_point_changed(points) ) break ;
    }

    return outputLines ;
}

// ----------------------------------------------------------------

bool no_point_changed( vector<Point> points )
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

void show_points( vector<Point> points)
{
    for( int i = 0 ; i<points.size() ; i++ )
    {
        int x = points[i].return_x() ;
        int y = points[i].return_y() ;

        cout << "(" << x << "," << y << ")\n" ;
    }
}



string dts( double db )
{
    ostringstream strs;
    strs << db;
    string str = strs.str();

    return str ;
}
