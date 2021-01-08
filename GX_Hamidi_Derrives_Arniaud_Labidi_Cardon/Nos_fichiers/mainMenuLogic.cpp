#include "logic.h"
#include "mingl/gui/sprite.h"

using namespace nsGame;

class MainMenuLogic : public Logic {
    public:
    void load() {

    }

    int update() {
        return 0;
    }

    void render(MinGL & window) {
        window << nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/background.i2s", nsGraphics::Vec2D(0, 0));
    }

};
