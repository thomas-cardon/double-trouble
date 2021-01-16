#ifndef ANIMATION_H
#define ANIMATION_H

#include <mingl/gui/sprite.h>

/**
 * \file    animation.h
 * \author  Thomas Cardon
 * \date    12 janvier 2020
 * \version 1.0
 * \brief   Animation
<<<<<<< HEAD
 *
 **/
=======
 */
>>>>>>> 637e215bdf2af770fb2935d9446fc1ca3c1e3554

namespace nsGame {
    /**
     * @class Animation
     * @brief Defines animations
     * @author Thomas Cardon
     */
    class Animation
    {
        private:
            /** \brief */
            unsigned _currentTime;

            /** \brief */
            bool inReverse = false;
           /**
            * @brief
            *
            */
            nsGraphics::Vec2D _pos;

        public:
            unsigned delay = 500, currentSprite = 0;
            bool alternate = true;

            std::vector<nsGui::Sprite> sprites;

            Animation();
            Animation(nsGraphics::Vec2D pos);
            Animation(unsigned delay, bool alternate); // 642
            Animation(unsigned delay, bool alternate, nsGraphics::Vec2D pos);

            /**
             * @brief Updates animation, changes sprite according to delta and direction
             * @fn void update(unsigned delta);
             */
            void update(unsigned delta);

            /**
             * @brief Sets coordinates on the window
             * @fn void setCoordinates(int x, int y);
             */
            void setCoordinates(int x, int y);

            /**
             * @brief Sets position on the map
             * @fn setPosition(int x, int y);
             */
            void setPosition(int x, int y);

            /**
             * @brief Sets position on the map
             * @fn setPosition(nsGraphics::Vec2D pos);
             */
            void setPosition(nsGraphics::Vec2D pos);

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window);
    };
}


#endif // ANIMATION_H
