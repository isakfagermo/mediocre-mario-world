//
// Created by isakf on 02.05.2022.
//

#ifndef ASSIGNMENT_PROJECT_COIN_COUNT_OVERLAY_H
#define ASSIGNMENT_PROJECT_COIN_COUNT_OVERLAY_H

#include "objects.h"

class Coin_count_overlay : public Objects
        {
    sf::Texture texture1;
    sf::Sprite counter1;

    sf::Texture texture2;
    sf::Sprite counter2;

public:
            Coin_count_overlay();
            void tegn2(sf::RenderWindow &vindu, int i);
            void tegn(sf::RenderWindow &vindu) override;

};


#endif //ASSIGNMENT_PROJECT_COIN_COUNT_OVERLAY_H
