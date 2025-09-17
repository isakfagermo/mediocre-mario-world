//
// Created by isakf on 22.04.2022.
//

#ifndef ASSIGNMENT_PROJECT_COIN_H
#define ASSIGNMENT_PROJECT_COIN_H

#include "objects.h"

class Coin : public Objects
        {
public:
    Coin(float x, float y);
    void tegn(sf::RenderWindow &vindu) override;

        };


#endif //ASSIGNMENT_PROJECT_COIN_H
