// Time-stamp: <2015-12-11 13:09:41 dmendyke>

//
// point.cc: Source for the functions of the structure metric::point
//

//-----------------------------------------------------------------------------
#include "point.hh"  // metric::point

//-----------------------------------------------------------------------------
using namespace metric;
using namespace std;

//-----------------------------------------------------------------------------
point::point( int x_, int y_ )
  : x( x_ ), y( y_ ) {};

//-----------------------------------------------------------------------------
point::point( const point& P )
  : point( P.x, P.y ) {};

//-----------------------------------------------------------------------------
point::~point() {};

//-----------------------------------------------------------------------------
ostream& metric::operator<<( ostream& out, const point& P ) {
  out << P.x << "," << P.y;
  return out;
};  // end operator<<

//-----------------------------------------------------------------------------
istream& metric::operator>>( istream& in, point& P ) {
  in >> P.x >> P.y;
  return in;
};  // end operator>>
