#include "LogClass.h"

Log::Log()
{
  // Create a logger with a file sink
  auto file_logger = spdlog::basic_logger_mt("file_logger", outFile);

  // Set logging level to debug
  file_logger->set_level(spdlog::level::debug);

  // Log messages
  file_logger->info("Logging initialized.");
  file_logger->debug("This is a debug message.");
  file_logger->error("An error occurred.");
}
Log::~Log()
{
}
