#include "Quaternion.hpp"

Quaternion::Quaternion(){a=0.0;b=0.0;c=0.0;d=0.0;}

Quaternion::Quaternion(const double& a_, const double& b_, const double& c_, const double& d_)
{
   a=a_;b=b_;c=c_;d=d_;
}

inline double Quaternion::norm2()const
{
   return a*a+b*b+c*c+d*d;
}

inline double Quaternion::norm()const
{
   return sqrt(this->norm2());
}

Quaternion& Quaternion::operator=(const Quaternion& q)
{
   this -> a = q.a;
   this -> b = q.b;
   this -> c = q.c;
   this -> d = q.d;
   return *this;
}

Quaternion Quaternion::inverse() const
{
   Quaternion result=bar(*this);
   const double nrm = this->norm2();
   result.a /= nrm;
   result.b /= nrm;
   result.c /= nrm;
   result.d /= nrm;
   return result;
}

Quaternion::Quaternion(const Vector3D& v)
{
   a=0.0;
   b=v.x;
   c=v.y;
   d=v.z;
}
   
Quaternion::Quaternion(const Vector3D& v, const double rad)
{
   a=cos(0.5*rad);
   Vector3D v_=v/v.norm();
   const Vector3D u=v_*sin(0.5*rad);
   b=u.x;
   c=u.y;
   d=u.z;
}

Quaternion operator*(const Quaternion& q, const Quaternion& p)
{
   return Quaternion
      (
         ((q.a * p.a) - (q.b * p.b) - (q.c * p.c) - (q.d * p.d)),
         ((q.a * p.b) + (q.b * p.a) + (q.c * p.d) - (q.d * p.c)),
         ((q.a * p.c) - (q.b * p.d) + (q.c * p.a) + (q.d * p.b)),
         ((q.a * p.d) + (q.b * p.c) - (q.c * p.b) + (q.d * p.a))
      );
}

Quaternion operator*(const Quaternion& q, const Vector3D& v)
{
   const Quaternion v_(v);
   return q*v_;
}

Quaternion bar(const Quaternion& q)
{
   return Quaternion(q.a,-q.b,-q.c,-q.d);
}

std::ostream& operator<<(std::ostream& s, const Quaternion& q)
{
      auto sign = [&s](const double& d)
      {
         if(d>10*DBL_EPSILON)
         {s<<"+"<<d;}
         else if(d<-10*DBL_EPSILON)
         {s<<d;}
         else
         {
            s<<"+0"; 
         }
      };
      sign(q.a);
      sign(q.b);s<<"i";
      sign(q.c);s<<"j";
      sign(q.d);s<<"k";
      return s;
}
