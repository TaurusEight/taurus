// Time-stamp: <2016-01-25 15:49:49 dmendyke>

//
// exception.cc: Exception class used with the taurus library
//
// Time-stamp: <>

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
  : std::runtime_error( "" ),
    message_( ) {

  std::cout << "constructor" << std::endl;

  char buffer[ exception::length ];
  auto cstr = strerror_r( err_num, buffer, exception::length );

  if ( cstr == 0x0 ) throw runtime_error( "Call to strerror_r failed!" );


  std::cout << "cstr: " << cstr[ 0 ] << std::endl;
  message_.assign( cstr );  // save the message
  std::cout << "err_num: " << err_num << " -- message_: " << message_ << std::endl;

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
