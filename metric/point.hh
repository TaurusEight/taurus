#ifndef __POINT_HH__
#define __POINT_HH__
// Time-stamp: <2015-12-11 12:11:33 dmendyke>

//
// point.hh: Part of the 'metric' class of objects
// This structure defines a single point on the screen
//

#include <ostream>
#include <istream>

// Namespace used with this structure
//-----------------------------------------------------------------------------
namespace metric {


  // Wrapper around the concept of a point
  //---------------------------------------------------------------------------
  struct point {

    point( int = 0, int = 0 );
    point( const metric::point& );
    virtual ~point();

    int x;
    int y;

  };  // end class point

  std::ostream& operator<<( std::ostream&, const metric::point& );
  std::istream& operator>>( std::istream&, metric::point& );

};  // end NS metric


#endif  // __POINT_HH__
