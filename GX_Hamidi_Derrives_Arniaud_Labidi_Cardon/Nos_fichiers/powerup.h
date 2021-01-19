#ifndef FRUIT_H
#define FRUIT_H

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>
#include <mingl/graphics/vec2d.h>

#include "item.h"

/**
 * \file    powerup.h
 * \author  Thomas Cardon
 * \date    19 janvier 2020
 * \version 1.0
 * \brief   Powerup
 */

namespace nsGame {
    /**
     * @class Powerup
     * @brief Defines Powerup - allows Pacman to eat monsters and players without getting killed
     * @authors Thomas Cardon
     */
    class Powerup : public Item
    {

        public:
            Powerup(nsGraphics::Vec2D pos) : Item(pos) {}

            /**
             * @brief Loads food
             * @fn void load();
             */
            void load() override;

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
            void action(Player & player) override;

            /**
             * @brief Gets item type
             * @return ItemType.ITEM
             */
            ItemType getType() override {
                return nsGame::ItemType::POWERUP;
            };
    };
}

#endif // FRUIT_H
