#include "mingl/gui/sprite.h"
#include "logic.h"

using namespace nsGame;

class MainMenuLogic : public Logic {
    public:
        nsGui::Sprite background = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/background.i2s", nsGraphics::Vec2D(0, 0));

        void load() {

        }

        int update(MinGL & window) {
            return 0;
        }

        void events(nsEvent::Event_t event) override {
            if (event.eventType == nsEvent::EventType_t::MouseClick) {
                this->setLogic(1);
            }
        }

        void render(MinGL & window) override {
            window << background;
        }
};
