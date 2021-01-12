#include "mingl/gui/sprite.h"
#include "state.h"

using namespace nsGame;

class LoadingState : public State {
    public:

        void load() override {}

        void render(MinGL & window) override {
            window.setBackgroundColor(nsGraphics::KCyan);
        }
};
