#ifndef MONSTER_H
#define MONSTER_H

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>
#include <mingl/audio/audioengine.h>

#include "entity.h"

#include "animation.h"
#include "type.h"

/**
 *
 * \file    monster.h
 * \authors Ines Hamidi, Thomas Cardon
 * \date    11 janvier 2020
 * \version 1.0
 * \brief   Monster
 *
 **/

namespace nsGame {
    /**
     * @class Monster
     * @brief Defines the monsters class
     * @authors Ines Hamidi, Thomas Cardon
     */
    class Monster : public Entity {
        private:
            char IS_FACING;

            int delay = 130 * movementSpeed;
            unsigned behaviourId;
        public:
            /** \brief Animations for every direction */
            Animation bottom = Animation(600, true), top = Animation(600, true), left = Animation(600, true), right = Animation(600, true);

            Monster(unsigned behaviourId);

            /**
             * @brief Updates the ennemy
             * @fn void update(unsigned delta, CMat & mat);
             */
            void update(unsigned delta, CMat & mat);

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window);

            /**
             * @brief Loads the ennemy
             * @fn void load();
             */
            void load();

            /**
             * @brief Teleports the entity at its spawn
             * @fn void spawn();
             */
            void spawn();
    };
}

#endif // ENNEMY_H
