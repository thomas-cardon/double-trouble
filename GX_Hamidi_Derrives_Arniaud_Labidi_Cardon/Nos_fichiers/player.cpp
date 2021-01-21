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
#include <mingl/audio/audioengine.h>
#include <mingl/gui/sprite.h>

#include "type.h"
#include "definitions.h"

#include "player.h"
#include "entity.h"

#include "cooldowns.cpp"

/**
 *
 * \file    player.cpp
 * \author  Thomas Cardon
 * \date    10 janvier 2021
 * \version 1.0
 * \brief   Method definitions for Player.h
 */

using namespace nsGame;

nsAudio::AudioEngine audio;

Player::Player(unsigned N) : Entity("player-" + std::to_string(N), nsGraphics::Vec2D(N == 1 ? 1 : 18, N == 1 ? 1 : 18)) {
    this->N = N;
}

void Player::spawn() {
    this->pos = nsGraphics::Vec2D(N == 1 ? 1 : 18, N == 1 ? 1 : 18);
    this->IS_FACING = N == 1 ? this->KEY_RIGHT : this->KEY_LEFT;
}

void Player::load(CMyParam params) {
    std::cout << "[Player N=" << std::to_string(N) + "] Loading" << std::endl;
    this->setMovementSpeed(0.35);
    this->spawn();

    audio.loadSound(RES_PATH + "/audio/player-hit-1.wav");
    audio.loadSound(RES_PATH + "/audio/player-moving-1.wav");

    for (int i = 1; i <= 6; i++) {
        this->top.sprites.push_back(nsGui::Sprite(RES_PATH + "/entities/player" + std::to_string(N) + "/top-" + std::to_string(i) + ".i2s"));
        this->bottom.sprites.push_back(nsGui::Sprite(RES_PATH + "/entities/player" + std::to_string(N) + "/bottom-" + std::to_string(i) + ".i2s"));
        this->left.sprites.push_back(nsGui::Sprite(RES_PATH + "/entities/player" + std::to_string(N) + "/left-" + std::to_string(i) + ".i2s"));
        this->right.sprites.push_back(nsGui::Sprite(RES_PATH + "/entities/player" + std::to_string(N) + "/right-" + std::to_string(i) + ".i2s"));

        this->invincible.sprites.push_back(nsGui::Sprite(RES_PATH + "/entities/noDamage/" + std::to_string(i) + ".i2s"));
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
    if (!canMove || !isAllowedToMove) return;

    if (key == KEY_UP) this->pos.setY(this->pos.getY() - 1);
    else if (key == KEY_DOWN) this->pos.setY(this->pos.getY() + 1);
    else if (key == KEY_RIGHT) this->pos.setX(this->pos.getX() + 1);
    else if (key == KEY_LEFT) this->pos.setX(this->pos.getX() - 1);
    //else if (key == KEY_ACTION_1) this->powerball();
    else return;

    IS_FACING = key;
    canMove = false;
}

void Player::update(MinGL & window, unsigned delta, CMat map) {
    /*
     * Movement cooldowns
     */
    canMove = Cooldowns::isCooldownOver(id + "_move");
    if (_noDamage != -1) {
        if (_noDamage >= _noDamageFor) {
            _noDamage = -1;
            _canTakeDamage = true;
        }
        else {
            _canTakeDamage = false;
            _noDamage += delta;
        }
    }

    if (isAllowedToMove) {
        if (window.isPressed({ KEY_UP, false })) {
            if (this->inCollision(map, this->pos.getX(), this->pos.getY() - 1))
                audio.playSoundFromBuffer(RES_PATH + "/audio/player-hit-1.wav");
            else onKeyPress(KEY_UP);
        }
        else if (window.isPressed({ KEY_DOWN, false })) {
            if (this->inCollision(map, this->pos.getX(), this->pos.getY() + 1))
                audio.playSoundFromBuffer(RES_PATH + "/audio/player-hit-1.wav");
            else onKeyPress(KEY_DOWN);
        }
        else if (window.isPressed({ KEY_LEFT, false })) {
            if (this->inCollision(map, this->pos.getX() - 1, this->pos.getY()))
                audio.playSoundFromBuffer(RES_PATH + "/audio/player-hit-1.wav");
            else onKeyPress(KEY_LEFT);
        }
        else if (window.isPressed({ KEY_RIGHT, false })) {
            if (this->inCollision(map, this->pos.getX() + 1, this->pos.getY()))
                audio.playSoundFromBuffer(RES_PATH + "/audio/player-hit-1.wav");
            else onKeyPress(KEY_RIGHT);
        }
    }

    this->top.update(delta);
    this->bottom.update(delta);
    this->right.update(delta);
    this->left.update(delta);

    this->invincible.update(delta);
}

void Player::damage() {
    audio.playSoundFromBuffer(RES_PATH + "/audio/player-hit-1.wav");

    --hearts;
    noDamage(5000);

    if (hearts <= 0) this->kill();
}

void Player::noDamage(int ms) {
    _noDamageFor = ms;
    _noDamage = 0;
}

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

    if (!this->canTakeDamage()) {
        this->invincible.setPosition(this->getCoordinates());
        this->invincible.render(window);
    }
}
