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

    void Create_Points( std::string fileName,
                       std::vector<Point>* p_points );

    void write_to_csv( std::string fileName ) ;
    void write_thing_into_csv( std::string fileName, std::vector<std::string> thing ) ;

    private:

};
