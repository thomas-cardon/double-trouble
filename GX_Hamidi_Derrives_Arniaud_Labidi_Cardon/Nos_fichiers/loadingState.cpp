#include "mingl/gui/sprite.h"
#include "state.h"

using namespace nsGame;

class LoadingState : public State {
    public:

        void load() {}

        int update(MinGL & window) {
            return 0;
        }

        void events(nsEvent::Event_t event) override {
        }

        void render(MinGL & window) override {
            window.setBackgroundColor(nsGraphics::KCyan);
        }
};
