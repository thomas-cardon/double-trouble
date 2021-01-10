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

            char KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT;

            bool canMove = true;
        public:
            CPosition pos = CPosition(1, 1);
            nsGui::Sprite texture;

            Player() : texture("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile027.i2s", nsGraphics::Vec2D(32, 32)) {}
            Player(std::string texturePath): texture("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/" + texturePath, nsGraphics::Vec2D(32, 32)) {}

            void load(CMyParam params) {
                std::cout << "[Player] Loading" << std::endl;

                this->KEY_UP = params.MapParamChar["P1_KeyUp"];
                this->KEY_DOWN = params.MapParamChar["P1_KeyDown"];
                this->KEY_LEFT = params.MapParamChar["P1_KeyLeft"];
                this->KEY_RIGHT = params.MapParamChar["P1_KeyRight"];
            }

            void onKeyPress(char key) {
                if (!canMove) return;

                if (key == KEY_UP) this->pos.second -= 1;
                else if (key == KEY_DOWN) this->pos.second += 1;
                else if (key == KEY_RIGHT) this->pos.first += 1;
                else if (key == KEY_LEFT) this->pos.first -= 1;
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

                if (window.isPressed({ KEY_UP, false }))
                    onKeyPress(KEY_UP);
                else if (window.isPressed({ KEY_DOWN, false }))
                    onKeyPress(KEY_DOWN);
                else if (window.isPressed({ KEY_LEFT, false }))
                    onKeyPress(KEY_LEFT);
                else if (window.isPressed({ KEY_RIGHT, false }))
                    onKeyPress(KEY_RIGHT);

                return 0;
            }

            void render(MinGL & window) {
                window << texture;
            }
    };
}
