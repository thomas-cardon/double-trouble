#include "powerup.h"
#include "definitions.h"

#include <mingl/gui/sprite.h>
#include <mingl/shape/circle.h>

/**
 *
 * \file    powerup.cpp
 * \author  Thomas Cardon
 * \date    12 janvier 2021
 * \version 1.0
 * \brief   Method definitions for powerup.h
 */

using namespace nsGame;

void Powerup::load() {
    audio.loadSound(RES_PATH + "/audio/powerup-1.wav");
}

void Powerup::update(unsigned delta) {}

void Powerup::action(Player *player) {
    audio.playSoundFromBuffer(RES_PATH + "/audio/powerup-1.wav");

    player->score += 100;
    player->addEffect(EffectType::POWER, 5000);
}

void Powerup::render(MinGL &window) {
    window << nsShape::Circle(this->getCoordinates(), 8, nsGraphics::KBlack) << nsShape::Circle(this->getCoordinates(), 6, nsGraphics::RGBAcolor(255, 215));
}
