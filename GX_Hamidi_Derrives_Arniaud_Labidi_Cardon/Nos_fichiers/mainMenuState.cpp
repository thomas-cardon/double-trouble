#include "mingl/gui/sprite.h"
#include "state.h"

using namespace nsGame;

class MainMenuState : public State {
    public:
        nsGui::Sprite background = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/background.i2s", nsGraphics::Vec2D(0, 0));

        nsGui::Sprite btn_play = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_play.i2s", nsGraphics::Vec2D(0, 0));
        nsGui::Sprite btn_quit = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_quit.i2s", nsGraphics::Vec2D(0, 0));
        nsGui::Sprite btn_options = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_options.i2s", nsGraphics::Vec2D(0, 0));
        nsGui::Sprite btn_play_hover = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_play_hover.i2s", nsGraphics::Vec2D(0, 0));
        nsGui::Sprite btn_quit_hover = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_quit_hover.i2s", nsGraphics::Vec2D(0, 0));
        nsGui::Sprite btn_options_hover = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_options_hover.i2s", nsGraphics::Vec2D(0, 0));

        void load() {

        }

        int update(MinGL & window) {
            this->setState(1);

            return 0;
        }

        void events(nsEvent::Event_t event) override {
        }

        void render(MinGL & window) override {
            window << background;
            window << btn_play;
            window << btn_quit;
            window << btn_options;
        }
};
