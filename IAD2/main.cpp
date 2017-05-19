#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "headers.h"
using namespace std ;

vector<string> iterate( Measure measure, vector<Point> points, vector<Center> centers ) ;
string dts( double db ) ;

int main()
{


    Reader reader = Reader() ;
    Measure measure = Measure();

    //reader.write_to_csv("test.csv");

    vector<Point> points ;

    vector<Center> centers ;
    centers.push_back( Center(20,20,1)) ;
    centers.push_back( Center(20,0 ,2)) ;
    centers.push_back( Center(0,20 ,3)) ;

    reader.Create_Pairs("test_data.txt",&points) ;

    vector<string> csvLines = iterate(measure,points,centers) ;

    //for(int i = 0 ; i<csvLines.size() ; i++ ) cout << csvLines[i] << '\n' ;

    reader.write_thing_into_csv("test.csv",csvLines);



    cin.get();

    return 0 ;
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

    for( int j = 0 ; j<50 ; j++ )
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



        string line = "" ;
        for( int c = 0 ; c<centers.size() ; c++ )
        {
            line += dts(measure.total_sqDistance(centers[c],centers[c].return_belonging_points(points))) ;
            line += ';' ;
        }
        line += '\n' ;
        outputLines.push_back(line);
    }

    return outputLines ;
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
