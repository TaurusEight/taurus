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

    void mvwprintw( int, int, const char* );
    void box( int = 0, int = 0 );
    void wbkgd( const chtype );
    void refresh();

  protected:

    void error( int, const char* );

  private:

    WINDOW* window_;  // handle to the ncurses window pointer

  };  // end class window


};  // end NS curse


#endif  // __WINDOW_HH__
