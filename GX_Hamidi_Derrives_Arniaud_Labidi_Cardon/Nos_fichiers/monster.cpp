/**
 * @file    monster.cpp
 * @authors Ines Hamidi, Thomas Cardon, Alexandre Arniaud
 * @date    11 janvier 2020
 * @version 1.0
 * @brief   Définition des méthodes de la classe monster.h
 **/

#include <math.h>

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

void Monster::load() {
    std::cout << "[Monster#" << this->id() + "] Loading" << std::endl;
    Cooldowns::createCooldown(id() + "_move", this->_getDelay());

    this->Entity::load();

    this->setMovementSpeed(this->behaviourId == 4 ? 0.1 : 0.35);
    this->audio.loadSound(RES_PATH + "/audio/monster-hit-1.wav");

    this->spawn();
}

std::string Monster::id() {
    return "monster-" + std::to_string(this->behaviourId);
}

int carre (int a) {
    return a * a;
}

void Monster::update(unsigned delta, CMat & mat, Player *p1, Player *p2)
{
    this->Entity::update(delta, mat);

    if (slain) return;

    canMove = Cooldowns::isCooldownOver(this->id() + "_move");
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
        int distp1, distp2; // Va permettre de calculer la distance qui sépare le monstre des deux joueurs pour déterminer la distance la plus courte
        distp1 = sqrt(carre((p1->getPosition().getX() - this->getPosition().getX())) + carre((p1->getPosition().getY() - this->getPosition().getY())));
        distp2 = sqrt(carre((p2->getPosition().getX() - this->getPosition().getX())) + carre((p2->getPosition().getY() - this->getPosition().getY())));
        Player *target = distp1 < distp2 ? p1 : p2; // On vérifie la distance la plus courte pour faire déplacer le monstre en fonction du joueur le plus proche

        if (target->IS_FACING == target->KEY_UP) { // Le joueur va vers le haut ?
            this->IS_FACING = 'S';

            if (!this->inCollision(mat, x, y - 1))
            this->pos.setY(this->pos.getY() - 1);
        }

        if (target->IS_FACING == target->KEY_DOWN) { // Le joueur va vers le bas ?
            this->IS_FACING = 'Z';

            if (!this->inCollision(mat, x, y + 1))
            this->pos.setY(this->pos.getY() + 1);
        }

        if (target->IS_FACING == target->KEY_LEFT) { // Le joueur va vers la gauche?
            this->IS_FACING = 'D';

            if (!this->inCollision(mat, x + 1, y))
            this->pos.setX(this->pos.getX() + 1);
        }

        if (target->IS_FACING == target->KEY_RIGHT) { // Le joueur va vers la droite ?
            this->IS_FACING = 'Q';

            if (!this->inCollision(mat, x - 1, y))
            this->pos.setX(this->pos.getX() - 1);
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
    if (this->slain) return;

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

    this->Entity::render(window);
}
