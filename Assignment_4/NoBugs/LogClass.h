#ifndef LOGCLASS_H
#define LOGCLASS_H

#include "supportingFunctions.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>


class Log
{
  public:
      // declare variables
      string outFile = "logs/logs.txt";  // Use std::string instead of string

      // functions
      Log();

      ~Log();
};

#endif
