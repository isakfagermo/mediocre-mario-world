cmake_minimum_required(VERSION 3.21)
project(assignment_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(assignment_project main.cpp Mario.cpp Mario.h mario.cpp mario.h objects.cpp objects.h coin.cpp coin.h tiles.cpp tiles.h level.cpp level.h solid_blocks.cpp solid_blocks.h mushrooms.cpp mushrooms.h coin_count_overlay.cpp coin_count_overlay.h)
target_link_libraries (assignment_project sfml-graphics sfml-audio sfml-window sfml-system)