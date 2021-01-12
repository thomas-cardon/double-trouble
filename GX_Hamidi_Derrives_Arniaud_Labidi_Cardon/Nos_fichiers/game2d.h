#ifndef GAME_2D_H
#define GAME_2D_H

#define FPS_LIMIT 60
#include <mingl/mingl.h>

/**
 * @brief update
 * @param window
 * @param delta
 * @return
 */
int update(MinGL & window, int delta);

/**
 * @brief render
 * @param window
 */
void render(MinGL & window);

/**
 * @brief load
 * @return
 */
int load();

#endif
