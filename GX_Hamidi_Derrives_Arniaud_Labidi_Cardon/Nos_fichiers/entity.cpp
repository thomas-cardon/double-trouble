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

bool Entity::canBeHitBy(Entity entity) {
    if (this->getPosition().getX() == entity.getPosition().getX() && this->getPosition().getY() == entity.getPosition().getY())
        return true;

    return false;
}

void Entity::spawn(CMyParam params) {
    this->pos.setX(0);
    this->pos.setY(0);
}
