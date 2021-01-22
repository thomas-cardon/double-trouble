#ifndef MONSTER_H
#define MONSTER_H

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>
#include <mingl/audio/audioengine.h>

#include "type.h"

#include "definitions.h"
#include "entity.h"
#include "player.h"

/**
 * \file    monster.h
 * \authors Ines Hamidi, Thomas Cardon
 * \date    11 janvier 2021
 * \version 1.0
 * \brief   Monster
 */

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

            /** \brief Indicates direction */
            char IS_FACING = 'Z';

            /** \brief Indicates type of behaviour */
            unsigned behaviourId;
        public:
            /** \brief Allows entity to move or not */
            bool canMove = true;

            /** \brief Sprites for every direction */
            nsGui::Sprite top, left, right, bottom;

            Monster(unsigned behaviourId) : Entity("monster-" + std::to_string(behaviourId), nsGraphics::Vec2D()), top(RES_PATH + "/entities/monsters/" + std::to_string(behaviourId) + "M/2.i2s"), left(RES_PATH + "/entities/monsters/" + std::to_string(behaviourId) + "M/2.i2s"), right(RES_PATH + "/entities/monsters/" + std::to_string(behaviourId) + "M/2.i2s"), bottom(RES_PATH + "/entities/monsters/" + std::to_string(behaviourId) + "M/2.i2s") {
                this->behaviourId = behaviourId;
            }

            /**
             * @brief Updates the monster
             * @fn void update(unsigned delta, CMat & mat, Player *p1, Player *p2);
             */
            void update(unsigned delta, CMat & mat, Player *p1, Player *p2);

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
