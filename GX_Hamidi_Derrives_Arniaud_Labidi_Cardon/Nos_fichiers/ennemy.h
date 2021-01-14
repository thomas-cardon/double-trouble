#ifndef ENNEMY_H
#define ENNEMY_H

/**
 *
 * \file    ennemy.h
 * \author  Ines HAMIDI
 * \date    11 janvier 2020
 * \version 1.0
 * \brief   Ennemy
 *
 **/

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>

#include "entity.cpp"

#include "animation.h"
#include "type.h"

namespace nsGame {
    /**
     * @class Ennemy
     * @brief Defines the ennemy's class
     * @author Ines Hamidi
     */
    class Ennemy : public Entity {
        private:
            char IS_FACING;

            int delay = 130 * movementSpeed;
        public:
            /** \brief Animations for every direction */
            Animation bottom = Animation(642, true), top = Animation(642, true), left = Animation(642, true), right = Animation(642, true);

            Ennemy(unsigned N /* = 2 */);

            /**
             * @brief Updates the ennemy
             * @fn void update(MinGL & window, unsigned delta, CMat map);
             */
            void update(MinGL & window, unsigned delta, CMat map);

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window);

            /**
             * @brief Loads the ennemy
             * @fn void load(CMyParam params);
             */
            void load(CMyParam params);


            /**
             * @brief Teleports the entity at its spawn
             * @fn void spawn();
             */
            void spawn() override;

            /**
             * @brief Sets the movement speed
             * @fn void setMovementSpeed(double speed);
             */
            void setMovementSpeed(double speed) override;
    };
}

#endif // ENNEMY_H
