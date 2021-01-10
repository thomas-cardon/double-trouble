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
            int delay = 5;

            char KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT;

            bool canMove = true;

        public:
            CPosition pos = CPosition(1, 1);
            nsGui::Sprite sprite;

            int N = 1;

            Player() : sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/entities/player1/bottom-1.i2s", nsGraphics::Vec2D(32, 32)) {}

            Player(int N /* = 2*/) : sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/entities/player" + std::to_string(N) + "/bottom-1.i2s", nsGraphics::Vec2D(640 - 64, 640 - 64)) {
                this->N = N;
            }

            /**
             * @brief This function is called everytime a key is pressed.
             * @fn void onKeyPress(char key);
             */
            void onKeyPress(char key);

            /**
             * @brief Updates player
             * @fn int update(MinGL & window, CMat map);
             */
            int update(MinGL & window, CMat map);

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
    };
}

#endif // PLAYER_H
