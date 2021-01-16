#ifndef COOLDOWNS_H
#define COOLDOWNS_H

#include <string>
#include "type.h"

static std::map<std::string, Cooldown> cooldowns;

/**
 *
 * \file    cooldowns.h
 * \author  Thomas Cardon
 * \date    10 janvier 2020
 * \version 1.0
 * \brief   Method definitions for Player.h
 */

namespace nsGame {
    class Cooldowns {
        public:
            /**
             * @brief Saves a cooldown into the map
             * @param std::string id
             * @param int delay
             */
            static void createCooldown(std::string id, unsigned delay);

            /**
             * @brief Updates cooldowns according to frame delta
             * @param unsigned delta
             */
            static void updateCooldowns(unsigned delta);

            /**
             * @brief Checks if a cooldown is over
             * @param std::string id
             * @return
             */
            static bool isCooldownOver(std::string id);

            /**
             * @brief Checks if a cooldown is over, and deletes it if hasToDelete=true
             * @param std::string id
             * @param bool hasToDelete
             * @return
             */
            static bool isCooldownOver(std::string id, bool hasToDelete);

            /**
             * @brief Sets a new delay for a cooldown that had been saved already.
             * @param std::string id
             * @param unsigned delay
             */
            static void setCooldownDelay(std::string id, unsigned delay);

            /**
             * @brief Removes all cooldowns
             */
            static void resetCooldowns();
    };
}

#endif // COOLDOWNS_H
