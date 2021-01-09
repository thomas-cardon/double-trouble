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
     * @authors Thomas Cardon
     */
    class Player {
        public:
            CPosition pos;

            std::string texturePath = "tile027.i2s";
            nsGui::Sprite texture = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/" + texturePath, nsGraphics::Vec2D(32, 32));

            Player() {}

            Player(std::string texture) {
                this->texturePath = texture;
                this->texture = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/" + texturePath, nsGraphics::Vec2D(32, 32));
            }

            void load() {
                pos.first = 1;
                pos.second = 1;

            }

            void onKeyDown(char key) {
                std::cout << "key down" << std::endl;

                if (key == 's') this->pos.second += 1;
                else if (key == 'z') this->pos.second -= 1;
                else if (key == 'd') this->pos.first += 1;
                else if (key == 'q') this->pos.first -= 1;
                else return;

                texture = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/" + texturePath, nsGraphics::Vec2D(this->pos.first * 32, this->pos.second * 32));

            }

            int update() {
                std::cout << this->pos.first << " : " << this->pos.second << std::endl;

                return 0;
            }

            void render(MinGL & window) {
                window << texture;
            }
    };
}
