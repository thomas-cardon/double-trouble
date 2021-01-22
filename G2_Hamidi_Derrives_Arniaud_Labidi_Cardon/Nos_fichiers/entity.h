#ifndef ENTITY_H
#define ENTITY_H

#include <mingl/graphics/vec2d.h>

#include "animation.h"
#include "effectType.h"

#include "definitions.h"
#include "type.h"

/**
 * \file    entity.h
 * \author  Thomas Cardon
 * \date    10 janvier 2021
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
        private:
            Animation _powerUp = Animation(833, false);
            Animation _invincible = Animation(625, true);

            /** \brief Effect list */
            std::map<nsGame::EffectType, Effect> effects;

        protected:
            /** \brief Movement Speed */
            double movementSpeed = 1.0;

        public:
            /** \brief Prevents entity to move */
            bool isAllowedToMove = true;

            /** \brief Says if entity has been killed */
            bool slain = false;

            /** \brief Entity position */
            nsGraphics::Vec2D pos;

            /**
             * @brief load
             */
            void load();

            /**
             * @brief update
             * @param delta
             * @param mat
             */
            void update(unsigned delta, CMat & mat);

            /**
             * @brief render
             * @param window
             */
            void render(MinGL & window);

            /**
             * @brief Returns an entity ID, allows the game to set cooldowns or whatever associated with its ID
             * @return Entity ID
             */
            std::string id();

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
             * @brief Checks if entity can be hit by another entity.
             * @fn virtual bool canBeHitBy(Entity *entity);
             */
            bool canBeHitBy(Entity *entity);

            /**
             * @brief Damages entity
             * @fn void damage();
             */
            void damage();

            /**
             * @brief Kills entity
             * @fn void damage();
             */
            void kill();

            /**
             * @brief Adds an effect to the entity for x milliseconds
             * @param EffectType - Effect ID
             * @param unsigned delay
             */
            void addEffect(EffectType type, unsigned delay);

            /**
             * @brief Removes an effect from the entity
             * @param EffectType - Effect ID
             * @param Effect - Effect
             */
            void removeEffect(EffectType type);

            /**
             * @brief Says if entity has effect
             * @param EffectType type
             * @return true if effect is present
             */
            bool hasEffect(EffectType type);

            /**
             * @brief Prevents entity to move for X milliseconds
             */
            unsigned _getDelay() {
                return 140 / movementSpeed;
            }
    };
}

#endif // ENTITY_H
