#ifndef LOGCLASS_H
#define LOGCLASS_H

#include "supportingFunctions.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>


class Log
{
  public:
      // declare variables
      string fileName = "logs/logs.txt";  // Use std::string instead of string
      ofstream outFile;

      Log();

      ~Log();

      void LogInfo( string msg );

      void LogError( string msg );

      void LogStudent( string firstName, string lastName, string gradeStr );

    private:
      std::shared_ptr <spdlog::logger> file_logger;
};

#endif
