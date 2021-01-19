#include "powerup.h"
#include <mingl/gui/sprite.h>
#include <mingl/shape/rectangle.h>

/**
 *
 * \file    powerup.cpp
 * \author  Thomas Cardon
 * \date    12 janvier 2020
 * \version 1.0
 * \brief   Method definitions for powerup.h
 */

using namespace nsGame;

void Powerup::load() {}

void Powerup::update(unsigned delta) {}

void Powerup::action(Player & player) {
    player.score += 100;
}

void Powerup::render(MinGL &window) {
    window <<  nsShape::Rectangle(this->getCoordinates(), 2, nsGraphics::KGreen);
}
