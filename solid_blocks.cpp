//
// Created by isakf on 01.05.2022.
//

#include "solid_blocks.h"
#include "string"

Solid_blocks::Solid_blocks(const std::string& loc, float xPos, float yPos, bool sopp)
{
    spawn = sopp;
    texture.loadFromFile(loc);
    sprite.setTexture(texture);
    sprite.setPosition(xPos, yPos);
}