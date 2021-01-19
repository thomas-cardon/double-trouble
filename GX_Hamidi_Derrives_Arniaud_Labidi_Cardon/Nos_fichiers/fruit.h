#ifndef FRUIT_H
#define FRUIT_H

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>
#include <mingl/graphics/vec2d.h>

#include "item.h"

/**
 * \file    fruit.h
 * \author  Thomas Cardon
 * \date    17 janvier 2020
 * \version 1.0
 * \brief   Fruit
 */

namespace nsGame {
    /**
     * @class Fruit
     * @brief Defines Fruit
     * @authors Thomas Cardon
     */
    class Fruit : public Item
    {
        private:
            nsGui::Sprite sprite;

        public:
            Fruit(nsGraphics::Vec2D pos) : Item(pos), sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/items/fruit_" + std::to_string(rand() % 4) + ".i2s") {}

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
            void action(Player & player) override;

            /**
             * @brief Gets item type
             * @return ItemType.ITEM
             */
            ItemType getType() override {
                return nsGame::ItemType::FRUIT;
            };
    };
}

#endif // FRUIT_H
