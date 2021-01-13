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

#include "entity.cpp"

#include "animation.h"
#include "type.h"

namespace nsGame {
    /**
     * @class Player
     * @brief Defines the player's class
     * @author Thomas Cardon
     */
    class Player : public Entity {
        private:
            char IS_FACING;
            char KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT, KEY_ACTION_1;

            bool canMove = true;
            int delay = 125 * movementSpeed;
        public:
            Animation bottom = Animation(642, true), top = Animation(642, true), left = Animation(642, true), right = Animation(642, true);

            int score = 0;

            unsigned N = 1;

            Player(unsigned N /* = 2 */);

            /**
             * @brief This function is called everytime a key is pressed.
             * @fn void onKeyPress(char key);
             */
            void onKeyPress(char key);

            /**
             * @brief Updates player
             * @fn void update(MinGL & window, unsigned delta, CMat map);
             */
            void update(MinGL & window, unsigned delta, CMat map);

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
             * @fn bool canTakeDamage();
             */
            bool canTakeDamage();

            /**
             * @brief Decrements 1 to hearts, and disable damage for 5 seconds + adds movement speed;
             * @fn void damage();
             */
            void damage();

            /**
             * @brief Teleports the entity at its spawn
             */
            void spawn(CMyParam params) override;

            /**
             * @brief Sets the movement speed
             * @fn void setMovementSpeed(double speed);
             */
            void setMovementSpeed(double speed) override;
    };
}

#endif // PLAYER_H
