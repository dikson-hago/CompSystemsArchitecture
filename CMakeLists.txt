# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(task1 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
    # Headers
    Map/map.h
    Map/mapBuilder.h
    Models/constants.h
    Models/coord.h
    Models/randomiser.h
    Models/steps.h
    Pirates/group.h
    Pirates/silver.h
    errorMessages.h

    # Sources
    main.cpp
    Map/map.cpp
    Map/mapBuilder.cpp
    Models/coord.cpp
    Models/randomiser.cpp
    Models/steps.cpp
    Pirates/group.cpp
    Pirates/silver.cpp
)

add_executable(task ${SOURCE_FILES})
