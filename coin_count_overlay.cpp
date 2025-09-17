//
// Created by isakf on 02.05.2022.
//

#include "coin_count_overlay.h"
#include "iostream"

Coin_count_overlay::Coin_count_overlay()
{
    texture.loadFromFile("Textures/Numbers/base.png");
    sprite.setTexture(texture);
    sprite.setPosition(0.f, 0.f);

    texture1.loadFromFile("Textures/Numbers/0.png");
    counter1.setTexture(texture1);
    counter1.setPosition(24.f, 0.f);

    counter2.setPosition(35.f, 0.f);
}

void Coin_count_overlay::tegn(sf::RenderWindow &vindu) {

}

void Coin_count_overlay::tegn2(sf::RenderWindow &vindu, int i)
{
    vindu.draw(sprite);

    if (i <= 9)
    {
        switch (i)
        {
            case 0: { texture1.loadFromFile("Textures/Numbers/0.png"); break;}
            case 1: { texture1.loadFromFile("Textures/Numbers/1.png"); break;}
            case 2: { texture1.loadFromFile("Textures/Numbers/2.png"); break;}
            case 3: { texture1.loadFromFile("Textures/Numbers/3.png"); break;}
            case 4: { texture1.loadFromFile("Textures/Numbers/4.png"); break;}
            case 5: { texture1.loadFromFile("Textures/Numbers/5.png"); break;}
            case 6: { texture1.loadFromFile("Textures/Numbers/6.png"); break;}
            case 7: { texture1.loadFromFile("Textures/Numbers/7.png"); break;}
            case 8: { texture1.loadFromFile("Textures/Numbers/8.png"); break;}
            case 9: { texture1.loadFromFile("Textures/Numbers/9.png"); break;}
            default: { break; }
        }
    }else
    {
        texture1.loadFromFile("Textures/Numbers/1.png");

        switch (i)
        {
            case 10: {texture2.loadFromFile("Textures/Numbers/0.png"); break; }
            case 11: {texture2.loadFromFile("Textures/Numbers/1.png"); break; }
            case 12: {texture2.loadFromFile("Textures/Numbers/2.png"); break; }
            case 13: {texture2.loadFromFile("Textures/Numbers/3.png"); break; }
            case 14: {texture2.loadFromFile("Textures/Numbers/4.png"); break; }
            case 15: {texture2.loadFromFile("Textures/Numbers/5.png"); break; }
            case 16: {texture2.loadFromFile("Textures/Numbers/6.png"); break; }
            case 17: {texture2.loadFromFile("Textures/Numbers/7.png"); break; }
            case 18: {texture2.loadFromFile("Textures/Numbers/8.png"); break; }
            default: { break; }
        }

        counter2.setTexture(texture2);
        vindu.draw(counter2);
    }

    counter1.setTexture(texture1);
    vindu.draw(counter1);
}
