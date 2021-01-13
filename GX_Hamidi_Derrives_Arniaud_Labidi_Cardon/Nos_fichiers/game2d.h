#ifndef GAME_2D_H
#define GAME_2D_H

#define FPS_LIMIT 60
#include <mingl/mingl.h>

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
