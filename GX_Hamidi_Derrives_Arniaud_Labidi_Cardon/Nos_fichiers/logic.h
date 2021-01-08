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
     * @author Thomas Cardon
     */
    class Logic {
        public:

        /**
         * @brief Loads Logic resources
         * @fn void load();
         */
         void load();

         /**
          * @brief Updates logic
          * @fn int update();
          */
         int update();

         /**
          * @brief Renders resources
          * @fn void render(MinGL & window);
          */
         void render(MinGL & window);
    };
}

#endif // LOGIC_H
