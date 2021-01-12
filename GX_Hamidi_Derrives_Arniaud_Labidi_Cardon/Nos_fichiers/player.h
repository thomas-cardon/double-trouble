#ifndef PLAYER_H
#define PLAYER_H

/**
 *
 * \file    player.h
 * \author  Thomas Cardon
 * \date    8 janvier 2020
 * \version 1.0
 * \brief   Player
 *
 **/

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>

#include "animation.h"
#include "type.h"

namespace nsGame {
    /**
     * @class Player
     * @brief Defines the player's class
     * @author Thomas Cardon
     */
    class Player {
        private:
            int startTime = 0;
            int currentTime = 0;

            char IS_FACING;
            char KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT, KEY_ACTION_1;

            bool canMove = true;

            int _startTimeForDamage, _currentTimeForDamage;

        public:
            CPosition pos;
            Animation bottom = Animation(642, true), top = Animation(642, true), left = Animation(642, true), right = Animation(642, true);

            unsigned hearts = 3;
            double movementSpeed = 1.0;

        private:
            int delay = 125 * movementSpeed;

        public:
            unsigned N = 1;

            Player();
            Player(unsigned N /* = 2 */);

            /**
             * @brief This function is called everytime a key is pressed.
             * @fn void onKeyPress(char key);
             */
            void onKeyPress(char key);

            /**
             * @brief Updates player
             * @fn int update(MinGL & window, int delta, CMat map);
             */
            int update(MinGL & window, int delta, CMat map);

            /**
             * @brief Updates player
             * @fn bool inCollision(CMat map, unsigned x, unsigned y);
             */
            bool inCollision(CMat map, unsigned x, unsigned y);

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window);

            /**
             * @brief Loads player
             * @fn void load(CMyParam params);
             */
            void load(CMyParam params);

            /**
             * @brief Prevents player from being attacked for X milliseconds
             * @fn void noDamage(int ms);
             */
            void noDamage(int ms);

            /**
             * @brief Prevents player from being attacked for X milliseconds
             * @fn bool canTakeDamage(int delta);
             */
            bool canTakeDamage(int delta);

            /**
             * @brief Decrements 1 to hearts, and disable damage for 5 seconds + adds movement speed;
             * @fn void damage();
             */
            void damage();

            /**
             * @brief Sends powerball
             * @fn void powerball();
             */
            void powerball();
            //powerball.setPosition(nsGraphics::Vec2D((this->pos.first + 1) * 32, (this->pos.second) * 32));
    };
}

#endif // PLAYER_H
