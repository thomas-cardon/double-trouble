#ifndef MAP_H
#define MAP_H

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>

#include "entity.h"
#include "params.h"
#include "type.h"

namespace nsGame {
    class Map
    {
        private:
            CMat Mat;

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

            std::vector<nsGui::Sprite> sprites;
            std::pair <CPosition, CPosition> walls;


        public:
            void load(CMyParam & params);

            void update(int delta);

            void render(MinGL & window);

            unsigned getMinX();

            unsigned getMinY();

            unsigned getWidth();

            unsigned getHeight();

            CMat getMat() {
                return Mat;
            }
    };
}

#endif // MAP_H
