//
// Created by isakf on 22.04.2022.
//
#include "SFML/Graphics.hpp"
#include "tiles.h"
#include "vector"
#include "solid_blocks.h"
#include "coin.h"

using namespace std;

#ifndef ASSIGNMENT_PROJECT_LEVEL_H
#define ASSIGNMENT_PROJECT_LEVEL_H

class Level
        {

    void spawn();
    void setupTiles();

public:

    Level();
    void drawTiles(sf::RenderWindow &vindu);
    void drawBlocks(sf::RenderWindow &vindu);
    void drawCoins(sf::RenderWindow &vindu);
    vector< vector<Tiles *> > tiles;
    vector<Solid_blocks *> solideBlokker;
    vector<Coin *> mynter;

        };

#endif //ASSIGNMENT_PROJECT_LEVEL_H