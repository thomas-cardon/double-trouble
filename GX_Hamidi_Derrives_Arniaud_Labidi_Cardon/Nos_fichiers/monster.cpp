/**
 * @file    monster.cpp
 * @author  Ines Hamidi
 * @date    11 janvier 2020
 * @version 1.0
 * @brief   Définition des méthodes de la classe monster.h
 **/

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>
#include <mingl/shape/circle.h>

#include "type.h"

#include "monster.h"
#include "entity.h"
#include "map.h"
#include "cooldowns.h"

#include <math.h>
#include <vector>
#include <random>

using namespace nsGame;

void Monster::update(unsigned delta, CMat & mat)
{
    Cooldowns::updateCooldowns(delta);
    MonsterMoves(mat);
};

void Monster::render(MinGL &window) {
    // juste un affichage pour voir ou est le monstre
    window << nsShape::Circle(this->getCoordinates(), 2, nsGraphics::RGBAcolor(255 / this->behaviourId, 255 / this->behaviourId, 255 / this->behaviourId));
}


void Monster::MonsterMoves(CMat & mat)
{
    unsigned a = 4;
    unsigned b = 2;
    std::string Cd1;
    Cooldowns::createCooldown(Cd1, 100);

    std::string Cd2;
    Cooldowns::createCooldown(Cd2, 110);


    if (Cooldowns::isCooldownOver(Cd1) && (this->behaviourId == 1 || this->behaviourId == 2)) //Behaviour 1 : follow outer walls || Behaviour 2 : follow a little wall
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
        //randomly moves

        vector<CMat> DeplacementPossiblesX = [(this->getPosition().getX() + 1), (this->getPosition().getX() - 1)];
        vector<CMat> DeplacementPossiblesY = [(this->getPosition().getX() - 1),), (this->getPosition().getY() - 1), (this->getPosition().getY() + 1)];
        this->getPosition().setX(rand(DeplacementPossiblesX));
        this->getPosition().setY(rand(DeplacementPossiblesY));
    }

};

