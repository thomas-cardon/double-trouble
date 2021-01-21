/**
 * @file    monster.cpp
 * @authors Ines Hamidi, Thomas Cardon
 * @date    11 janvier 2020
 * @version 1.0
 * @brief   Définition des méthodes de la classe monster.h
 **/

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

    if (this->behaviourId == 1) //Behaviour 1 : Follow outer walls
    {
        unsigned x = this->getPosition().getX(), y = this->getPosition().getY();

        if (!this->inCollision(mat, x + 1, y) && y == 1) {
            this->pos.setX(x + 1);
        }
        else if (!this->inCollision(mat, x, y - 1) && x == 1) {
            this->pos.setY(y - 1);
        }
        else if (!this->inCollision(mat, x - 1, y) && y == mat.size() - 2) {
            this->pos.setX(x - 1);
        }

        else if (!this->inCollision(mat, x, y + 1) && y <= mat.size() - 2) {
            this->pos.setY(y + 1);
        }
    }
    else if (this->behaviourId == 2) //Behaviour 2 : Follow a little wall
    {

    }
    else if (this->behaviourId == 3) // Behaviour : Flee the player
    {

    }
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

void Monster::render(MinGL &window) {
    this->top.setPosition(this->getCoordinates());
    this->top.render(window);
}
