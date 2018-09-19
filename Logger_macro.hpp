#pragma once
#define DEBUG log_info(__FILE__, __LINE__, log_level::DEBUG).set_info_to(logger)
#define INFO log_info(__FILE__, __LINE__, log_level::INFO).set_info_to(logger)
#define WARN log_info(__FILE__, __LINE__, log_level::WARN).set_info_to(logger)
#define ERROR log_info(__FILE__, __LINE__, log_level::ERROR).set_info_to(logger)
#define FATAL log_info(__FILE__, __LINE__, log_level::FATAL).set_info_to(logger)
