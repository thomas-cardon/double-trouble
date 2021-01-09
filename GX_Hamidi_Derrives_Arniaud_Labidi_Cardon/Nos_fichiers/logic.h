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
#include "logicManager.h"

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
           void load() {}

           /**
            * @brief Updates logic
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
            * @brief Handles events
            * @fn void event(nsEvent::Event_t event);
            */
           virtual void events(nsEvent::Event_t event) {

           }

           /**
            * @brief This function is called everytime a key is pressed.
            * @fn virtual void onKeyDown(char key);
            */
           virtual void onKeyDown(char key) {

           }

           /**
            * @brief Changes logic
            * @fn void setLogic(int logic);
            */
           void setLogic(int logic) {
               LogicManager::current = logic;
           }

           /**
            * @brief Gets current logic
            * @fn int getLogic();
            */
           int getLogic() {
               return LogicManager::current;
           }
    };
}

#endif // LOGIC_H
