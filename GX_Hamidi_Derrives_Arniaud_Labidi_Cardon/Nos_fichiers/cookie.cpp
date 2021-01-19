#include "cookie.h"
#include <mingl/shape/circle.h>
/**
 *
 * \file    cookie.cpp
 * \author  Thomas Cardon
 * \date    12 janvier 2020
 * \version 1.0
 * \brief   Method definitions for cookie.h
 */

using namespace nsGame;

void Cookie::load() {}

void Cookie::update(unsigned delta) {}

void Cookie::render(MinGL &window) {
    window << nsShape::Circle(this->getCoordinates(), 2, nsGraphics::KWhite);
}
