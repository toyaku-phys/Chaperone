#include "FileReader.hpp"

Getline::Getline(std::string file_name)
{
   ifs.open(file_name,std::ios::in);
   std::getline(ifs,frontyard);  is_ok_frontyard=(ifs.fail())?false:true;
   std::getline(ifs,backyard );  is_ok_backyard =(ifs.fail())?false:true;
   wait_state=false;
}

std::string Getline::get()
{
   auto res=frontyard;
   load();
   wait_state=false;
   return res;
}

void Getline::load()
{
   if(wait_state) return ;
   frontyard       = backyard;
   is_ok_frontyard = is_ok_backyard;
   std::getline(ifs,backyard);
   if(ifs.fail()){is_ok_backyard=false;}
}

void Getline::back()
{
   assert(!wait_state);
   wait_state=true;
}

bool Getline::is_open()
{
   return is_ok_frontyard;
}
