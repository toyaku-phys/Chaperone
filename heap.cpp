#include "heap.hpp"

#pragma clang optimize off
heap& heap::operator+=(const double& val) noexcept
{
   const auto y = val - c;
   const auto t = (this->sum) + y;
   this->c      = (t-(this->sum))-y;
   this->sum    = t;
   return *this;
}
#pragma clang optimize on

heap& heap::operator=(const double& val) noexcept
{
   this->sum = val;
   this->c   =0.0;
   return *this;
}

double heap::get() const noexcept
{
   return sum;   
}

