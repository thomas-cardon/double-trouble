#ifndef LOGIC_H
#define LOGIC_H

/**
 *
 * @file    logic.h
 * @author  Thomas Cardon
 * @date    8 janvier 2020
 * @version 1.0
 * @brief   Logic
 *
 **/

#include <mingl/mingl.h>

namespace nsGame {
    /**
     * @class Logic
     * @brief Une classe pour différencier les divers états de jeu (dans les menu, en partie, etc.)
     */
    class Logic {
        public:

            void load();

            int update();

            void render(MinGL & window);
    };
}

#endif // LOGIC_H
