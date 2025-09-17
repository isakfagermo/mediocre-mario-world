//
// Created by isakf on 22.04.2022.
//

#include "tiles.h"
#include <utility>

Tiles::Tiles(std::string navn, float x, float y, bool myk, bool sopp)
{
    setSprite(std::move(navn));
    sprite.setPosition(x, y);

    erMyk = myk;
    spawn = sopp;
}

bool Tiles::setSprite(std::string navn)
{
    texture.loadFromFile(navn);
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,16,16));

    return true;
}