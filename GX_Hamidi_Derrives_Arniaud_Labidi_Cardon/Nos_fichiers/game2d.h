
#ifndef GAME_2D_H
#define GAME_2D_H

/*!
 * \file game2d.h
 * \brief Version 2D de game.h
 * \author Thomas Cardon
 * \version 1.0
 * \date 7 janvier 2018
 */

#include "./type.h"


/*!
 * \brief Moves the current token according to the character in the 2nd parameter
 * \param[in, out] Mat the matrix before and after the move
 * \param[in] Move the key pressed by the user
 * \param[in, out] Pos the player's position before and after the move
 */

void MoveToken (CMat & Mat, const char & Move, CPosition & Pos);

/**
 * @brief Loads the engine and the game
 * @return 0 if everything is OK
 * @fn int ppal ();
 */
int load ();
#endif // GAME_H
