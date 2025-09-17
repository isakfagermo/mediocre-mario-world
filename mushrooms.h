//
// Created by isakf on 02.05.2022.
//

#ifndef ASSIGNMENT_PROJECT_MUSHROOMS_H
#define ASSIGNMENT_PROJECT_MUSHROOMS_H

#include "objects.h"


class Mushrooms : public Objects
        {
public:
            Mushrooms(float, float);
            void Tyngdekraft();
            void tegn(sf::RenderWindow &vindu) override;

        };


#endif //ASSIGNMENT_PROJECT_MUSHROOMS_H
