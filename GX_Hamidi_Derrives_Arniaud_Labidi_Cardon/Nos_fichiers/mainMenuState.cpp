#include "mingl/gui/sprite.h"
#include "state.h"

#include <chrono>
#include <thread>

using namespace nsGame;

class MainMenuState : public State {
    public:
        nsGui::Sprite background = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/background.i2s", nsGraphics::Vec2D(0, 0));

        nsGui::Sprite btn_play = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_play.i2s", nsGraphics::Vec2D(278, 432));
        nsGui::Sprite btn_quit = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_quit.i2s", nsGraphics::Vec2D(262, 530));
        nsGui::Sprite btn_options = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_options.i2s", nsGraphics::Vec2D(264, 482));
        nsGui::Sprite btn_play_hover = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_play_hover.i2s", nsGraphics::Vec2D(271, 429));
        nsGui::Sprite btn_quit_hover = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_quit_hover.i2s", nsGraphics::Vec2D(252, 529));
        nsGui::Sprite btn_options_hover = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_options_hover.i2s", nsGraphics::Vec2D(254, 478));

        int startTime = 0;
        int currentTime = 0;
        int delay = 500;

        bool canMove = true;

        int hovering = 0;

        void load() override {

        }

        int update(MinGL & window, int delta) override {
            currentTime += delta;

            if (window.isPressed({ 'a', false })) {
                if (hovering == 0) this->setState(1);
                else if (hovering == 1) {
                    window.stopGaphic();
                    return 0;
                }
            }

            /*
             * Cooldowns de déplacement des boutons
             */

            if (!canMove && currentTime - startTime > delay) {
                canMove = true;
                currentTime = 0;
            }

            if (!canMove) return 0;

            if (window.isPressed({ 'z', false })) { // UP
                if (hovering == 2) hovering = 0;
                else hovering += 1;

                canMove = false;
            }
            else if (window.isPressed({ 's', false })) { // DOWN
                if (hovering == 0) hovering = 2;
                else hovering -= 1;

                canMove = false;
            }

            return 0;
        }

        void events(nsEvent::Event_t event) override {
            std::cout << "event" << std::endl;
            if (event.eventType == nsEvent::EventType_t::MouseMove) {
                std::cout << event.eventData.moveData.x << std::endl;
                std::cout << event.eventData.moveData.y << std::endl;

                if (event.eventData.moveData.x > btn_play.getPosition().getX() && event.eventData.moveData.x < btn_play.getPosition().getX() + 85 && event.eventData.moveData.y > btn_play.getPosition().getY() && event.eventData.moveData.y < btn_play.getPosition().getY() + 18) {
                    hovering = 1;
                }
            }
        }

        void render(MinGL & window) override {
            window << background;

            window << (hovering == 0 ? btn_play_hover : btn_play);
            window << (hovering == 1 ? btn_quit_hover : btn_quit);
            window << (hovering == 2 ? btn_options_hover : btn_options);
        }
};
