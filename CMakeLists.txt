cmake_minimum_required(VERSION 3.17)
project(Project_Pheonix)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(Project_Pheonix main.cpp src/Game.cpp src/Game.h src/UserEvent.cpp src/UserEvent.h src/GameObject.cpp src/GameObject.h src/TextureManager.cpp src/TextureManager.h src/Player.cpp src/Player.h)


target_link_libraries(Project_Pheonix ${SDL2_LIBRARY} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

#[[ ------ ]]