#ifndef MONSTER_H
#define MONSTER_H

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>

#include "entity.h"
#include "player.h"

#include "animation.h"
#include "type.h"

namespace nsGame {
    /**
     * @class Monster
     * @brief Defines the monsters class
     * @author Ines Hamidi
     */
    class Monster : public Entity {
        private:
            int delay = 130 * movementSpeed;
            int behaviourId = 1;
        public:
            Monster(int behaviour) : behaviourId(behaviour) {}

            /**
             * @brief Updates the monster
             * @fn void update(CMat & mat, unsigned delta, Player player1, Player player2);
             */
            void update(unsigned delta, CMat & mat, Player player1, Player player2);

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window);

            /**
             * @brief Loads the ennemy
             * @fn void load(CMyParam & params);
             */
            void load(CMyParam & params);

            /**
             * @brief Teleports the entity at its spawn
             * @fn void spawn();
             */
            void spawn();

            /**
             * @brief Sets the movement speed
             * @fn void setMovementSpeed(double speed);
             */
            void setMovementSpeed(double speed);

            /**
             * @brief MonsterMoves
             * @param mat
             * @param player1
             * @param player2
             */
            void MonsterMoves(CMat & mat);
    };
}

#endif // ENNEMY_H
