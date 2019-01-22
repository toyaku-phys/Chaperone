#include <ostream>
#include <cmath>
#include "Vector3D.hpp"

constexpr double sqr(const double& s){return s*s;}

Vector3D::Vector3D(){x=y=z=0.0;}

Vector3D::Vector3D(double x_, double y_, double z_)
{
   this->x=x_;  this->y=y_;  this->z=z_;
}

Vector3D& Vector3D::operator=(const Vector3D& v)
{
   this->x=v.x;   this->y=v.y;   this->z=v.z;
   return *this;
}

Vector3D& Vector3D::operator+=(const Vector3D& v)
{
   this->x += v.x;   this->y += v.y;   this->z += v.z;
   return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& v)
{
   this->x -= v.x;   this->y -= v.y;   this->z -= v.z;
   return *this;
}

Vector3D& Vector3D::operator*=(double k)
{
   this->x *= k;  this->y *= k;  this->z *= k;
   return *this;  
}

Vector3D& Vector3D::operator/=(double k)
{
   this->x /= k;  this->y /= k;  this->z /= k;
   return *this;  
}

Vector3D Vector3D::operator+()const
{//+Vector3D
   return *this;
}

Vector3D Vector3D::operator-()const
{//-Vector3D
   return Vector3D(-x,-y,-z);
}

bool Vector3D::operator==(const Vector3D& v)const
{
   return (x==v.x)&&(y==v.y)&&(z==v.z);
}

bool Vector3D::operator!=(const Vector3D& v)const
{
   return !(*this==v);
}

double Vector3D::norm()const
{
   return std::sqrt(x*x+y*y+z*z);
}

double Vector3D::norm2()const
{
   return (sqr(x)+sqr(y)+sqr(z));
}

void Vector3D::normalize()
{
   *this /= norm();
}

Vector3D operator+(const Vector3D& u, const Vector3D& v)
{
      Vector3D w;
      w.x=u.x+v.x;
      w.y=u.y+v.y;
      w.z=u.z+v.z;
      return w;
}

Vector3D operator-(const Vector3D& u, const Vector3D& v)
{
      Vector3D w;
      w.x=u.x-v.x;
      w.y=u.y-v.y;
      w.z=u.z-v.z;
      return w;
}

Vector3D operator*(double k, const Vector3D& v)
{
      return Vector3D(k*v.x, k*v.y, k*v.z);
}

Vector3D operator*(const Vector3D& v, double k)
{
      return Vector3D(v.x*k, v.y*k, v.z*k);
}

Vector3D operator/(const Vector3D& v,double k)
{
      return Vector3D(v.x/k, v.y/k, v.z/k);
}

double operator*(const Vector3D& u, const Vector3D& v)
{
      return u.x*v.x+u.y*v.y+u.z*v.z;
}

Vector3D operator%(const Vector3D& u, const Vector3D& v)
{
      Vector3D w;
      w.x=u.y*v.z-u.z*v.y;
      w.y=u.z*v.x-u.x*v.z;
      w.z=u.x*v.y-u.y*v.x;
      return w;
}

std::ostream& operator<<(std::ostream& s, const Vector3D& v)
{
      return s<<v.x<<" "<<v.y<<" "<<v.z;
}

double angle(const Vector3D& u, const Vector3D& v)
{
      double cos=u*v/(u.norm()*v.norm());
      if( 1.0<cos && std::abs( 1.0-cos)<10*DBL_EPSILON){cos=+1.0;}
      if(-1.0>cos && std::abs(-1.0-cos)<10*DBL_EPSILON){cos=-1.0;}
      return std::acos(cos);
}
