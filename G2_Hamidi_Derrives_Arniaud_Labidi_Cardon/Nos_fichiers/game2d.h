#ifndef GAME_2D_H
#define GAME_2D_H

#include "definitions.h"
#include <mingl/mingl.h>

/**
 * \file    game2d.h
 * \author  Thomas Cardon
 * \date    10 janvier 2021
 * \version 1.0
 * \brief   Main rendering functions
 */

/**
 * @brief Updates all sub components every tick
 * @fn void update(MinGL & window, unsigned delta);
 */
void update(MinGL & window, unsigned delta);

/**
 * @brief Renders every component
 * @fn void render(MinGL & window);
 */
void render(MinGL & window);

/**
 * @brief Loads the game
 * @return 0 if game has closed correctly
 */
int load();

#endif
