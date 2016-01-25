// Time-stamp: <2016-01-25 15:33:15 dmendyke>
#ifndef __EXCEPTION_HH__
#define __EXCEPTION_HH__


// Required header files
//-----------------------------------------------------------------------------
#include <stdexcept>  // std::runtime_error
#include <memory>  // std::unique_ptr


// Namespace used with this exception class
//-----------------------------------------------------------------------------
namespace taurus {

  // Wrapper around an excpetion class used with this class library
  //---------------------------------------------------------------------------
  class exception : public std::runtime_error {

  public:

    exception( int );
    exception( const exception& );
    const char* what() const noexcept;

  private:

    enum { length = 96 };  // length of the message string
    std::string message_;  // error message

  };  // end class exception

};  // end NS taurus


#endif  // __EXCEPTION_HH__
