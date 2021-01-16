#ifndef FOOD_H
#define FOOD_H

#include <mingl/mingl.h>
#include <mingl/graphics/vec2d.h>

#include "item.h"

namespace nsGame {
    /**
     * @class Item
     * @brief A class defining the different states of the game (In-game, Menus, Loading...)
     * @authors Thomas Cardon, Alexandre Arniaud
     */
    class Food : public Item
    {
        public:
            Food(nsGraphics::Vec2D pos) : Item(pos) {}

            /**
            * @brief This function is used to get the position on the screen/canvas/window, whatever you want to call it
            * @fn virtual nsGraphics::Vec2D getCoordinates();
            */
            nsGraphics::Vec2D getCoordinates() {
                return nsGraphics::Vec2D((this->pos.getX() * 32) + 16, (this->pos.getY() * 32) + 16);
            }

            /**
             * @brief Loads item
             * @fn void load();
             */
            void load() override; // On dirait que sans = 0 à la fin, Qt ne veut pas compiler parce qu'il considère que la fonction n'est pas définie (source: stackoverflow)

            /**
             * @brief Updates item
             * @fn void update(unsigned delta);
             */
            void update(unsigned delta) override;

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window) override;
    };
}

#endif // FOOD_H
