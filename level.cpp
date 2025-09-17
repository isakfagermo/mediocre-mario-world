//
// Created by isakf on 22.04.2022.
//
#include "level.h"
#include "solid_blocks.h"

#define CLEAR_BLOCK "Textures/Level/clear.png"
#define DIRT_BLOCK "Textures/Level/dirt.png"
#define GRASS_BLOCK "Textures/Level/dirt_grass.png"
#define QUESTION_BLOCK "Textures/Level/question.png"
#define BRICK_BLOCK "Textures/Level/brick.png"
#define CLOUD_TOP_LEFT "Textures/Level/cloud_top_left.png"
#define CLOUD_TOP_RIGHT "Textures/Level/cloud_top_right.png"
#define CLOUD_BOTTOM_LEFT "Textures/Level/cloud_bottom_left.png"
#define CLOUD_BOTTOM_RIGHT "Textures/Level/cloud_bottom_right.png"
#define LEFT_MOUNTAIN_BLOCK "Textures/Level/mountain_left.png"
#define RIGHT_MOUNTAIN_BLOCK "Textures/Level/mountain_right.png"
#define BUSH_BLOCK "Textures/Level/small_bush.png"
#define LEVEL_LENGTH 54

Level::Level()
{
    spawn();
}

void Level::spawn()
{
    setupTiles();
}


//Jeg tegner banen rad for rad. For å ungå error når jeg skal printe så legger jeg et lag med igjennomsiktige blokker over hele banen
//Derfor vil ikke noen av vectorene i lista være tom.
//Shoutout RAM-brikkan mine :)

void Level::setupTiles()
{
    tiles.clear();
/////////////////////////////////////   Lag 2 kommer før lag 1... Dont fix it if its not broken
#define ROW_TWO 192

    vector<Tiles *> first;
    first.reserve(LEVEL_LENGTH);
for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        first.push_back(new Tiles(GRASS_BLOCK, (i * 16), ROW_TWO, false, false));
    }
    tiles.push_back(first);
/////////////////////////////////////
#define ROW_ONE 208

    vector<Tiles *> second;
    second.reserve(LEVEL_LENGTH);
for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        second.push_back(new Tiles(DIRT_BLOCK, (i * 16), ROW_ONE, false, false));
    }
    tiles.push_back(second);
/////////////////////////////////////
#define ROW_THREE 176

    vector<Tiles *> three;
    three.reserve(LEVEL_LENGTH);



    three.push_back(new Tiles("Textures/Slott/R1-1.png", 720, ROW_THREE, true, false));
    three.push_back(new Tiles("Textures/Slott/R1-2.png", 736, ROW_THREE, true, false));
    three.push_back(new Tiles("Textures/Slott/R1-3.png", 752, ROW_THREE, true, false));
    three.push_back(new Tiles("Textures/Slott/R1-4.png", 768, ROW_THREE, true, false));
    three.push_back(new Tiles("Textures/Slott/R1-5.png", 784, ROW_THREE, true, false));

    mynter.push_back(new Coin((15 * 16), ROW_THREE));
    mynter.push_back(new Coin((16 * 16), ROW_THREE));
    mynter.push_back(new Coin((17 * 16), ROW_THREE));
    mynter.push_back(new Coin((16 * 41), ROW_THREE));
    mynter.push_back(new Coin((16 * 40), ROW_THREE));
    mynter.push_back(new Coin((16 * 39), ROW_THREE));

    for (int i = 0; i < 4; ++i)
    { //Tegner fjellan i bakgrunnen av mario. Kommer et nytt fjell hver 16 block.
        three.push_back(new Tiles(LEFT_MOUNTAIN_BLOCK,((2 * 16) + ((16 * 16) * i) ), ROW_THREE, true, false));
        three.push_back(new Tiles(RIGHT_MOUNTAIN_BLOCK,(((2 * 16) + 16) + ((16 * 16) * i) ), ROW_THREE, true, false));
        three.push_back(new Tiles(BUSH_BLOCK,((9 * 16) + ((16 * 16) * i) ), ROW_THREE, true, false));
    }

    for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        three.push_back(new Tiles(CLEAR_BLOCK, (i * 16), ROW_THREE, false, false));
    }
    tiles.push_back(three);
///////////////////////////////////
#define ROW_FOUR 160

    vector<Tiles *> four;
    four.reserve(LEVEL_LENGTH);

    four.push_back(new Tiles("Textures/Slott/R2-1.png", 720, ROW_FOUR, true, false));
    four.push_back(new Tiles("Textures/Slott/R2-2.png", 736, ROW_FOUR, true, false));
    four.push_back(new Tiles("Textures/Slott/R2-3.png", 752, ROW_FOUR, true, false));
    four.push_back(new Tiles("Textures/Slott/R2-4.png", 768, ROW_FOUR, true, false));
    four.push_back(new Tiles("Textures/Slott/R2-5.png", 784, ROW_FOUR, true, false));

    for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        four.push_back(new Tiles(CLEAR_BLOCK, (i * 16), ROW_FOUR, false, false));
    }
    tiles.push_back(four);
