#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H

#include <mingl/mingl.h>

/**
 *
 * \file    logicManager.h
 * \author  Thomas Cardon
 * \date    9 janvier 2020
 * \version 1.0
 * \brief   LogicManager
 *
 **/

namespace nsGame {

    /**
     * @class LogicManager
     * @brief Une classe pour gérer les divers états de jeu
     * @author  Thomas Cardon
     */
    class LogicManager {
        public:
            static int current;

            void load();

            void events(MinGL & window);

            void onKeyDown(char key);

            int update(MinGL & window);
            void render(MinGL & window);
    };
}

#endif // LOGICMANAGER_H
