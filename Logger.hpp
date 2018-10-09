#pragma once
#include <cstdarg>
#include <ostream>
#include <fstream>
#include <string>

//DEBUG,
//INFO,
//WARN,
//ERROR,
//FATAL
//

void logger_base(std::string label, const char* file, const int line,const char* format, ...);

#define DEBUG(X) logger_base("DEBUG",__FILE__,__LINE__,X)
#define INFO(X) logger_base("INFO",__FILE__,__LINE__,X)
#define WARN(X) logger_base("WARN",__FILE__,__LINE__,X)
#define ERROR(X) logger_base("ERROR",__FILE__,__LINE__,X)
#define FATAL(X) logger_base("FATAL",__FILE__,__LINE__,X)
