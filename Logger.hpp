#pragma once
#include <cstdarg>
#include <ostream>
#include <fstream>

struct log_level
{
   enum type
   {
      DEBUG,
      INFO,
      WARN,
      ERROR,
      FATAL
   };
};

std::ostream& operator<<(std::ostream& os, log_level::type level);

class log_info;

class logger_base
{
protected:
   const char* file_name;  //note: source file
   int line_num;
   log_level::type level;
public:
   void set_log_info(const log_info& info);
};

class log_info
{
friend class logger_base;

   const char* file_name;
   const int   line_num;
   const       log_level::type level;
public:
   log_info(const char* file_name, int line_num, log_level::type level);

   template <class Logger>
   Logger& set_info_to(Logger& logger) const;
};

struct stdout_logger : private logger_base
{
   using logger_base::set_log_info;
   void operator()(const char* format, ...) const;
};

//NOTE:: Sample code
//int main()
//{
//    stdout_logger logger;
//
//    DEBUG("hoge");
//    ERROR("piyo %d", 10);
//}

//Special thanks for bleis-tift=san
