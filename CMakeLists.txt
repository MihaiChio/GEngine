cmake_minimum_required(VERSION 2.6)
project(GENGINE)

include_directories(
  src
)

add_executable(demo
	src/demo/main.cpp
)

target_link_libraries(demo GEngine)

# .h files included to show in VS, they don't compile.

add_library(GEngine SHARED
	src/GEngine/Core.cpp
	src/GEngine/Core.h
)