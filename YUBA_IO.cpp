#include "YUBA_IO.hpp"

void OutYUBA(const int& step, const std::vector<Vector3D>& elements, const std::string& file_name, const std::string& tag, bool trunc_f)
{
   std::ofstream ofs(file_name,(trunc_f)?(std::ios::trunc):(std::ios::app));
   ofs<<"# "<<tag<<" "<<step<<"\n";
   for(size_t i=0,size=elements.size();i<size;++i)
   {
      ofs<<i<<" "<<elements.at(i)<<"\n";
   }
   ofs<<"\n";
   ofs.close();
}

void OutYUBA(const int& step, const std::vector<Triangle>& elements, const std::string& file_name, const std::string& tag, bool trunc_f)
{
   std::ofstream ofs(file_name,(trunc_f)?(std::ios::trunc):(std::ios::app));
   ofs<<"# "<<tag<<" "<<step<<"\n";
   for(size_t i=0,size=elements.size();i<size;++i)
   {
      const Triangle& t =elements.at(i);
      ofs<<i<<" "<<t.a<<" "<<t.b<<" "<<t.c<<" "<<t.AB<<" "<<t.BC<<" "<<t.CA<<"\n";
   }
   ofs<<"\n";
   ofs.close();
}

std::vector<Vector3D> get_next_Beads
(
   Getline& gl,
   const std::tuple<int,int>& tr
)
{
   std::vector<Vector3D> res;
   while(gl.is_open())
   {
      std::string tmp = gl.get();
      std::vector<std::string> vs;
      boost::algorithm::split(vs,tmp,boost::is_any_of(" "));
      if("#"==vs.at(0) && "Bead"==vs.at(1))
      {
         const int step = boost::lexical_cast<int>(vs.at(2));
         if(std::get<0>(tr)<=step && step<=std::get<1>(tr))
         {
            //read it!
            while(gl.is_open())
            {
               tmp = gl.get();
               boost::algorithm::split(vs,tmp,boost::is_any_of(" ")); 
               if(""==tmp){break;}
               if("#"==vs.at(0)){gl.back(); break;}
               //Bead-format: x y z
               res.push_back
               (
                  Vector3D
                  (
                     boost::lexical_cast<double>(vs.at(0)),
                     boost::lexical_cast<double>(vs.at(1)),
                     boost::lexical_cast<double>(vs.at(2))
                  ) 
               );
            }
            res.shrink_to_fit();
            return res;
         }
      }
   }
   throw std::out_of_range("end");
   return res;
}

std::vector<Vector3D> get_next_Coordinate
(
   Getline& gl,
   const std::tuple<int,int>& tr
)
{
   std::vector<Vector3D> res;
   while(gl.is_open())
   {
      std::string tmp = gl.get();
      std::vector<std::string> vs;
      boost::algorithm::split(vs,tmp,boost::is_any_of(" "));
      if("#"==vs.at(0) && "Coordinate"==vs.at(1))
      {
         const int step = boost::lexical_cast<int>(vs.at(2));
         if(std::get<0>(tr)<=step && step<=std::get<1>(tr))
         {
            //read it!
            while(gl.is_open())
            {
               tmp = gl.get();
               boost::algorithm::split(vs,tmp,boost::is_any_of(" "));
               if(""==tmp){break;}
               if("#"==vs.at(0)){gl.back(); break;}
               res.push_back
               (
                  Vector3D
                  (
                     boost::lexical_cast<double>(vs.at(1)),
                     boost::lexical_cast<double>(vs.at(2)),
                     boost::lexical_cast<double>(vs.at(3))
                  )
               );
            }
            res.shrink_to_fit();
            return res;
         }
      }
   }
   throw std::out_of_range("end");
   return res;
}

std::vector<Triangle> get_next_Triangle
(
   Getline& gl,
   const std::tuple<int,int>& tr
)
{
   std::vector<Triangle> res;
   while(gl.is_open())
   {
      std::string tmp = gl.get();
      std::vector<std::string> vs;
      boost::algorithm::split(vs,tmp,boost::is_any_of(" "));
      if("#"==vs.at(0) && "Triangle"==vs.at(1))
      {
         const int step = boost::lexical_cast<int>(vs.at(2));
         if(std::get<0>(tr)<=step && step<=std::get<1>(tr))
         {
            //read it!
            while(gl.is_open())
            {
               tmp = gl.get();
               boost::algorithm::split(vs,tmp,boost::is_any_of(" "));
               if(""==tmp){break;}
               if("#"==vs.at(0)){gl.back(); break;}
               res.push_back
               (
                  Triangle
                  (
                     boost::lexical_cast<int>(vs.at(1)),
                     boost::lexical_cast<int>(vs.at(2)),
                     boost::lexical_cast<int>(vs.at(3)),
                     boost::lexical_cast<int>(vs.at(0)),
                     boost::lexical_cast<int>(vs.at(4)),
                     boost::lexical_cast<int>(vs.at(5)),
                     boost::lexical_cast<int>(vs.at(6))
                  )
               );
            }
            res.shrink_to_fit();
            return res;
         }
      }
   }
   throw std::out_of_range("end");
   return res;
}

