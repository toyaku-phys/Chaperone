#include "Logger.hpp"
#ifndef RUN_NAME
#define RUN_NAME "UNOwen"
#endif

log_info::log_info(const char* file_name, int line_num, log_level::type level)
   : file_name(file_name), line_num(line_num), level(level)
   {}

template <class Logger>
Logger& log_info::set_info_to(Logger& logger) const
{
   logger.set_log_info(*this);
   return logger;
}

void logger_base::set_log_info(const log_info& info)
{
   file_name = info.file_name;
   line_num  = info.line_num;
   level     = info.level;
}

void stdout_logger::operator()(const char* format, ...) const
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

std::ostream& operator<<(std::ostream& os, log_level::type level)
{
   switch (level) {
      case log_level::DEBUG: os << "DEBUG"; break;
      case log_level::INFO:  os << "INFO" ; break;
      case log_level::WARN:  os << "WARN" ; break;
      case log_level::ERROR: os << "ERROR"; break;
      case log_level::FATAL: os << "FATAL"; break;
      default: break;
   }
   return os;
}

