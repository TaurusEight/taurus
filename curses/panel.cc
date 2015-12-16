// Time-stamp: <2015-12-12 07:02:53 daniel>

#include "panel.hh"  // curses::panel

//using namespace curses;


curses::panel::panel( WINDOW* W )
  : window_( W ), panel_( nullptr ) {
  panel_ = ::new_panel( W );
};  // end constructor


curses::panel::panel( const curses::panel& P )
  : window_( P.window_ ), panel_( P.panel_ ) {};


curses::panel::~panel( ) {
  ::del_panel( panel_ );
};  // end destructor
