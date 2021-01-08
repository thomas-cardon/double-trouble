#include "logic.h"

using namespace nsGame;
class MainMenuLogic : public Logic {
    public:
    void load() {

    }

    int update() {
        return 0;
    }

    void render(MinGL & window) {
        window.clearScreen();
        window.setBackgroundColor(nsGraphics::RGBAcolor(0, 0, 255, 1));
    }

};
