#ifndef ANIMATION_H
#define ANIMATION_H

/**
 *
 * \file    animation.h
 * \author  Thomas Cardon
 * \date    12 janvier 2020
 * \version 1.0
 * \brief   Animation
 *
 **/
#include <mingl/gui/sprite.h>

namespace nsGame {
    /**
     * @class Animation
     * @brief Defines animations
     * @author Thomas Cardon
     */
    class Animation
    {
        private:
            unsigned _currentTime;
            nsGraphics::Vec2D _pos;
        public:
            unsigned delay = 200, currentSprite = 0;

            std::vector<nsGui::Sprite> sprites;

            Animation() {}

            Animation(nsGraphics::Vec2D pos) {
                this->_pos = pos;
            }

            /**
             * @brief Updates animation, changes sprite according to delta
             * @fn void update(unsigned delta);
             */
            void update(unsigned delta) {
                _currentTime += delta;

                if (_currentTime >= delay) {
                    if (currentSprite == sprites.size()) {
                        currentSprite = 0;
                    }
                }
            }

            /**
             * @brief Sets coordinates on the window
             * @fn void setCoordinates(int x, int y);
             */
            void setCoordinates(int x, int y) {
                this->_pos.setX(x);
                this->_pos.setY(y);
            }

            /**
             * @brief Sets position on the map
             * @fn setPosition(int x, int y);
             */
            void setPosition(int x, int y) {
                this->_pos.setX(x * 32); // CELL_SIZE
                this->_pos.setY(y * 32); // CELL_SIZE
            }

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window) {
                nsGui::Sprite sprite = sprites.at(currentSprite);
                std::cout << "[Animations] Getting pos at x: " << sprite.getPosition().getX() << ", y:" << sprite.getPosition().getY() << std::endl;

                sprite.setPosition(this->_pos);
                std::cout << "[Animations] Getting pos at x: " << sprite.getPosition().getX() << ", y:" << sprite.getPosition().getY() << std::endl;

                sprite.draw(window);
            }
    };
}


#endif // ANIMATION_H
