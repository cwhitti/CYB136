cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add spdlog library
add_subdirectory(spdlog)

# Add your source files
set(SOURCE_FILES
    main.cpp
    BSTClass.cpp
    LogClass.cpp
    supportingFunctions.cpp
)

# Create executable
add_executable(your_program ${SOURCE_FILES})

# Link spdlog library
target_link_libraries(your_program PRIVATE spdlog::spdlog)
