#include "Logger.hpp"
#ifndef RUN_NAME
#define RUN_NAME "UNOwen"
#endif

void logger_base(std::string label, const char* file, const int line, const char* format, ...)
{
   std::string name=RUN_NAME;
   name += ".log";
   std::ofstream ofs(name,std::ios::app);
   ofs<<label<<" in "<<file<<" L:"<<line<<" ";

   std::va_list args;
   char tsv[256]={'\0'};
   va_start(args,format);
   vsprintf(tsv,format,args);
   va_end(args);
   ofs<<tsv<<std::endl;
}
