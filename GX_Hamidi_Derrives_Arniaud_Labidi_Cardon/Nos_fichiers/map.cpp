/**
 * @file    map.cpp
 * @author  Thomas Cardon
 * @date    12 janvier 2020
 * @version 1.0
 * @brief   Définition des méthodes de la classe map.h
 **/
#include "map.h"

#include <utility>
#include <iostream>
#include <fstream>
#include <dirent.h>

#include <mingl/graphics/vec2d.h>
#include <mingl/shape/rectangle.h>
#include <mingl/shape/shape.h>

#include "cooldowns.h"
#include "food.h"

#include "fruit.cpp"

/**
 *
 * \file    map.cpp
 * \author  Thomas Cardon
 * \date    13 janvier 2020
 * \version 1.0
 * \brief   Method definitions for Map.h
 */

using namespace nsGame;

std::string getRandomLevel() {
    DIR *dir;
    struct dirent *ent;

    std::vector<std::string> maps;

    if ((dir = opendir ("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/maps")) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
          std::string str = ent->d_name;
          if (str.substr(str.find_last_of(".") + 1) == "map")
              maps.push_back(str);
      }
      closedir (dir);
    } else throw("Impossible d'ouvrir le dossier de cartes du jeu");

    return "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/maps/" + maps[rand() % maps.size()];
}

nsGraphics::Vec2D Map::getEmptyPosition() {
    for (unsigned y = 0; y < getHeight(); y++) {
        for (unsigned x = 0; x < getWidth(); x++) {
            if (this->grid[y][x] == '0') {
                if (this->items.find(std::pair<int, int>(x, y)) == this->items.end())
                    continue;

                return nsGraphics::Vec2D(x, y);
            }
        }
    }

    return nsGraphics::Vec2D(-1, -1);
}

std::vector<nsGraphics::Vec2D> Map::getEmptyPositions() {
    std::vector<nsGraphics::Vec2D> vec;

    for (unsigned y = 0; y < getHeight(); y++) {
        for (unsigned x = 0; x < getWidth(); x++) {
            if (this->grid[y][x] == '0') vec.push_back(nsGraphics::Vec2D(x, y));
        }
    }

    return vec;
}

void Map::spawnItem(Item* item) {
    std::cout << "[Map] Spawns item at coordinates: x=" << item->getPosition().getX() << " y=" << item->getPosition().getY() << std::endl;
    try {
        item->load();
        items.insert(std::make_pair(std::make_pair(item->getPosition().getX(), item->getPosition().getY()), item));
    }  catch (...) {
        std::cout << "[Map] Can't spawn item!";
    }
}

void Map::load() {
    /** \brief Input FileStream for the different levels */
    std::ifstream input;
    input.open(getRandomLevel());

    if (!input) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }

    std::vector<std::string> lineList;
    for( std::string line; getline(input, line ); ) {
        lineList.push_back(line);
    }

    int lineIndex = 0;
    this->grid.resize(lineList.size());

    for(auto string : lineList) {
        for(char& c : string)
            this->grid[lineIndex].push_back(c);

        lineIndex++;
    }

    input.close();

    /*
     * On précharge les sprites des murs
     */
    /* Murs */
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("X_1", new nsGui::Sprite(WALL_X_1)));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("X_2", new nsGui::Sprite(WALL_X_2)));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("X_3", new nsGui::Sprite(WALL_X_3)));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("Y_1", new nsGui::Sprite(WALL_Y_1)));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("Y_2", new nsGui::Sprite(WALL_Y_2)));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("Y_3", new nsGui::Sprite(WALL_Y_3)));


    /* Corners */
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("CORNER_1", new nsGui::Sprite(WALL_XY_1)));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("CORNER_2", new nsGui::Sprite(WALL_XY_2)));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("CORNER_3", new nsGui::Sprite(WALL_XY_3)));
    sprites.insert(std::pair<std::string, nsGui::Sprite*>("CORNER_4", new nsGui::Sprite(WALL_XY_4)));

    /* We're getting all empty positions */
    std::vector<nsGraphics::Vec2D> empty = getEmptyPositions();

    /* Added food */
    for (unsigned i = 0; i < empty.size(); i++)
        this->spawnItem(new Food(empty[i]));

    /* Added */
    Cooldowns::createCooldown("item_spawn", 1000);
}

void Map::update(unsigned delta, Player & player1, Player & player2) {
    /* Every 30 seconds, a new fruit spawns */
    if (Cooldowns::isCooldownOver("item_spawn") && itemsSpawned <= 8) {
        nsGraphics::Vec2D pos = getEmptyPosition();
        if (pos.getX() != -1 && pos.getY() != -1) this->spawnItem(new Fruit(pos));
    }

    for (auto & f : items)
        f.second->update(delta);

    /* Using a iterator to delete items when there's a player on it */
    for (auto it = this->items.begin(); it != this->items.end(); ++it) {
        if (player1.getPosition().getX() == it->first.first && player1.getPosition().getY() == it->first.second) {
            items.erase(it);
            player1.score += it->second->getType() == ItemType::FRUIT ? 200 : 50;
        }
        else if (player2.getPosition().getX() == it->first.first && player2.getPosition().getY() == it->first.second) {
            items.erase(it);
            player2.score += it->second->getType() == ItemType::FRUIT ? 200 : 50;
        }
        else continue;

        return;
    }
}

void Map::render(MinGL & window) {
    window << nsShape::Rectangle(nsGraphics::Vec2D(0, 0), this->grid[0].size() * 64, this->grid.size() * 64, nsGraphics::RGBAcolor(4, 4, 100));

    for (unsigned y = 0; y < this->grid.size(); y++) {
        for (unsigned x = 0; x < this->grid[y].size(); x++) {
            char & c = this->grid[y][x];

            switch(c) {
                case '0': // CELL
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
                case '^': // VERTICAL WALL 1
                    sprites["Y_1"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["Y_1"]->draw(window);
                    break;
                case '|': // VERTICAL WALL 2
                    sprites["Y_2"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["Y_2"]->draw(window);
                    break;
                case '-': // VERTICALL WALL 3
                    sprites["Y_3"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["Y_3"]->draw(window);
                    break;
                case '#': // HORIZONTAL WALL 1
                    sprites["X_1"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["X_1"]->draw(window);
                    break;
                case '=': // HORIZONTAL WALL 2
                    sprites["X_2"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["X_2"]->draw(window);
                    break;
                case '~': // HORIZONTAL WALL 3
                    sprites["X_3"]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites["X_3"]->draw(window);
                    break;
            }
        }
    }

    for (auto & f : items) {
        std::cout << "render " << f.second->getPosition().getX() << " " << f.second->getPosition().getY() << std::endl;
        f.second->render(window);
    }
}

unsigned Map::getMinX() {
    return 0;
}

unsigned Map::getMinY() {
    return 0;
}

unsigned Map::getWidth() {
    return grid[0].size();
}

unsigned Map::getHeight() {
    return grid.size();
}
