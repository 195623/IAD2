#include <iostream>
#include <fstream>
#include <vector>

class Point ;

class Reader
{
public:
    Reader() ;
    std::vector<std::string> Read( std::string fileName ) ;

    Point Parse_Line( std::string textLine ) ;

    std::vector<Point> Parse_All_Lines( std::vector<std::string> lines ) ;

    void Create_Pairs( std::string FileNameA,
                       std::vector<Point>* pPointsA,
                       std::string FileNameB,
                       std::vector<Point>* pPointsB );

    private:

};
