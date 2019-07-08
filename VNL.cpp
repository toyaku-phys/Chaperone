#include "VNL.hpp"

constexpr double sqr(const double& s){return s*s;}

VNL::VNL(){}

VNL::VNL
(
   double cutoff_length,
   double skin_width,
   const std::vector<Vector3D>* ps1,
   const std::vector<Vector3D>* ps2
) 
{
   set(cutoff_length,skin_width);
   target(ps1,ps2);
}

void VNL::set
(
   double cutoff_length,
   double skin_width
) 
{
   Rc=cutoff_length;
   SKIN=skin_width;
   f_guarantee=false;
}

void VNL::target
(
   const std::vector<Vector3D>* ps1,
   const std::vector<Vector3D>*  ps2
) 
{
   ps1_ptr = ps1;
   ps2_ptr = ps2;
   f_twins = ps1==ps2;
}

void VNL::init() 
{
   neighbor_lists.clear();
   d_1st=std::tuple<bool,int>(true,0);
   d_2nd=d_1st;
   const std::vector<Vector3D>& ps1 = *ps1_ptr;
   const std::vector<Vector3D>& ps2 = *ps2_ptr;
   const double range2 = sqr(Rc+SKIN);
   ps1_displacements.resize(ps1.size());
   ps2_displacements.resize(ps2.size());
   std::fill(ps1_displacements.begin(),ps1_displacements.end(),0.0);
   std::fill(ps2_displacements.begin(),ps2_displacements.end(),0.0);
   size_t max_size=20;
   for(size_t i=0,i_size=ps1.size();i<i_size;++i)
   {
      std::vector<int> neighbors;   neighbors.reserve(max_size);
      for(size_t j=0,j_size=ps2.size();j<j_size;++j)
      {
         if(!(f_twins && i==j))
         {
            if((ps1.at(i)-ps2.at(j)).norm2()<=range2)
            {
               neighbors.emplace_back(j);
            }
         }
      }
      max_size=std::max(max_size,neighbors.size());
      neighbor_lists.emplace_back(neighbors);
   }
   f_guarantee=true;
   return ;
}

const std::vector<int>& VNL::at(int pos) 
{
   if(!f_guarantee){init();}
   return neighbor_lists.at(pos);
}

void VNL::moved
(
   int    pos, 
   double disp,
   bool   is_ps1
) 
{
   const auto get =[this](const std::tuple<bool,int>& d)->double&
   {
      return (std::get<bool>(d))?
             (ps1_displacements.at(std::get<int>(d))):(ps2_displacements.at(std::get<int>(d)));
   };

   std::tuple<bool,int> tmp(is_ps1,pos);
   get(tmp)+=disp;

   if(tmp==d_2nd)
   {
      if(get(d_1st)<get(d_2nd))
      {
         d_1st.swap(d_2nd);
      }
   }else
   {
      if(get(d_1st)<get(tmp))
      {
         d_1st.swap(tmp);
         d_2nd.swap(tmp);
      }else
      if(get(d_2nd)<get(tmp))
      {
         d_2nd.swap(tmp);
      }
   }
   f_guarantee = (get(d_1st)+get(d_2nd))<SKIN;
}

