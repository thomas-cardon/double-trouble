#include <mingl/gui/sprite.h>
#include <mingl/audio/audioengine.h>

#include "state.h"
#include "cooldowns.h"

using namespace nsGame;

class MainMenuState : public State {
    /**
     * @class MainMenuState
     * @brief Defines the main menu
     * @authors Thomas Cardon, Alexandre Arniaud
     */
    public:
        nsAudio::AudioEngine audio;

        nsGui::Sprite background = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/background.i2s", nsGraphics::Vec2D(0, 0));

        nsGui::Sprite btn_play = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_play.i2s", nsGraphics::Vec2D(409, 432));
        nsGui::Sprite btn_quit = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_quit.i2s", nsGraphics::Vec2D(409, 530));
        nsGui::Sprite btn_credits = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_credits.i2s", nsGraphics::Vec2D(410, 482));

        nsGui::Sprite btn_play_hover = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_play_hover.i2s", nsGraphics::Vec2D(417, 429));
        nsGui::Sprite btn_quit_hover = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_quit_hover.i2s", nsGraphics::Vec2D(399, 529));
        nsGui::Sprite btn_credits_hover = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/btn_credits_hover.i2s", nsGraphics::Vec2D(401, 478));

        nsGui::Sprite appuyer_a = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/appuyer_a.i2s", nsGraphics::Vec2D(0, 0));

        bool canMove = true;
        int hovering = 0;

        void load() override {
            createCooldown("mainMenu_move", 500);

            audio.loadSound("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/audio/button-select.wav");
            audio.loadSound("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/audio/button-click.wav");
        }

        void events(nsEvent::Event_t event) override {
            std::cout << event.eventType << std::endl;
        }

        void update(MinGL & window, unsigned delta) override {
            if (isCooldownOver("mainMenu_move")) canMove = true;
            if (!canMove) return;

            if (window.isPressed({ 'a', false })) {
                if (hovering == 0) this->setState(1);
                else if (hovering == 1) this->setState(99);
                else if (hovering == 2) window.stopGaphic();

                audio.playSoundFromBuffer("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/audio/button-click.wav");
                return;
            }

            if (window.isPressed({ 's', false })) { // UP
                if (hovering == 2) hovering = 0;
                else hovering++;
            }
            else if (window.isPressed({ 'z', false })) { // DOWN
                if (hovering == 0) hovering = 2;
                else --hovering;
            }
            else return;

            canMove = false;
            audio.playSoundFromBuffer("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/audio/button-select.wav");
        }

        void render(MinGL & window) override {
            window << background;
            window << appuyer_a;

            window << (hovering == 0 ? btn_play_hover : btn_play);
            window << (hovering == 1 ? btn_credits_hover : btn_credits);
            window << (hovering == 2 ? btn_quit_hover : btn_quit);
        }
};