/////////////////////////////////////
#define ROW_FIVE 144


    solideBlokker.push_back(new Solid_blocks(BRICK_BLOCK, (16 * 29), ROW_FIVE, false));
    solideBlokker.push_back(new Solid_blocks(BRICK_BLOCK, (16 * 30), ROW_FIVE, false));

    vector<Tiles *> five;
    five.reserve(LEVEL_LENGTH);

    five.push_back(new Tiles("Textures/Slott/R3-1.png", 720, ROW_FIVE, true, false));
    five.push_back(new Tiles("Textures/Slott/R3-2.png", 736, ROW_FIVE, true, false));
    five.push_back(new Tiles("Textures/Slott/R3-3.png", 752, ROW_FIVE, true, false));
    five.push_back(new Tiles("Textures/Slott/R3-4.png", 768, ROW_FIVE, true, false));
    five.push_back(new Tiles("Textures/Slott/R3-5.png", 784, ROW_FIVE, true, false));

    for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        five.push_back(new Tiles(CLEAR_BLOCK, (i * 16), ROW_FIVE, false, false));
    }
    tiles.push_back(five);
/////////////////////////////////////
#define ROW_SIX 128

    vector<Tiles *> six;
    six.reserve(LEVEL_LENGTH);

    solideBlokker.push_back(new Solid_blocks(QUESTION_BLOCK, (4 * 16), ROW_SIX, true));
    solideBlokker.push_back(new Solid_blocks(BRICK_BLOCK, (8 * 16), ROW_SIX, false));
    solideBlokker.push_back(new Solid_blocks(QUESTION_BLOCK, (9 * 16), ROW_SIX, true));
    solideBlokker.push_back(new Solid_blocks(BRICK_BLOCK, (10 * 16), ROW_SIX, false));
    solideBlokker.push_back(new Solid_blocks(QUESTION_BLOCK, (11 * 16), ROW_SIX, true));
    solideBlokker.push_back(new Solid_blocks(BRICK_BLOCK, (12 * 16), ROW_SIX, false));

    six.push_back(new Tiles("Textures/Slott/R4-1.png", 720, ROW_SIX, true, false));
    six.push_back(new Tiles("Textures/Slott/R4-2.png", 736, ROW_SIX, true, false));
    six.push_back(new Tiles("Textures/Slott/R4-3.png", 752, ROW_SIX, true, false));
    six.push_back(new Tiles("Textures/Slott/R4-4.png", 768, ROW_SIX, true, false));
    six.push_back(new Tiles("Textures/Slott/R4-5.png", 784, ROW_SIX, true, false));

    for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        six.push_back(new Tiles(CLEAR_BLOCK, (i * 16), ROW_SIX, false, false));
    }
    tiles.push_back(six);
/////////////////////////////////////
#define ROW_SEVEN 112

    solideBlokker.push_back(new Solid_blocks(BRICK_BLOCK, (16 * 21), ROW_SEVEN, false));
    solideBlokker.push_back(new Solid_blocks(BRICK_BLOCK, (16 * 22), ROW_SEVEN, false));
    solideBlokker.push_back(new Solid_blocks(BRICK_BLOCK, (16 * 23), ROW_SEVEN, false));
    solideBlokker.push_back(new Solid_blocks(BRICK_BLOCK, (16 * 32), ROW_SEVEN, false));

    mynter.push_back(new Coin((8 * 16), ROW_SEVEN));
    mynter.push_back(new Coin((10 * 16), ROW_SEVEN));
    mynter.push_back(new Coin((12 * 16), ROW_SEVEN));

    vector<Tiles *> seven;
    seven.reserve(LEVEL_LENGTH);
for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        seven.push_back(new Tiles(CLEAR_BLOCK, (i * 16), ROW_SEVEN, false, false));
    }
    tiles.push_back(seven);
/////////////////////////////////////
#define ROW_EIGHT 96

    mynter.push_back(new Coin((21 * 16), ROW_EIGHT));
    mynter.push_back(new Coin((22 * 16), ROW_EIGHT));
    mynter.push_back(new Coin((23 * 16), ROW_EIGHT));
    mynter.push_back(new Coin((32 * 16), ROW_EIGHT));

    vector<Tiles *> eight;
    eight.reserve(LEVEL_LENGTH);

    for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        eight.push_back(new Tiles(CLEAR_BLOCK, (i * 16), ROW_EIGHT, false, false));
    }
    tiles.push_back(eight);
