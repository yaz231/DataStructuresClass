/** @file NotFoundException.h */
#ifndef _NOT_FOUND_EXCEP
#define _NOT_FOUND_EXCEP
#include <stdexcept> 
#include <string> 
using namespace std; 
class TargetNotFoundException: public exception { 
    public: 
        TargetNotFoundException(const string& message = "")
            : exception("Target not found: " + message.c_str()) // end constructor
}; // end TargetNotFoundException
#endif