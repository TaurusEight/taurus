

#include <iostream>
#include "exception.hh"

int main() {

  try {

    std::cout << "DEBUG" << std::endl;
    throw taurus::exception( 8 );

  } catch( std::exception& e ) {

    std::cout << "DEBUG02" << std::endl;
    std::cout << e.what() << std::endl;

  };  // end try / catch

  return 0;

};  // end main
