#ifndef MONSTER_H
#define MONSTER_H

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>
#include <mingl/audio/audioengine.h>

<<<<<<< main
#include "type.h"

#include "definitions.h"
#include "entity.h"

/**
 *
 * \file    monster.h
 * \authors Ines Hamidi, Thomas Cardon
 * \date    11 janvier 2021
 * \version 1.0
 * \brief   Monster
 *
 **/

=======
#include "entity.h"
#include "player.h"

#include "animation.h"
#include "type.h"

>>>>>>> Refonte des classes
namespace nsGame {
    /**
     * @class Monster
     * @brief Defines the monsters class
     * @authors Ines Hamidi, Thomas Cardon, Alexandre Arniaud
     */
    class Monster : public Entity {
        private:
<<<<<<< main
            /** \brief Audio Engine */
            nsAudio::AudioEngine audio;

            /** \brief Indicates direction */
            char IS_FACING, LastMove;

            /** \brief Indicates type of behaviour */
            unsigned behaviourId;
        public:
            /** \brief Allows entity to move or not */
            bool canMove = true;

            /** \brief Sprites for every direction */
            nsGui::Sprite top, left, right, bottom;

            Monster(unsigned behaviourId) : top(RES_PATH + "/entities/monsters/" + std::to_string(behaviourId) + "M/2.i2s"), left(RES_PATH + "/entities/monsters/" + std::to_string(behaviourId) + "M/1.i2s"), right(RES_PATH + "/entities/monsters/" + std::to_string(behaviourId) + "M/5.i2s"), bottom(RES_PATH + "/entities/monsters/" + std::to_string(behaviourId) + "M/3.i2s") {
                this->behaviourId = behaviourId;
            };

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
=======
            int delay = 130 * movementSpeed;
            int behaviourId = 1;
        public:
            Monster(int behaviour) : behaviourId(behaviour) {}

            /**
             * @brief Updates the monster
             * @fn void update(CMat & mat, unsigned delta, Player player1, Player player2);
             */
<<<<<<< main
            void update(unsigned delta, CMat & mat, Player player1, Player player2);
>>>>>>> Refonte des classes
=======
            void update(unsigned delta, CMat & mat);
>>>>>>> Moves : finis

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window);

            /**
             * @brief Loads the ennemy
<<<<<<< main
             * @fn void load();
             */
            void load();
=======
             * @fn void load(CMyParam & params);
             */
            void load(CMyParam & params);
>>>>>>> Refonte des classes

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
<<<<<<< main
            bool canBeHitBy(Entity *entity);
=======
            void setMovementSpeed(double speed);

            /**
             * @brief MonsterMoves
             * @param mat
             */
<<<<<<< main
            void MonsterMoves(CMat & mat, Player player1, Player player2);
>>>>>>> Refonte des classes
=======
            void MonsterMoves(CMat & mat);
>>>>>>> random moves
    };
}

#endif // ENNEMY_H
