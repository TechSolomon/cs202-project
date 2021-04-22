cmake_minimum_required(VERSION 3.17)
# This says use at least version 3.17 of CMake, you can probably get by
# with whatever modern version you already have.

project(cs202-project) # This is the name of your project.

set(CMAKE_CXX_STANDARD 20)
# This says use C++20 (C++17 would be fine, too).

add_executable(sfml src/main.cpp src/ranking.cpp src/ranking.h src/deck.cpp src/deck.h
        src/game.cpp src/game.h src/player.cpp src/player.h src/displayCard.cpp src/displayCard.h)
# This says what source files are compiled/linked to make your executable
# and lists any header files they use (so the IDE knows to recompile/relink
# if those headers change.

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
# This is the money line that makes modern CMake so nice. If you have SFML
# installed on your system, this should find it. Note this example only
# requires the graphics and audio libraries but it is obvious how
# to include the others if you need them.

target_link_libraries(sfml sfml-graphics sfml-audio)
# This line says that your program must be linked with the libraries we
# found in the above steps.