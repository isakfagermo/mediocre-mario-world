//
// Created by isakf on 22.04.2022.
//

#include "mario.h"
#include "string"
#include "SFML/Audio.hpp"
#include "level.h"
#include "solid_blocks.h"
#include "mushrooms.h"

std::string MARIO_STILL = "Textures/Mario/flipped/Mario_still.png";
std::string MARIO_WALK1 = "Textures/Mario/walk_1.png";
std::string MARIO_WALK2 = "Textures/Mario/walk_2.png";
std::string MARIO_WALK3 = "Textures/Mario/walk_3.png";
std::string MARIO_WALK4 = "Textures/Mario/walk_4.png";
std::string MARIO_JUMP = "Textures/Mario/jump.png";
std::string MARIO_FALL = "Textures/Mario/fall.png";
std::string MARIO_DOWN = "Textures/Mario/down.png";

void Mario::FlippedMario() const
{
    if (!Flipped)
    {
        MARIO_STILL = "Textures/Mario/Mario_still.png";
        MARIO_WALK1 = "Textures/Mario/walk_1.png";
        MARIO_WALK2 = "Textures/Mario/walk_2.png";
        MARIO_WALK3 = "Textures/Mario/walk_3.png";
        MARIO_WALK4 = "Textures/Mario/walk_4.png";
        MARIO_JUMP = "Textures/Mario/jump.png";
        MARIO_FALL = "Textures/Mario/fall.png";
        MARIO_DOWN = "Textures/Mario/down.png";
    }else
    {
        MARIO_STILL = "Textures/Mario/flipped/Mario_still.png";
        MARIO_WALK1 = "Textures/Mario/flipped/walk_1.png";
        MARIO_WALK2 = "Textures/Mario/flipped/walk_2.png";
        MARIO_WALK3 = "Textures/Mario/flipped/walk_3.png";
        MARIO_WALK4 = "Textures/Mario/flipped/walk_4.png";
        MARIO_JUMP = "Textures/Mario/flipped/jump.png";
        MARIO_FALL = "Textures/Mario/flipped/fall.png";
        MARIO_DOWN = "Textures/Mario/flipped/down.png";
    }
}

Mario::Mario(float xPos, float yPos)
{
    texture.loadFromFile(MARIO_STILL);
    sprite.setTexture(texture);
    sprite.setPosition(xPos, yPos);

    Variabler();
}

void Mario::tegn(sf::RenderWindow &vindu)
{
    vindu.draw(sprite);
}

void Mario::Variabler()
{
    movementSpeed = 2.f;
    tyngdekraften = 2.f;
    hoppKraft = 5.f;
}

float Mario::GetGround() const
{
    if (shroomCount == 0)
    {
        return 169.f;
    }else if (shroomCount == 1)
    {
        return 163.f;
    }else if (shroomCount == 2)
    {
        return 156.f;
    }else if (shroomCount == 3)
    {
        return 149.f;
    }
    else if (shroomCount == 4)
    {
        return 142.f;
    }
}

void Mario::tyngdekraft()
{
    if ( sprite.getPosition().y < GetGround() && !inJump && !onBlock)
    {
        texture.loadFromFile(MARIO_FALL);
        sprite.setTexture(texture);
        sprite.move(0.f, tyngdekraften);
    }else if ( inJump && JumpTimer > 0 )
    {
        texture.loadFromFile(MARIO_JUMP);
        sprite.setTexture(texture);
        sprite.move(0.f, -hoppKraft);
        JumpTimer--;

        if(JumpTimer == 1)
        {
            JumpTimer = 0;
            inJump = false;
            onBlock = false;
        }
    }

    if(sprite.getPosition().y > (GetGround() - 1.f))
        atGround = true;
    else
        atGround = false;
}

