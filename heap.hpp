#pragma once

template <typename T>
class heap
{
   private:
   T sum;
   T c;
   public:
   heap<T>()noexcept{sum=0.0;c=0.0;}
   heap<T>(const T& val)noexcept{sum=val;c=0.0;};
   heap<T>& operator+=(const T& val)noexcept;
   heap<T>& operator=(const T& val)noexcept;
   T get()const noexcept;
};

