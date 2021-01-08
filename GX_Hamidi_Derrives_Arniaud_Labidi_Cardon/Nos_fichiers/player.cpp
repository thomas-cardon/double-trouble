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
            std::string texture;

            Player(std::string texture) {
                this->texture = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/" + texture;
            }

            void load() {
                pos.first = 0;
                pos.second = 0;
            }

            int update(MinGL & window) {
                return 0;
            }

            void render(MinGL & window) {
                window << nsGui::Sprite(texture, nsGraphics::Vec2D(this->pos.first * 32, this->pos.second * 32));
            }
    };
}
