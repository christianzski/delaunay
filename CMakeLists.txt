cmake_minimum_required(VERSION 3.5)
project(delaunay)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Werror")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(BUILD_SHARED_LIBS "Build shared library" OFF)
if(BUILD_SHARED_LIBS)
  set(LIBRARY SHARED)
else()
  set(LIBRARY STATIC)
endif()

include_directories(src)

set(SOURCE_FILES
  src/geometry.cpp
  src/delaunay.cpp
)

add_library(${PROJECT_NAME} ${LIBRARY} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME})

add_subdirectory(test)
