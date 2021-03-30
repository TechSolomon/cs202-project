cmake_minimum_required(VERSION 3.17)
#this says use at least version 3.17 of Cmake, you can probably get by
#with whatever modern version you already have

project(sfml) #this is the name of your project

set(CMAKE_CXX_STANDARD 20)
#this says use c++20 (c++17 would be fine, too)

add_executable(sfml main.cpp)
#this says what source files are compiled/linked to make your executable
#and lists any header files they use (so the IDE knows to recompile/relink
#if those headers change

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
#this is the money line that makes modern CMake so nice. If you have SFML
#installed on your system, this should find it. Note this example only
#requires the graphics and audio libraries but it is obvious how
#to include the others if you need them

target_link_libraries(sfml sfml-graphics sfml-audio)
#this line says that your program must be linked with the libraries we
#found in the above steps