#include "cooldowns.h"

void createCooldown(std::string id, int delay) {
    cooldowns[id] = std::make_pair(0, delay);
}

void updateCooldowns(int delta) {
    for (auto &cd : cooldowns)
        cd.second.first += delta;
}

bool isCooldownOver(std::string id) {
    if (cooldowns[id].first >= cooldowns[id].second) {
        cooldowns[id].first = 0;
        return true;
    }
    return false;
}

bool isCooldownOver(std::string id, bool hasToDelete) {
    if (cooldowns.find(id) != cooldowns.end()) {
        if (hasToDelete) cooldowns.erase(cooldowns.find(id));
        else cooldowns[id].first = 0;
        return true;
    }

    return false;
}


void setCooldownDelay(std::string id, int delay) {
    cooldowns[id].second = delay;
}

void resetCooldowns() {
    cooldowns.clear();
}
