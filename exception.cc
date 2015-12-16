// Time-stamp: <2015-12-14 02:38:08 daniel>

//
// exception.cc: Exception class used with the taurus library
//


// Requried header files
//------------------------------------------------------------------------------
#include <cerrno>  // error number
#include <cstring>  // strerror_r
#include "exception.hh"  // taurus::exception


#include <iostream>


// NS Short-cuts
//-----------------------------------------------------------------------------
//using namespace taurus;  // library NS shortcut


// Class constructor
//-----------------------------------------------------------------------------
taurus::exception::exception( int err_num )
  : std::runtime_error( nullptr ),
    message_( "xx" ) {

  std::cout << "constructor" << std::endl;

  char message[ exception::length ];
  if ( strerror_r( err_num, message, exception::length ) != 0x0 ) {
    throw runtime_error( "Call to strerror_r failed!" );
  };  // end if strerror

  std::cout << "message_: " << message_ << std::endl;
  message_.assign( message );  // save the message

};  // end constructor


// Copy constructor
//-----------------------------------------------------------------------------
taurus::exception::exception( const taurus::exception& except )
  : std::runtime_error( nullptr ),
    message_( except.message_ ) {

  std::cout << "copy constructor" << std::endl;

};  // end copy construtor

// Return the error message
//-----------------------------------------------------------------------------
const char* taurus::exception::what() const noexcept {
  std::cout << "DEBUG03" << std::endl;
  return message_.c_str();
};  // end what
