// Time-stamp: <2015-12-11 12:10:32 dmendyke>

//
// window.cc: Source for the curses::window class
//


// Required head files
//-----------------------------------------------------------------------------
#include "window.hh"  // jinx::window

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

// refresh this window only
void curses::window::refresh( ) {
  ::wrefresh( window_ );
};  // end refresh
