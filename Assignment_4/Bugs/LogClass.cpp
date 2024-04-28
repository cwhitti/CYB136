#include "LogClass.h"

Log::Log( )
{
  // Create a logger with a file sink
  file_logger = spdlog::basic_logger_mt("file_logger", fileName);

  // Set logging level to debug
  file_logger->set_level(spdlog::level::debug);

  // Log messages
  file_logger->info("Logging initialized.");
}

Log::~Log()
{
  if ( outFile.is_open() )
  {
    outFile.close();
  }
}

void Log::LogInfo( string msg )
{
  file_logger->info( msg );
}

void Log::LogError( string msg )
{
  file_logger->error(msg);
}
