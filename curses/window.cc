// Time-stamp: <2015-12-14 03:30:40 daniel>

//
// window.cc: Source for the curses::window class
//


// Required head files
//-----------------------------------------------------------------------------
#include "window.hh"  // jinx::window

#include <stdexcept>
#include <sstream>

// main constructor
curses::window::window( int l, int c, int y, int x ) : window_( nullptr ) {
  window_ = ::newwin( l, c, y, x );
};  // end constructor

// copy constructor
curses::window::window( const curses::window& W ) : window_( W.window_ ) { };

// destructor
curses::window::~window( ) {
  if ( window_ == nullptr ) return;  // nothing to do
  delwin( window_ );
};  // end destructor


void curses::window::error( int result, const char* text ) {
  if ( result != OK ) {
    std::ostringstream out;
    out << text << " failed";
    throw std::runtime_error( out.str() );
  };  // end if
};  // end error


// refresh this window only
void curses::window::refresh( ) {
  error( ::wrefresh( window_ ), "wrefresh" );
};  // end refresh

// Draw a box around
void curses::window::box( int x, int y ) {
  error( ::box( window_, x, y ), "box" );
};  // end box

// Color the background of this window
void curses::window::wbkgd( const chtype color ) {
  error( ::wbkgd( window_, color ), "wbkgd" );
};  // end wbkgd

// Draw text to this window
void curses::window::mvwprintw( int x, int y, const char* text ) {
  error( ::mvwprintw( window_, x, y, text ), "mvwprintw" );
};  // end mvwprintw
