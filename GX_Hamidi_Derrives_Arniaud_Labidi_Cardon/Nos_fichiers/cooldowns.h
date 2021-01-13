#ifndef COOLDOWNS_H
#define COOLDOWNS_H

#include <string.h>
#include "type.h"

std::map<std::string, Cooldown> cooldowns;

/**
 * @brief Saves a cooldown into the map
 * @param std::string id
 * @param int delay
 */
void createCooldown(std::string id, unsigned delay);

/**
 * @brief Updates cooldowns according to frame delta
 * @param unsigned delta
 */
void updateCooldowns(unsigned delta);

/**
 * @brief Checks if a cooldown is over
 * @param std::string id
 * @return
 */
bool isCooldownOver(std::string id);

/**
 * @brief Checks if a cooldown is over, and deletes it if hasToDelete=true
 * @param std::string id
 * @param bool hasToDelete
 * @return
 */
bool isCooldownOver(std::string id, bool hasToDelete);

/**
 * @brief Sets a new delay for a cooldown that had been saved already.
 * @param std::string id
 * @param unsigned delay
 */
void setCooldownDelay(std::string id, unsigned delay);

/**
 * @brief Removes all cooldowns
 */
void resetCooldowns();

#endif // COOLDOWNS_H
