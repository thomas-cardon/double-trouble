#ifndef ENTITY_H
#define ENTITY_H

#define CELL_SIZE 32

#include <mingl/graphics/vec2d.h>
#include "cooldowns.cpp"

namespace nsGame
{
    /**
     * @class Entity
     * @brief Defines the Entity class
     * @author Thomas Cardon
     */
    class Entity
    {
        protected:
            double movementSpeed = 1.0;
        public:
            unsigned hearts = 3;

            nsGraphics::Vec2D pos;

            /**
             * @brief This function is used to get the position on the screen/canvas/window, whatever you want to call it
             * @fn virtual nsGraphics::Vec2D getCoordinates();
             */
            virtual nsGraphics::Vec2D getCoordinates();

             /**
              * @brief Gets the coordinates compared to the map.
              * @fn virtual nsGraphics::Vec2D getPosition();
              */
            virtual nsGraphics::Vec2D getPosition();

            /**
             * @brief Checks if entity can be hit by another entity.
             * @fn virtual bool canBeHitBy(Entity entity);
             */
            virtual bool canBeHitBy(Entity entity);

            /**
             * @brief Teleports the entity at its spawn
             * @fn virtual void spawn(CMyParam params);
             */
            virtual void spawn(CMyParam params);

            /**
             * @brief Gets the movement speed
             * @fn bool getMovementSpeed();
             */
            virtual double getMovementSpeed();

            /**
             * @brief Sets the movement speed
             * @fn void setMovementSpeed(double speed);
             */
            virtual void setMovementSpeed(double speed);

            /**
             * @brief Checks if entity would be in collision with a structure (walls...) | OVERRIDE IF NEEDED (Flying monsters?)
             * @fn bool inCollision(CMat map, unsigned x, unsigned y);
             */
            bool inCollision(CMat map, unsigned x, unsigned y);
    };
}

#endif // ENTITY_H
