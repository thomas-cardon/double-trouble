#include <mingl/gui/sprite.h>
#include <mingl/transition/transition_engine.h>

#include "state.h"

using namespace nsGame;

class CreditState : public State {
    public:

        nsGui::Sprite sprite = nsGui::Sprite("../GX_Hamidi_Derrives_Arniaud_Labidi_Cardon/Nos_fichiers/res/gui/credits.i2s", nsGraphics::Vec2D(0, 0));
        nsTransition::TransitionEngine transitionEngine;

        void load() override {
            nsTransition::TransitionContract spriteContract(sprite, sprite.TRANSITION_POSITION, std::chrono::seconds(10), { 0, -800 });

            spriteContract.setDestinationCallback([&] {
                this->setState(0);
            });

            transitionEngine.startContract(spriteContract);
        }

        void update(MinGL & window, unsigned delta) override {
            transitionEngine.update(std::chrono::microseconds(delta * 1000));
        }

        void render(MinGL & window) override {
            window << sprite;
        }
};
