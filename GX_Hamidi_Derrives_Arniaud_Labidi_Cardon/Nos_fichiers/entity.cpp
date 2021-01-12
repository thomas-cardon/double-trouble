#include "entity.h"

using namespace nsGame;

nsGraphics::Vec2D Entity::getCoordinates() {
    int x = this->getPosition().getX() * CELL_SIZE;
    int y = this->getPosition().getY() * CELL_SIZE;

    return nsGraphics::Vec2D(x, y);
}

nsGraphics::Vec2D Entity::getPosition() {
    return pos;
}
