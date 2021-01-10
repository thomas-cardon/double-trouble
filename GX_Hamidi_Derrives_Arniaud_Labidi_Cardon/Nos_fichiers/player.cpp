/**
 *
 * @file    player.h
 * @author  Thomas Cardon
 * @date    8 janvier 2020
 * @version 1.0
 * @brief   Définition des méthodes de la classe Player
 *
 **/

#define CELL_SIZE 32

#include <time.h>

#include "player.h"

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>

#include "type.h"

using namespace nsGame;

void Player::load(CMyParam params) {
    std::cout << "[Player] Loading" << std::endl;

    this->KEY_UP = params.MapParamChar["P" + std::to_string(N) + "_KeyUp"];
    this->KEY_DOWN = params.MapParamChar["P" + std::to_string(N) + "_KeyDown"];
    this->KEY_LEFT = params.MapParamChar["P" + std::to_string(N) + "_KeyLeft"];
    this->KEY_RIGHT = params.MapParamChar["P" + std::to_string(N) + "_KeyRight"];
}

void Player::onKeyPress(char key) {
    if (!canMove) return;

    if (key == KEY_UP) this->pos.second -= 1;
    else if (key == KEY_DOWN) this->pos.second += 1;
    else if (key == KEY_RIGHT) this->pos.first += 1;
    else if (key == KEY_LEFT) this->pos.first -= 1;
    else return;

    canMove = false;
    this->sprite.setPosition(nsGraphics::Vec2D(this->pos.first * CELL_SIZE, this->pos.second * CELL_SIZE));
}

int Player::update(MinGL & window) {
    /*
     * Movement cooldowns
     */
    currentTime++;

    if (!canMove && currentTime - startTime > delay) {
        canMove = true;
        currentTime = 0;
    }

    if (window.isPressed({ KEY_UP, false }))
        onKeyPress(KEY_UP);
    else if (window.isPressed({ KEY_DOWN, false }))
        onKeyPress(KEY_DOWN);
    else if (window.isPressed({ KEY_LEFT, false }))
        onKeyPress(KEY_LEFT);
    else if (window.isPressed({ KEY_RIGHT, false }))
        onKeyPress(KEY_RIGHT);

    return 0;
}

void Player::render(MinGL & window) {
    window << this->sprite;
}
