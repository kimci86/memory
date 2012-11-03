cmake_minimum_required(VERSION 2.8)

# default build type
if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# project name
project(Memory)

# header path
include_directories("${PROJECT_SOURCE_DIR}/include")

# add the subdirectory
add_subdirectory(src)

# install rules
install(FILES README.md DESTINATION . RENAME readme.txt)
