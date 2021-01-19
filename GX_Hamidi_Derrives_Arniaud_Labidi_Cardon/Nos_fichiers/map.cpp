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

#include "definitions.h"
#include "cooldowns.h"
#include "cookie.h"

#include "fruit.cpp"

/**
 *
 * \file    map.cpp
 * \author  Thomas Cardon
 * \date    13 janvier 2020
 * \version 1.0
 * \brief   Method definitions for map.h
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

    return RES_PATH + "/maps/" + maps[rand() % maps.size()];
}

nsGraphics::Vec2D Map::getEmptyPosition() {
    std::vector<nsGraphics::Vec2D> empty = this->getEmptyPositions();
    return empty.at(rand() % empty.size());
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
    std::cout << "[Map] Spawns item at coordinates: x=" << item->getPosition().getX() << " y=" << item->getPosition().getY() << " " << item->getType() << std::endl;
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
    std::string map = getRandomLevel();

    std::cout << "[Map] Loading map: " << map << std::endl;
    input.open(map);

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
    sprites.insert(std::pair<char, nsGui::Sprite*>('#', new nsGui::Sprite(WALL_X_1)));
    sprites.insert(std::pair<char, nsGui::Sprite*>('=', new nsGui::Sprite(WALL_X_2)));
    sprites.insert(std::pair<char, nsGui::Sprite*>('~', new nsGui::Sprite(WALL_X_3)));
    sprites.insert(std::pair<char, nsGui::Sprite*>('^', new nsGui::Sprite(WALL_Y_1)));
    sprites.insert(std::pair<char, nsGui::Sprite*>('|', new nsGui::Sprite(WALL_Y_2)));
    sprites.insert(std::pair<char, nsGui::Sprite*>('-', new nsGui::Sprite(WALL_Y_3)));


    /* Corners */
    sprites.insert(std::pair<char, nsGui::Sprite*>('/', new nsGui::Sprite(CORNER_1)));
    sprites.insert(std::pair<char, nsGui::Sprite*>('\\', new nsGui::Sprite(CORNER_2)));
    sprites.insert(std::pair<char, nsGui::Sprite*>('(', new nsGui::Sprite(CORNER_3)));
    sprites.insert(std::pair<char, nsGui::Sprite*>(')', new nsGui::Sprite(CORNER_4)));

    /* Item spawn every 6 seconds */
    Cooldowns::createCooldown("item_spawn", 6*1000);

    /* We're getting all empty positions */
    std::vector<nsGraphics::Vec2D> empty = getEmptyPositions();

    /* Added food */
    for (unsigned i = 0; i < empty.size(); i++)
        this->spawnItem(new Cookie(empty[i]));
}

void Map::update(unsigned delta, Player & player1, Player & player2) {
    /* Every 6 seconds, a new fruit spawns, while the other fruits despawn */
    bool spawnNewItem = Cooldowns::isCooldownOver("item_spawn");

    for (auto & item : items)
        item.second->update(delta);

    /* Using a iterator to delete items when there's a player on it */
    auto it = this->items.begin();
    while (it != this->items.end()) {
        if (player1.getPosition().getX() == it->first.first && player1.getPosition().getY() == it->first.second)
            player1.score += it->second->getType() == ItemType::FRUIT ? 200 : 35; // +200 if it's a FRUIT, +35 if it's not
        else if (player2.getPosition().getX() == it->first.first && player2.getPosition().getY() == it->first.second)
            player2.score += it->second->getType() == ItemType::FRUIT ? 200 : 35;
        else if (spawnNewItem && it->second->getType() == ItemType::FRUIT) { // if a new item needs to be spawned, it removes the other fruits
            items.erase(it++);
            continue;
        }
        else {
            ++it;
            continue;
        }

        items.erase(it++);
        return;
    }

    if (spawnNewItem && itemsLeft != 0) {
        this->spawnItem(new Fruit(getEmptyPosition()));
        --itemsLeft;
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
                default:
                    sprites[c]->setPosition(nsGraphics::Vec2D(x * 32, y * 32));
                    sprites[c]->draw(window);
            }
        }
    }

    for (auto & item : items)
        item.second->render(window);
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
