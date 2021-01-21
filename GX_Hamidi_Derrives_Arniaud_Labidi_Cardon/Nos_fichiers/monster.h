#ifndef MONSTER_H
#define MONSTER_H

#include <mingl/mingl.h>
#include <mingl/gui/sprite.h>
#include <mingl/audio/audioengine.h>

#include "entity.h"
<<<<<<< HEAD
#include "player.h"
=======
>>>>>>> main

#include "animation.h"
#include "type.h"

<<<<<<< HEAD
=======
/**
 *
 * \file    monster.h
 * \authors Ines Hamidi, Thomas Cardon
 * \date    11 janvier 2020
 * \version 1.0
 * \brief   Monster
 *
 **/

>>>>>>> main
namespace nsGame {
    /**
     * @class Monster
     * @brief Defines the monsters class
     * @authors Ines Hamidi, Thomas Cardon
     */
    class Monster : public Entity {
        private:
<<<<<<< HEAD
            int delay = 130 * movementSpeed;
            int behaviourId = 1;
        public:
            Monster(int behaviour) : behaviourId(behaviour) {}

            /**
             * @brief Updates the monster
             * @fn void update(CMat & mat, unsigned delta, Player player1, Player player2);
=======
            /** \brief Entity position */
            nsGraphics::Vec2D _goingToPos;

            /** \brief Indicates direction */
            char IS_FACING;

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
>>>>>>> main
             */
            void update(unsigned delta, CMat & mat);

            /**
             * @brief Renders resources
             * @fn void render(MinGL & window);
             */
            void render(MinGL & window);

            /**
             * @brief Loads the ennemy
<<<<<<< HEAD
             * @fn void load(CMyParam & params);
             */
            void load(CMyParam & params);
=======
             * @fn void load();
             */
            void load();
>>>>>>> main

            /**
             * @brief Teleports the entity at its spawn
             * @fn void spawn();
             */
            void spawn();
<<<<<<< HEAD

            /**
             * @brief Sets the movement speed
             * @fn void setMovementSpeed(double speed);
             */
            void setMovementSpeed(double speed);

            /**
             * @brief MonsterMoves
             * @param mat
             */
            void MonsterMoves(CMat & mat);
=======
>>>>>>> main
    };
}

#endif // ENNEMY_H
