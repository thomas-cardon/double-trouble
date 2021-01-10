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
    std::cout << "[Player N=" << std::to_string(N) + "] Loading" << std::endl;

    this->KEY_UP = params.MapParamChar["P" + std::to_string(N) + "_KeyUp"];
    this->KEY_DOWN = params.MapParamChar["P" + std::to_string(N) + "_KeyDown"];
    this->KEY_LEFT = params.MapParamChar["P" + std::to_string(N) + "_KeyLeft"];
    this->KEY_RIGHT = params.MapParamChar["P" + std::to_string(N) + "_KeyRight"];

    std::cout << "[Player N=" << std::to_string(N) + "] KEY_UP -> " << this->KEY_UP << std::endl;
    std::cout << "[Player N=" << std::to_string(N) + "] KEY_DOWN -> " << this->KEY_DOWN << std::endl;
    std::cout << "[Player N=" << std::to_string(N) + "] KEY_LEFT -> " << this->KEY_LEFT << std::endl;
    std::cout << "[Player N=" << std::to_string(N) + "] KEY_RIGHT -> " << this->KEY_RIGHT << std::endl;
}

void Player::onKeyPress(char key) {
    if (!canMove) return;

    if (key == KEY_UP) this->pos.second -= 1;
    else if (key == KEY_DOWN) this->pos.second += 1;
    else if (key == KEY_RIGHT) this->pos.first += 1;
    else if (key == KEY_LEFT) this->pos.first -= 1;
    else return;

    canMove = false;
}

int Player::update(MinGL & window, CMat map) {
    /*
     * Movement cooldowns
     */
    currentTime++;

    if (!canMove && currentTime - startTime > delay) {
        canMove = true;
        currentTime = 0;
    }

    if (window.isPressed({ KEY_UP, false }) && this->inCollision(map, this->pos.first, this->pos.second - 1))
        onKeyPress(KEY_UP);
    else if (window.isPressed({ KEY_DOWN, false }) && this->inCollision(map, this->pos.first, this->pos.second + 1))
        onKeyPress(KEY_DOWN);
    else if (window.isPressed({ KEY_LEFT, false }) && this->inCollision(map, this->pos.first + 1, this->pos.second))
        onKeyPress(KEY_LEFT);
    else if (window.isPressed({ KEY_RIGHT, false }) && this->inCollision(map, this->pos.first - 1, this->pos.second))
        onKeyPress(KEY_RIGHT);

    return 0;
}


bool Player::inCollision(CMat map, unsigned x, unsigned y) {
    return true;
}

void Player::render(MinGL & window) {
    this->sprite.setPosition(nsGraphics::Vec2D(this->pos.first * CELL_SIZE, this->pos.second * CELL_SIZE));
    window << this->sprite;
}
