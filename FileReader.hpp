#ifndef FILE_READER_HPP
#define FILE_READER_HPP

class Getline
{
   private:
      std::ifstream ifs;
      std::string frontyard;
      std::string backyard;
      bool is_ok_frontyard;
      bool is_ok_backyard;
      bool wait_state;
   public:
      Getline(std::string file_name);
      std::string get();
      void back();
      bool is_open();
   private:
      void load();
};

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

#endif
