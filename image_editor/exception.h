#pragma once

#include <exception>

class Exception : public std::exception
{
    using std::exception::exception;
};
