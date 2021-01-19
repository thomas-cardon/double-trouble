#ifndef LOGIC_H
#define LOGIC_H

#include <mingl/mingl.h>
#include "stateManager.h"

/**
 *
 * @file    state.h
 * @author  Thomas Cardon
 * @date    8 janvier 2020
 * @version 1.0
 * @brief   State
 *
 **/

namespace nsGame {
    /**
     * @class State
     * @brief A class defining the different states of the game (In-game, Menus, Loading...)
     * @author Thomas Cardon
     */
    struct State {
        public:
            /** \brief */
            bool hasLoaded = false;

           /**
            * @brief Loads State resources
            * @fn virtual void load();
            */
           virtual void load() {
                hasLoaded = true;
            }

           /**
            * @brief Destroys state (and resets it)
            * @fn virtual void destroy();
            */
           virtual void destroy() {}

           /**
            * @brief Updates state
            * @fn virtual int update(MinGL & window, unsigned delta);
            */
           virtual void update(MinGL & window, unsigned delta) {}

           /**
            * @brief Renders resources
            * @fn virtual void render(MinGL & window);
            */
           virtual void render(MinGL & window) {
               window.setBackgroundColor(nsGraphics::RGBAcolor(0, 255));
           }

           /**
            * @brief Handles minGL 2 mouse events
            * @fn virtual void events(nsEvent::Event_t event);
            */
           virtual void events(nsEvent::Event_t event) {}

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
