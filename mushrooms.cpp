//
// Created by isakf on 02.05.2022.
//

#include "mushrooms.h"

Mushrooms::Mushrooms(float xPos, float yPos)
{
    texture.loadFromFile("Textures/Level/mario_sopp.png");
    sprite.setTexture(texture);
    sprite.setPosition(xPos, yPos);
}

void Mushrooms::Tyngdekraft()
{
    sprite.move(0.f, 2.f);
}

void Mushrooms::tegn(sf::RenderWindow &vindu)
{

}