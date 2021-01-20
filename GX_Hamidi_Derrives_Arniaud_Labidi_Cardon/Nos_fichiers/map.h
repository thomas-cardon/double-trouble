#ifndef MAP_H
#define MAP_H

#include "definitions.h"

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>

#include "params.h"
#include "type.h"

#include "monster.h"
#include "player.h"

#include "item.h"

/**
 * @file    map.h
 * @author  Thomas Cardon
 * @date    8 janvier 2020
 * @version 1.0
 * @brief   Map
 **/

namespace nsGame {
    /**
     * @class Map
     * @brief Defines the game grid, its textures, file loading, coordinates, positions
     * @author Thomas Cardon
     */
    class Map
    {
        private:
            /** \brief Game grid */
            CMat grid;

            const std::string WALL_X_1 = RES_PATH + "/tiles/wall-x-1.i2s";
            const std::string WALL_X_2 = RES_PATH + "/tiles/wall-x-2.i2s";
            const std::string WALL_X_3 = RES_PATH + "/tiles/wall-x-3.i2s";

            const std::string WALL_Y_1 = RES_PATH + "/tiles/wall-y-1.i2s";
            const std::string WALL_Y_2 = RES_PATH + "/tiles/wall-y-2.i2s";
            const std::string WALL_Y_3 = RES_PATH + "/tiles/wall-y-3.i2s";

            const std::string CORNER_1 = RES_PATH + "/tiles/corner-1.i2s";
            const std::string CORNER_2 = RES_PATH + "/tiles/corner-2.i2s";
            const std::string CORNER_3 = RES_PATH + "/tiles/corner-3.i2s";
            const std::string CORNER_4 = RES_PATH + "/tiles/corner-4.i2s";

            const std::string T_WALL_1 = RES_PATH + "/tiles/t-wall-1.i2s";
            const std::string T_WALL_2 = RES_PATH + "/tiles/t-wall-2.i2s";

            /** \brief Preloaded resources */
            std::map<char, nsGui::Sprite*> sprites;
        public:
            /** \brief Items ( + food) */
            std::map<std::pair<int, int> /* x/y coordinates */, Item*> items;

            /** \brief Monsters */
            std::vector<Monster*> monsters;

            /** \brief Items to spawn */
            unsigned itemsLeft = 8;

            /**
             * @brief load
             */
            void load();

            /**
             * @brief update
             * @param delta
             * @fn void update(unsigned delta, Player *p1, Player *p2);
             */
            void update(unsigned delta, Player *p1, Player *p2);

            /**
             * @brief Renders the layer of the map, with its cells (walls, etc.)
             * @param window
             */
            void render(MinGL & window);

            /**
             * @brief Gets the minimal X coordinates (it should be 0 but who knows)
             */
            unsigned getMinX();

            /**
             * @brief Gets the minimal Y coordinates (it should be 0 but who knows)
             */
            unsigned getMinY();

            /**
             * @brief Gets the map width
             */
            unsigned getWidth();

            /**
             * @brief Gets the map height
             */
            unsigned getHeight();

            /**
             * @brief getMat
             * @return CMat grid
             */
            CMat & getMat() {
                return grid;
            }

            /**
             * @brief Adds an item to the item list with given coordinates
             * @return Item*
             */
            void spawnItem(Item* item);

            /**
             * @brief Gets a place where there's just a cell (there may be a player)
             * @return nsGraphics::Vec2D
             */
            nsGraphics::Vec2D getEmptyPosition();

            /**
             * @brief Gets a list of positions where there's nothing but a cell
             * @return std::vector<nsGraphics::Vec2D>
             */
            std::vector<nsGraphics::Vec2D> getEmptyPositions();
    };
}

#endif // MAP_H