/////////////////////////////////////
#define ROW_NINE 80

    vector<Tiles *> nine;
    nine.reserve(LEVEL_LENGTH);

    solideBlokker.push_back(new Solid_blocks(BRICK_BLOCK, (16 * 28), ROW_NINE, false));
    solideBlokker.push_back(new Solid_blocks(BRICK_BLOCK, (16 * 29), ROW_NINE, false));


    nine.push_back(new Tiles("Textures/LevelComplete/L.png", (60 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/E.png", (61 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/V.png", (62 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/E.png", (63 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/L.png", (64 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/C.png", (66 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/O.png", (67 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/M.png", (68 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/P.png", (69 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/L.png", (70 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/E.png", (71 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/T.png", (72 * 16), ROW_NINE, false, false));
    nine.push_back(new Tiles("Textures/LevelComplete/E.png", (73 * 16), ROW_NINE, false, false));




for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        nine.push_back(new Tiles(CLEAR_BLOCK, (i * 16), ROW_NINE, false, false));
    }
    tiles.push_back(nine);
/////////////////////////////////////
#define ROW_TEN 64
    vector<Tiles *> ten;
    ten.reserve(LEVEL_LENGTH);

    mynter.push_back(new Coin((28 * 16), ROW_TEN));
    mynter.push_back(new Coin((29 * 16), ROW_TEN));

    for (int i = 0; i < 3; ++i)
    {
        ten.push_back(new Tiles(CLOUD_BOTTOM_LEFT,((7 * 16) + ((16 * 16) * i) ), ROW_TEN, true, false));
        ten.push_back(new Tiles(CLOUD_BOTTOM_RIGHT,(((7 * 16) + 16) + ((16 * 16) * i) ), ROW_TEN, true, false));
    }

    for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        ten.push_back(new Tiles(CLEAR_BLOCK, (i * 16), ROW_TEN, false, false));
    }
    tiles.push_back(ten);
/////////////////////////////////////
#define ROW_ELEVEN 48

    vector<Tiles *> eleven;
    eleven.reserve(LEVEL_LENGTH);

    solideBlokker.push_back(new Solid_blocks(QUESTION_BLOCK, (10 * 16), ROW_ELEVEN, true));

    mynter.push_back(new Coin((15 * 16), ROW_ELEVEN));
    mynter.push_back(new Coin((16 * 16), ROW_ELEVEN));
    mynter.push_back(new Coin((17 * 16), ROW_ELEVEN));

    for (int i = 0; i < 3; ++i)
    {
        eleven.push_back(new Tiles(CLOUD_TOP_LEFT,((7 * 16) + ((16 * 16) * i) ), ROW_ELEVEN, true, false));
        eleven.push_back(new Tiles(CLOUD_TOP_RIGHT,(((7 * 16) + 16) + ((16 * 16) * i) ), ROW_ELEVEN, true, false));
    }

for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        eleven.push_back(new Tiles(CLEAR_BLOCK, (i * 16), ROW_ELEVEN, false, false));
    }
    tiles.push_back(eleven);
/////////////////////////////////////
#define ROW_TWELVE 32

    vector<Tiles *> twelve;
    twelve.reserve(LEVEL_LENGTH);

    for (int i = 0; i < 3; ++i)
    {
        twelve.push_back(new Tiles(CLOUD_BOTTOM_LEFT,((17 * 16) + ((16 * 16) * i) ), ROW_TWELVE, true, false));
        twelve.push_back(new Tiles(CLOUD_BOTTOM_RIGHT,(((17 * 16) + 16) + ((16 * 16) * i) ), ROW_TWELVE, true, false));
    }

    for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        twelve.push_back(new Tiles(CLEAR_BLOCK, (i * 16), ROW_TWELVE, false, false));
    }
    tiles.push_back(twelve);
/////////////////////////////////////
#define ROW_THIRTEEN 16

    vector<Tiles *> thirteen;
    thirteen.reserve(LEVEL_LENGTH);

    for (int i = 0; i < 3; ++i)
    {
        thirteen.push_back(new Tiles(CLOUD_TOP_LEFT,((17 * 16) + ((16 * 16) * i) ), ROW_THIRTEEN, true, false));
        thirteen.push_back(new Tiles(CLOUD_TOP_RIGHT,(((17 * 16) + 16) + ((16 * 16) * i) ), ROW_THIRTEEN, true, false));
    }

for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        thirteen.push_back(new Tiles(CLEAR_BLOCK, (i * 16), ROW_THIRTEEN, false, false));
    }
    tiles.push_back(thirteen);
/////////////////////////////////////
#define ROW_FOURTEEN 0

    vector<Tiles *> fourteen;
    fourteen.reserve(LEVEL_LENGTH);
for (int i = 0; i < LEVEL_LENGTH; ++i)
    {
        fourteen.push_back(new Tiles(CLEAR_BLOCK, (i * 16),ROW_FOURTEEN, false, false));
    }
    tiles.push_back(fourteen);
}

void Level::drawTiles(sf::RenderWindow &vindu)
{
    for (int i = 0; i < 13; ++i)
    {
        for (int j = 0; j < LEVEL_LENGTH; ++j)
        {
            vindu.draw(tiles[i][j]->sprite);
        }
    }
}

void Level::drawBlocks(sf::RenderWindow &vindu)
{
    for (auto & i : solideBlokker)
    {
        vindu.draw(i->sprite);
    }
}

void Level::drawCoins(sf::RenderWindow &vindu)
{
    for (auto & i : mynter)
    {
        vindu.draw(i->sprite);
    }
}