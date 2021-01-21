#include "map.h"

#include <utility>
#include <iostream>
#include <fstream>
#include <dirent.h>

#include <mingl/graphics/vec2d.h>
#include <mingl/shape/rectangle.h>
#include <mingl/gui/text.h>

#include "definitions.h"
#include "cooldowns.h"
#include "cookie.h"

#include "fruit.cpp"
#include "powerup.h"

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

    if (empty.size() > 0) return empty.at(rand() % empty.size());
    return nsGraphics::Vec2D(-1, -1);
}

std::vector<nsGraphics::Vec2D> Map::getEmptyPositions() {
    std::vector<nsGraphics::Vec2D> vec;

    for (unsigned y = 0; y < getHeight(); y++) {
        for (unsigned x = 0; x < getWidth(); x++) {
            if (this->grid[y][x] == '0' && this->items.count(std::make_pair(x, y)) == 0) vec.push_back(nsGraphics::Vec2D(x, y));
        }
    }

    return vec;
}

void Map::spawnItem(Item* item) {
    std::cout << "[Map] Spawns item at coordinates: x=" << item->getPosition().getX() << " y=" << item->getPosition().getY() << " " << item->getType() << std::endl;
    try {
        item->load();
        items[std::make_pair(item->getPosition().getX(), item->getPosition().getY())] = item;
    }  catch (...) {
        std::cout << "[Map] Can't spawn item!";
    }
}

void Map::load() {
    /** \brief Input FileStream for the different levels */
    std::ifstream input;

    /** \brief A random level taken from its folder */
    std::string map = getRandomLevel();

    std::cout << "[Map] Loading map: " << map << std::endl;
    input.open(map);

    if (!input) {
        std::cerr << "Unable to open file" << std::endl;
        exit(1); // Terminate with error
    }

    /* For each line, we resize the grid to add one more entry and pushes the characters for each row in the grid */
    for( std::string line; getline(input, line ); ) {
        this->grid.resize(this->grid.size() + 1);

        for(char& c : line)
            this->grid[this->grid.size() - 1].push_back(c);
    }

    input.close();

    /* Each character has its own sprite for the map */
    /* Walls */
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

    /* T_Walls */
    sprites.insert(std::pair<char, nsGui::Sprite*>('$', new nsGui::Sprite(T_WALL_1)));
    sprites.insert(std::pair<char, nsGui::Sprite*>('%', new nsGui::Sprite(T_WALL_2)));

    /* Item spawn every 6 seconds */
    Cooldowns::createCooldown("item_spawn", COOLDOWNS_ITEM_SPAWN);

    /* We're getting all empty positions */
    std::vector<nsGraphics::Vec2D> empty = getEmptyPositions();

    /* Adding food */
    for (unsigned i = 0; i < empty.size(); i++)
        this->spawnItem(new Cookie(empty[i]));

    /* Adding monsters */
    for (unsigned i = 1; i <= 4; i++) {
        Monster *m = new Monster(i);
        m->load();
        this->monsters.push_back(m);
    }
}

void Map::update(unsigned delta, Player *p1, Player *p2) {
    /** \brief Every 6 seconds, a new fruit spawns, while the other ones despawn */
    bool spawnNewItem = Cooldowns::isCooldownOver("item_spawn");

    /* Updating items */
    for (auto & item : items)
        item.second->update(delta);

    /* Using a iterator to delete items when there's a player on it */
    auto it = this->items.begin();
    while (it != this->items.end()) {
        if (p1->getPosition().getX() == it->first.first && p1->getPosition().getY() == it->first.second)
            it->second->action(p1);
        else if (p2->getPosition().getX() == it->first.first && p2->getPosition().getY() == it->first.second)
            it->second->action(p2);
        else if (spawnNewItem && it->second->getType() == ItemType::FRUIT) { // if a new item needs to be spawned, it removes the other fruits
            items.erase(it++);
            continue;
        }
        else {
            ++it;
            continue;
        }

        --itemsLeft;
        items.erase(it++);
        return;
    }

    for (auto & monster : monsters)
        monster->update(delta, this->getMat());

    if (spawnNewItem && itemsLeft > 0) {
        nsGraphics::Vec2D pos = getEmptyPosition();

        if (pos == p1->getPosition() || pos == p2->pos) {
            std::cout << "[Map] Item can't spawn because there's a player !" << std::endl;
            return;
        }

        if (pos.getX() == -1 && pos.getY() == -1) {
            std::cout << "[Map] Item can't spawn because there's no space left !" << std::endl;
            return;
        }

        if (rand() % 10 == 9 && !hasPowerupSpawned) {
            this->spawnItem(new Powerup(pos));
            hasPowerupSpawned = true;
        }
        else this->spawnItem(new Fruit(pos));
    }
}

void Map::render(MinGL & window) {
    window << nsShape::Rectangle(nsGraphics::Vec2D(0, 0), this->grid[0].size() * CELL_SIZE, this->grid.size() * CELL_SIZE, nsGraphics::RGBAcolor(4, 4, 100));

    for (unsigned y = 0; y < this->grid.size(); y++) {
        for (unsigned x = 0; x < this->grid[y].size(); x++) {
            char & c = this->grid[y][x];

            switch(c) {
                case '0': /* If it's a cell, we don't show anything since we've put a rectangle all over the map */
                    break;
                default:
                    sprites[c]->setPosition(nsGraphics::Vec2D(x * CELL_SIZE, y * CELL_SIZE));
                    sprites[c]->draw(window);
            }
        }
    }

    for (auto & item : items)
        item.second->render(window);

    for (auto & monster : monsters)
        monster->render(window);
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
