#pragma once

template <typename T>
class heap
{
   private:
   T sum;
   T c;
   public:
   heap<T>()noexcept{}
   heap<T>(const T& val)noexcept;
   heap<T>& operator+=(const T& val)noexcept;
   heap<T>& operator=(const T& val)noexcept;
   T get()const noexcept;
};

#pragma clang optimize off
template <typename T>
inline heap<T>& heap<T>::operator+=(const T& val) noexcept
{
   const auto y = val - c;
   const auto t = (this->sum) + y;
   this->c      = (t-(this->sum))-y;
   this->sum    = t;
   return *this;
}
#pragma clang optimize on

template <typename T>
inline heap<T>& heap<T>::operator=(const T& val) noexcept
{
   this->sum = val;
   this->c   =0.0;
   return *this;
}

template <typename T>
inline T heap<T>::get() const noexcept
{
   return sum;   
}

//ex.
//int main()
//{
//   heap<double> hoo;   
//   heap+=1.23456789;
//   heap+=10.2465725;
//   heap+=3475.94859;
//   printf("%1.15e\n",hoo.get());
//}

