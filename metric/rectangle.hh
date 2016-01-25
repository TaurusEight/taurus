#ifndef __RECTANGLE_HH__
#define __RECTANGLE_HH__
// Time-stamp: <2015-12-11 17:08:58 dmendyke>

//
// rectangle.c: Defines a class that used two points to define a rectangle
//


// Required header files
//-----------------------------------------------------------------------------
#include "metric/point.hh" // metric::point class


// Namespace used with this class
//-----------------------------------------------------------------------------
namespace metric {


  // Wrapper around the idea of a rectangle
  //---------------------------------------------------------------------------
  class rectangle {

  public:

    rectangle( const point&, const point& );
    rectangle( const rectangle& );
    virtual ~rectangle();

    const point& measurements() const { return measurements_; };
    int width() const { return measurements_.x; };
    int height() const { return measurements_.y; };



  protected:

  private:

    point measurements_;
    point location_;

  };  // end class rectangle


};  // end NS metric


#endif  // __RECTANGLE_HH__
