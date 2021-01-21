#ifndef ITEM_H
#define ITEM_H

#include <mingl/mingl.h>
#include "player.h"

/**
 * @file    item.h
 * @author  Thomas Cardon, Alexandre Arniaud
 * @date    8 janvier 2021
 * @version 1.0
 * @brief   Item
 **/

namespace nsGame {
    /**
     * @brief The ItemType enum
     */
    enum ItemType {
        ITEM,
        FOOD,
        FRUIT,
        POWERUP
    };

    /**
     * @class Item
     * @brief Defines the Item
     * @author Thomas Cardon, Alexandre Arniaud
     */
    struct Item {
        protected:
            /** \brief Item coordinates */
            nsGraphics::Vec2D pos;

        public:
            /** \brief Generate an item with its position */
            Item(nsGraphics::Vec2D pos) {
                this->pos = pos;
            }

            /**
            * @brief This function is used to get the position on the screen/canvas/window, whatever you want to call it
            * @fn virtual nsGraphics::Vec2D getCoordinates();
            */
            nsGraphics::Vec2D getCoordinates() {
                return nsGraphics::Vec2D(this->pos.getX() * 32, this->pos.getY() * 32);
            }

            /**
             * @brief Gets the coordinates compared to the map.
             * @fn virtual nsGraphics::Vec2D getPosition();
             */
            nsGraphics::Vec2D getPosition() {
                return pos;
            }

           /**
            * @brief Loads item
            * @fn virtual void load();
            */
           virtual void load() = 0; // On dirait que sans = 0 à la fin, Qt ne veut pas compiler parce qu'il considère que la fonction n'est pas définie (source: stackoverflow)

           /**
            * @brief Updates item
            * @fn virtual int update(unsigned delta);
            */
           virtual void update(unsigned delta) = 0;

           /**
            * @brief Renders resources
            * @fn virtual void render(MinGL & window);
            */
           virtual void render(MinGL & window) = 0;

            /**
            * @brief Makes an action for the player
            * @param Player - The player that steps on an item
            */
           virtual void action(Player *player) = 0;

           /**
            * @brief Gets item type
            * @return ItemType.ITEM
            */
           virtual ItemType getType() {
               return nsGame::ItemType::ITEM;
           };
    };
}

#endif // ITEM_H
