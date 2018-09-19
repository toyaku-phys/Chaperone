#pragma once
#include <iostream>
#include <ostream>
#include <cmath>
#include <cfloat>

template <typename T>constexpr double sqr(const T& s);

class Vector3D{
   public:
      double x;
      double y;
      double z;
         
      Vector3D();
      Vector3D(double x_,double y_,double z_);
         
      Vector3D& operator=(const Vector3D& v);
      
      Vector3D& operator+=(const Vector3D& v);
      Vector3D& operator-=(const Vector3D& v);
      Vector3D& operator*=(double k);
      Vector3D& operator/=(double k);
      Vector3D operator+()const;
      Vector3D operator-()const;

      bool operator==(const Vector3D& v) const;
      bool operator!=(const Vector3D& v) const;

      double norm() const;
      double norm2()const;
      
      void normalize();
};

Vector3D operator+(const Vector3D& u, const Vector3D& v);
Vector3D operator-(const Vector3D& u, const Vector3D& v);
Vector3D operator*(double k, const Vector3D& v);
Vector3D operator*(const Vector3D& v, double  k);
Vector3D operator/(const Vector3D& v, double  k);
double operator*(const Vector3D& u, const Vector3D& v);
Vector3D operator%(const Vector3D& u, const Vector3D& v);
double angle(const Vector3D& u, const Vector3D& v);

inline std::ostream& operator<<(std::ostream& s, const Vector3D& v);

inline std::ostream& operator<<(std::ostream& s, const Vector3D& v);
inline double angle(const Vector3D& u, const Vector3D& v);
