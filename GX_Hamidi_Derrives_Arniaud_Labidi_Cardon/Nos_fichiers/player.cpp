/**
 *
 * @file    player.cpp
 * @author  Thomas Cardon
 * @date    8 janvier 2020
 * @version 1.0
 * @brief   Définition des méthodes de la classe Player
 *
 **/
#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>

#include "type.h"

#include "player.h"
#include "entity.h"

using namespace nsGame;

Player::Player(unsigned N) : Entity() {
    this->N = N;
}

void Player::load(CMyParam params) {
    std::cout << "[Player N=" << std::to_string(N) + "] Loading" << std::endl;

    this->pos.setX(N == 1 ? 1 : params.MapParamUnsigned["NbColumn"] - 2);
    this->pos.setY(N == 1 ? 1 : params.MapParamUnsigned["NbRow"] - 2);

    for (int i = 1; i <= 6; i++) {
        this->top.sprites.push_back(nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/entities/player" + std::to_string(N) + "/top-" + std::to_string(i) + ".i2s"));
        this->bottom.sprites.push_back(nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/entities/player" + std::to_string(N) + "/bottom-" + std::to_string(i) + ".i2s"));
        this->left.sprites.push_back(nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/entities/player" + std::to_string(N) + "/left-" + std::to_string(i) + ".i2s"));
        this->right.sprites.push_back(nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/entities/player" + std::to_string(N) + "/right-" + std::to_string(i) + ".i2s"));
    }

    this->KEY_UP = params.MapParamChar["P" + std::to_string(N) + "_KeyUp"];
    this->KEY_DOWN = params.MapParamChar["P" + std::to_string(N) + "_KeyDown"];
    this->KEY_LEFT = params.MapParamChar["P" + std::to_string(N) + "_KeyLeft"];
    this->KEY_RIGHT = params.MapParamChar["P" + std::to_string(N) + "_KeyRight"];

    this->KEY_ACTION_1 = params.MapParamChar["P" + std::to_string(N) + "_KeyAction1"];

    std::cout << "[Player N=" << std::to_string(N) + "] KEY_UP -> " << this->KEY_UP << std::endl;
    std::cout << "[Player N=" << std::to_string(N) + "] KEY_DOWN -> " << this->KEY_DOWN << std::endl;
    std::cout << "[Player N=" << std::to_string(N) + "] KEY_LEFT -> " << this->KEY_LEFT << std::endl;
    std::cout << "[Player N=" << std::to_string(N) + "] KEY_RIGHT -> " << this->KEY_RIGHT << std::endl;
}

void Player::onKeyPress(char key) {
    if (!canMove) return;

    if (key == KEY_UP) this->pos.setY(this->pos.getY() - 1);
    else if (key == KEY_DOWN) this->pos.setY(this->pos.getY() + 1);
    else if (key == KEY_RIGHT) this->pos.setX(this->pos.getX() + 1);
    else if (key == KEY_LEFT) this->pos.setX(this->pos.getX() - 1);
    //else if (key == KEY_ACTION_1) this->powerball();
    else return;

    IS_FACING = key;
    canMove = false;
}

int Player::update(MinGL & window, int delta, CMat map) {
    /*
     * Movement cooldowns
     */
    currentTime += delta;

    if (!canMove && currentTime - startTime > delay) {
        canMove = true;
        currentTime = 0;
    }

    if (window.isPressed({ KEY_UP, false }) && !this->inCollision(map, this->pos.getX(), this->pos.getY() - 1))
        onKeyPress(KEY_UP);
    else if (window.isPressed({ KEY_DOWN, false }) && !this->inCollision(map, this->pos.getX(), this->pos.getY() + 1))
        onKeyPress(KEY_DOWN);
    else if (window.isPressed({ KEY_LEFT, false }) && !this->inCollision(map, this->pos.getX() + 1, this->pos.getY()))
        onKeyPress(KEY_LEFT);
    else if (window.isPressed({ KEY_RIGHT, false }) && !this->inCollision(map, this->pos.getX() - 1, this->pos.getY()))
        onKeyPress(KEY_RIGHT);

    //if (canTakeDamage(delta)) std::cout << "[Player N=" << std::to_string(N) + "] can take damage !" << std::endl;
    //else std::cout << "[Player N=" << std::to_string(N) + "] can't take damage !" << std::endl;

    this->top.update(delta);
    this->bottom.update(delta);
    this->right.update(delta);
    this->left.update(delta);

    return 0;
}


/*
 * TODO: Empêcher le joueur de passer en dehors des murs!
 */
bool Player::inCollision(CMat map, unsigned x, unsigned y) {
    return false;
}

bool Player::canTakeDamage(int delta) {
    _currentTimeForDamage += delta;

    if (_currentTimeForDamage >= 5000) return true;
    return false;
}

void Player::damage() {
    _startTimeForDamage = 0;

    --hearts;
    noDamage(5000);
}

void Player::noDamage(int ms) {}

void Player::render(MinGL & window) {
    if (this->IS_FACING == KEY_UP) {
        this->top.setPosition(this->getCoordinates());
        this->top.render(window);
    }
    else if (this->IS_FACING == KEY_DOWN) {
        this->bottom.setPosition(this->getCoordinates());
        this->bottom.render(window);
    }
    else if (this->IS_FACING == KEY_RIGHT) {
        this->right.setPosition(this->getCoordinates());
        this->right.render(window);
    }
    else {
        this->left.setPosition(this->getCoordinates());
        this->left.render(window);
    }
}
