#pragma once

template <typename T>
constexpr double sqr(const T& s){return s*s;}

//ベクトルの定義と各種計算
class Vector3D{
   public:
      double x;
      double y;
      double z;
         
      //コンストラクタ
      Vector3D();
      Vector3D(double x_,double y_,double z_);
         
      //代入演算子
      Vector3D& operator=(const Vector3D& v);
      
      //単項演算子
      Vector3D& operator+=(const Vector3D& v);
      Vector3D& operator-=(const Vector3D& v);
      Vector3D& operator*=(double k);
      Vector3D& operator/=(double k);
      Vector3D operator+()const;
      Vector3D operator-()const;

      //添字演算子
      double& operator[](int i);
      
      //比較演算子
      bool operator==(const Vector3D& v) const;
      bool operator!=(const Vector3D& v) const;

      //ベクトルの長さ
      double norm() const;
      double norm2()const;
      
      //正規化
      void normalize();
      //Vector3D normalize();
};

//ベクトル演算
//Vector3D+Vector3D
Vector3D operator+(const Vector3D& u, const Vector3D& v);
//Vector3D-Vector3D
Vector3D operator-(const Vector3D& u, const Vector3D& v);
//double*Vector3D
Vector3D operator*(double k, const Vector3D& v);
//Vector3D*double
Vector3D operator*(const Vector3D& v, double  k);
//Vector3D/double
Vector3D operator/(const Vector3D& v, double  k);
//内積Vector3D*Vector3D
double operator*(const Vector3D& u, const Vector3D& v);
//外積Vector3D%Vector3D
Vector3D operator%(const Vector3D& u, const Vector3D& v);
//２つのベクトルのなす角
double angle(const Vector3D& u, const Vector3D& v);

//出力
inline std::ostream& operator<<(std::ostream& s, const Vector3D& v);

/********メンバ関数の実装**********************************************/
//コンストラクタ
inline Vector3D::Vector3D(){x=y=z=0.0;}
inline Vector3D::Vector3D(double x_, double y_, double z_){
   this->x=x_;  this->y=y_;  this->z=z_;
}
//代入演算子
inline Vector3D& Vector3D::operator=(const Vector3D& v){
   this->x=v.x;   this->y=v.y;   this->z=v.z;
   return *this;
}
//単項演算子
inline Vector3D& Vector3D::operator+=(const Vector3D& v){
   this->x += v.x;   this->y += v.y;   this->z += v.z;
   return *this;
}
inline Vector3D& Vector3D::operator-=(const Vector3D& v){
   this->x -= v.x;   this->y -= v.y;   this->z -= v.z;
   return *this;
}
inline Vector3D& Vector3D::operator*=(double k){
   this->x *= k;  this->y *= k;  this->z *= k;
   return *this;  
}
inline Vector3D& Vector3D::operator/=(double k){
   this->x /= k;  this->y /= k;  this->z /= k;
   return *this;  
}
inline Vector3D Vector3D::operator+()const{//+Vector3D
   return *this;
}
inline Vector3D Vector3D::operator-()const{//-Vector3D
   return Vector3D(-x,-y,-z);
}
////添字演算子
//inline double Vector3D::operator[](const int& i)const{
// if(i==0){
//          return x;
// }else if(i==1){
//          return y;
// }else if(i==2){
//          return z;
// }else{
//          exit(1);
// }
//}
//比較演算子
inline bool Vector3D::operator==(const Vector3D& v)const{
   return (x==v.x)&&(y==v.y)&&(z==v.z);
}
inline bool Vector3D::operator!=(const Vector3D& v)const{
   return !(*this==v);
}
//ベクトルの長さ
inline double Vector3D::norm()const{
   return std::hypot(x,y,z);
}
inline double Vector3D::norm2()const{
   return (sqr(x)+sqr(y)+sqr(z));
}
//正規化
inline void Vector3D::normalize(){
   *this /= norm();
}
/********グローバル関数の実装**********************************************/
//二項演算子の定義
//Vector3D+Vector3D
inline Vector3D operator+(const Vector3D& u, const Vector3D& v){
      Vector3D w;
      w.x=u.x+v.x;
      w.y=u.y+v.y;
      w.z=u.z+v.z;
      return w;
}
//Vector3D-Vector3D
inline Vector3D operator-(const Vector3D& u, const Vector3D& v){
      Vector3D w;
      w.x=u.x-v.x;
      w.y=u.y-v.y;
      w.z=u.z-v.z;
      return w;
}
//double*Vector3D
inline Vector3D operator*(double k, const Vector3D& v){
      return Vector3D(k*v.x, k*v.y, k*v.z);
}
//Vector3D*double
inline Vector3D operator*(const Vector3D& v, double k){
      return Vector3D(v.x*k, v.y*k, v.z*k);
}
//Vector3D/double
inline Vector3D operator/(const Vector3D& v,double k){
      return Vector3D(v.x/k, v.y/k, v.z/k);
}
//内積 Vector3D*Vector3D
inline double operator*(const Vector3D& u, const Vector3D& v){
      return u.x*v.x+u.y*v.y+u.z*v.z;
}
//外積 Vector3D%Vector3D
inline Vector3D operator%(const Vector3D& u, const Vector3D& v){
      Vector3D w;
      w.x=u.y*v.z-u.z*v.y;
      w.y=u.z*v.x-u.x*v.z;
      w.z=u.x*v.y-u.y*v.x;
      return w;
}
//画面への表示
inline std::ostream& operator<<(std::ostream& s, const Vector3D& v){
      return s<<v.x<<" "<<v.y<<" "<<v.z;
}
//２つのベクトルのなす角(rad)
inline double angle(const Vector3D& u, const Vector3D& v){
      double cos=u*v/(u.norm()*v.norm());
      return std::acos(cos);
}
