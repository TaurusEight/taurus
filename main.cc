
#include <iostream>
#include "curses/window.hh"  // curses::window
#include "metric/point.hh"  // metric::point

class app {

public:

  app();
  ~app();

  void sample();
  void refresh() { ::refresh(); };

};  // end class app


app::app() { initscr(); };
app::~app() { endwin(); };

void app::sample( ) {

  curses::window win( 20, 20, 5, 5 );
  //  taurus::panel panel( win );
  box( win, 0, 0 );
  wbkgd( win, COLOR_PAIR( 1 ) );
  mvwprintw( win, 1, 1, "Sample Window" );
  win.refresh();
  while ( getch() != 'q' ) {};

};  // end sample



int main( int, char*[] ) {

  {

    app a;

    start_color();
    init_pair( 1, COLOR_BLUE, COLOR_CYAN );

    a.refresh();
    a.sample();

  };

  metric::point p( 10, 16 );
  std::cout << p << std::endl;

  return 0x0;

};  // end main
