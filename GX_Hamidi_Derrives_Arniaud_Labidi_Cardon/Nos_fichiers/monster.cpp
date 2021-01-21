/**
 * @file    monster.cpp
<<<<<<< main
<<<<<<< main
 * @authors Ines Hamidi, Thomas Cardon, Alexandre Arniaud
=======
 * @author  Ines Hamidi
>>>>>>> Refonte des classes
=======
 * @authors Ines Hamidi, Thomas Cardon
>>>>>>> Monster -> flees player ébauche
 * @date    11 janvier 2020
 * @version 1.0
 * @brief   Définition des méthodes de la classe monster.h
 **/

<<<<<<< main
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

<<<<<<< main
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

=======
>>>>>>> Monster -> flees player ébauche
#include "type.h"

#include "monster.h"
#include "cooldowns.h"

#include "definitions.h"

using namespace nsGame;

Monster::Monster(unsigned behaviourId) {
    this->behaviourId = behaviourId;
}

std::string Monster::getEntityId() {
    return "Monster" + std::to_string(this->behaviourId);
}

void Monster::spawn() {
    this->pos.setX(1);
    this->pos.setY(1 * behaviourId);
}

void goTo(nsGraphics::Vec2D newPos) {

}

void Monster::load() {
    std::cout << "[Monster#" << getEntityId() + "] Loading" << std::endl;

    this->movementSpeed = 0.35;
    Cooldowns::createCooldown(getEntityId() + "_move", this->_getDelay());

    for (int i = 1; i <= 6; i++) {
        this->top.sprites.push_back(nsGui::Sprite(RES_PATH + "/entities/monsters/" + std::to_string(this->behaviourId) + "/" + std::to_string(this->behaviourId) + "-" + std::to_string(i) + ".i2s"));
    }

    this->spawn();
    goTo(nsGraphics::Vec2D(15, 15));
}

// Inspiré de l'algorithme trouvé sur Wikipédia: https://fr.wikipedia.org/wiki/Algorithme_de_parcours_en_largeur
void BreadthFirstSearch(CMat & mat, nsGraphics::Vec2D A) {
    std::vector<nsGraphics::Vec2D> list;
}

void Monster::update(unsigned delta, CMat & mat)
{
    canMove = Cooldowns::isCooldownOver(getEntityId() + "_move");
    if (!canMove) return;

    std::cout << "[Monster#" << getEntityId() + "] Position: x= " << this->getPosition().getY() << ", y= " << this->getPosition().getY() << std::endl;

    if (this->behaviourId == 1) //Behaviour 1 : follow outer walls
    {
        unsigned x = this->getPosition().getX(), y = this->getPosition().getY();

        if ((x + 1 <= mat[y].size() - 1) && !this->inCollision(mat, x + 1, y)) {
            this->pos.setX(x + 1);
        }
        else if ((x - 1 >= 0) && !this->inCollision(mat, x - 1, y)) {
            this->pos.setX(x - 1);
        }
        else if ((y + 1 <= mat.size() - 1) && !this->inCollision(mat, x, y + 1)) {
            this->pos.setY(y + 1);
        }
        else if ((y - 1 >= 0) && !this->inCollision(mat, x, y - 1)) {
            this->pos.setY(y - 1);
        }
    }
    else if (this->behaviourId == 2) {

    }

    else if (this->behaviourId == 3) // Behaviour : if player close : flees to back right, else, move in random circle
    {
        unsigned x = this->getPosition().getX(), y = this->getPosition().getY();

=======

<<<<<<< HEAD

<<<<<<< main
<<<<<<< main
    else if (this->behaviourId == 3) // Behaviour : if player close : flees to back right, else, move in random circle
{
    unsigned x = this->getPosition().getX(), y = this->getPosition().getY();
>>>>>>> monster flee

    if (p1)
=======
    else if (this->behaviourId == 3) // Behaviour : move in random circle
{
    unsigned x = this->getPosition().getX(), y = this->getPosition().getY();

>>>>>>> flee
    //random circles
    bool circleID = rand() % 1;

    if (circleID == 1) //circle to the left
    {
        if ((x + 1 <= mat[y].size() - 1) && !this->inCollision(mat, x + 1, y))
        {
            this->pos.setX(x + 1);
        };

        else if ((y + 1 <= mat.size() - 1) && !this->inCollision(mat, x, y + 1))
        {
            this->pos.setY(y + 1);
        };

        else if ((x - 1 >= 0) && !this->inCollision(mat, x - 1, y))
        {
            this->pos.setX(x - 1);
        };
<<<<<<< main

        else if ((y - 1 >= 0) && !this->inCollision(mat, x, y - 1))
        {
             this->pos.setY(y - 1);
        };
    }//fi
=======

        else if ((y - 1 >= 0) && !this->inCollision(mat, x, y - 1))
        {
             this->pos.setY(y - 1);
        };
    }//fi

    else
    {

        if ((x - 1 >= 0) && !this->inCollision(mat, x - 1, y))
        {
            this->pos.setX(x - 1);
        }

        else if ((y - 1 >= 0) && !this->inCollision(mat, x, y - 1))
        {
            this->pos.setY(y - 1);
        }

        else if ((x + 1 <= mat[y].size() - 1) && !this->inCollision(mat, x + 1, y))
        {
            this->pos.setX(x + 1);
        }

        else if ((y + 1 <= mat.size() - 1) && !this->inCollision(mat, x, y + 1))
        {
            this->pos.setY(y + 1);
        }
    }
}//end of behaviour 3
>>>>>>> flee

    else
    {
=======
>>>>>>> Auto stash before rebase of "main"


<<<<<<< main

=======
>>>>>>> main
>>>>>>> monster flee
    else if (false) { // this->behaviourId == 4) { // Behaviour 4 => Random
        int move = rand() % 4 + 1;
        unsigned x = this->getPosition().getX(), y = this->getPosition().getY();
        std::cout << move << std::endl;

        if (move == 0 && (x + 1 <= mat[y].size() - 1) && !this->inCollision(mat, x + 1, y)) {
            this->pos.setX(x + 1);
        }
        else if (move == 1 && (x - 1 >= 0) && !this->inCollision(mat, x - 1, y)) {
            this->pos.setX(x - 1);
        }
        else if (move == 2 && (y + 1 <= mat.size() - 1) && !this->inCollision(mat, x, y + 1)) {
            this->pos.setY(y + 1);
        }
        else if ((y - 1 >= 0) && !this->inCollision(mat, x, y - 1)) {
            this->pos.setY(y - 1);
        }
    }
};
<<<<<<< main
>>>>>>> Refonte des classes
=======

<<<<<<< main
>>>>>>> random moves
=======
void Monster::render(MinGL &window) {
    this->top.setPosition(this->getCoordinates());
    this->top.render(window);
}
>>>>>>> Monster -> flees player ébauche
