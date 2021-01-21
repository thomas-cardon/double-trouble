#ifndef COOKIE_H
#define COOKIE_H

#include <mingl/mingl.h>
#include <mingl/graphics/vec2d.h>

#include "item.h"

/**
 * \file    cookie.h
 * \author  Thomas Cardon
 * \date    10 janvier 2020
 * \version 1.0
 * \brief   Cookie
 */

namespace nsGame {
    /**
     * @class Cookie
     * @brief Defines Food
     * @authors Thomas Cardon
     */
    class Cookie : public Item
    {
        public:
            Cookie(nsGraphics::Vec2D pos) : Item(pos) {}

            /**
            * @brief This function is used to get the position on the screen/canvas/window, whatever you want to call it
            * @fn virtual nsGraphics::Vec2D getCoordinates();
            */
            nsGraphics::Vec2D getCoordinates() {
                return nsGraphics::Vec2D((this->pos.getX() * 32) + 16, (this->pos.getY() * 32) + 16);
            }

            /**
             * @brief Loads food
             * @fn void load();
             */
            void load() override; // On dirait que sans = 0 à la fin, Qt ne veut pas compiler parce qu'il considère que la fonction n'est pas définie (source: stackoverflow)

            /**
             * @brief Updates food
             * @fn void update(unsigned delta);
             */
            void update(unsigned delta) override;

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window) override;

            /**
            * @brief Makes an action for the player
            * @param Player - The player that steps on an item
            */
            void action(Player *player) override;

            /**
             * @brief Gets item type
             * @return ItemType.FOOD
             */
            ItemType getType() override {
                return nsGame::ItemType::FOOD;
            };
    };
}

#endif // COOKIE_H
