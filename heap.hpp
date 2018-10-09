#pragma once

class heap
{
   private:
   double sum;
   double c;
   public:
   heap()noexcept{sum=0.0;c=0.0;}
   heap(const double& val)noexcept{sum=val;c=0.0;};
   heap& operator+=(const double& val)noexcept;
   heap& operator=(const double& val)noexcept;
   double get()const noexcept;
};

