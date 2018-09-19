#pragma once
#include <cstdarg>

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

std::ostream& operator<<(std::ostream& os, log_level::type level)
{
   switch (level) {
      case log_level::DEBUG: os << "DEBUG"; break;
      case log_level::INFO:  os << "INFO" ; break;
      case log_level::WARN:  os << "WARN" ; break;
      case log_level::ERROR: os << "ERROR"; break;
      case log_level::FATAL: os << "FATAL"; break;
   }
   return os;
}

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
   log_info(const char* file_name, int line_num, log_level::type level)
   : file_name(file_name), line_num(line_num), level(level)
   {}
   //const member initalize: This initialization is somewhat special. 

   template <class Logger>
   Logger& set_info_to(Logger& logger) const
   {
      logger.set_log_info(*this);
      return logger;
   }
};

void logger_base::set_log_info(const log_info& info)
{
   file_name = info.file_name;
   line_num  = info.line_num;
   level     = info.level;
}

//MACRO has the necessity which can access Logger
#define DEBUG log_info(__FILE__, __LINE__, log_level::DEBUG).set_info_to(logger)
#define INFO log_info(__FILE__, __LINE__, log_level::INFO).set_info_to(logger)
#define WARN log_info(__FILE__, __LINE__, log_level::WARN).set_info_to(logger)
#define ERROR log_info(__FILE__, __LINE__, log_level::ERROR).set_info_to(logger)
#define FATAL log_info(__FILE__, __LINE__, log_level::FATAL).set_info_to(logger)

struct stdout_logger : private logger_base
{
   using logger_base::set_log_info;

   void operator()(const char* format, ...) const
   {
      std::va_list args;
      char tsv[256]={'\0'};
      va_start(args,format);
      vsprintf(tsv,format,args);
      va_end(args);
      
      //output
      std::string name=RUN_NAME;
      name+=".log";
      std::ofstream ofs(name,std::ios::app);
      ofs<< level <<" "<< file_name <<"("<< line_num << "): ";
      ofs<<tsv;
      ofs<<"\n";
   }

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

stdout_logger logger;
