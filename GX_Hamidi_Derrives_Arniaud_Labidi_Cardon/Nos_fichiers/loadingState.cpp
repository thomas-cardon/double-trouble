#include "mingl/gui/sprite.h"
#include "state.h"

using namespace nsGame;

class LoadingState : public State {
    public:

        void load() override {}

        int update(MinGL & window, int delta) override {
            return 0;
        }

        void events(nsEvent::Event_t event) override {
        }

        void render(MinGL & window) override {
            window.setBackgroundColor(nsGraphics::KCyan);
        }
};
