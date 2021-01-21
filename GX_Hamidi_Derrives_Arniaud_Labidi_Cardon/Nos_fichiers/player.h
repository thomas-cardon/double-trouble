#ifndef PLAYER_H
#define PLAYER_H

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>
#include <mingl/audio/audioengine.h>

#include "entity.h"

#include "animation.h"
#include "type.h"

/**
 * \file    player.h
 * \author  Thomas Cardon, Alexandre Arniaud
 * \date    8 janvier 2020
 * \version 1.0
 * \brief   Player
 */

namespace nsGame {
    /**
     * @class Player
     * @brief Defines the player's class
     * @author Thomas Cardon, Alexandre Arniaud
     */
    class Player : public Entity {
        private:
            /** \brief Direction the player is facing */
            char IS_FACING;

            /** \brief Keystrokes */
            char KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT, KEY_ACTION_1;
        public:
            /** \brief Animations for every direction */
            Animation bottom = Animation(600, true), top = Animation(600, true), left = Animation(600, true), right = Animation(600, true);

            /** \brief Player hearts */
            unsigned hearts = 3;

            /** \brief Player score */
            int score = 0;

            /** \brief Player number */
            unsigned N = 1;

            /** \brief Allows player to move or not */
            bool canMove = true;

            int _noDamage, _noDamageFor;

            Player(unsigned N /* = 2 */);

            /**
             * @brief Returns an entity ID, allows the game to set cooldowns or whatever associated with its ID
             * @return Entity ID
             */
            std::string getEntityId();

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
             * @brief Decrements 1 to hearts, and disable damage for 5 seconds + adds movement speed;
             * @fn void damage();
             */
            void damage();

            /**
             * @brief Teleports the entity at its spawn
             * @fn void spawn();
             */
            void spawn();
    };
}

#endif // PLAYER_H
