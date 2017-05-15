#include <string>
#include <cstdlib>
#include "../headers.h"

using namespace std ;

Reader::Reader()
{

}

vector<string> Reader::Read( string fileName )
{
    char* fileNameC = (char*) &fileName[0] ;
    vector<string> textLines ;
    string thisLine, previousLine ;

    ifstream myFile;
    myFile.open (fileNameC);

    if( myFile.is_open() )
    {
        for(int i = 0;;i++)
        {
            previousLine = thisLine ;
            getline(myFile,thisLine);

            if ( thisLine == previousLine ) break ;
            else textLines.push_back(thisLine);
        }
    }
    else cout << "There is no \"" << fileName << "\" file.\n\n" ;

    myFile.close();

    return textLines ;
}

vector<Point> Reader::Parse_All_Lines( vector<string> lines )
{
    vector<Point> points ;

    for( vector<string>::iterator i = lines.begin() ; i != lines.end() ; i++ )
    {
        //cout << *i << endl ;
        points.push_back( Parse_Line(*i) );
    }

    //cout << "\n\n" ;

    return points ;
}

Point Reader::Parse_Line( string textLine )
{
    int len = textLine.length() ;
    int spaceIndex ;

    for( int i = 0 ; i<len ; i++ )
    {
        if ( textLine[i] == ',' )
        {
            spaceIndex = i ;
            break ;
        }
    }

    string xx, yy ;

    xx = textLine.substr(0,spaceIndex) ;
    yy = textLine.substr(spaceIndex+1,len-spaceIndex-1) ;
    //cout << sinput << "_" << soutput << endl ;

    //float input, output ; // convert strings to floats

    int x = (int) atof(xx.c_str());
    int y = (int) atof(yy.c_str());

    return Point(x,y) ;
}


void Reader::Create_Pairs( string fileName, vector<Point>* p_points )
{
        vector<string> lines = Read(fileName) ;
        *p_points = Parse_All_Lines(lines) ;

        //lines = Read(FileNameB) ;
        //*pPointsB = Parse_All_Lines(lines) ;
}
