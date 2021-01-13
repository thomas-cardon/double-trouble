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

#include "player.h"
#include "entity.h"

#include "cooldowns.h"

/**
 *
 * \file    player.cpp
 * \author  Thomas Cardon
 * \date    10 janvier 2020
 * \version 1.0
 * \brief   Method definitions for Player.h
 */


using namespace nsGame;

nsAudio::AudioEngine audio;

Player::Player(unsigned N) : Entity() {
    this->N = N;
}

void Player::spawn() {
    this->pos = nsGraphics::Vec2D(0, 0);

    this->pos.setX(N == 1 ? 1 : 18);
    this->pos.setY(N == 1 ? 1 : 18);

    this->IS_FACING = N == 1 ? this->KEY_RIGHT : this->KEY_LEFT;
}

void Player::load(CMyParam params) {
    std::cout << "[Player N=" << std::to_string(N) + "] Loading" << std::endl;

    createCooldown("player" + std::to_string(N) + "_move", 200 / movementSpeed);

    this->spawn();

    audio.loadSound("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/audio/player-hit-1.wav");

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
    canMove = isCooldownOver("player" + std::to_string(N) + "_move");

    if (isAllowedToMove) {
        if (window.isPressed({ KEY_UP, false })) {
            if (this->inCollision(map, this->pos.getX(), this->pos.getY() - 1))
                audio.playSoundFromBuffer("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/audio/player-hit-1.wav");
            else onKeyPress(KEY_UP);
        }
        else if (window.isPressed({ KEY_DOWN, false })) {
            if (this->inCollision(map, this->pos.getX(), this->pos.getY() + 1))
                audio.playSoundFromBuffer("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/audio/player-hit-1.wav");
            else onKeyPress(KEY_DOWN);
        }
        else if (window.isPressed({ KEY_LEFT, false })) {
            if (this->inCollision(map, this->pos.getX() - 1, this->pos.getY()))
                audio.playSoundFromBuffer("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/audio/player-hit-1.wav");
            else onKeyPress(KEY_LEFT);
        }
        else if (window.isPressed({ KEY_RIGHT, false })) {
            if (this->inCollision(map, this->pos.getX() + 1, this->pos.getY()))
                audio.playSoundFromBuffer("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/audio/player-hit-1.wav");
            else onKeyPress(KEY_RIGHT);
        }
    }

    this->top.update(delta);
    this->bottom.update(delta);
    this->right.update(delta);
    this->left.update(delta);
}

bool Player::canTakeDamage() {
    return isCooldownOver("player" + std::to_string(N) + "_canTakeDamage", true);
}

void Player::damage() {
    --hearts;
    noDamage(5000);
}

void Player::noDamage(int ms) {
    createCooldown("player" + std::to_string(N) + "_canTakeDamage", ms);
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
}

void Player::setMovementSpeed(double speed) {
    this->movementSpeed = speed;
    setCooldownDelay("player" + std::to_string(N) + "_move", 200 / getMovementSpeed());
}
