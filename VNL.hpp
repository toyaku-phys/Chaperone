#pragma once

#include <vector>
#include <tuple>
#include <string>

#include "Chaperone/Vector3D.hpp"
#include "Chaperone/heap.hpp"

class VNL
{
   public:
      explicit VNL();
      explicit VNL
      (
         double cutoff_length,
         double skin_width,
         const std::vector<Vector3D>* ps1,
         const std::vector<Vector3D>* ps2
      ) noexcept(In_RELEASE);
   private:
      const std::vector<Vector3D>* ps1_ptr;
      const std::vector<Vector3D>* ps2_ptr;
   private:
      double Rc;
      double SKIN;
      bool   f_guarantee;
      bool   f_twins;
      std::vector<std::vector<int> > neighbor_lists;
      std::vector<double>            ps1_displacements;
      std::vector<double>            ps2_displacements;
      std::tuple<bool,int>           d_1st;//(is_ps1,pos)
      std::tuple<bool,int>           d_2nd;
   public:
      void set(double cutoff_length, double skin_width) noexcept(In_RELEASE);
      void target
         (
            const std::vector<Vector3D>* ps1,
            const std::vector<Vector3D>* ps2
         ) noexcept(In_RELEASE);
      void moved
         (
            int pos, 
            double disp,
            bool is_ps1
         ) noexcept(In_RELEASE);
      const std::vector<int>& at(int pos) noexcept(In_RELEASE);
   private://subroutine
      void init() noexcept(In_RELEASE);
};
