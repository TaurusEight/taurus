#ifndef __WINDOW_HH__
#define __WINDOW_HH__


// Required header files
//-----------------------------------------------------------------------------
#include <ncurses.h>  // ncusrsed header file


// Namespace used with this class
//-----------------------------------------------------------------------------
namespace curses {


  // Wrapper around an ncurses window object
  //---------------------------------------------------------------------------
  class window {

  public:

    window( int, int, int, int );
    window( const curses::window& );
    virtual ~window();

    operator WINDOW*() { return window_; };

    void refresh();

  protected:


  private:

    WINDOW* window_;  // handle to the ncurses window pointer

  };  // end class window


};  // end NS curse


#endif  // __WINDOW_HH__