void Mario::movement(sf::Sound &hopp)
{
    //Input fra spiller
    //if (sf::Joystick::isButtonPressed(0, 1))

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (!inJump && atGround || !inJump && onBlock)
        {
            //Vi flipper tyngdekraften i funksjonen over.
            inJump = true;
            onBlock = false;
            JumpTimer = 14;

            //Hoppe lyd
            hopp.play();
        }
    }

    //if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) == -100)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) == -100)
    {
        Flipped = true;
        if (sprite.getPosition().x > 0)
            sprite.move(-movementSpeed, 0.f);

        if(!inJump && atGround || !inJump && onBlock)
            walking();

    }
    //else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) == 100)
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Flipped = false;
        sprite.move(movementSpeed, 0.f);

        if(!inJump && atGround || !inJump && onBlock)
            walking();

    }
    //else if(sf::Joystick::getAxisPosition(0, sf::Joystick::Y) == -100)
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        texture.loadFromFile(MARIO_DOWN);
        sprite.setTexture(texture);

    }else if (sprite.getPosition().y > ( GetGround() - 1.f ) || onBlock)
    {
        texture.loadFromFile(MARIO_STILL);
        sprite.setTexture(texture);
    }
}

void Mario::walking()
{
    walkAnimation++;

    if (walkAnimation == 1)
    {
        texture.loadFromFile(MARIO_WALK1);
        sprite.setTexture(texture);
    }else if (walkAnimation == 4)
    {
        texture.loadFromFile(MARIO_WALK2);
        sprite.setTexture(texture);
    }else if (walkAnimation == 8)
    {
        texture.loadFromFile(MARIO_WALK3);
        sprite.setTexture(texture);
    }else if (walkAnimation == 12)
    {
        texture.loadFromFile(MARIO_WALK4);
        sprite.setTexture(texture);
    }else if (walkAnimation > 16)
    {
        walkAnimation = 0;
    }
}

float Mario::get_x_Position()
{
    if (sprite.getPosition().x > 128.f)
        return sprite.getPosition().x;
    else
        return 128.f;
}

void Mario::PickupCoin(std::vector<Coin *> &cash, sf::Sound &CoinPling)
{
    for (int i = 0; i < cash.size(); ++i)
    {
        if (sprite.getGlobalBounds().intersects(cash[i]->sprite.getGlobalBounds()))
        {
            cash.erase(cash.begin() + i);
            CoinPling.play();
            CoinCounter++;
        }
    }
}

void Mario::PickupSopp(sf::Sound &SpisSopp)
{
    for (int i = 0; i < sopp.size(); ++i)
    {
        if (sprite.getGlobalBounds().intersects(sopp[i]->sprite.getGlobalBounds()))
        {
            sopp.erase(sopp.begin() + i);
            SpisSopp.play();
            shroomCount++;
            size += 0.3;
            sprite.setScale(size, size);
        }
    }
}

void Mario::Collision(vector<Solid_blocks *> &lmaoo, sf::Sound &breakBlock)
{
    int counter = 0;

    for (int i = 0; i < lmaoo.size(); i++)
    {
        if(sprite.getGlobalBounds().intersects(lmaoo[i]->sprite.getGlobalBounds()))
        {
            counter++;

            if (sprite.getPosition().y > lmaoo[i]->sprite.getPosition().y)
            {
                inJump = false;
                sprite.move(0.f, 3.f);

                if (lmaoo[i]->spawn)
                {
                    sopp.push_back(new Mushrooms( lmaoo[i]->sprite.getPosition().x, 0.f));
                    mushrooms++;
                }

                breakBlock.play();
                lmaoo.erase(lmaoo.begin() + i);
            }else
            {
                onBlock = true;
            }
        }
    }

    if (counter == 0)
    {
        onBlock = false;
    }
}

void Mario::SpawnSopp(sf::RenderWindow &vindu)
{
    if (mushrooms > 0)
    {
        for (auto &i: sopp)
        {
            vindu.draw(i->sprite);

            if (i->sprite.getPosition().y < 177.f)
                i->Tyngdekraft();
        }
    }
}