#include "fruit.h"
#include <mingl/gui/sprite.h>
#include <mingl/shape/circle.h>

/**
 *
 * \file    fruit.cpp
 * \author  Thomas Cardon
 * \date    12 janvier 2020
 * \version 1.0
 * \brief   Method definitions for fruit.h
 */

using namespace nsGame;

void Fruit::load() {}

void Fruit::update(unsigned delta) {
    sprite.setPosition(this->getCoordinates());
}

void Fruit::render(MinGL &window) {
    window << sprite;
}
