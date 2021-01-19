/**
 * @file    monster.cpp
<<<<<<< main
 * @authors Ines Hamidi, Thomas Cardon, Alexandre Arniaud
=======
 * @author  Ines Hamidi
>>>>>>> Refonte des classes
 * @date    11 janvier 2020
 * @version 1.0
 * @brief   Définition des méthodes de la classe monster.h
 **/

<<<<<<< main
#include "type.h"

#include "monster.h"
#include "cooldowns.h"

#include "definitions.h"

/**
 * \file    animation.cpp
 * \author  Alexandre Arniaud, Thomas Cardon, Ines Hamidi
 * \date    21 janvier 2021
 * \version 1.0
 * \brief   Method definitions for monster.h
 */

using namespace nsGame;

std::string Monster::getEntityId() {
    return "Monster" + std::to_string(this->behaviourId);
}

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
    std::cout << "[Monster#" << getEntityId() + "] Loading" << std::endl;

    this->movementSpeed = 0.35;
    Cooldowns::createCooldown(getEntityId() + "_move", this->_getDelay());

    this->audio.loadSound(RES_PATH + "/audio/monster-hit-1.wav");

    this->spawn();
}

void Monster::update(unsigned delta, CMat & mat)
{
    if (slain) return;

    canMove = Cooldowns::isCooldownOver(getEntityId() + "_move");
    if (!canMove) return;

    //std::cout << "[Monster#" << getEntityId() + "] Position: x= " << this->getPosition().getY() << ", y= " << this->getPosition().getY() << std::endl;

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
        if (this->inCollision(mat, x, y + 1) && LastMove == 'd') {
            this->pos.setX(x + 1); // Right
            this->IS_FACING = 'D';
            LastMove = 'd';
        }
        else if (this->inCollision(mat, x + 1, y) && LastMove == 'z') {
            this->pos.setY(y - 1); // Up
            this->IS_FACING = 'Z';
            LastMove = 'z';
        }
        else if (this->inCollision(mat, x, y - 1) && LastMove == 'q') {
            this->pos.setX(x - 1); // Left
            this->IS_FACING = 'Q';
            LastMove = 'q';
        }
        else if (this->inCollision(mat, x - 1, y) && LastMove == 's') {
            this->pos.setY(y + 1); // Down
            this->IS_FACING = 'S';
            LastMove = 's';
        }

        else if (!this->inCollision(mat, x + 1, y + 1) && !this->inCollision(mat, x - 1, y - 1) && LastMove == 'z') {
            this->pos.setX(x + 1); // Right without collision on down
            this->IS_FACING = 'D';
            LastMove = 'd';
        }
        else if (!this->inCollision(mat, x + 1, y + 1) && !this->inCollision(mat, x - 1, y - 1) && LastMove == 'q') {
            this->pos.setX(x - 1); // Up without collision on right
            this->IS_FACING = 'Z';
            LastMove = 'z';
        }
        else if (!this->inCollision(mat, x + 1, y + 1) && !this->inCollision(mat, x - 1, y - 1) && LastMove == 's') {
            this->pos.setX(y - 1); // Left without collision on top
            this->IS_FACING = 'Q';
            LastMove = 'q';
        }
        else if (!this->inCollision(mat, x + 1, y + 1) && !this->inCollision(mat, x - 1, y - 1) && LastMove == 'd') {
            this->pos.setX(y + 1); // Down without collision on left
            this->IS_FACING = 'S';
            LastMove = 's';
        }

        else if (!this->inCollision(mat, x + 1, y + 1) && !this->inCollision(mat, x - 1, y - 1)) {
            this->pos.setX(x + 1); // If there isn't collisions, right
            this->IS_FACING = 'D';
            LastMove = 'd';
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
        unsigned x = this->getPosition().getX(), y = this->getPosition().getY();
        std::cout << move << std::endl;

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
    if (slain) return;

    if (IS_FACING == 'Z') {
        this->top.setPosition(this->getCoordinates());
        window << this->top;
    }
    else if (IS_FACING == 'Q') {
        this->left.setPosition(this->getCoordinates());
        window << this->left;
    }
    else if (IS_FACING == 'D') {
        this->right.setPosition(this->getCoordinates());
        window << this->right;
    }
    else if (IS_FACING == 'S') {
        this->bottom.setPosition(this->getCoordinates());
        window << this->bottom;
    }
}
=======
#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>
#include <mingl/shape/circle.h>

#include "type.h"

#include "monster.h"
#include "entity.h"
#include "map.h"

#include <math.h>

using namespace nsGame;

void Monster::update(unsigned delta, CMat & mat, Player player1, Player player2)
{
    //MonsterMoves(mat, player1, player2);
};

void Monster::render(MinGL &window) {
    // juste un affichage pour voir ou est le monstre
    window << nsShape::Circle(this->getCoordinates(), 2, nsGraphics::RGBAcolor(255 / this->behaviourId, 255 / this->behaviourId, 255 / this->behaviourId));
}


void Monster::MonsterMoves(CMat & mat, Player player1, Player player2)
{
    unsigned a = 4;
    unsigned b = 2;

    if (this->behaviourId == 1 || this->behaviourId == 2) //Behaviour 1 : follow outer walls || Behaviour 2 : follow a little wall
    {
        if (mat[this->getPosition().getY()][this->getPosition().getX() - 1] != '0') // MurGauche->bas
        {
            this->getPosition().setY(this->getPosition().getY() - 1);
        }

        if (mat[this->getPosition().getY() - 1][this->getPosition().getX()] != '0') // MurBas->droite
        {
            this->getPosition().setX(this->getPosition().getX() + 1);
        }

        if (mat[this->getPosition().getY()][this->getPosition().getX() + 1] != '0') // MurDroite->haut
        {
            this->getPosition().setY(this->getPosition().getY() + 1);
        }

        if (mat[this->getPosition().getY() + 1][this->getPosition().getX()] != '0') // MurHaut->gauche
        {
            this->getPosition().setX(this->getPosition().getX() - 1);
        }
    }

    else if (this->behaviourId == 3) // Behaviour : flee the player
    {
        //wants to maintain a distance of a between the monster and the player

        while(sqrt(pow((player1.getPosition().getX() - this->getPosition().getX()),2) + pow((player1.getPosition().getY() - this->getPosition().getY()),2)) != a) //formule de calcul de la distance entre monster et player
        {
            this->getPosition().setX(a + player1.getPosition().getX() - this->getPosition().getY() - player1.getPosition().getX());
            this->getPosition().setY(a - this->getPosition().getX() + player1.getPosition().getX() + player1.getPosition().getY());
        }

    }


    else if (this->behaviourId == 4) // Behaviour : follow player
    {
        while(sqrt(pow((player2.getPosition().getX() - this->getPosition().getX()),2) + pow((player2.getPosition().getY() - this->getPosition().getY()),2)) != b) //formule de calcul de la distance entre monster et player
        {
            this->getPosition().setX(b + player2.getPosition().getX() - this->getPosition().getY() + player2.getPosition().getY());
            this->getPosition().setY(b - this->getPosition().getX() + player2.getPosition().getX() + player2.getPosition().getY());
        }

    }
};
>>>>>>> Refonte des classes
