#include "constexpr_math.hpp"

namespace cexpr_math{

constexpr double sqr(double s)
{
   return s*s;
}

constexpr double sqrt(double s)
{
   double x = s / 2.0;
   double prev = 0.0;
   while(x!=prev)
   {
      prev=x;
      x=(x+s/x)/2.0;
   }
    return x;
}

constexpr double max(const double& v1, const double& v2){return (v1<v2)?v2:v1;}

constexpr double pow(const double& a, const unsigned int b)
{
   double result=a;
   for(unsigned int i=1;i<b;++i){result*=a;}
   return result;
}

}

