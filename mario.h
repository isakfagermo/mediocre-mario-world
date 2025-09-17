//
// Created by isakf on 21.04.2022.
//

#ifndef ASSIGNMENT_PROJECT_MARIO_H
#define ASSIGNMENT_PROJECT_MARIO_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "objects.h"
#include "solid_blocks.h"
#include "coin.h"
#include "mushrooms.h"

class Mario : public Objects
{
    bool inJump = false;
    bool onBlock = false;
    bool atGround{};
    bool Flipped = false;
    int JumpTimer = 0;
    int walkAnimation = 0;
    float size = 1.f;
    int shroomCount = 0;
    int mushrooms = 0;

    float movementSpeed{};
    float tyngdekraften{};
    float hoppKraft{};

    std::vector<Mushrooms *> sopp;

    void walking();
    void Variabler();
    float GetGround() const;

public:

    int CoinCounter = 0;

    Mario(float x, float y);
    float get_x_Position();
    void FlippedMario() const;
    void tyngdekraft();
    void Collision(std::vector<Solid_blocks *> &lmaoo, sf::Sound &breakBlock);
    void PickupCoin(std::vector<Coin *> &cash, sf::Sound &CoinPling);
    void PickupSopp(sf::Sound &SpisSopp);
    void tegn(sf::RenderWindow &vindu) override;
    void movement(sf::Sound &hopp);
    void SpawnSopp(sf::RenderWindow &vindu);

};

#endif //ASSIGNMENT_PROJECT_MARIO_H