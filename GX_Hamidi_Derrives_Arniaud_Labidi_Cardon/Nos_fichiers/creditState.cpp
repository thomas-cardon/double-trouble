#include <mingl/gui/sprite.h>
#include <mingl/transition/transition_engine.h>

#include "state.h"
#include "definitions.h"

/**
 *
 * \file    creditState.cpp
 * \authors Thomas Cardon, Alexandre Arniaud
 * \date    10 janvier 2021
 * \version 1.0
 * \brief   Credits state
 */

using namespace nsGame;

class CreditState : public State {
    /**
     * @class CreditState
     * @brief Defines the credits
     * @authors Thomas Cardon, Alexandre Arniaud
     */
    public:
        nsGui::Sprite sprite = nsGui::Sprite(RES_PATH + "/gui/credits.i2s", nsGraphics::Vec2D(0, 0));
        nsTransition::TransitionEngine transitionEngine;

        void load() override {
            nsTransition::TransitionContract spriteContract(sprite, sprite.TRANSITION_POSITION, std::chrono::seconds(11), { 0, -640 });

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
