cmake_minimum_required(VERSION 3.21)
project(mediocre-mario-world)

set(CMAKE_CXX_STANDARD 14)

# Add SFML using find_package
find_package(SFML 2.6 COMPONENTS graphics audio window system REQUIRED)
add_executable(mediocre-mario-world main.cpp Mario.cpp Mario.h mario.cpp mario.h objects.cpp objects.h coin.cpp coin.h tiles.cpp tiles.h level.cpp level.h solid_blocks.cpp solid_blocks.h mushrooms.cpp mushrooms.h coin_count_overlay.cpp coin_count_overlay.h
        theme.cpp
        theme.h)
target_link_libraries (mediocre-mario-world sfml-graphics sfml-audio sfml-window sfml-system)