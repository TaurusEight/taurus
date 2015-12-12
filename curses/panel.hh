#ifndef __PANEL_HH__
#define __PANEL_HH__

namespace jinx {

  class panel {

  public:

    panel( WINDOW* );  // constructor
    panel( const panel& );  // copy constructor
    virtual ~panel();  // destructor

    operator WINDOW*() { return window_; };
    operator PANEL*() { return panel_; };

    static update() { ::update_panels(); };

    void hide();
    void show();
    void del();
    void top();
    void bottom();
    panel* above();
    panel* below();
    void move( int, int );
    bool hidden();

  protected:


  private:

    WINDOW* window_;  // pointer to the window structor
    PANEL* panel_;  // pointer to the panel structor

  };  // end class panel

};  // end NS jinx

#endif  // __PANEL_HH__
