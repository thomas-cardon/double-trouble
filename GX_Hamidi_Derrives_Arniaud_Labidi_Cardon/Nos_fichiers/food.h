#ifndef FOOD_H
#define FOOD_H

#include <mingl/mingl.h>
#include <mingl/graphics/vec2d.h>

namespace nsGame {
    class Food // : Item
    {
        public:
            nsGraphics::Vec2D pos;

            Food(nsGraphics::Vec2D pos) {
                this->pos = pos;
            }

            /**
            * @brief This function is used to get the position on the screen/canvas/window, whatever you want to call it
            * @fn virtual nsGraphics::Vec2D getCoordinates();
            */
            nsGraphics::Vec2D getCoordinates() {
                return nsGraphics::Vec2D((this->pos.getX() * 32) + 16, (this->pos.getY() * 32) + 16);
            }

            /**
             * @brief Gets the coordinates compared to the map.
             * @fn virtual nsGraphics::Vec2D getPosition();
             */
            nsGraphics::Vec2D getPosition() {
                return pos;
            }

            /**
             * @brief Loads food
             * @fn void load();
             */
            void load();

            /**
             * @brief Updates food
             * @fn int update(MinGL & window, unsigned delta);
             */
            void update(unsigned delta);

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window);
    };
}

#endif // FOOD_H
