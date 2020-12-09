#pragma once
/*!
  * \file MyType_AC.h
  * \author Alain Casali Marc Laporte
  * \date 7 janvier 2016
  * \brief Fichier décrivant l'ensemble des alias vers les types utilisés dans le jeu
  * \version 1.0
  * \bug Aucun connu
  */
  
#include <vector>

namespace nsSpaceInvaderML
{
/*!
  * \typedef CVString
  * \brief   Alias vers le type de l'écran (l'espace, la matrice).
  */
 typedef std::vector <std::string> CVString;
 /**
  * @brief Alias vers le type des indices d'un CVString
  */
 typedef CVString::size_type Size_t;

}
