#ifndef COOLDOWNS_H
#define COOLDOWNS_H

#include <string.h>
#include "type.h"

std::map<std::string, Cooldown> cooldowns;

/**
 * @brief createCooldown
 * @param id
 * @param delay
 */
void createCooldown(std::string id, int delay);

/**
 * @brief updateCooldowns
 * @param delta
 */
void updateCooldowns(int delta);

/**
 * @brief isCooldownOver
 * @param id
 * @return
 */
bool isCooldownOver(std::string id);

/**
 * @brief isCooldownOver
 * @param id
 * @param hasToDelete
 * @return
 */
bool isCooldownOver(std::string id, bool hasToDelete);

/**
 * @brief setCooldownDelay
 * @param id
 * @param delay
 */
void setCooldownDelay(std::string id, int delay);

/**
 * @brief resetCooldowns
 */
void resetCooldowns();

#endif // COOLDOWNS_H
