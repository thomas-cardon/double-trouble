#include "entity.h"
#include "cooldowns.h"
/**
 *
 * \file    entity.cpp
 * \author  Thomas Cardon
 * \date    9 janvier 2021
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
    if (y >= map.size() - 1) return true;
    if (x >= map[y].size() - 1) return true;

    if (map[y][x] != '0') return true;

    return false;
}


bool Entity::canTakeDamage() {
    return this->_canTakeDamage;
}

void Entity::kill() {
    this->slain = true;
}

bool Entity::canBeHitBy(Entity *entity) {
    if (this->canTakeDamage() && this->getPosition().getX() == entity->getPosition().getX() && this->getPosition().getY() == entity->getPosition().getY())
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

std::string Entity::id() {
    return "entity_" + std::to_string(rand());
}

void Entity::setMovementSpeed(double speed) {
    this->movementSpeed = speed;
    Cooldowns::setCooldownDelay(this->id() + "_move", this->_getDelay());
}
