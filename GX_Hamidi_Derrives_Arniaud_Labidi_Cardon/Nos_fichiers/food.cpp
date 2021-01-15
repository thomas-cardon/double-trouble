#include "food.h"
#include <mingl/shape/circle.h>
/**
 *
 * \file    food.cpp
 * \author  Thomas Cardon
 * \date    12 janvier 2020
 * \version 1.0
 * \brief   Method definitions for food.h
 */

using namespace nsGame;

void Food::load() {}
void Food::update(unsigned delta) {}

void Food::render(MinGL &window) {
    window << nsShape::Circle(this->getCoordinates(), 1, nsGraphics::KWhite);
}
