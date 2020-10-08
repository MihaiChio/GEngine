cmake_minimum_required(VERSION 2.6)
project(GENGINE)

include_directories(
 src
 ${CMAKE_SOURCE_DIR}/contrib/SDL2/include

)

if(MSVC)
 include_directories(
  ${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86_x64/include
 )
 link_directories(
  ${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86_x64/lib
 )
endif()
link_directories(${CMAKE_SOURCE_DIR}/contrib/SDL2/lib/x64)


add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)

# .h files included to show in VS, they don't compile.

add_library(GEngine 
	src/GEngine/Core.cpp
	src/GEngine/Entity.cpp
	
	src/GEngine/Core.h
	src/GEngine/Component.h
	src/GEngine/GEngine.h
	src/GEngine/Entity.h
)


add_executable(demo
	src/demo/main.cpp
)

target_link_libraries(GEngine rend)

target_link_libraries(demo GEngine)

target_link_libraries(demo SDL2 SDL2Main)

if(MSVC OR MINGW)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()




