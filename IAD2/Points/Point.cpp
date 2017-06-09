#include "../headers.h"

using namespace std ;



string dts( double db ) ;

// ----------------

Point::Point( double x, double y )
{
    this->x = x ;
    this->y = y ;

    this->currentCenterID = -1 ;
}

bool Point::did_not_change()
{
    if( currentCenterID == previousCenterID )
    {
        //cout << currentCenterID ;
        return true ;
    }

    //cout << currentCenterID ;
    return false ;
}

bool has_comma( string text )
{
    int n = text.length() ;
    for( int i = 0 ; i<n ; i++ )
    {
        if( text[i] == '.' ) return true ;
    }

    return false ;
}

string Point::display_point()
{
    string strX = dts(x) ;
           if( has_comma(strX) ) strX += "0000" ;
           else strX += ".0000" ;

           if( strX[0] == '-' ) strX = strX.substr(0,6) ;
           else strX = strX.substr(0,5) ;

    string strY = dts(y) ;
           if( has_comma(strY) ) strY += "0000" ;
           else strY += ".0000" ;

           if( strY[0] == '-' ) strY = strY.substr(0,6) ;
           else strY = strY.substr(0,5) ;

    return "(" + strX + "," + strY + ")" ;
}

void Point::set_currentCenterID( int newCenterID )
{
    this->previousCenterID = this->currentCenterID ;

    this->currentCenterID = newCenterID ;

    //if ( this->previousCenterID != this->currentCenterID ) cout << "*" ;
    //else cout << " " ;
}

int Point::return_currentCenterID()
{
    return this->currentCenterID ;
}

double Point::return_x()
{
    return this->x ;
}

double Point::return_y()
{
    return this->y ;
}

