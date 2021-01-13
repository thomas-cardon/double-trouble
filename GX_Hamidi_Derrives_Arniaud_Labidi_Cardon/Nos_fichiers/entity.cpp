#include "entity.h"

/**
 *
 * \file    entity.cpp
 * \author  Thomas Cardon
 * \date    9 janvier 2020
 * \version 1.0
 * \brief   Method definitions for Entity.h
 */

using namespace nsGame;

nsGraphics::Vec2D Entity::getCoordinates() {
    int x = this->getPosition().getX() * CELL_SIZE;
    int y = this->getPosition().getY() * CELL_SIZE;

    return nsGraphics::Vec2D(x, y);
}

nsGraphics::Vec2D Entity::getPosition() {
    return pos;
}

bool Entity::inCollision(CMat map, unsigned x, unsigned y) {
    if (map.size() < y + 1) return true;
    if (map[y].size() < x + 1) return true;

    if (map[y][x] != '0') return true;

    return false;
}


bool Entity::canBeHitBy(Entity entity) {
    if (this->getPosition().getX() == entity.getPosition().getX() && this->getPosition().getY() == entity.getPosition().getY())
        return true;

    return false;
}

void Entity::spawn() {
    this->pos.setX(0);
    this->pos.setY(0);
}

double Entity::getMovementSpeed() {
    return this->movementSpeed;
}

void Entity::setMovementSpeed(double speed) {
    this->movementSpeed = speed;
}
