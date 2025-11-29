#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "mario.h"
#include "objects.h"
#include "level.h"
#include <chrono>
#include "thread"
#include "coin_count_overlay.h"

int main()
{
    std::cout << "Hello Mario World!\nLoading world..." << std::endl;

    //Class definitions
    Mario mario( 128.f, 169.f);
    Level verden = Level();
    Coin_count_overlay overlay;

    //The window
    sf::RenderWindow vindu(sf::VideoMode(256, 224), "Mediocre Mario World!");
    sf::View view(sf::Vector2f(128.f, 169.f), sf::Vector2f(256, 224));
    sf::View CoinCounter(sf::Vector2f(128.f, 169.f), sf::Vector2f(256, 224));
    vindu.setFramerateLimit(60);

    //Soundeffects
    sf::SoundBuffer jumpBuffer;
    jumpBuffer.loadFromFile("Sound/Jump.wav");
    sf::Sound jump;
    jump.setVolume(50.f);
    jump.setBuffer(jumpBuffer);

    sf::SoundBuffer CoinBuffer;
    CoinBuffer.loadFromFile("Sound/Coin.wav");
    sf::Sound Coin;
    Coin.setBuffer(CoinBuffer);

    sf::SoundBuffer SoppBuffer;
    SoppBuffer.loadFromFile("Sound/PowerUp_mario.wav");
    sf::Sound Soppen;
    Soppen.setBuffer(SoppBuffer);

    sf::SoundBuffer breakBuffer;
    breakBuffer.loadFromFile("Sound/Break_block.wav");
    sf::Sound breakBlock;
    breakBlock.setBuffer(breakBuffer);

    sf::SoundBuffer FinishBuffer;
    FinishBuffer.loadFromFile("Sound/Level_finish.wav");
    sf::Sound Finish;
    Finish.setBuffer(FinishBuffer);

    //Music
    sf::Music music;
    music.openFromFile("Sound/MainTheme_loop.wav");
    music.setLoop(true);
    music.setVolume(50.f);
    music.play();

    while (vindu.isOpen())
    {
        sf::Event event{};
        while (vindu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                vindu.close();
        }


        //Player movement
        mario.Collision(verden.solideBlokker, breakBlock);
        mario.PickupCoin(verden.mynter, Coin);
        mario.PickupSopp(Soppen);
        mario.FlippedMario();
        mario.tyngdekraft();
        mario.movement(jump);

        //Check if we have reached the finish
        if (mario.sprite.getPosition().x > 752.f)
        {
            mario.sprite.move(320.f, 0.f);
        }

        vindu.clear(sf::Color(35, 150, 230));

        //Overlay
        CoinCounter.setCenter(-75.f, 110.f);
        vindu.setView(CoinCounter);
        overlay.tegn2(vindu, mario.CoinCounter);

        //Follow the player with camera
        view.setCenter(mario.get_x_Position(), 112.f);
        vindu.setView(view);

        //Draw world
        verden.drawTiles(vindu);
        verden.drawBlocks(vindu);
        verden.drawCoins(vindu);

        //Mario&Co
        mario.tegn(vindu);
        mario.SpawnSopp(vindu);

        //Update window
        vindu.display();

        if (mario.sprite.getPosition().x > 752.f)
        {
            music.stop();
            Finish.play();

            std::chrono::seconds dura( 7);
            std::this_thread::sleep_for(dura);

            vindu.close();
        }
    }
    return 0;
}