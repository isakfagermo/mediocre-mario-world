//
// Created by isakf on 01.05.2022.
//

#ifndef ASSIGNMENT_PROJECT_SOLID_BLOCKS_H
#define ASSIGNMENT_PROJECT_SOLID_BLOCKS_H

#include "objects.h"


class Solid_blocks
        {
public:
            bool spawn = false;

            sf::Texture texture;
            sf::Sprite sprite;

            sf::FloatRect hitbox;

            Solid_blocks(const std::string& loc, float xPos, float yPos, bool spawn);
};


#endif //ASSIGNMENT_PROJECT_SOLID_BLOCKS_H
