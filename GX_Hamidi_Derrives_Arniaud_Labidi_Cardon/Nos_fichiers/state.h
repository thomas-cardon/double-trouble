#ifndef LOGIC_H
#define LOGIC_H

/**
 *
 * @file    logic.h
 * @author  Thomas Cardon
 * @date    8 janvier 2020
 * @version 1.0
 * @brief   State
 *
 **/

#include <mingl/mingl.h>
#include "stateManager.h"

namespace nsGame {
    /**
     * @class State
     * @brief A class defining the different states of the game (In-game, Menus, Loading...)
     * @author Thomas Cardon
     */
    class State {
        public:

           /**
            * @brief Loads State resources
            * @fn void load();
            */
           void load() {}

           /**
            * @brief Updates state
            * @fn int update();
            */
           int update(MinGL & window) { return 0; }

           /**
            * @brief Renders resources
            * @fn void render(MinGL & window);
            */
           virtual void render(MinGL & window) {
               window.setBackgroundColor(nsGraphics::RGBAcolor(0, 255));
           }

           /**
            * @brief Handles minGL 2 mouse events
            * @fn void event(nsEvent::Event_t event);
            */
           virtual void events(nsEvent::Event_t event) {

           }

           /**
            * @brief Changes logic
            * @fn void setState(int logic);
            */
           void setState(int logic) {
               StateManager::current = logic;
           }

           /**
            * @brief Gets current logic
            * @fn int getState();
            */
           int getState() {
               return StateManager::current;
           }
    };
}

#endif // LOGIC_H
