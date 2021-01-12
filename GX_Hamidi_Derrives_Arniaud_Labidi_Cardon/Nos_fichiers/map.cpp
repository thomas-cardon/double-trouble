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

using namespace nsGame;

void Map::load(CMyParam & params) {
    Mat.resize (params.MapParamUnsigned.find("NbColumn")->second);
    const CVLine KLine (params.MapParamUnsigned.find("NbRow")->second, KEmpty);
    for (CVLine &ALine : Mat)
        ALine = KLine;

    unsigned lines = this->getHeight(), columns = this->getWidth();

    for (unsigned i (0); i < lines; i = i + 1) {
        for (unsigned j (0); j < Mat[i].size(); ++j) {
            sprites.push_back(nsGui::Sprite(BLOCK, nsGraphics::Vec2D(i * 32, j * 32)));

            if (j > 0 && j < columns - 1) {
                /* Murs verticaux d'à gauche */
                sprites.push_back(nsGui::Sprite(WALL_Y_2, nsGraphics::Vec2D(0, j * 32)));
                /* Murs verticaux d'à droite */
                sprites.push_back(nsGui::Sprite(WALL_Y_2, nsGraphics::Vec2D((columns - 1) * 32, j * 32)));
            }
        }

        if (i > 0 && i < lines - 1) {
            /* Murs horizontaux du haut */
            sprites.push_back(nsGui::Sprite(i == 0 ? WALL_X_1 : (i != lines - 1 ? WALL_X_2 : WALL_X_3), nsGraphics::Vec2D(i * 32, 0)));
            /* Murs horizontaux du bas */
            sprites.push_back(nsGui::Sprite(i == 0 ? WALL_X_1 : (i != lines - 1 ? WALL_X_2 : WALL_X_3), nsGraphics::Vec2D(i * 32, (lines - 1) * 32)));
        }
    }

    /* Recoins */
    sprites.push_back(nsGui::Sprite(WALL_XY_1, nsGraphics::Vec2D(0, 0)));
    sprites.push_back(nsGui::Sprite(WALL_XY_2, nsGraphics::Vec2D((lines - 1) * 32, 0)));
    sprites.push_back(nsGui::Sprite(WALL_XY_3, nsGraphics::Vec2D(0, (lines - 1) * 32)));
    sprites.push_back(nsGui::Sprite(WALL_XY_4, nsGraphics::Vec2D((lines - 1) * 32, (lines - 1) * 32)));
}

void Map::update(int delta) {}

void Map::render(MinGL & window) {
    for (auto &sprite : sprites)
        window << sprite;
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
