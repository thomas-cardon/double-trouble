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
 * \date    11 janvier 2021
 * \version 1.0
 * \brief   Monster
 *
 **/

namespace nsGame {
    /**
     * @class Monster
     * @brief Defines the monsters class
     * @authors Ines Hamidi, Thomas Cardon, Alexandre Arniaud
     */
    class Monster : public Entity {
        private:
            /** \brief Audio Engine */
            nsAudio::AudioEngine audio;

            /** \brief Entity position */
            nsGraphics::Vec2D _goingToPos;

            /** \brief Indicates direction */
            char IS_FACING, LastMove;

            /** \brief Indicates type of behaviour */
            unsigned behaviourId;
        public:
            /** \brief Allows entity to move or not */
            bool canMove = true;

            /** \brief Animations for every direction */
            Animation bottom = Animation(600, true), top = Animation(600, true), left = Animation(600, true), right = Animation(600, true);

            Monster(unsigned behaviourId);

            /**
             * @brief Returns an entity ID, allows the game to set cooldowns or whatever associated with its ID
             * @return Entity ID
             */
            std::string getEntityId();

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

            /**
             * @brief Damages entity
             * @fn void damage();
             */
            void damage();

            /**
             * @brief Checks if entity can be hit by another entity.
             * @fn virtual bool canBeHitBy(Entity *entity);
             */
            bool canBeHitBy(Entity *entity);
    };
}

#endif // ENNEMY_H
