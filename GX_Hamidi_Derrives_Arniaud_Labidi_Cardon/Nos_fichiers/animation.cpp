#include "animation.h"

using namespace nsGame;

Animation::Animation(nsGraphics::Vec2D vec) {
    this->_pos = vec;
}

Animation::Animation(unsigned delay, bool alternate) {
    this->delay = delay;
    this->alternate = alternate;
}

Animation::Animation(unsigned delay, bool alternate, nsGraphics::Vec2D pos) {
    this->delay = delay;
    this->alternate = alternate;
    this->_pos = pos;
}

void Animation::update(unsigned delta) {
    _currentTime += delta;

    if (_currentTime >= delay) {
        if (!inReverse && currentSprite == sprites.size() - 1) { // NOT REVERSE AND  LAST SPRITE
            if (alternate) inReverse = true;
            else currentSprite = 0;
        }
        else if (inReverse && currentSprite == 0) { // IN REVERSE AND FIRST SPRITE
            currentSprite = 0;
            inReverse = false;
        }
        else {
            if (inReverse) currentSprite--; // -1 IF REVERSE
            else currentSprite++; // +1 IF REVERSE
        }

        std::cout << currentSprite << std::endl;
    }
}

void Animation::setCoordinates(int x, int y) {
    this->_pos.setX(x);
    this->_pos.setY(y);
}

void Animation::setPosition(int x, int y) {
    this->_pos.setX(x * 32); // CELL_SIZE
    this->_pos.setY(y * 32); // CELL_SIZE
}

void Animation::render(MinGL & window) {
    nsGui::Sprite sprite = sprites.at(currentSprite);

    sprite.setPosition(this->_pos);
    sprite.draw(window);
}
