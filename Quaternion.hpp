#pragma once
#include <cmath>
#include <iostream>
#include <cfloat>
#include "Vector3D.hpp"
// Ref http://mathtrain.jp/quaternion

class Quaternion{
   public:
   double a;
   double b;
   double c;
   double d;

   Quaternion();
   Quaternion(const double& a_, const double& b_, const double& c_, const double& d_);
   inline double norm2()const;
   inline double norm()const;
   Quaternion& operator=(const Quaternion& q);
   Quaternion inverse() const;
   Quaternion(const Vector3D& v);
   Quaternion(const Vector3D& v, const double rad);
};

Quaternion operator*(const Quaternion& q, const Quaternion& p);
Quaternion operator*(const Quaternion& q, const Vector3D& v);
Quaternion bar(const Quaternion& q);
std::ostream& operator<<(std::ostream& s, const Quaternion& q);
