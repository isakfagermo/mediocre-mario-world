//
// Created by isakf on 22.04.2022.
//

#ifndef ASSIGNMENT_PROJECT_TILES_H
#define ASSIGNMENT_PROJECT_TILES_H
#include "SFML/Graphics.hpp"

class Tiles
        {
public:
            sf::Texture texture;
            sf::Sprite sprite;

            bool erMyk;
            bool spawn;
            bool setSprite(std::string);

            Tiles(std::string, float, float, bool, bool);
        };

#endif //ASSIGNMENT_PROJECT_TILES_H
