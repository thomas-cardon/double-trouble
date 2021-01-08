/**
 *
 * @file    player.h
 * @author  Thomas Cardon
 * @date    8 janvier 2020
 * @version 1.0
 * @brief   Player
 *
 **/

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>

#include "type.h"

namespace nsGame {
    /**
     * @class Logic
     * @brief Une classe pour différencier les divers états de jeu (dans les menu, en partie, etc.)
     */
    class Player {
        public:
            CPosition pos;
            std::string texture = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile027.i2s";

            void load() {
                pos.first = 1;
                pos.second = 1;
            }

            int update(MinGL & window) {
                if (window.isPressed({ 'Z', false }))
                    this->pos.first += 1;

                if (window.isPressed({ 'S', false }))
                    this->pos.first -= 1;

                if (window.isPressed({ 'Q', false }))
                    this->pos.second += 1;

                if (window.isPressed({ 'D', false }))
                    this->pos.second += 1;

                return 0;
            }

            void render(MinGL & window) {
                window << nsGui::Sprite(texture, nsGraphics::Vec2D(this->pos.first * 32, this->pos.second * 32));
            }
    };
}
