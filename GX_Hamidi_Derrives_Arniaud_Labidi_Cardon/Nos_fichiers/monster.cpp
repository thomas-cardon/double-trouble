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

void Monster::spawn() {
    this->pos.setX(1);
    this->pos.setY(1 * behaviourId);
}

void Monster::load() {
    std::cout << "[Monster behaviourId=" << std::to_string(this->behaviourId) + "] Loading" << std::endl;

    Cooldowns::createCooldown("monster_" + std::to_string(this->behaviourId) + "_move", delay);

    for (int i = 1; i <= 6; i++) {
        this->top.sprites.push_back(nsGui::Sprite(RES_PATH + "/entities/monsters/" + std::to_string(this->behaviourId) + "/" + std::to_string(this->behaviourId) + "-" + std::to_string(i) + ".i2s"));
    }

    this->spawn();
}

// Inspiré de l'algorithme trouvé sur Wikipédia: https://fr.wikipedia.org/wiki/Algorithme_de_parcours_en_largeur
void BreadthFirstSearch(CMat & mat, nsGraphics::Vec2D A) {
    std::vector<nsGraphics::Vec2D> list;
}

void Monster::update(unsigned delta, CMat & mat)
{
    std::cout << "[Monster #" << this->behaviourId << "] Position: x= " << this->getPosition().getY() << ", y= " << this->getPosition().getY() << std::endl;

    if (this->behaviourId == 1 || this->behaviourId == 2) //Behaviour 1 : follow outer walls || Behaviour 2 : follow a little wall
    {
        if (mat[this->getPosition().getY()][this->getPosition().getX() - 1] != '0') // MurGauche->bas
        {
            this->pos.setY(this->getPosition().getY() - 1);
        }

        if (mat[this->getPosition().getY() - 1][this->getPosition().getX()] != '0') // MurBas->droite
        {
            this->pos.setX(this->getPosition().getX() + 1);
        }

        if (mat[this->getPosition().getY()][this->getPosition().getX() + 1] != '0') // MurDroite->haut
        {
            this->pos.setY(this->getPosition().getY() + 1);
        }

        if (mat[this->getPosition().getY() + 1][this->getPosition().getX()] != '0') // MurHaut->gauche
        {
            this->pos.setX(this->getPosition().getX() - 1);
        }
    }
    else if (this->behaviourId == 3) // Behaviour : flee the player
    {

        //randomly moves
        this->pos.setX(this->getPosition().getX() + rand() % 1 - 1);
        this->pos.setY(this->getPosition().getY() + rand() % 1 - 1);
    }
};

void Monster::render(MinGL &window) {
    this->top.setPosition(this->getCoordinates());
    this->top.render(window);
}
