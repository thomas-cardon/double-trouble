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
