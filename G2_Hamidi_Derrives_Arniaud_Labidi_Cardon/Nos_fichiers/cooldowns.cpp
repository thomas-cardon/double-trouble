#include "cooldowns.h"

/**
 *
 * \file    cooldowns.cpp
 * \author  Thomas Cardon
 * \date    10 janvier 2021
 * \version 1.0
 * \brief   Method definitions for cooldowns.h
 */

using namespace nsGame;

void Cooldowns::createCooldown(std::string id, unsigned delay) {
    cooldowns[id] = std::make_pair(0, delay);
}

void Cooldowns::updateCooldowns(unsigned delta) {
    for (auto &cd : cooldowns)
        cd.second.first += delta;
}

bool Cooldowns::isCooldownOver(std::string id) {
    if (cooldowns.find(id) == cooldowns.end()) return false;

    if (cooldowns[id].first >= cooldowns[id].second) {
        cooldowns[id].first = 0;
        return true;
    }

    return false;
}

bool Cooldowns::isCooldownOver(std::string id, bool hasToDelete) {
    if (cooldowns.find(id) != cooldowns.end()) {
        if (hasToDelete) cooldowns.erase(cooldowns.find(id));
        else cooldowns[id].first = 0;
        return true;
    }

    return false;
}


void Cooldowns::setCooldownDelay(std::string id, unsigned delay) {
    cooldowns[id].second = delay;
}

void Cooldowns::resetCooldowns() {
    cooldowns.clear();
}
