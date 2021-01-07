#include <mingl/mingl.h>

class Logic {
    public:
    int load() {
        return 0;
    }

    int update() {
        return 0;
    }

    void render(MinGL & window) {
        window.setBackgroundColor(nsGraphics::RGBAcolor(255, 0, 0));
    }
};
