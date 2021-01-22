/**
 * @file    monster.cpp
 * @authors Ines Hamidi, Thomas Cardon, Alexandre Arniaud
 * @date    11 janvier 2020
 * @version 1.0
 * @brief   Définition des méthodes de la classe monster.h
 **/

#include "type.h"

#include "monster.h"
#include "cooldowns.h"

#include "definitions.h"

#include <mingl/shape/circle.h>

/**
 * \file    monster.cpp
 * \author  Alexandre Arniaud, Thomas Cardon, Ines Hamidi
 * \date    21 janvier 2021
 * \version 1.0
 * \brief   Method definitions for monster.h
 */

using namespace nsGame;

void Monster::spawn() {
    this->pos.setX(10);
    this->pos.setY(1 * behaviourId);
}

void Monster::damage() {
    this->audio.playSoundFromBuffer(RES_PATH + "/audio/monster-hit-1.wav");
    this->kill();
}

bool Monster::canBeHitBy(Entity *entity) {
    if (entity->canBeHitBy(this)) return false;

    if (this->getPosition().getX() == entity->getPosition().getX() && this->getPosition().getY() == entity->getPosition().getY() && !entity->canBeHitBy(this))
        return true;

    return false;
}

void Monster::load() {
    std::cout << "[Monster#" << id + "] Loading" << std::endl;
    this->Entity::load();

    this->setMovementSpeed(0.35);
    this->audio.loadSound(RES_PATH + "/audio/monster-hit-1.wav");

    this->spawn();
}

void Monster::update(unsigned delta, CMat & mat)
{
    this->Entity::update(delta, mat);

    if (slain) return;

    canMove = Cooldowns::isCooldownOver(id + "_move");
    if (!canMove) return;

    unsigned x = this->getPosition().getX(), y = this->getPosition().getY();

    if (this->behaviourId == 1) //Behaviour 1 : Follow outer walls
    {
        if (!this->inCollision(mat, x + 1, y) && y == 1) {
            this->pos.setX(x + 1); // Right
            this->IS_FACING = 'D';
        }
        else if (!this->inCollision(mat, x, y - 1) && x == 1) {
            this->pos.setY(y - 1); // Down
            this->IS_FACING = 'S';
        }
        else if (!this->inCollision(mat, x - 1, y) && y == mat.size() - 2) {
            this->pos.setX(x - 1); // Left
            this->IS_FACING = 'Q';
        }

        else if (!this->inCollision(mat, x, y + 1) && y <= mat.size() - 2) {
            this->pos.setY(y + 1); // Up
            this->IS_FACING = 'Z';
        }
    }

    else if (this->behaviourId == 2) //Behaviour 2 : Follow a little wall
        {
        if (this->inCollision(mat, x, y + 1) && (IS_FACING == 'L' || IS_FACING == 'D')) {
            this->pos.setX(x + 1); // Right
            this->IS_FACING = 'D';
        }
        else if (this->inCollision(mat, x + 1, y) && (IS_FACING == 'J' || IS_FACING == 'Z' || IS_FACING == 'R')) {
            this->pos.setY(y - 1); // Up
            this->IS_FACING = 'Z';
        }
        else if (this->inCollision(mat, x, y - 1) && (IS_FACING == 'I' || IS_FACING == 'Q')) {
            this->pos.setX(x - 1); // Left
            this->IS_FACING = 'Q';
        }
        else if (this->inCollision(mat, x - 1, y) && (IS_FACING == 'K' || IS_FACING == 'S')) {
            this->pos.setY(y + 1); // Down
            this->IS_FACING = 'S';
        }

        else if (!this->inCollision(mat, x + 1, y) && IS_FACING == 'Z') {
            this->pos.setX(x + 1); // Right without collision on right
            this->IS_FACING = 'L';
        }
        else if (!this->inCollision(mat, x, y - 1) && IS_FACING == 'Q') {
            this->pos.setY(y - 1); // Up without collision on top
            this->IS_FACING = 'J';
        }
        else if (!this->inCollision(mat, x - 1, y) && IS_FACING == 'S') {
            this->pos.setX(x - 1); // Left without collision on left
            this->IS_FACING = 'I';
        }
        else if (!this->inCollision(mat, x, y + 1) && IS_FACING == 'D') {
            this->pos.setY(y + 1); // Down without collision on down
            this->IS_FACING = 'K';
        }

        else if (!this->inCollision(mat, x + 1, y + 1) && !this->inCollision(mat, x - 1, y - 1)) {
         this->pos.setX(x + 1); // If there isn't collisions, right
         this->IS_FACING = 'R';
        }
    }

    else if (this->behaviourId == 3) // Behaviour : Flee the player
    {
        bool circleID = rand() % 1;

        if (circleID == 1) //circle to the left
        {
            this->pos.setX(x + 1);
            this->pos.setY(y + 1);
            this->pos.setX(x - 1);
            this->pos.setY(y - 1);
        }
        else {
            this->pos.setX(x - 1);
            this->pos.setY(y - 1);
            this->pos.setX(x + 1);
            this->pos.setY(y + 1);
        }
    }
    else if (this->behaviourId == 4) { // Behaviour 4 => Random
        int move = rand() % 4 + 1;

        if (move == 0 && (x + 1 <= mat[y].size() - 1) && !this->inCollision(mat, x + 1, y)) {
            this->pos.setX(x + 1);
            this->IS_FACING = 'D';
        }
        else if (move == 1 && (x - 1 >= 0) && !this->inCollision(mat, x - 1, y)) {
            this->pos.setX(x - 1);
            this->IS_FACING = 'Q';
        }
        else if (move == 2 && (y + 1 <= mat.size() - 1) && !this->inCollision(mat, x, y + 1)) {
            this->pos.setY(y + 1);
            this->IS_FACING = 'S';
        }
        else if ((y - 1 >= 0) && !this->inCollision(mat, x, y - 1)) {
            this->pos.setY(y - 1);
            this->IS_FACING = 'Z';
        }
    }
};

void Monster::render(MinGL &window) {
    this->Entity::render(window);
    if (slain) return;

    if (IS_FACING == 'Z' || IS_FACING == 'J') {
        this->top.setPosition(this->getCoordinates());
        window << this->top;
    }
    else if (IS_FACING == 'Q' || IS_FACING == 'I') {
        this->left.setPosition(this->getCoordinates());
        window << this->left;
    }
    else if (IS_FACING == 'D' || IS_FACING == 'K' || IS_FACING == 'R') {
        this->right.setPosition(this->getCoordinates());
        window << this->right;
    }
    else if (IS_FACING == 'S' || IS_FACING == 'L') {
        this->bottom.setPosition(this->getCoordinates());
        window << this->bottom;
    }

    window << nsShape::Circle(nsGraphics::Vec2D(this->getCoordinates().getX() + 16, this->getCoordinates().getY() + 16), 8, nsGraphics::KPurple);
}
