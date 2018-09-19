#include "constexpr_math.hpp"

namespace cexpr_math{
template <typename T>
constexpr T sqr(T s)
{
   return s*s;
}

template <typename T>
constexpr T sqrt(T s)
{
   T x = s / 2.0;
   T prev = 0.0;
   while(x!=prev)
   {
      prev=x;
      x=(x+s/x)/2.0;
   }
    return x;
}

template constexpr double sqrt<double>(double);

template <typename T>
constexpr double max(const T& v1, const T& v2){return (v1<v2)?v2:v1;}

template <typename T>
constexpr T pow(const T& a, const unsigned int b)
{
   T result=a;
   for(unsigned int i=1;i<b;++i){result*=a;}
   return result;
}

}

