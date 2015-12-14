
#include <iostream>
#include "curses/window.hh"  // curses::window
#include "metric/point.hh"  // metric::point

#include <stdexcept>

class twin : public curses::window {
public:
  twin( const metric::point&, const metric::point& );
  ~twin() { };
protected:
private:
};  // end class twin


twin::twin( const metric::point& m, const metric::point& p )
  : curses::window( m.x, m.y, p.x, p.y ) {

  box( 0, 0 );
  wbkgd( COLOR_PAIR( 1 ) );
  mvwprintw( 5, 10, "Simple Window" );

  try {
    refresh();
  } catch( std::runtime_error& e ) {
    std::cout << e.what() << std::endl;
  };  // end try / catch

};  // end twin constructor

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

  twin win( metric::point( 30, 50 ), metric::point( 10, 10 ) );
  while ( getch() != 'q' ) {};

};  // end sample



int main( int, char*[] ) {

  app a;

  start_color();
  init_pair( 1, COLOR_BLUE, COLOR_CYAN );

  a.refresh();
  a.sample();

  return 0x0;

};  // end main
