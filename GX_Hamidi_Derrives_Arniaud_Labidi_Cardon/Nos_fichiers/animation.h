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
            bool isReversing = false;

            nsGraphics::Vec2D _pos;
        public:
            unsigned delay = 642, currentSprite = 0;
            bool reverseAtEnd = true;

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
                    if (currentSprite == sprites.size() - 1) { // LAST SPRITE
                        if (reverseAtEnd && !isReversing) {
                            isReversing = true;
                            std::cout << "is reversing" << std::endl;
                        }
                        else {
                            currentSprite = 0;
                            isReversing = false;
                            std::cout << "is NOT reversing" << std::endl;
                        }
                    }
                    else if (isReversing) currentSprite--;
                    else currentSprite++;

                    std::cout << currentSprite << std::endl;
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

                sprite.setPosition(this->_pos);
                sprite.draw(window);
            }
    };
}


#endif // ANIMATION_H
