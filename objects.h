//
// Created by isakf on 22.04.2022.
//
#include "SFML/Graphics.hpp"
#ifndef ASSIGNMENT_PROJECT_OBJECTS_H
#define ASSIGNMENT_PROJECT_OBJECTS_H

class Objects
{
public:
    virtual void tegn(sf::RenderWindow &vindu) = 0;

    sf::Sprite sprite;
    sf::Texture texture;

protected:

    float X;
    float Y;
};

#endif //ASSIGNMENT_PROJECT_OBJECTS_H
