#pragma once
#include <climits>

class Triangle
{
   public:
      int  a,  b,  c;   //vertex number
      int  n;           //triangle number
      int AB, BC, CA;   //Neighbor triangle number

   public:
      Triangle() noexcept;
      Triangle
      (
         int a_, int b_, int c_,
         int n_,
         int AB_, int BC_, int CA_
      ) noexcept;
};


class Particle
{
   public:
      Vector3D q;//coordinates
      Vector3D p;//velocity
      Particle();
      Particle(const Vector3D& a, const Vector3D& b);
};
