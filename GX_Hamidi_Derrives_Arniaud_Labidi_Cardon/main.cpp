/*!
  * \file main.cpp
  * \author Alain Casali Marc Laporte
  * \date 7 janvier 2016
  * \brief Projet de C++ simulant un SpaceInvader
  * \version 1.0
  * \bug Aucun connu
  */

#include <iostream>
#include "Correc_prof/SpaceInvader_AC.h"
#include "Correc_prof/SpaceInvader_ML.h"
using namespace std;

int main()
{
    cout << "Quel jeu lancer? ";
    string Nom;
    cin >> Nom;
    if (Nom == "Alain")
        nsSpaceInvader_AC::ppal("../G6_Berno_Casali_Ernst_Laporte_Palermo/Correc_prof/");
    else if (Nom == "Marc")
        nsSpaceInvaderML::SpaceInvaders ();
    return 0;
}
