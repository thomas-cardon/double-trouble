#include "entity.h"
#include "cooldowns.h"

#include <mingl/shape/circle.h>
/**
 *
 * \file    entity.cpp
 * \author  Thomas Cardon
 * \date    9 janvier 2021
 * \version 1.0
 * \brief   Method definitions for Entity.h
 */

using namespace nsGame;

void Entity::load() {
    for (int i = 1; i <= 6; i++)
        this->_invincible.sprites.push_back(nsGui::Sprite(RES_PATH + "/entities/noDamage/" + std::to_string(i) + ".i2s"));
}

void Entity::update(unsigned delta, CMat & mat) {

}

void Entity::render(MinGL &window) {
    if (this->effects.count(nsGame::EffectType::POWER)) {
        this->_invincible.setPosition(this->getCoordinates());
        this->_invincible.render(window);
    }

    if (this->effects.count(nsGame::EffectType::INVICIBLE)) {
        window << nsShape::Circle(this->getCoordinates(), 4, nsGraphics::KLime);
    }
}

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
    return this->hasEffect(EffectType::INVICIBLE);
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

void Entity::addEffect(EffectType type, unsigned delay) {
    this->effects[type] = std::make_pair(0, delay);
}

void Entity::removeEffect(EffectType type) {
    this->effects.erase(type);
}

bool Entity::hasEffect(EffectType type) {
    return this->effects.count(type) > 0;
}
