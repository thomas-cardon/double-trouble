#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H

#include <mingl/mingl.h>

/**
 *
 * \file    logicManager.h
 * \author  Thomas Cardon
 * \date    9 janvier 2020
 * \version 1.0
 * \brief   StateManager
 *
 **/

namespace nsGame {

    /**
     * @class StateManager
     * @brief The class handling the game states
     * @author  Thomas Cardon
     */
    class StateManager {
        public:
            /* ID de State actuel */
            static int current;

            /**
             * @brief Loads all states
             * @fn void event(nsEvent::Event_t event);
             */
            void load();

            /**
             * @brief Handles minGL 2 mouse events for the current state
             * @fn void event(nsEvent::Event_t event);
             */
            void events(MinGL & window);

            /**
             * @brief Updates the current state
             * @fn int update(MinGL & window, int delta);
             */
            int update(MinGL & window, int delta);

            /**
             * @brief Renders current state resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window);
    };
}

#endif // LOGICMANAGER_H
