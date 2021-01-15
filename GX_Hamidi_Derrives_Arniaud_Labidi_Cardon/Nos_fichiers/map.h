#ifndef MAP_H
#define MAP_H

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>

#include "params.h"
#include "type.h"

#include "player.h"
#include "item.h"
#include "food.h"

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

            const std::string BLOCK = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile011.i2s";

            const std::string WALL_X_1 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile007.i2s";
            const std::string WALL_X_2 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile008.i2s";
            const std::string WALL_X_3 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile009.i2s";

            const std::string WALL_Y_1 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile006.i2s";
            const std::string WALL_Y_2 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile016.i2s";
            const std::string WALL_Y_3 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile026.i2s";

            const std::string WALL_XY_1 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile003.i2s";
            const std::string WALL_XY_2 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile005.i2s";
            const std::string WALL_XY_3 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile023.i2s";
            const std::string WALL_XY_4 = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile025.i2s";

            /** \brief Preloaded resources */
            std::map<std::string, nsGui::Sprite*> sprites;
        public:
            /** \brief Food */
            std::map<std::pair<int, int> /* x/y coordinates */, Food> food;

            /** \brief Items */
            std::vector<Item> items;

            /**
             * @brief load
             */
            void load();

            /**
             * @brief update
             * @param delta
             * @fn void update(unsigned delta, Player & player1, Player & player2);
             */
            void update(unsigned delta, Player & player1, Player & player2);

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
            CMat getMat() {
                return grid;
            }

            /**
             * @brief Gets a place where there's nothing but a cell
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
