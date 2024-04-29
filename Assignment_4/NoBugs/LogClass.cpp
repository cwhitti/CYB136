#include "LogClass.h"

Log::Log( )
{
  // Create a logger with a file sink
  file_logger = spdlog::basic_logger_mt("file_logger", fileName);

  // Set logging level to debug
  file_logger->set_level(spdlog::level::debug);

  // Log messages
  LogInfo("Initialized Logging");
}

Log::~Log()
{
  LogInfo("Stopped Logging");
  spdlog::shutdown();
}

void Log::LogStudent( string firstName, string lastName, string gradeStr )
{
  string outStr;

  outStr = "Added new student: " + lastName + ", " + firstName;

  LogInfo(outStr);

}
void Log::LogInfo( string msg )
{
  file_logger->info( msg );
}

void Log::LogError( string msg )
{
  file_logger->error(msg);
}
