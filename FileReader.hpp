#pragma once
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

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
