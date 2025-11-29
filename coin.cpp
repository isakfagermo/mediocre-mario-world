//
// Created by isakf on 22.04.2022.
//

#include "coin.h"

Coin::Coin(float x, float y)
{
    texture.loadFromFile("Textures/coin.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void Coin::tegn(sf::RenderWindow &vindu)
{
    vindu.draw(sprite);
}
