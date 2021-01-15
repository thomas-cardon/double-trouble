#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <mingl/mingl.h>
#include "state.h"

/**
 *
 * \file    stateManager.h
 * \author  Thomas Cardon
 * \date    9 janvier 2020
 * \version 1.0
 * \brief   StateManager handles the different game states (Menu, Credits, Game...)
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
            /** \brief States */
            std::map<int, State*> states;

            /* ID de State actuel */
            static int current;

            /**
             * @brief Loads all states
             * @fn void load();
             */
            void load();

            /**
             * @brief Handles minGL 2 mouse events for the current state
             * @fn void event(MinGL & window);
             */
            void events(MinGL & window);

            /**
             * @brief Updates the current state
             * @fn void update(MinGL & window, unsigned delta);
             */
            void update(MinGL & window, unsigned delta);

            /**
             * @brief Renders current state resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window);
    };
}

#endif // STATEMANAGER_H
