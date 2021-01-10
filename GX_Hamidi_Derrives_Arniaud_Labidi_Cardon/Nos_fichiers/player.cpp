/**
 *
 * @file    player.h
 * @author  Thomas Cardon
 * @date    8 janvier 2020
 * @version 1.0
 * @brief   Player
 *
 **/

#define CELL_SIZE 32

#include <time.h>

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
        private:
            int startTime = 0;
            int currentTime = 0;
            int delay = 5;

            bool canMove = true;
        public:
            CPosition pos = CPosition(1, 1);
            nsGui::Sprite texture;

            Player() : texture("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile027.i2s", nsGraphics::Vec2D(32, 32)) {}
            Player(std::string texturePath): texture("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/" + texturePath, nsGraphics::Vec2D(32, 32)) {}

            void load() {}

            void onKeyDown(char key) {
                std::cout << "key down" << std::endl;

                if (!canMove) return;

                if (key == 's') this->pos.second += 1;
                else if (key == 'z') this->pos.second -= 1;
                else if (key == 'd') this->pos.first += 1;
                else if (key == 'q') this->pos.first -= 1;
                else return;

                canMove = false;
                texture.setPosition(nsGraphics::Vec2D(this->pos.first * CELL_SIZE, this->pos.second * CELL_SIZE));
            }

            int update(MinGL & window) {
                /*
                 * Movement cooldowns
                 */
                currentTime++;

                if (!canMove && currentTime - startTime > delay) {
                    canMove = true;
                    currentTime = 0;
                }

                if (window.isPressed({ 'z', false }))
                    onKeyDown('z');
                else if (window.isPressed({ 's', false }))
                    onKeyDown('s');
                else if (window.isPressed({ 'q', false }))
                    onKeyDown('q');
                else if (window.isPressed({ 'd', false }))
                    onKeyDown('d');

                return 0;
            }

            void render(MinGL & window) {
                window << texture;
            }
    };
}
