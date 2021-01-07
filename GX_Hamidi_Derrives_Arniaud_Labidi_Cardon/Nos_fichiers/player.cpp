#include "mingl/gui/sprite.h"

class Player {
    public:
        unsigned x = 1, y = 1;
        std::string texture = "../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/tile027.i2s";

        void load() {

        }

        void update() {

        }

        void render(MinGL & window) {
            window << nsGui::Sprite(texture, nsGraphics::Vec2D(x * 32, y * 32));
        }
};
