#!/bin/bash

# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Source files
SOURCE_FILES=(
    main.cpp
    BSTClass.cpp
    LogClass.cpp
    supportingFunctions.cpp
)

OUTPUT_NAME="project"

if g++ -Wall -I ./spdlog "${SOURCE_FILES[@]}" -o "$OUTPUT_NAME" -pthread; then
    echo -e "\n\n${GREEN}Successfully compiled into '$OUTPUT_NAME'${NC}"
else
    echo -e "\n\n${RED}ERROR: Compilation failed.${NC}"
fi
