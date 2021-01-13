/**
 *
 * @file    map.cpp
 * @author  Thomas Cardon
 * @date    12 janvier 2020
 * @version 1.0
 * @brief   Définition des méthodes de la classe Map
 *
 **/
#include "map.h"

#include <iostream>
#include <fstream>

#include <mingl/graphics/vec2d.h>
#include <mingl/shape/rectangle.h>
#include <mingl/shape/shape.h>

using namespace nsGame;

void Map::load() {
    std::ifstream input;

    input.open("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/level_1.map");
    if (!input) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }

    std::vector<std::string> lineList;
    for( std::string line; getline(input, line ); ) {
        lineList.push_back(line);
    }

    int lineIndex = 0;
    this->Mat.resize(lineList.size());

    for(auto string : lineList) {
        for(char& c : string) {
            this->Mat[lineIndex].push_back(c);
        }

        lineIndex++;
    }

    input.close();

    /*
     * On précharge les sprites des murs
     */
    /* Murs */
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("X_1", new nsGui::Sprite(WALL_X_1, nsGraphics::Vec2D(0, 0))));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("X_2", new nsGui::Sprite(WALL_X_2, nsGraphics::Vec2D(0, 0))));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("X_3", new nsGui::Sprite(WALL_X_3, nsGraphics::Vec2D(0, 0))));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("Y_1", new nsGui::Sprite(WALL_Y_1, nsGraphics::Vec2D(0, 0))));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("Y_2", new nsGui::Sprite(WALL_Y_2, nsGraphics::Vec2D(0, 0))));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("Y_3", new nsGui::Sprite(WALL_Y_3, nsGraphics::Vec2D(0, 0))));


    /* Coins */
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("CORNER_1", new nsGui::Sprite(WALL_XY_1, nsGraphics::Vec2D(0, 0))));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("CORNER_2", new nsGui::Sprite(WALL_XY_2, nsGraphics::Vec2D(0, 0))));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("CORNER_3", new nsGui::Sprite(WALL_XY_3, nsGraphics::Vec2D(0, 0))));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("CORNER_4", new nsGui::Sprite(WALL_XY_4, nsGraphics::Vec2D(0, 0))));
}

int Map::update(int delta) {
    return 0;
}

void Map::render(MinGL & window) {
    for (unsigned y = 0; y < this->Mat.size(); y++) {
        for (unsigned x = 0; x < this->Mat[y].size(); x++) {
            char & c = this->Mat[y][x];

            switch(c) {
                case '0': // CELL
                    window << nsShape::Rectangle(nsGraphics::Vec2D(x * 32, y * 32), 32, 32, nsGraphics::RGBAcolor(4, 4, 100));
                    break;
                case '/': // TOP LEFT
                    sprites["CORNER_1"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["CORNER_1"]->draw(window);
                    break;
                case '\\': // TOP RIGHT
                    sprites["CORNER_2"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["CORNER_2"]->draw(window);
                    break;
                case '(': // BOTTOM LEFT
                    sprites["CORNER_3"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["CORNER_3"]->draw(window);
                    break;
                case ')': // BOTTOM RIGHT
                    sprites["CORNER_4"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["CORNER_4"]->draw(window);
                    break;
                case '|': // VERTICAL WALL
                    sprites["Y_2"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["Y_2"]->draw(window);
                    break;
                case '=': // HORIZONTAL WALL
                    sprites["X_2"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["X_2"]->draw(window);
                    break;
            }
        }
    }
}

unsigned Map::getMinX() {
    return 0;
}

unsigned Map::getMinY() {
    return 0;
}

unsigned Map::getWidth() {
    return Mat[0].size();
}

unsigned Map::getHeight() {
    return Mat.size();
}
