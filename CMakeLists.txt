cmake_minimum_required(VERSION 2.6)
project(GENGINE)


#set(CMAKE_EXECUTABLE_SUFFIX ".html")

add_definitions(-DSDL_MAIN_HANDLED)

include_directories(
 src
 ${CMAKE_SOURCE_DIR}/contrib/SDL2/include
 ${CMAKE_SOURCE_DIR}/contrib

)

if(MSVC)
 include_directories(
  ${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86_x64/include
 )
 link_directories(
  ${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86_x64/lib
 )
else()
 # this is done so emscripten can use its own SDL2
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2") 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s DISABLE_EXCEPTION_CATCHING=0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s DISABLE_EXCEPTION_CATCHING=0")
endif()
link_directories(${CMAKE_SOURCE_DIR}/contrib/SDL2/lib/x64)
link_directories(${CMAKE_SOURCE_DIR}/contrib/openal-soft/libs)


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
	src/GEngine/Component.cpp
	src/GEngine/Renderer.cpp
	src/GEngine/Transform.cpp	
	src/GEngine/Screen.cpp
	src/GEngine/Resource.cpp
	src/GEngine/Texture.cpp
	src/GEngine/Sound.cpp
	src/GEngine/AssetManager.cpp
	src/GEngine/soundSource.cpp
	src/GEngine/Keyboard.cpp
	src/GEngine/Camera.cpp
	src/GEngine/Model.cpp
	src/GEngine/Exception.cpp
	src/GEngine/Shader.cpp

	src/GEngine/Core.h
	src/GEngine/Component.h
	src/GEngine/GEngine.h
	src/GEngine/Entity.h
	src/GEngine/Renderer.h
	src/GEngine/Transform.h
	src/GEngine/Screen.h
	src/GEngine/Resource.h
	src/GEngine/Texture.h
	src/GEngine/Sound.h
	src/GEngine/AssetManager.h
	src/GEngine/soundSource.h
	src/GEngine/Keyboard.h
	src/GEngine/Camera.h
	src/GEngine/Model.h
	src/GEngine/Exception.h
	src/GEngine/Shader.h

)


add_executable(demo
	src/demo/main.cpp
)

target_link_libraries(GEngine rend)

target_link_libraries(demo GEngine)

target_link_libraries(demo SDL2)

if(MSVC OR MINGW)
  target_link_libraries(rend glew32 opengl32 OpenAL32)
else()
  target_link_libraries(rend GLEW GL)
endif()




