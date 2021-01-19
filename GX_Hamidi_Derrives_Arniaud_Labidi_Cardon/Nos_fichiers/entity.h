#ifndef ENTITY_H
#define ENTITY_H

#define CELL_SIZE 32

#include <mingl/graphics/vec2d.h>
#include "type.h"

/**
 * \file    entity.h
 * \author  Thomas Cardon
 * \date    10 janvier 2020
 * \version 1.0
 * \brief   Definitions for the Entity class
 */

namespace nsGame
{
    /**
     * @class Entity
     * @brief Defines the Entity class
     * @author Thomas Cardon
     */
    struct Entity
    {
        protected:
            /** \brief Movement Speed */
            double movementSpeed = 1.0;

        public:
            /** \brief Prevents entity to move */
            bool isAllowedToMove = true;

            nsGraphics::Vec2D pos;

            /**
             * @brief This function is used to get the position on the screen/canvas/window, whatever you want to call it
             * @fn virtual nsGraphics::Vec2D getCoordinates();
             */
            nsGraphics::Vec2D getCoordinates();

           /**
            * @brief Gets the coordinates compared to the map.
            * @fn virtual nsGraphics::Vec2D getPosition();
            */
            nsGraphics::Vec2D getPosition();

            /**
             * @brief Checks if entity can be hit by another entity.
             * @fn virtual bool canBeHitBy(Entity entity);
             */
            bool canBeHitBy(Entity entity);

            /**
             * @brief Teleports the entity at its spawn
             * @fn void spawn();
             */
            void spawn();

            /**
             * @brief Gets the movement speed
             * @fn bool getMovementSpeed();
             */
            double getMovementSpeed();

            /**
             * @brief Sets the movement speed
             * @fn void setMovementSpeed(double speed);
             */
            void setMovementSpeed(double speed);

            /**
             * @brief Checks if entity would be in collision with a structure (walls...) | OVERRIDE IF NEEDED (Flying monsters?)
             * @fn bool inCollision(CMat map, unsigned x, unsigned y);
             */
            bool inCollision(CMat map, unsigned x, unsigned y);

            /**
             * @brief Tells if entity can be attacked
             * @fn bool canTakeDamage();
             */
            bool canTakeDamage();
    };
}

#endif // ENTITY_H
