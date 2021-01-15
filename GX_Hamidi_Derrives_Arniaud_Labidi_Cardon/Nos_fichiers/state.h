#ifndef STATE_H
#define STATE_H

/**
 * @file    state.h
 * @author  Thomas Cardon
 * @date    8 janvier 2020
 * @version 1.0
 * @brief   State
 **/

#include <mingl/mingl.h>

namespace nsGame {
    /**
     * @class State
     * @brief A class defining the different states of the game (In-game, Menus, Loading...)
     * @author Thomas Cardon
     */
    struct State {
        public:

           /**
            * @brief Loads State resources
            * @fn void load();
            */
           void load() {}

           /**
            * @brief Updates state
            * @fn int update(MinGL & window, unsigned delta);
            */
           void update(MinGL & window, unsigned delta);

           /**
            * @brief Renders resources
            * @fn void render(MinGL & window);
            */
            void render(MinGL & window) {
               window.setBackgroundColor(nsGraphics::RGBAcolor(0, 255));
           }

           /**
            * @brief Handles minGL 2 mouse events
            * @fn void events(nsEvent::Event_t event);
            */
           void events(nsEvent::Event_t event);

           /**
            * @brief Changes logic
            * @fn void setState(int logic);
            */
           void setState(int logic);

           /**
            * @brief Gets current logic
            * @fn int getState();
            */
           int getState();
    };
}

#endif // STATE_H
