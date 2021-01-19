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

void Fruit::load() {
    audio.loadSound(RES_PATH + "/audio/fruit-eaten.wav");
}

void Fruit::update(unsigned delta) {}


void Fruit::action(Player & player) {
    player.score += 200;
    audio.playSoundFromBuffer(RES_PATH + "/audio/fruit-eaten.wav");
}

void Fruit::render(MinGL &window) {
    sprite.setPosition(this->getCoordinates());
    window << sprite;
}
